# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lhy/CLionProjects/ThreadTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lhy/CLionProjects/ThreadTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ThreadTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ThreadTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ThreadTree.dir/flags.make

CMakeFiles/ThreadTree.dir/main.c.o: CMakeFiles/ThreadTree.dir/flags.make
CMakeFiles/ThreadTree.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lhy/CLionProjects/ThreadTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ThreadTree.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ThreadTree.dir/main.c.o   -c /Users/lhy/CLionProjects/ThreadTree/main.c

CMakeFiles/ThreadTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ThreadTree.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lhy/CLionProjects/ThreadTree/main.c > CMakeFiles/ThreadTree.dir/main.c.i

CMakeFiles/ThreadTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ThreadTree.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lhy/CLionProjects/ThreadTree/main.c -o CMakeFiles/ThreadTree.dir/main.c.s

# Object files for target ThreadTree
ThreadTree_OBJECTS = \
"CMakeFiles/ThreadTree.dir/main.c.o"

# External object files for target ThreadTree
ThreadTree_EXTERNAL_OBJECTS =

ThreadTree: CMakeFiles/ThreadTree.dir/main.c.o
ThreadTree: CMakeFiles/ThreadTree.dir/build.make
ThreadTree: CMakeFiles/ThreadTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lhy/CLionProjects/ThreadTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ThreadTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThreadTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ThreadTree.dir/build: ThreadTree

.PHONY : CMakeFiles/ThreadTree.dir/build

CMakeFiles/ThreadTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ThreadTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ThreadTree.dir/clean

CMakeFiles/ThreadTree.dir/depend:
	cd /Users/lhy/CLionProjects/ThreadTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lhy/CLionProjects/ThreadTree /Users/lhy/CLionProjects/ThreadTree /Users/lhy/CLionProjects/ThreadTree/cmake-build-debug /Users/lhy/CLionProjects/ThreadTree/cmake-build-debug /Users/lhy/CLionProjects/ThreadTree/cmake-build-debug/CMakeFiles/ThreadTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ThreadTree.dir/depend

