# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jay/libraries/dart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jay/libraries/dart/build

# Include any dependencies generated for this target.
include tutorials/CMakeFiles/tutorialDominoes.dir/depend.make

# Include the progress variables for this target.
include tutorials/CMakeFiles/tutorialDominoes.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/CMakeFiles/tutorialDominoes.dir/flags.make

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o: tutorials/CMakeFiles/tutorialDominoes.dir/flags.make
tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o: ../tutorials/tutorialDominoes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jay/libraries/dart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o"
	cd /home/jay/libraries/dart/build/tutorials && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o -c /home/jay/libraries/dart/tutorials/tutorialDominoes.cpp

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.i"
	cd /home/jay/libraries/dart/build/tutorials && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jay/libraries/dart/tutorials/tutorialDominoes.cpp > CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.i

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.s"
	cd /home/jay/libraries/dart/build/tutorials && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jay/libraries/dart/tutorials/tutorialDominoes.cpp -o CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.s

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.requires:

.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.requires

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.provides: tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.requires
	$(MAKE) -f tutorials/CMakeFiles/tutorialDominoes.dir/build.make tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.provides.build
.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.provides

tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.provides.build: tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o


# Object files for target tutorialDominoes
tutorialDominoes_OBJECTS = \
"CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o"

# External object files for target tutorialDominoes
tutorialDominoes_EXTERNAL_OBJECTS =

tutorials/tutorialDominoes: tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o
tutorials/tutorialDominoes: tutorials/CMakeFiles/tutorialDominoes.dir/build.make
tutorials/tutorialDominoes: lib/libdart.so.5.1.2
tutorials/tutorialDominoes: lib/libdart-core.so.5.1.2
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libccd.so
tutorials/tutorialDominoes: /usr/lib/libfcl.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libassimp.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libboost_regex.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libboost_system.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libGLU.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libGL.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libglut.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libXmu.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libXi.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/liburdfdom_sensor.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/liburdfdom_model_state.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/liburdfdom_model.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/liburdfdom_world.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libtinyxml.so
tutorials/tutorialDominoes: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
tutorials/tutorialDominoes: tutorials/CMakeFiles/tutorialDominoes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jay/libraries/dart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tutorialDominoes"
	cd /home/jay/libraries/dart/build/tutorials && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorialDominoes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tutorials/CMakeFiles/tutorialDominoes.dir/build: tutorials/tutorialDominoes

.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/build

tutorials/CMakeFiles/tutorialDominoes.dir/requires: tutorials/CMakeFiles/tutorialDominoes.dir/tutorialDominoes.cpp.o.requires

.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/requires

tutorials/CMakeFiles/tutorialDominoes.dir/clean:
	cd /home/jay/libraries/dart/build/tutorials && $(CMAKE_COMMAND) -P CMakeFiles/tutorialDominoes.dir/cmake_clean.cmake
.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/clean

tutorials/CMakeFiles/tutorialDominoes.dir/depend:
	cd /home/jay/libraries/dart/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jay/libraries/dart /home/jay/libraries/dart/tutorials /home/jay/libraries/dart/build /home/jay/libraries/dart/build/tutorials /home/jay/libraries/dart/build/tutorials/CMakeFiles/tutorialDominoes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/CMakeFiles/tutorialDominoes.dir/depend

