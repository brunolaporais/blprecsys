# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/brunolaporais/git/blprecsys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brunolaporais/git/blprecsys

# Include any dependencies generated for this target.
include CMakeFiles/recommender.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recommender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recommender.dir/flags.make

CMakeFiles/recommender.dir/main.cpp.o: CMakeFiles/recommender.dir/flags.make
CMakeFiles/recommender.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunolaporais/git/blprecsys/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/recommender.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/recommender.dir/main.cpp.o -c /home/brunolaporais/git/blprecsys/main.cpp

CMakeFiles/recommender.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recommender.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunolaporais/git/blprecsys/main.cpp > CMakeFiles/recommender.dir/main.cpp.i

CMakeFiles/recommender.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recommender.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunolaporais/git/blprecsys/main.cpp -o CMakeFiles/recommender.dir/main.cpp.s

CMakeFiles/recommender.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/recommender.dir/main.cpp.o.requires

CMakeFiles/recommender.dir/main.cpp.o.provides: CMakeFiles/recommender.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/recommender.dir/build.make CMakeFiles/recommender.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/recommender.dir/main.cpp.o.provides

CMakeFiles/recommender.dir/main.cpp.o.provides.build: CMakeFiles/recommender.dir/main.cpp.o

# Object files for target recommender
recommender_OBJECTS = \
"CMakeFiles/recommender.dir/main.cpp.o"

# External object files for target recommender
recommender_EXTERNAL_OBJECTS =

recommender: CMakeFiles/recommender.dir/main.cpp.o
recommender: CMakeFiles/recommender.dir/build.make
recommender: model/libmodel.a
recommender: file_operation/libfile_operation.a
recommender: model/libmodel.a
recommender: CMakeFiles/recommender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable recommender"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recommender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recommender.dir/build: recommender
.PHONY : CMakeFiles/recommender.dir/build

CMakeFiles/recommender.dir/requires: CMakeFiles/recommender.dir/main.cpp.o.requires
.PHONY : CMakeFiles/recommender.dir/requires

CMakeFiles/recommender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recommender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recommender.dir/clean

CMakeFiles/recommender.dir/depend:
	cd /home/brunolaporais/git/blprecsys && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys/CMakeFiles/recommender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recommender.dir/depend
