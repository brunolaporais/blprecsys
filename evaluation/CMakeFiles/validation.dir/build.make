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
include evaluation/CMakeFiles/validation.dir/depend.make

# Include the progress variables for this target.
include evaluation/CMakeFiles/validation.dir/progress.make

# Include the compile flags for this target's objects.
include evaluation/CMakeFiles/validation.dir/flags.make

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o: evaluation/CMakeFiles/validation.dir/flags.make
evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o: evaluation/ErrorValidation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunolaporais/git/blprecsys/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o"
	cd /home/brunolaporais/git/blprecsys/evaluation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/validation.dir/ErrorValidation.cpp.o -c /home/brunolaporais/git/blprecsys/evaluation/ErrorValidation.cpp

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/validation.dir/ErrorValidation.cpp.i"
	cd /home/brunolaporais/git/blprecsys/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunolaporais/git/blprecsys/evaluation/ErrorValidation.cpp > CMakeFiles/validation.dir/ErrorValidation.cpp.i

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/validation.dir/ErrorValidation.cpp.s"
	cd /home/brunolaporais/git/blprecsys/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunolaporais/git/blprecsys/evaluation/ErrorValidation.cpp -o CMakeFiles/validation.dir/ErrorValidation.cpp.s

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.requires:
.PHONY : evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.requires

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.provides: evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.requires
	$(MAKE) -f evaluation/CMakeFiles/validation.dir/build.make evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.provides.build
.PHONY : evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.provides

evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.provides.build: evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o

# Object files for target validation
validation_OBJECTS = \
"CMakeFiles/validation.dir/ErrorValidation.cpp.o"

# External object files for target validation
validation_EXTERNAL_OBJECTS =

evaluation/libvalidation.a: evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o
evaluation/libvalidation.a: evaluation/CMakeFiles/validation.dir/build.make
evaluation/libvalidation.a: evaluation/CMakeFiles/validation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libvalidation.a"
	cd /home/brunolaporais/git/blprecsys/evaluation && $(CMAKE_COMMAND) -P CMakeFiles/validation.dir/cmake_clean_target.cmake
	cd /home/brunolaporais/git/blprecsys/evaluation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/validation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
evaluation/CMakeFiles/validation.dir/build: evaluation/libvalidation.a
.PHONY : evaluation/CMakeFiles/validation.dir/build

evaluation/CMakeFiles/validation.dir/requires: evaluation/CMakeFiles/validation.dir/ErrorValidation.cpp.o.requires
.PHONY : evaluation/CMakeFiles/validation.dir/requires

evaluation/CMakeFiles/validation.dir/clean:
	cd /home/brunolaporais/git/blprecsys/evaluation && $(CMAKE_COMMAND) -P CMakeFiles/validation.dir/cmake_clean.cmake
.PHONY : evaluation/CMakeFiles/validation.dir/clean

evaluation/CMakeFiles/validation.dir/depend:
	cd /home/brunolaporais/git/blprecsys && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys/evaluation /home/brunolaporais/git/blprecsys /home/brunolaporais/git/blprecsys/evaluation /home/brunolaporais/git/blprecsys/evaluation/CMakeFiles/validation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : evaluation/CMakeFiles/validation.dir/depend
