#include "MyWorld.h"
#include "RigidBody.h"
#include "CollisionInterface.h"
#include <iostream>

using namespace Eigen;
using namespace std;

MyWorld::MyWorld() {
    mFrame = 0;
    mTimeStep = 0.001;
    mGravity = Vector3d(0.0, -9.8, 0.0);
    mForce.setZero();
    // Create a collision detector
    mCollisionDetector = new CollisionInterface();

    // Create and intialize two default rigid bodies
    RigidBody *rb1 = new RigidBody(dart::dynamics::Shape::BOX, Vector3d(0.05, 0.05, 0.05));
    mCollisionDetector->addRigidBody(rb1, "box"); // Put rb1 in collision detector
    rb1->mPosition[0] = -0.3;
    rb1->mPosition[1] = -0.5;

    rb1->mAngMomentum = Vector3d(0.0, 0.01, 0.0);
    mRigidBodies.push_back(rb1);

    RigidBody *rb2 = new RigidBody(dart::dynamics::Shape::ELLIPSOID, Vector3d(0.06, 0.06, 0.06));
    mCollisionDetector->addRigidBody(rb2, "ellipse"); // Put rb2 in collision detector
    rb2->mPosition[0] = 0.3;
    rb2->mPosition[1] = -0.5;
    rb2->mAngMomentum = Vector3d(0.01, 0.0, 0.0);
    rb2->mColor = Vector4d(0.2, 0.8, 0.2, 1.0); // Blue
    mRigidBodies.push_back(rb2);
}

void MyWorld::initializePinata() {
    // Add pinata to the collison detector
    mCollisionDetector->addSkeleton(mPinataWorld->getSkeleton(0));

    // Add some damping in the Pinata joints
    int nJoints = mPinataWorld->getSkeleton(0)->getNumBodyNodes();
    for (int i = 0; i < nJoints; i++) {
        int nDofs = mPinataWorld->getSkeleton(0)->getJoint(i)->getNumDofs();
        for (int j = 0; j < nDofs; j++)
        mPinataWorld->getSkeleton(0)->getJoint(i)->setDampingCoefficient(j, 1.0);
    }

    // Weld two seems to make a box
    dart::dynamics::BodyNode* top = mPinataWorld->getSkeleton(0)->getBodyNode("top");
    dart::dynamics::BodyNode* front = mPinataWorld->getSkeleton(0)->getBodyNode("front");
    dart::dynamics::BodyNode* back = mPinataWorld->getSkeleton(0)->getBodyNode("back");
    dart::constraint::WeldJointConstraint *joint1 = new dart::constraint::WeldJointConstraint(top, front);
    dart::constraint::WeldJointConstraint *joint2 = new dart::constraint::WeldJointConstraint(top, back);
    mPinataWorld->getConstraintSolver()->addConstraint(joint1);
    mPinataWorld->getConstraintSolver()->addConstraint(joint2);
}

MyWorld::~MyWorld() {
    for (int i = 0; i < mRigidBodies.size(); i++)
    delete mRigidBodies[i];
    mRigidBodies.clear();
    if (mCollisionDetector)
    delete mCollisionDetector;
}

void MyWorld::simulate() {
    mFrame++;

    // TODO: The skeleton code has provided the integration of position and linear momentum,
    // your first job is to fill in the integration of orientation and angular momentum.
    for (int i = 0; i < mRigidBodies.size(); i++) {
        // derivative of position and linear momentum
        Eigen::Vector3d dPos = mRigidBodies[i]->mLinMomentum / mRigidBodies[i]->mMass;
        Eigen::Vector3d dLinMom = mRigidBodies[i]->mMass * mGravity + mRigidBodies[i]->mAccumulatedForce;

        // update position and linear momentum
        mRigidBodies[i]->mPosition += dPos * mTimeStep;
        mRigidBodies[i]->mLinMomentum += mTimeStep * dLinMom;

        mRigidBodies[i]->mQuatOrient.normalize();
        mRigidBodies[i]->mOrientation = mRigidBodies[i]->mQuatOrient.toRotationMatrix();
        Eigen::Matrix3d inertiaBody = mRigidBodies[i]->mShape->computeInertia(mRigidBodies[i]->mMass);
        Eigen::Matrix3d inertia = mRigidBodies[i]->mOrientation * inertiaBody * mRigidBodies[i]->mOrientation.transpose();

        // derivative of orientation and angular momentum
        Eigen::Vector3d dOri = inertia.inverse() * mRigidBodies[i]->mAngMomentum;
        Eigen::Vector3d dAngMom = mRigidBodies[i]->mAccumulatedTorque;

        Eigen::Quaterniond qdot;
        qdot.w() = - 0.5 * mRigidBodies[i]->mQuatOrient.vec().dot(dOri);
        qdot.vec() = 0.5 * (mRigidBodies[i]->mQuatOrient.w() * dOri + mRigidBodies[i]->mQuatOrient.vec().cross(dOri));

        // update orientation and angular momentum
        mRigidBodies[i]->mQuatOrient.w() += qdot.w() * mTimeStep;
        mRigidBodies[i]->mQuatOrient.vec() += qdot.vec() * mTimeStep;
        // mRigidBodies[i]->mOrientation += dOri * mTimeStep;
        mRigidBodies[i]->mAngMomentum += mTimeStep * dAngMom;

        // cout << dOri << endl;
    }

    // Reset accumulated force and torque to be zero after a complete integration
    for (int i = 0; i < mRigidBodies.size(); i++) {
        mRigidBodies[i]->mAccumulatedForce.setZero();
        mRigidBodies[i]->mAccumulatedTorque.setZero();
    }

    // Apply external force to the pinata
    mPinataWorld->getSkeleton(0)->getBodyNode("bottom")->addExtForce(mForce);
    mForce.setZero();

    // Simulate Pinata using DART
    mPinataWorld->step();

    // Run collision detector
    mCollisionDetector->checkCollision();

    // TODO: implement a collision handler
    collisionHandling();

    // Break the pinata if it has enough momentum
    if (mPinataWorld->getSkeleton(0)->getCOMLinearVelocity().norm() > 0.6)
    mPinataWorld->getConstraintSolver()->removeAllConstraints();
}

// TODO: fill in the collision handling function
void MyWorld::collisionHandling() {
    // restitution coefficient
    double epsilon = 0.8;

    // TODO: handle the collision events
    int nContacts = mCollisionDetector->getNumContacts();
    for (int i = 0; i < nContacts; i++) {
      RigidBody* A = mCollisionDetector->getContact(i).rb1;
      RigidBody* B = mCollisionDetector->getContact(i).rb2;

      Eigen::Vector3d point = mCollisionDetector->getContact(i).point;
      Eigen::Vector3d normal = mCollisionDetector->getContact(i).normal;

      double AMassInv = 0;
      double BMassInv = 0;
      Eigen::Matrix3d AInertiaInv = Eigen::Matrix3d::Zero();
      Eigen::Matrix3d BInertiaInv = Eigen::Matrix3d::Zero();
      Eigen::Vector3d pdotA = mCollisionDetector->getContact(i).pinataVelocity;
      Eigen::Vector3d pdotB = mCollisionDetector->getContact(i).pinataVelocity;
      double Aterm = 0;
      double Bterm = 0;

      if (A != NULL) {
        // cout << "A exist" << endl;
        A->mQuatOrient.normalize();
        A->mOrientation = A->mQuatOrient.toRotationMatrix();
        AMassInv = 1.0 / A->mMass;
        Eigen::Matrix3d inertiaBody = A->mShape->computeInertia(A->mMass);
        Eigen::Matrix3d inertia = A->mOrientation * inertiaBody * A->mOrientation.transpose();
        AInertiaInv = inertia.inverse();

        Eigen::Vector3d vA = A->mLinMomentum / A->mMass;
        Eigen::Vector3d wA = A->mShape->computeInertia(A->mMass).inverse() * A->mAngMomentum;
        pdotA = vA + wA.cross(point - A->mPosition) + mGravity * mTimeStep;

        Eigen::Vector3d c = (point - A->mPosition).cross(normal);
        Eigen::Vector3d a = AInertiaInv * c;
        Eigen::Vector3d b = a.cross(point - A->mPosition);
        Aterm = normal.dot(b);
      }

      if (B != NULL) {
        // cout << "B exist" << endl;
        B->mQuatOrient.normalize();
        B->mOrientation = B->mQuatOrient.toRotationMatrix();
        BMassInv = 1.0 / B->mMass;
        Eigen::Matrix3d inertiaBody = B->mShape->computeInertia(B->mMass);
        Eigen::Matrix3d inertia = B->mOrientation * inertiaBody * B->mOrientation.transpose();
        BInertiaInv = inertia.inverse();

        Eigen::Vector3d vB = B->mLinMomentum / B->mMass;
        Eigen::Vector3d wB = B->mShape->computeInertia(B->mMass).inverse() * B->mAngMomentum;
        pdotB = vB + wB.cross(point - B->mPosition) + mGravity * mTimeStep;

        Eigen::Vector3d c = (point - B->mPosition).cross(normal);
        Eigen::Vector3d a = BInertiaInv * c;
        Eigen::Vector3d b = a.cross(point - B->mPosition);
        Bterm = normal.dot(b);
      }

      // cout << "qdotA:" << pdotA << "\nqdotB:" << pdotB << endl;
      double vr = normal.dot(pdotA - pdotB);

      if (vr >= 0) continue;

      double j = (- (1 + epsilon) * vr) / (AMassInv + BMassInv + Aterm + Bterm);

      Eigen::Vector3d J = j * normal;
      // cout << j << endl;
      if (A) {
        A->mAccumulatedForce += J / mTimeStep;
        A->mAccumulatedTorque += (point - A->mPosition).cross(J) / mTimeStep;
      }
      if (B) {
        B->mAccumulatedForce -= J / mTimeStep;
        B->mAccumulatedTorque -= (point - B->mPosition).cross(J) / mTimeStep;
      }
    }
    // if (nContacts)
    // cout << nContacts << endl;
}
