#include "simulator.h"
#include <fstream>
#include <iostream>

using namespace std;

Simulator::Simulator() {
    // initialize the particles
    mParticles.resize(3);

    // Init particle positions (default is 0, 0, 0)
    mParticles[0].mPosition[0] = -0.3;
    mParticles[0].mPosition[1] = 20.0;
    mParticles[1].mPosition[0] = 0.0;
    mParticles[1].mPosition[1] = 20.0;
    mParticles[2].mPosition[0] = 0.3;
    mParticles[2].mPosition[1] = 20.0;

    // Init particle colors (default is red)
    mParticles[1].mColor = Eigen::Vector4d(0.2, 0.2, 0.9, 1.0); // Blue
    mParticles[2].mColor = Eigen::Vector4d(0.2, 0.2, 0.9, 1.0); // Blue

    mTimeStep = 0.03;
    mElapsedTime = 0;
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
    mParticles[0].mPosition[0] = -0.3;
    mParticles[0].mPosition[1] = 20.0;
    mParticles[1].mPosition[0] = 0.0;
    mParticles[1].mPosition[1] = 20.0;
    mParticles[2].mPosition[0] = 0.3;
    mParticles[2].mPosition[1] = 20.0;

    for (int i = 0; i < 3; i++) {
        mParticles[i].mVelocity.setZero();
        mParticles[i].mAccumulatedForce.setZero();
    }

    mElapsedTime = 0;
}

void Simulator::simulate() {
    // TODO: Replace the following code
    // for (int i = 0; i < mParticles.size(); i++) {
    //     mParticles[i].mPosition[1] -= 0.005;
    // }

    mElapsedTime += mTimeStep;
    
    for (int i = 0; i < mParticles.size(); i++) {
        mParticles[i].mAccumulatedForce[1] = 9.8 * mParticles[i].mMass;
    }

    mParticles[0].mPosition[1] = (-1) * 0.5 * 9.8 * mElapsedTime * mElapsedTime + 20;
    mParticles[0].mVelocity[1] = (-1) * 9.8 * mElapsedTime;

    mParticles[1].mPosition[1] += mTimeStep * mParticles[1].mVelocity[1];
    mParticles[1].mVelocity[1] -= 9.8 * mTimeStep;

    double mpPosition = mParticles[2].mPosition[1] + 0.5 * mTimeStep * mParticles[2].mVelocity[1];
    double mpvelocity = mParticles[2].mVelocity[1] - 0.5 * 9.8 * mTimeStep;
    mParticles[2].mPosition[1] += mTimeStep * mpvelocity;
    mParticles[2].mVelocity[1] -= 9.8 * mTimeStep;

    // for (int i = 0; i < mParticles.size(); i++) {
    //     cout << mParticles[i].mPosition[1] << "\t";
    //     cout << mParticles[i].mVelocity[1] << ", ";
    // }
    // cout << endl;

}
