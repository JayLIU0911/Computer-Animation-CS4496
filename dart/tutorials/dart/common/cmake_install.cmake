# Install script for directory: /home/jay/libraries/dart/dart/common

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart/common" TYPE FILE FILES
    "/home/jay/libraries/dart/dart/common/ResourceRetriever.h"
    "/home/jay/libraries/dart/dart/common/Resource.h"
    "/home/jay/libraries/dart/dart/common/Timer.h"
    "/home/jay/libraries/dart/dart/common/Console.h"
    "/home/jay/libraries/dart/dart/common/LocalResource.h"
    "/home/jay/libraries/dart/dart/common/Uri.h"
    "/home/jay/libraries/dart/dart/common/NameManager.h"
    "/home/jay/libraries/dart/dart/common/Deprecated.h"
    "/home/jay/libraries/dart/dart/common/Memory.h"
    "/home/jay/libraries/dart/dart/common/Subject.h"
    "/home/jay/libraries/dart/dart/common/Signal.h"
    "/home/jay/libraries/dart/dart/common/sub_ptr.h"
    "/home/jay/libraries/dart/dart/common/Observer.h"
    "/home/jay/libraries/dart/dart/common/LocalResourceRetriever.h"
    "/home/jay/libraries/dart/tutorials/dart/common/common.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart/common/detail" TYPE FILE FILES
    "/home/jay/libraries/dart/dart/common/detail/ConnectionBody.h"
    "/home/jay/libraries/dart/dart/common/detail/NameManager.h"
    "/home/jay/libraries/dart/dart/common/detail/Signal.h"
    "/home/jay/libraries/dart/dart/common/detail/sub_ptr.h"
    )
endif()

