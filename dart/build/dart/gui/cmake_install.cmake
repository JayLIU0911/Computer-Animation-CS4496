# Install script for directory: /home/jay/libraries/dart/dart/gui

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart/gui" TYPE FILE FILES
    "/home/jay/libraries/dart/dart/gui/LoadGlut.h"
    "/home/jay/libraries/dart/dart/gui/GraphWindow.h"
    "/home/jay/libraries/dart/dart/gui/lodepng.h"
    "/home/jay/libraries/dart/dart/gui/Trackball.h"
    "/home/jay/libraries/dart/dart/gui/Jitter.h"
    "/home/jay/libraries/dart/dart/gui/Win3D.h"
    "/home/jay/libraries/dart/dart/gui/Win2D.h"
    "/home/jay/libraries/dart/dart/gui/GLFuncs.h"
    "/home/jay/libraries/dart/dart/gui/SimWindow.h"
    "/home/jay/libraries/dart/dart/gui/GlutWindow.h"
    "/home/jay/libraries/dart/dart/gui/SoftSimWindow.h"
    "/home/jay/libraries/dart/build/dart/gui/gui.h"
    )
endif()

