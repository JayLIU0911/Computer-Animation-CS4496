/*
 * Copyright (c) 2015, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Michael X. Grey <mxgrey@gatech.edu>
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DART_DYNAMICS_SIMPLEFRAME_H_
#define DART_DYNAMICS_SIMPLEFRAME_H_

#include "dart/dynamics/Frame.h"

namespace dart {
namespace dynamics {

/// The SimpleFrame class offers a user-friendly way of creating arbitrary
/// Frames within the kinematic tree structure of DART. The user is free to
/// specify the relative transform, relative velocity, and relative acceleration
/// of this Frame.
///
/// While many classes (such as BodyNode and EndEffector) inherit the Frame
/// class, they all have restrictions (constraints) on how their properties
/// (such as position, velocity, and acceleration) can be modified. Conversely,
/// the SimpleFrame class is nothing but a simple abstract Frame whose
/// properties can be arbitrarily set and modified by the user.
class SimpleFrame : public Detachable, public Frame
{
public:

  /// Constructor
  explicit SimpleFrame(Frame* _refFrame,
    const std::string& _name = "simple_frame",
    const Eigen::Isometry3d& _relativeTransform = Eigen::Isometry3d::Identity());

  /// Copy constructor. Note that the parent frame of _otherFrame will not be
  /// copied as the reference frame for the newly created SimpleFrame.
  SimpleFrame(const SimpleFrame& _otherFrame, Frame* _refFrame = Frame::World());

  /// Destructor
  virtual ~SimpleFrame();

  /// Create a new SimpleFrame with the same world transform, velocity, and
  /// acceleration as this one. _refFrame will be used as the reference Frame
  /// of the new SimpleFrame.
  virtual std::shared_ptr<SimpleFrame> clone(Frame* _refFrame = Frame::World()) const;

  /// Make the world transform, world velocity, and world acceleration of this
  /// SimpleFrame match another Frame. The _refFrame argument will be the new
  /// parent Frame of this SimpleFrame. Also copies the Entity Properties if
  /// _copyProperties is left as true.
  void copy(const Frame& _otherFrame, Frame* _refFrame = Frame::World(),
            bool _copyProperties=true);

  /// Same as copy(const Frame&)
  void copy(const Frame* _otherFrame, Frame* _refFrame = Frame::World(),
            bool _copyProperties=true);

  /// Same as copy(const Frame&) except the parent frame of this SimpleFrame is
  /// left the same, and _copyProperties is set to false.
  SimpleFrame& operator=(const SimpleFrame& _otherFrame);

  //--------------------------------------------------------------------------
  // Transform
  //--------------------------------------------------------------------------

  /// Set the relative transform of this SimpleFrame
  void setRelativeTransform(const Eigen::Isometry3d& _newRelTransform);

  /// Set the transform of this SimpleFrame so that its transform with respect
  /// to Frame _withRespectTo is equal to _newTransform. Note that the parent
  /// Frame of this SimpleFrame will not be changed.
  void setTransform(const Eigen::Isometry3d& _newTransform,
                    const Frame* _withRespectTo = Frame::World());

  // Documentation inherited
  const Eigen::Isometry3d& getRelativeTransform() const;

  //--------------------------------------------------------------------------
  // Velocity
  //--------------------------------------------------------------------------

  /// Set the spatial velocity of this SimpleFrame relative to its parent Frame.
  /// Must be in the coordinates of THIS Frame.
  ///
  /// This is the most computationally efficient way of setting relative
  /// velocity.
  ///
  /// Use setClassicDerivatives to set the velocity according to classic
  /// relative linear and angular velocity values.
  void setRelativeSpatialVelocity(const Eigen::Vector6d& _newSpatialVelocity);

  /// Set the spatial velocity of this SimpleFrame relative to its parent Frame.
  /// Specify the coordinate Frame of _newSpatialVelocity.
  ///
  /// Use setClassicDerivatives to set the velocity according to classic
  /// relative linear and angular velocity values.
  void setRelativeSpatialVelocity(const Eigen::Vector6d& _newSpatialVelocity,
                                  const Frame* _inCoordinatesOf);

  // Documentation inherited
  virtual const Eigen::Vector6d& getRelativeSpatialVelocity() const;

  //--------------------------------------------------------------------------
  // Acceleration
  //--------------------------------------------------------------------------

  /// Set the spatial acceleration of this SimpleFrame relative to its parent
  /// Frame. Must be in the coordinates of THIS Frame.
  ///
  /// This is the most computationally efficient way of setting relative
  /// acceleration.
  void setRelativeSpatialAcceleration(
      const Eigen::Vector6d& _newSpatialAcceleration);

  /// Set the spatial acceleration of this SimpleFrame relative to its parent
  /// Frame. Specify the coordinate Frame of _newSpatialAcceleration.
  void setRelativeSpatialAcceleration(
      const Eigen::Vector6d& _newSpatialAcceleration,
      const Frame* _inCoordinatesOf);

  // Documentation inherited
  virtual const Eigen::Vector6d& getRelativeSpatialAcceleration() const;

  // Documentation inherited
  virtual const Eigen::Vector6d& getPrimaryRelativeAcceleration() const;

  // Documentation inherited
  virtual const Eigen::Vector6d& getPartialAcceleration() const;

  //--------------------------------------------------------------------------
  // Classic Method
  //--------------------------------------------------------------------------

  /// Set the relative velocity and acceleration of this Frame according to
  /// classical (non-spatial) relative velocity and relative acceleration
  /// vectors. These values must be given with respect to this Frame's parent
  /// (note: this is unlike setRelativeSpatialVelocity and
  /// setRelativeSpatialAcceleration which expect values in the Frame's own
  /// coordinates).
  ///
  /// This method is slightly less computationally efficient than using
  /// setRelativeSpatialVelocity and setRelativeSpatialAcceleration, but offers
  /// the most intuitive way of setting relative velocities and relative
  /// accelerations.
  ///
  /// These values are equivalent to the terms in the Newton-Euler
  void setClassicDerivatives(
      const Eigen::Vector3d& _linearVelocity      = Eigen::Vector3d::Zero(),
      const Eigen::Vector3d& _angularVelocity     = Eigen::Vector3d::Zero(),
      const Eigen::Vector3d& _linearAcceleration  = Eigen::Vector3d::Zero(),
      const Eigen::Vector3d& _angularAcceleration = Eigen::Vector3d::Zero());

protected:

  /// Relative transform of the SimpleFrame
  Eigen::Isometry3d mRelativeTf;

  /// Relative spatial velocity of the SimpleFrame
  Eigen::Vector6d mRelativeVelocity;

  /// Relative spatial acceleration of the SimpleFrame
  Eigen::Vector6d mRelativeAcceleration;

  /// Partial Acceleration of this Frame
  mutable Eigen::Vector6d mPartialAcceleration;

};

} // namespace dart
} // namespace dynamics

#endif // DART_DYNAMICS_SIMPLEFRAME_H_
