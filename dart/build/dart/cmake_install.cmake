# Install script for directory: /home/jay/libraries/dart/dart

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart" TYPE FILE FILES "/home/jay/libraries/dart/dart/dart-core.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jay/libraries/dart/build/lib/libdart-core.so.5.1.2"
    "/home/jay/libraries/dart/build/lib/libdart-core.so.5.1"
    "/home/jay/libraries/dart/build/lib/libdart-core.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jay/libraries/dart/build/lib:/usr/local/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dart" TYPE FILE FILES "/home/jay/libraries/dart/dart/dart.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jay/libraries/dart/build/lib/libdart-core.so.5.1.2"
    "/home/jay/libraries/dart/build/lib/libdart-core.so.5.1"
    "/home/jay/libraries/dart/build/lib/libdart-core.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart-core.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jay/libraries/dart/build/lib:/usr/local/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jay/libraries/dart/build/lib/libdart.so.5.1.2"
    "/home/jay/libraries/dart/build/lib/libdart.so.5.1"
    "/home/jay/libraries/dart/build/lib/libdart.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so.5.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so.5.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdart.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jay/libraries/dart/build/lib:/usr/local/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jay/libraries/dart/build/dart/collision/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/common/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/constraint/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/dynamics/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/optimizer/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/integration/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/lcpsolver/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/math/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/renderer/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/simulation/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/gui/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/planning/cmake_install.cmake")
  include("/home/jay/libraries/dart/build/dart/utils/cmake_install.cmake")

endif()

