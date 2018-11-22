#include "simulator.h"
#include <fstream>
#include <iostream>

using namespace std;

Simulator::Simulator() {
    // initialize the particles
    mParticles.resize(2);

    // Init particle positions (default is 0, 0, 0)
    mParticles[0].mPosition[0] = 0.2;
    mParticles[1].mPosition[0] = 0.2;
    mParticles[1].mPosition[1] = -0.1;

    mTimeStep = 0.0003;
}

int Simulator::getNumParticles() {
    return mParticles.size();
}

Particle* Simulator::getParticle(int index) {
    return &mParticles[index];
}

double Simulator::getTimeStep() {
    return mTimeStep;
}

void Simulator::reset() {
    mParticles[0].mPosition[1] = 0.0;
    mParticles[0].mPosition[0] = 0.2;
    mParticles[1].mPosition[0] = 0.2;
    mParticles[1].mPosition[1] = -0.1;

    for (int i = 0; i < getNumParticles(); i++) {
        mParticles[i].mVelocity.setZero();
        mParticles[i].mAccumulatedForce.setZero();
    }

}

void Simulator::simulate() {
    // TODO:

    for (int i = 0; i < mParticles.size(); i++) {
        mParticles[i].mAccumulatedForce[1] -= 9.8 * mParticles[i].mMass;
    }

  	double kd = 0.5;
    double ks = 0.5;

    Eigen::Vector3d relativePosition = mParticles[0].mPosition - mParticles[1].mPosition;
    Eigen::Vector3d relativeVelocity = mParticles[0].mVelocity - mParticles[1].mVelocity;

    Eigen::MatrixXd W = Eigen::MatrixXd::Identity(6, 6);
    Eigen::VectorXd Q( mParticles[0].mAccumulatedForce.rows() + mParticles[1].mAccumulatedForce.rows() );
    Q << mParticles[0].mAccumulatedForce, mParticles[1].mAccumulatedForce;
    Eigen::VectorXd qdot( mParticles[0].mVelocity.rows() + mParticles[1].mVelocity.rows() );
    qdot << mParticles[0].mVelocity, mParticles[1].mVelocity;

  	Eigen::MatrixXd J(2, 6);
    J.row(0) << mParticles[0].mPosition.transpose(), 0, 0, 0;
    J.row(1) << relativePosition.transpose(), -relativePosition.transpose();
  	Eigen::MatrixXd Jtran = J.transpose();

  	Eigen::MatrixXd Jdot(2, 6);
    Jdot.row(0) << mParticles[0].mVelocity.transpose(), 0, 0, 0;
    Jdot.row(1) << relativeVelocity.transpose(), -relativeVelocity.transpose();

  	Eigen::MatrixXd C(2, 1);
  	C(0, 0) = 0.5 * (mParticles[0].mPosition.dot(mParticles[0].mPosition) - pow(0.2, 2));
  	C(1, 0) = 0.5 * (relativePosition.dot(relativePosition) - pow(0.1, 2));

  	Eigen::MatrixXd Cdot(2, 1);
  	Cdot(0, 0) = mParticles[0].mPosition.dot(mParticles[0].mVelocity);
  	Cdot(1, 0) = relativePosition.dot(relativeVelocity);

  	Eigen::MatrixXd lambda = (J*W*Jtran).inverse() * (-Jdot*qdot - J*W*Q - ks*C - kd*Cdot);
  	Q += Jtran * lambda;

    mParticles[0].mAccumulatedForce[0] = Q(0, 0);
    mParticles[0].mAccumulatedForce[1] = Q(1, 0);
  	mParticles[0].mAccumulatedForce[2] = Q(2, 0);
  	mParticles[1].mAccumulatedForce[0] = Q(3, 0);
    mParticles[1].mAccumulatedForce[1] = Q(4, 0);
  	mParticles[1].mAccumulatedForce[2] = Q(5, 0);

    // double lambda2 = (- mParticles[1].mAccumulatedForce.dot(relativePosition)
    //                   - mParticles[1].mMass * relativeVelocity.dot(relativeVelocity))
    //                   // - 0.5 * (0.5 * relativePosition.dot(relativePosition) - 0.005)
    //                   // - 0.5 * relativePosition.dot(relativeVelocity))
    //                   / relativePosition.dot(relativePosition);
    //
    // Eigen::Vector3d conForce2 = lambda2 * relativePosition;
    // mParticles[1].mAccumulatedForce += conForce2;
    // cout << conForce2 << endl;
    // // mParticles[0].mAccumulatedForce -= conForce2;
    //
    // double lambda1 = (- mParticles[0].mAccumulatedForce.dot(mParticles[0].mPosition)
    //                   - mParticles[0].mMass * mParticles[0].mVelocity.dot(mParticles[0].mVelocity))
    //                   // - 0.5 * (0.5 * mParticles[0].mPosition.dot(mParticles[0].mPosition) - 0.02)
    //                   // - 0.5 * mParticles[0].mPosition.dot(mParticles[0].mVelocity))
    //                   / mParticles[0].mPosition.dot(mParticles[0].mPosition);
    //
    // double lambda3 = (mParticles[0].mAccumulatedForce.dot(relativePosition)
    //                   - mParticles[0].mMass * relativeVelocity.dot(relativeVelocity))
    //                   // - 0.5 * (0.5 * relativePosition.dot(relativePosition) - 0.005)
    //                   // - 0.5 * relativePosition.dot(relativeVelocity))
    //                   / relativePosition.dot(relativePosition);
    //
    // Eigen::Vector3d conForce1 = lambda1 * mParticles[0].mPosition;
    // mParticles[0].mAccumulatedForce += conForce1;

    for (int i = 0; i < mParticles.size(); i++) {
        mParticles[i].mPosition += mParticles[i].mVelocity * mTimeStep;
        mParticles[i].mVelocity += mParticles[i].mAccumulatedForce / mParticles[i].mMass * mTimeStep;
    }

    for (int i = 0; i < mParticles.size(); i++) {
        mParticles[i].mAccumulatedForce.setZero();
    }
}
