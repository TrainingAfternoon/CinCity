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
CMAKE_COMMAND = /opt/clion-2020.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/team/workspace/CinCity/Jonny

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/team/workspace/CinCity/Jonny/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProblemK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProblemK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProblemK.dir/flags.make

CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o: CMakeFiles/ProblemK.dir/flags.make
CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o: ../NCNARegional2020/ProblemK.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/team/workspace/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o -c /home/team/workspace/CinCity/Jonny/NCNARegional2020/ProblemK.cpp

CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/team/workspace/CinCity/Jonny/NCNARegional2020/ProblemK.cpp > CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.i

CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/team/workspace/CinCity/Jonny/NCNARegional2020/ProblemK.cpp -o CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.s

# Object files for target ProblemK
ProblemK_OBJECTS = \
"CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o"

# External object files for target ProblemK
ProblemK_EXTERNAL_OBJECTS =

ProblemK: CMakeFiles/ProblemK.dir/NCNARegional2020/ProblemK.cpp.o
ProblemK: CMakeFiles/ProblemK.dir/build.make
ProblemK: CMakeFiles/ProblemK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/team/workspace/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProblemK"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProblemK.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProblemK.dir/build: ProblemK

.PHONY : CMakeFiles/ProblemK.dir/build

CMakeFiles/ProblemK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProblemK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProblemK.dir/clean

CMakeFiles/ProblemK.dir/depend:
	cd /home/team/workspace/CinCity/Jonny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/team/workspace/CinCity/Jonny /home/team/workspace/CinCity/Jonny /home/team/workspace/CinCity/Jonny/cmake-build-debug /home/team/workspace/CinCity/Jonny/cmake-build-debug /home/team/workspace/CinCity/Jonny/cmake-build-debug/CMakeFiles/ProblemK.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProblemK.dir/depend

