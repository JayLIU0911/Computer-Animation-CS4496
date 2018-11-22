#ifndef SPLINE_H
#define SPLINE_H

#define EIGEN_DONT_VECTORIZE
#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT

#include <vector>
#include <string>
#include <Eigen/Dense>

// class for spline
class Spline2d {
public:
    enum SplineType {LINEAR, BEZIER, DEBOOR, CATMULL};
public:
    Spline2d();
    
    void AddPoint(const Eigen::Vector2d&);
    
    void RemoveLastPoint();
    
    void RemoveAll();
    
    void SetSplineType(SplineType type);
    
    std::vector<Eigen::Vector2d> GetInterpolatedSpline();
    
    std::vector<Eigen::Vector2d> GetControlPoints();
    
private:
    void LinearInterpolate(std::vector<Eigen::Vector2d>& interpolatedSpline);
    
    void BezierInterpolate(std::vector<Eigen::Vector2d>& interpolatedSpline);
    
    void DeBoorInterpolate(std::vector<Eigen::Vector2d>& interpolatedSpline);
    
    void CatmullInterpolate(std::vector<Eigen::Vector2d>& interpolatedSpline);
    
    std::vector<Eigen::Vector2d> controlPoints_;
    SplineType type_;
};

#endif  // SPLINE_H
