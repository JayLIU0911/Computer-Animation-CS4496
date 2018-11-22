###############################################################################
# Config file for DARTCore
#
# This sets the following variables:
# DARTCore_INCLUDE_DIRS - Directories containing the DART include files.
# DARTCore_LIBRARY_DIRS - Directories that contain the DART libraries.
# DARTCore_VERSION      - DART version.

#===============================================================================
# DARTCore_INCLUDE_DIRS
#===============================================================================
set(DARTCore_INCLUDE_DIRS "/usr/local/include;/usr/include/eigen3")

#===============================================================================
# DARTCore_LIBRARIES
#===============================================================================
if(NOT TARGET dart-core)
  include("${CMAKE_CURRENT_LIST_DIR}/DARTCoreTargets.cmake")
endif()
set(DARTCore_LIBRARIES dart-core)

#===============================================================================
# DARTCore_VERSION
#===============================================================================
set(DARTCore_VERSION 5.1.2)
