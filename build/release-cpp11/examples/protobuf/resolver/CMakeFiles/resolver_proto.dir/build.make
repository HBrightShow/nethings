# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/hml/xiaozhong/code/nethings/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hml/xiaozhong/code/nethings/build/release-cpp11

# Include any dependencies generated for this target.
include examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/depend.make

# Include the progress variables for this target.
include examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/progress.make

# Include the compile flags for this target's objects.
include examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/flags.make

examples/protobuf/resolver/resolver.pb.cc: /home/hml/xiaozhong/code/nethings/muduo/examples/protobuf/resolver/resolver.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hml/xiaozhong/code/nethings/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating resolver.pb.cc, resolver.pb.h"
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && protoc --cpp_out . /home/hml/xiaozhong/code/nethings/muduo/examples/protobuf/resolver/resolver.proto -I/home/hml/xiaozhong/code/nethings/muduo/examples/protobuf/resolver

examples/protobuf/resolver/resolver.pb.h: examples/protobuf/resolver/resolver.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate examples/protobuf/resolver/resolver.pb.h

examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.o: examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/flags.make
examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.o: examples/protobuf/resolver/resolver.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hml/xiaozhong/code/nethings/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.o"
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-conversion -Wno-shadow -o CMakeFiles/resolver_proto.dir/resolver.pb.cc.o -c /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver/resolver.pb.cc

examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/resolver_proto.dir/resolver.pb.cc.i"
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-conversion -Wno-shadow -E /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver/resolver.pb.cc > CMakeFiles/resolver_proto.dir/resolver.pb.cc.i

examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/resolver_proto.dir/resolver.pb.cc.s"
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-conversion -Wno-shadow -S /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver/resolver.pb.cc -o CMakeFiles/resolver_proto.dir/resolver.pb.cc.s

# Object files for target resolver_proto
resolver_proto_OBJECTS = \
"CMakeFiles/resolver_proto.dir/resolver.pb.cc.o"

# External object files for target resolver_proto
resolver_proto_EXTERNAL_OBJECTS =

lib/libresolver_proto.a: examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/resolver.pb.cc.o
lib/libresolver_proto.a: examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/build.make
lib/libresolver_proto.a: examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hml/xiaozhong/code/nethings/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../lib/libresolver_proto.a"
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && $(CMAKE_COMMAND) -P CMakeFiles/resolver_proto.dir/cmake_clean_target.cmake
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/resolver_proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/build: lib/libresolver_proto.a

.PHONY : examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/build

examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/clean:
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver && $(CMAKE_COMMAND) -P CMakeFiles/resolver_proto.dir/cmake_clean.cmake
.PHONY : examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/clean

examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/depend: examples/protobuf/resolver/resolver.pb.cc
examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/depend: examples/protobuf/resolver/resolver.pb.h
	cd /home/hml/xiaozhong/code/nethings/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hml/xiaozhong/code/nethings/muduo /home/hml/xiaozhong/code/nethings/muduo/examples/protobuf/resolver /home/hml/xiaozhong/code/nethings/build/release-cpp11 /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver /home/hml/xiaozhong/code/nethings/build/release-cpp11/examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/protobuf/resolver/CMakeFiles/resolver_proto.dir/depend

