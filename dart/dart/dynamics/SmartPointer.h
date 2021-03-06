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

#ifndef DART_DYNAMICS_SMARTPOINTER_H_
#define DART_DYNAMICS_SMARTPOINTER_H_

#include "dart/dynamics/detail/BodyNodePtr.h"
#include "dart/dynamics/detail/JointPtr.h"
#include "dart/dynamics/detail/DegreeOfFreedomPtr.h"
#include "dart/dynamics/detail/NodePtr.h"
#include "dart/dynamics/detail/InverseKinematicsPtr.h"

// This file is a lightweight means of providing the smart pointers which are
// commonly used within the dart::dynamics namespace. It is 'lightweight' in the
// sense that it does not depend on any types being fully defined, making this
// header suitable for inclusion in other headers which might only want access
// to the smart pointers without needing fully defined classes.

namespace dart {
namespace dynamics {

// -- Standard shared/weak pointers --
// Define a typedef for const and non-const version of shared_ptr and weak_ptr
// for the class X
#define DART_DYNAMICS_MAKE_SHARED_WEAK( X )                 \
  class X ;                                                 \
  typedef std::shared_ptr< X >      X ## Ptr;               \
  typedef std::shared_ptr< const X > Const ## X ## Ptr;     \
  typedef std::weak_ptr< X >        Weak ## X ## Ptr;       \
  typedef std::weak_ptr< const X >   WeakConst ## X ## Ptr;

DART_DYNAMICS_MAKE_SHARED_WEAK(SimpleFrame)

//-----------------------------------------------------------------------------
// Skeleton Smart Pointers
//-----------------------------------------------------------------------------
DART_DYNAMICS_MAKE_SHARED_WEAK(Skeleton)
// These pointers will take the form of:
// std::shared_ptr<Skeleton>        --> SkeletonPtr
// std::shared_ptr<const Skeleton>  --> ConstSkeletonPtr
// std::weak_ptr<Skeleton>          --> WeakSkeletonPtr
// std::weak_ptr<const Skeleton>    --> WeakConstSkeletonPtr

// MetaSkeleton smart pointers
DART_DYNAMICS_MAKE_SHARED_WEAK(MetaSkeleton)

// ReferentialSkeleton smart pointers
DART_DYNAMICS_MAKE_SHARED_WEAK(ReferentialSkeleton)

DART_DYNAMICS_MAKE_SHARED_WEAK(Group)
DART_DYNAMICS_MAKE_SHARED_WEAK(Linkage)
DART_DYNAMICS_MAKE_SHARED_WEAK(Branch)
DART_DYNAMICS_MAKE_SHARED_WEAK(Chain)


//-----------------------------------------------------------------------------
// Shape Smart Pointers
//-----------------------------------------------------------------------------
DART_DYNAMICS_MAKE_SHARED_WEAK(Shape)
DART_DYNAMICS_MAKE_SHARED_WEAK(ArrowShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(BoxShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(CylinderShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(EllipsoidShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(LineSegmentShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(MeshShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(PlaneShape)
DART_DYNAMICS_MAKE_SHARED_WEAK(SoftMeshShape)


//-----------------------------------------------------------------------------
// BodyNode Smart Pointers
//-----------------------------------------------------------------------------
#define DART_DYNAMICS_MAKE_BODYNODEPTR( X )                         \
  class X ;                                                         \
  typedef TemplateBodyNodePtr< X >          X ## Ptr;               \
  typedef TemplateBodyNodePtr< const X >     Const ## X ## Ptr;     \
  typedef TemplateWeakBodyNodePtr< X >      Weak ## X ## Ptr;       \
  typedef TemplateWeakBodyNodePtr< const X > WeakConst ## X ## Ptr;

// BodyNode smart pointers
DART_DYNAMICS_MAKE_BODYNODEPTR(BodyNode)
// These pointers will take the form of:
// TemplateBodyNodePtr<BodyNode>            --> BodyNodePtr
// TemplateBodyNodePtr<const BodyNode>      --> ConstBodyNodePtr
// TemplateWeakBodyNodePtr<BodyNode>        --> WeakBodyNodePtr
// TemplateWeakBodyNodePtr<const BodyNode>  --> WeakConstBodyNodePtr

// SoftBodyNode smart pointers
DART_DYNAMICS_MAKE_BODYNODEPTR(SoftBodyNode)


//-----------------------------------------------------------------------------
// BodyNode-dependent Smart Pointers
//-----------------------------------------------------------------------------
#define DART_DYNAMICS_MAKE_BN_DEPENDENT_PTR( X )                                          \
  class X ;                                                                               \
  typedef Template ## X ## Ptr < X , BodyNode >                   X ## Ptr;               \
  typedef Template ## X ## Ptr < const X , const BodyNode >       Const ## X ## Ptr;      \
  typedef TemplateWeak ## X ## Ptr < X , BodyNode >               Weak ## X ## Ptr;       \
  typedef TemplateWeak ## X ## Ptr < const X , const BodyNode >   WeakConst ## X ## Ptr;


// Joint smart pointers
DART_DYNAMICS_MAKE_BN_DEPENDENT_PTR(Joint)
// These pointers will take the form of:
// TemplateJointPtr<Joint>            --> JointPtr
// TemplateJointPtr<const Joint>      --> ConstJointPtr
// TemplateWeakJointPtr<Joint>        --> WeakJointPtr
// TemplateWeakJointPtr<const Joint>  --> WeakConstJointPtr

// DegreeOfFreedom smart pointers
DART_DYNAMICS_MAKE_BN_DEPENDENT_PTR(DegreeOfFreedom)
// These pointers will take the form of:
// TemplateDegreeOfFreedomPtr<DegreeOfFreedom>            --> DegreeOfFreedomPtr
// TemplateDegreeOfFreedomPtr<const DegreeOfFreedom>      --> ConstDegreeOfFreedomPtr
// TemplateWeakDegreeOfFreedomPtr<DegreeOfFreedom>        --> WeakDegreeOfFreedomPtr
// TemplateWeakDegreeOfFreedomPtr<const DegreeOfFreedom>  --> WeakConstDegreeOfFreedomPtr


//-----------------------------------------------------------------------------
// Node Smart Pointers
//-----------------------------------------------------------------------------
#define DART_DYNAMICS_MAKE_NODEPTR( X )                                            \
  class X ;                                                                        \
  typedef TemplateNodePtr < X , BodyNode >                  X ## Ptr;              \
  typedef TemplateNodePtr < const X , const BodyNode >      Const ## X ## Ptr;     \
  typedef TemplateWeakNodePtr < X , BodyNode >              Weak ## X ## Ptr;      \
  typedef TemplateWeakNodePtr < const X , const BodyNode >  WeakConst ## X ## Ptr;

DART_DYNAMICS_MAKE_NODEPTR(Node)
// These pointers will take the form of:
// TemplateNodePtr<Node>            --> NodePtr
// TemplateNodePtr<const Node>      --> ConstNodePtr
// TemplateWeakNodePtr<Node>        --> WeakNodePtr
// TemplateWeakNodePtr<const Node>  --> WeakConstNodePtr

DART_DYNAMICS_MAKE_NODEPTR(JacobianNode)

DART_DYNAMICS_MAKE_NODEPTR(EndEffector)
// These pointers will take the form of:
// TemplateNodePtr<EndEffector>             --> EndEffectorPtr
// TemplateNodePtr<const EndEffector>       --> ConstEndEffectorPtr
// TemplateWeakNodePtr<EndEffector>         --> WeakEndEffectorPtr
// TemplateWeakNodePtr<const EndEffector>   --> WeakConstEndEffectorPtr


//-----------------------------------------------------------------------------
// InverseKinematics Smart Pointers
//-----------------------------------------------------------------------------
#define DART_DYNAMICS_MAKE_IK_PTR( X )                                                              \
  class X ;                                                                                         \
  typedef TemplateInverseKinematicsPtr< X , JacobianNodePtr > X ## Ptr;                             \
  typedef TemplateInverseKinematicsPtr< const X , ConstJacobianNodePtr > Const ## X ## Ptr;         \
  typedef TemplateWeakInverseKinematicsPtr< X , JacobianNodePtr > Weak ## X ## Ptr;                 \
  typedef TemplateWeakInverseKinematicsPtr< const X , ConstJacobianNodePtr > WeakConst ## X ## Ptr;

DART_DYNAMICS_MAKE_IK_PTR(InverseKinematics)

} // namespace dynamics
} // namespace dart

#endif // DART_DYNAMICS_SMARTPOINTER_H_
