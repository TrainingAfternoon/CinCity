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
include CMakeFiles/ProblemC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProblemC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProblemC.dir/flags.make

CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o: CMakeFiles/ProblemC.dir/flags.make
CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o: ../NCNARegional2020/ProblemC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o -c /Users/jkeane/CLionProjects/CinCity/Jonny/NCNARegional2020/ProblemC.cpp

CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/CinCity/Jonny/NCNARegional2020/ProblemC.cpp > CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.i

CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/CinCity/Jonny/NCNARegional2020/ProblemC.cpp -o CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.s

# Object files for target ProblemC
ProblemC_OBJECTS = \
"CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o"

# External object files for target ProblemC
ProblemC_EXTERNAL_OBJECTS =

ProblemC: CMakeFiles/ProblemC.dir/NCNARegional2020/ProblemC.cpp.o
ProblemC: CMakeFiles/ProblemC.dir/build.make
ProblemC: CMakeFiles/ProblemC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProblemC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProblemC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProblemC.dir/build: ProblemC

.PHONY : CMakeFiles/ProblemC.dir/build

CMakeFiles/ProblemC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProblemC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProblemC.dir/clean

CMakeFiles/ProblemC.dir/depend:
	cd /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles/ProblemC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProblemC.dir/depend
