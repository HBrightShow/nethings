# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/hml/nethings

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hml/nethings/build

# Include any dependencies generated for this target.
include core/CMakeFiles/core.dir/depend.make

# Include the progress variables for this target.
include core/CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/core.dir/flags.make

core/CMakeFiles/core.dir/nethings.cpp.o: core/CMakeFiles/core.dir/flags.make
core/CMakeFiles/core.dir/nethings.cpp.o: ../core/nethings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hml/nethings/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/CMakeFiles/core.dir/nethings.cpp.o"
	cd /home/hml/nethings/build/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/nethings.cpp.o -c /home/hml/nethings/core/nethings.cpp

core/CMakeFiles/core.dir/nethings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/nethings.cpp.i"
	cd /home/hml/nethings/build/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hml/nethings/core/nethings.cpp > CMakeFiles/core.dir/nethings.cpp.i

core/CMakeFiles/core.dir/nethings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/nethings.cpp.s"
	cd /home/hml/nethings/build/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hml/nethings/core/nethings.cpp -o CMakeFiles/core.dir/nethings.cpp.s

core/CMakeFiles/core.dir/nethings.cpp.o.requires:

.PHONY : core/CMakeFiles/core.dir/nethings.cpp.o.requires

core/CMakeFiles/core.dir/nethings.cpp.o.provides: core/CMakeFiles/core.dir/nethings.cpp.o.requires
	$(MAKE) -f core/CMakeFiles/core.dir/build.make core/CMakeFiles/core.dir/nethings.cpp.o.provides.build
.PHONY : core/CMakeFiles/core.dir/nethings.cpp.o.provides

core/CMakeFiles/core.dir/nethings.cpp.o.provides.build: core/CMakeFiles/core.dir/nethings.cpp.o


# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/nethings.cpp.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

core/libcore.a: core/CMakeFiles/core.dir/nethings.cpp.o
core/libcore.a: core/CMakeFiles/core.dir/build.make
core/libcore.a: core/CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hml/nethings/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcore.a"
	cd /home/hml/nethings/build/core && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	cd /home/hml/nethings/build/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/core.dir/build: core/libcore.a

.PHONY : core/CMakeFiles/core.dir/build

core/CMakeFiles/core.dir/requires: core/CMakeFiles/core.dir/nethings.cpp.o.requires

.PHONY : core/CMakeFiles/core.dir/requires

core/CMakeFiles/core.dir/clean:
	cd /home/hml/nethings/build/core && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/core.dir/clean

core/CMakeFiles/core.dir/depend:
	cd /home/hml/nethings/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hml/nethings /home/hml/nethings/core /home/hml/nethings/build /home/hml/nethings/build/core /home/hml/nethings/build/core/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/CMakeFiles/core.dir/depend

