#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dart-core" for configuration "Release"
set_property(TARGET dart-core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dart-core PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "/usr/lib/x86_64-linux-gnu/libccd.so;/usr/lib/libfcl.so;/usr/lib/x86_64-linux-gnu/libassimp.so;/usr/lib/x86_64-linux-gnu/libboost_regex.so;/usr/lib/x86_64-linux-gnu/libboost_system.so;/usr/lib/x86_64-linux-gnu/libGLU.so;/usr/lib/x86_64-linux-gnu/libGL.so;/usr/lib/x86_64-linux-gnu/libglut.so;/usr/lib/x86_64-linux-gnu/libXmu.so;/usr/lib/x86_64-linux-gnu/libXi.so"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdart-core.so.5.1.2"
  IMPORTED_SONAME_RELEASE "libdart-core.so.5.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS dart-core )
list(APPEND _IMPORT_CHECK_FILES_FOR_dart-core "${_IMPORT_PREFIX}/lib/libdart-core.so.5.1.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
