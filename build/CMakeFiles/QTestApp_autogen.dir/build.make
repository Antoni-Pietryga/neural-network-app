# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antoni/Pulpit/qtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antoni/Pulpit/qtest/build

# Utility rule file for QTestApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/QTestApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QTestApp_autogen.dir/progress.make

CMakeFiles/QTestApp_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/antoni/Pulpit/qtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target QTestApp"
	/usr/local/bin/cmake -E cmake_autogen /home/antoni/Pulpit/qtest/build/CMakeFiles/QTestApp_autogen.dir/AutogenInfo.json ""

QTestApp_autogen: CMakeFiles/QTestApp_autogen
QTestApp_autogen: CMakeFiles/QTestApp_autogen.dir/build.make
.PHONY : QTestApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/QTestApp_autogen.dir/build: QTestApp_autogen
.PHONY : CMakeFiles/QTestApp_autogen.dir/build

CMakeFiles/QTestApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QTestApp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QTestApp_autogen.dir/clean

CMakeFiles/QTestApp_autogen.dir/depend:
	cd /home/antoni/Pulpit/qtest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoni/Pulpit/qtest /home/antoni/Pulpit/qtest /home/antoni/Pulpit/qtest/build /home/antoni/Pulpit/qtest/build /home/antoni/Pulpit/qtest/build/CMakeFiles/QTestApp_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QTestApp_autogen.dir/depend

