# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jkeane/CLionProjects/CinCity/Jonny

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Jonny.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Jonny.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Jonny.dir/flags.make

CMakeFiles/Jonny.dir/helloWorld.cpp.o: CMakeFiles/Jonny.dir/flags.make
CMakeFiles/Jonny.dir/helloWorld.cpp.o: ../helloWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Jonny.dir/helloWorld.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jonny.dir/helloWorld.cpp.o -c /Users/jkeane/CLionProjects/CinCity/Jonny/helloWorld.cpp

CMakeFiles/Jonny.dir/helloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jonny.dir/helloWorld.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/CinCity/Jonny/helloWorld.cpp > CMakeFiles/Jonny.dir/helloWorld.cpp.i

CMakeFiles/Jonny.dir/helloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jonny.dir/helloWorld.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/CinCity/Jonny/helloWorld.cpp -o CMakeFiles/Jonny.dir/helloWorld.cpp.s

# Object files for target Jonny
Jonny_OBJECTS = \
"CMakeFiles/Jonny.dir/helloWorld.cpp.o"

# External object files for target Jonny
Jonny_EXTERNAL_OBJECTS =

Jonny: CMakeFiles/Jonny.dir/helloWorld.cpp.o
Jonny: CMakeFiles/Jonny.dir/build.make
Jonny: CMakeFiles/Jonny.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Jonny"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Jonny.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Jonny.dir/build: Jonny

.PHONY : CMakeFiles/Jonny.dir/build

CMakeFiles/Jonny.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Jonny.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Jonny.dir/clean

CMakeFiles/Jonny.dir/depend:
	cd /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles/Jonny.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Jonny.dir/depend

