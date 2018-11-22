#include "spline.h"
#include <fstream>
#include <iostream>

using namespace std;

Spline2d::Spline2d() {
    controlPoints_.clear();
    type_ = Spline2d::LINEAR;
}

void Spline2d::AddPoint(const Eigen::Vector2d& pt) {
    controlPoints_.push_back(pt);
}

void Spline2d::RemoveLastPoint() {
    if (controlPoints_.size() != 0) {
        controlPoints_.erase(controlPoints_.end()-1);
    }
}

void Spline2d::RemoveAll() {
    controlPoints_.clear();
}

void Spline2d::SetSplineType(Spline2d::SplineType type) {
    type_ = type;
}

vector<Eigen::Vector2d> Spline2d::GetInterpolatedSpline() {
    vector<Eigen::Vector2d> interpolatedSpline;
    interpolatedSpline.clear();

    if (type_ == Spline2d::LINEAR) {
        LinearInterpolate(interpolatedSpline);
    } else if (type_ == Spline2d::BEZIER) {
        BezierInterpolate(interpolatedSpline);
    } else if (type_ == Spline2d::DEBOOR) {
        DeBoorInterpolate(interpolatedSpline);
    } else if (type_ == Spline2d::CATMULL) {
        CatmullInterpolate(interpolatedSpline);
    }

    return interpolatedSpline;
}

vector<Eigen::Vector2d> Spline2d::GetControlPoints() {
    return controlPoints_;
}

void Spline2d::LinearInterpolate(std::vector<Eigen::Vector2d>& interpolatedSpline) {
    interpolatedSpline = controlPoints_;
}

void Spline2d::BezierInterpolate(vector<Eigen::Vector2d>& interpolatedSpline) {
    // TODO: fill in code for bezier interpolation
    std::vector<Eigen::Vector2d> cr = controlPoints_;

    Eigen::MatrixXd G;
    G.resize(4, 2);

    Eigen::Matrix4d M;
    M << -1, 3, -3, 1,
         3, -6, 3, 0,
         -3, 3, 0, 0,
         1, 0, 0, 0;

    Eigen::MatrixXd T;
    T.resize(1, 4);

    Eigen::MatrixXd Q;
    Q.resize(1, 2);

    int index = 0;

    while (cr.size() - index >= 4) {
      Eigen::Vector2d b0 = cr[index];
      Eigen::Vector2d b1 = cr[index+1];
      Eigen::Vector2d b2 = cr[index+2];
      Eigen::Vector2d b3 = cr[index+3];

      for (float t = 0; t < 1; t += 0.01) {
        T(0, 0) = t*t*t;
        T(0, 1) = t*t;
        T(0, 2) = t;
        T(0, 3) = 1;

        G.row(0) = b0;
        G.row(1) = b1;
        G.row(2) = b2;
        G.row(3) = b3;

        Q = T * M * G;

        interpolatedSpline.push_back(Q.transpose().col(0));
      }

      index += 3;
    }
}

void Spline2d::DeBoorInterpolate(vector<Eigen::Vector2d>& interpolatedSpline) {
    // TODO: fill in code for deboor interpolation
    std::vector<Eigen::Vector2d> cr = controlPoints_;

    Eigen::MatrixXd G;
    G.resize(4, 2);

    Eigen::Matrix4d M;
    M << -1, 3, -3, 1,
         3, -6, 3, 0,
         -3, 0, 3, 0,
         1, 4, 1, 0;
    M /= 6;

    Eigen::MatrixXd T;
    T.resize(1, 4);

    Eigen::MatrixXd Q;
    Q.resize(1, 2);

    int index = 0;

    while (cr.size() - index >= 4) {
      Eigen::Vector2d b0 = cr[index];
      Eigen::Vector2d b1 = cr[index+1];
      Eigen::Vector2d b2 = cr[index+2];
      Eigen::Vector2d b3 = cr[index+3];

      for (float t = 0; t < 1; t += 0.01) {
        T(0, 0) = t*t*t;
        T(0, 1) = t*t;
        T(0, 2) = t;
        T(0, 3) = 1;

        G.row(0) = b0;
        G.row(1) = b1;
        G.row(2) = b2;
        G.row(3) = b3;

        Q = T * M * G;

        interpolatedSpline.push_back(Q.transpose().col(0));
      }

      index += 1;
    }
}

void Spline2d::CatmullInterpolate(vector<Eigen::Vector2d>& interpolatedSpline) {
    // TODO: fill in code for catmull-rom interpolation
    std::vector<Eigen::Vector2d> cr = controlPoints_;

    Eigen::MatrixXd G;
    G.resize(4, 2);

    Eigen::Matrix4d M;
    M << -1, 3, -3, 1,
         2, -5, 4, -1,
         -1, 0, 1, 0,
         0, 2, 0, 0;
    M /= 2;

    Eigen::MatrixXd T;
    T.resize(1, 4);

    Eigen::MatrixXd Q;
    Q.resize(1, 2);

    int index = 0;

    while (cr.size() - index >= 4) {
      if (index == 0) {
        Eigen::Vector2d b0 = 2 * cr[index] - cr[index+1];
        Eigen::Vector2d b1 = cr[index];
        Eigen::Vector2d b2 = cr[index+1];
        Eigen::Vector2d b3 = cr[index+2];

        for (float t = 0; t < 1; t += 0.01) {
          T(0, 0) = t*t*t;
          T(0, 1) = t*t;
          T(0, 2) = t;
          T(0, 3) = 1;

          G.row(0) = b0;
          G.row(1) = b1;
          G.row(2) = b2;
          G.row(3) = b3;

          Q = T * M * G;

          interpolatedSpline.push_back(Q.transpose().col(0));
        }
      }

      Eigen::Vector2d b0 = cr[index];
      Eigen::Vector2d b1 = cr[index+1];
      Eigen::Vector2d b2 = cr[index+2];
      Eigen::Vector2d b3 = cr[index+3];

      for (float t = 0; t < 1; t += 0.01) {
        T(0, 0) = t*t*t;
        T(0, 1) = t*t;
        T(0, 2) = t;
        T(0, 3) = 1;

        G.row(0) = b0;
        G.row(1) = b1;
        G.row(2) = b2;
        G.row(3) = b3;

        Q = T * M * G;

        interpolatedSpline.push_back(Q.transpose().col(0));
      }

      if (cr.size() - index == 4) {
        Eigen::Vector2d b0 = cr[index+1];
        Eigen::Vector2d b1 = cr[index+2];
        Eigen::Vector2d b2 = cr[index+3];
        Eigen::Vector2d b3 = 2 * cr[index+3] - cr[index+2];

        for (float t = 0; t < 1; t += 0.01) {
          T(0, 0) = t*t*t;
          T(0, 1) = t*t;
          T(0, 2) = t;
          T(0, 3) = 1;

          G.row(0) = b0;
          G.row(1) = b1;
          G.row(2) = b2;
          G.row(3) = b3;

          Q = T * M * G;

          interpolatedSpline.push_back(Q.transpose().col(0));
        }
      }

      index += 1;
    }
}
