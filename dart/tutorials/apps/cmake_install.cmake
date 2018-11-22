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
  include("/home/jay/libraries/dart/tutorials/apps/atlasSimbicon/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/hardcodedDesign/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/jointConstraints/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/operationalSpaceControl/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/vehicle/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/rigidShapes/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/softBodies/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/mixedChain/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/hybridDynamics/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/bipedStand/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/simpleFrames/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/rigidChain/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/rigidCubes/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/rigidLoop/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/addDeleteSkels/cmake_install.cmake")
  include("/home/jay/libraries/dart/tutorials/apps/speedTest/cmake_install.cmake")

endif()

