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
include CMakeFiles/PunctiliousCruciverbalist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PunctiliousCruciverbalist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PunctiliousCruciverbalist.dir/flags.make

CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o: CMakeFiles/PunctiliousCruciverbalist.dir/flags.make
CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o: ../MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o -c /Users/jkeane/CLionProjects/CinCity/Jonny/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp

CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/CinCity/Jonny/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp > CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.i

CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/CinCity/Jonny/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp -o CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.s

# Object files for target PunctiliousCruciverbalist
PunctiliousCruciverbalist_OBJECTS = \
"CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o"

# External object files for target PunctiliousCruciverbalist
PunctiliousCruciverbalist_EXTERNAL_OBJECTS =

PunctiliousCruciverbalist: CMakeFiles/PunctiliousCruciverbalist.dir/MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp.o
PunctiliousCruciverbalist: CMakeFiles/PunctiliousCruciverbalist.dir/build.make
PunctiliousCruciverbalist: CMakeFiles/PunctiliousCruciverbalist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PunctiliousCruciverbalist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PunctiliousCruciverbalist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PunctiliousCruciverbalist.dir/build: PunctiliousCruciverbalist

.PHONY : CMakeFiles/PunctiliousCruciverbalist.dir/build

CMakeFiles/PunctiliousCruciverbalist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PunctiliousCruciverbalist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PunctiliousCruciverbalist.dir/clean

CMakeFiles/PunctiliousCruciverbalist.dir/depend:
	cd /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug /Users/jkeane/CLionProjects/CinCity/Jonny/cmake-build-debug/CMakeFiles/PunctiliousCruciverbalist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PunctiliousCruciverbalist.dir/depend

