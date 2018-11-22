# Install script for directory: /home/jay/libraries/dart/apps

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jay/libraries/dart/build/apps/atlasSimbicon/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/twister/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/hardcodedDesign/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/jointConstraints/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/operationalSpaceControl/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/vehicle/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/rigidShapes/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/softBodies/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/mixedChain/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/hybridDynamics/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/bipedStand/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/rigidBodies/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/simpleFrames/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/rigidChain/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/rigidCubes/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/rigidLoop/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/addDeleteSkels/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/apps/speedTest/cmake_install.cmake")

endif()

