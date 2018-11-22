# Install script for directory: /home/jay/libraries/dart/dart/dynamics

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart/dynamics" TYPE FILE FILES
    "/home/jay/libraries/dart/dart/dynamics/UniversalJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/Entity.h"
    "/home/jay/libraries/dart/dart/dynamics/InvalidIndex.h"
    "/home/jay/libraries/dart/dart/dynamics/BoxShape.h"
    "/home/jay/libraries/dart/dart/dynamics/EllipsoidShape.h"
    "/home/jay/libraries/dart/dart/dynamics/SingleDofJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/RevoluteJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/Shape.h"
    "/home/jay/libraries/dart/dart/dynamics/EndEffector.h"
    "/home/jay/libraries/dart/dart/dynamics/ZeroDofJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/SimpleFrame.h"
    "/home/jay/libraries/dart/dart/dynamics/InverseKinematics.h"
    "/home/jay/libraries/dart/dart/dynamics/SoftBodyNode.h"
    "/home/jay/libraries/dart/dart/dynamics/SmartPointer.h"
    "/home/jay/libraries/dart/dart/dynamics/Branch.h"
    "/home/jay/libraries/dart/dart/dynamics/MetaSkeleton.h"
    "/home/jay/libraries/dart/dart/dynamics/MultiDofJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/ReferentialSkeleton.h"
    "/home/jay/libraries/dart/dart/dynamics/Frame.h"
    "/home/jay/libraries/dart/dart/dynamics/BodyNode.h"
    "/home/jay/libraries/dart/dart/dynamics/Joint.h"
    "/home/jay/libraries/dart/dart/dynamics/ArrowShape.h"
    "/home/jay/libraries/dart/dart/dynamics/PlanarJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/ScrewJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/Node.h"
    "/home/jay/libraries/dart/dart/dynamics/HierarchicalIK.h"
    "/home/jay/libraries/dart/dart/dynamics/Group.h"
    "/home/jay/libraries/dart/dart/dynamics/BallJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/WeldJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/TranslationalJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/DegreeOfFreedom.h"
    "/home/jay/libraries/dart/dart/dynamics/PlaneShape.h"
    "/home/jay/libraries/dart/dart/dynamics/PointMass.h"
    "/home/jay/libraries/dart/dart/dynamics/JacobianNode.h"
    "/home/jay/libraries/dart/dart/dynamics/Inertia.h"
    "/home/jay/libraries/dart/dart/dynamics/AssimpInputResourceAdaptor.h"
    "/home/jay/libraries/dart/dart/dynamics/SoftMeshShape.h"
    "/home/jay/libraries/dart/dart/dynamics/Chain.h"
    "/home/jay/libraries/dart/dart/dynamics/Linkage.h"
    "/home/jay/libraries/dart/dart/dynamics/Skeleton.h"
    "/home/jay/libraries/dart/dart/dynamics/PrismaticJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/MeshShape.h"
    "/home/jay/libraries/dart/dart/dynamics/CylinderShape.h"
    "/home/jay/libraries/dart/dart/dynamics/Marker.h"
    "/home/jay/libraries/dart/dart/dynamics/TemplatedJacobianNode.h"
    "/home/jay/libraries/dart/dart/dynamics/EulerJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/LineSegmentShape.h"
    "/home/jay/libraries/dart/dart/dynamics/FreeJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/FixedFrame.h"
    "/home/jay/libraries/dart/tutorials/dart/dynamics/dynamics.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart/dynamics/detail" TYPE FILE FILES
    "/home/jay/libraries/dart/dart/dynamics/detail/BodyNodePtr.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/InverseKinematics.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/MultiDofJoint.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/BodyNode.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/NodePtr.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/DegreeOfFreedomPtr.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/JointPtr.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/Skeleton.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/InverseKinematicsPtr.h"
    "/home/jay/libraries/dart/dart/dynamics/detail/TemplatedJacobianNode.h"
    )
endif()

