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
include CMakeFiles/YouBeTheJudge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/YouBeTheJudge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YouBeTheJudge.dir/flags.make

CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o: CMakeFiles/YouBeTheJudge.dir/flags.make
CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o: ../NADC2021/YouBeTheJudge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o -c /Users/jkeane/CLionProjects/CinCity/Jonny/NADC2021/YouBeTheJudge.cpp

CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/CinCity/Jonny/NADC2021/YouBeTheJudge.cpp > CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.i

CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/CinCity/Jonny/NADC2021/YouBeTheJudge.cpp -o CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.s

# Object files for target YouBeTheJudge
YouBeTheJudge_OBJECTS = \
"CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o"

# External object files for target YouBeTheJudge
YouBeTheJudge_EXTERNAL_OBJECTS =

YouBeTheJudge: CMakeFiles/YouBeTheJudge.dir/NADC2021/YouBeTheJudge.cpp.o
YouBeTheJudge: CMakeFiles/YouBeTheJudge.dir/build.make
YouBeTheJudge: CMakeFiles/YouBeTheJudge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable YouBeTheJudge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YouBeTheJudge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YouBeTheJudge.dir/build: YouBeTheJudge

.PHONY : CMakeFiles/YouBeTheJudge.dir/build

CMakeFiles/YouBeTheJudge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YouBeTheJudge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YouBeTheJudge.dir/clean

CMakeFiles/YouBeTheJudge.dir/depend:
	cd /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles/YouBeTheJudge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YouBeTheJudge.dir/depend

