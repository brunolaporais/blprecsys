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
CMAKE_SOURCE_DIR = /home/blpadmin/git/blprecsys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/blpadmin/git/blprecsys

# Include any dependencies generated for this target.
include lib/CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/lib.dir/flags.make

lib/CMakeFiles/lib.dir/json.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/json.cpp.o: lib/json.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/blpadmin/git/blprecsys/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/CMakeFiles/lib.dir/json.cpp.o"
	cd /home/blpadmin/git/blprecsys/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/json.cpp.o -c /home/blpadmin/git/blprecsys/lib/json.cpp

lib/CMakeFiles/lib.dir/json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/json.cpp.i"
	cd /home/blpadmin/git/blprecsys/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/blpadmin/git/blprecsys/lib/json.cpp > CMakeFiles/lib.dir/json.cpp.i

lib/CMakeFiles/lib.dir/json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/json.cpp.s"
	cd /home/blpadmin/git/blprecsys/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/blpadmin/git/blprecsys/lib/json.cpp -o CMakeFiles/lib.dir/json.cpp.s

lib/CMakeFiles/lib.dir/json.cpp.o.requires:
.PHONY : lib/CMakeFiles/lib.dir/json.cpp.o.requires

lib/CMakeFiles/lib.dir/json.cpp.o.provides: lib/CMakeFiles/lib.dir/json.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/lib.dir/build.make lib/CMakeFiles/lib.dir/json.cpp.o.provides.build
.PHONY : lib/CMakeFiles/lib.dir/json.cpp.o.provides

lib/CMakeFiles/lib.dir/json.cpp.o.provides.build: lib/CMakeFiles/lib.dir/json.cpp.o

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/json.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib/liblib.a: lib/CMakeFiles/lib.dir/json.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/build.make
lib/liblib.a: lib/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library liblib.a"
	cd /home/blpadmin/git/blprecsys/lib && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /home/blpadmin/git/blprecsys/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/lib.dir/build: lib/liblib.a
.PHONY : lib/CMakeFiles/lib.dir/build

lib/CMakeFiles/lib.dir/requires: lib/CMakeFiles/lib.dir/json.cpp.o.requires
.PHONY : lib/CMakeFiles/lib.dir/requires

lib/CMakeFiles/lib.dir/clean:
	cd /home/blpadmin/git/blprecsys/lib && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/lib.dir/clean

lib/CMakeFiles/lib.dir/depend:
	cd /home/blpadmin/git/blprecsys && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/blpadmin/git/blprecsys /home/blpadmin/git/blprecsys/lib /home/blpadmin/git/blprecsys /home/blpadmin/git/blprecsys/lib /home/blpadmin/git/blprecsys/lib/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/lib.dir/depend
