# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task5.dir/flags.make

CMakeFiles/Task5.dir/main.c.obj: CMakeFiles/Task5.dir/flags.make
CMakeFiles/Task5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task5.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Task5.dir\main.c.obj   -c "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\main.c"

CMakeFiles/Task5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task5.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\main.c" > CMakeFiles\Task5.dir\main.c.i

CMakeFiles/Task5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task5.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\main.c" -o CMakeFiles\Task5.dir\main.c.s

# Object files for target Task5
Task5_OBJECTS = \
"CMakeFiles/Task5.dir/main.c.obj"

# External object files for target Task5
Task5_EXTERNAL_OBJECTS =

Task5.exe: CMakeFiles/Task5.dir/main.c.obj
Task5.exe: CMakeFiles/Task5.dir/build.make
Task5.exe: CMakeFiles/Task5.dir/linklibs.rsp
Task5.exe: CMakeFiles/Task5.dir/objects1.rsp
Task5.exe: CMakeFiles/Task5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Task5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task5.dir/build: Task5.exe

.PHONY : CMakeFiles/Task5.dir/build

CMakeFiles/Task5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task5.dir/clean

CMakeFiles/Task5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5" "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5" "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug" "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug" "C:\Users\Dimitar Kitanovski\Desktop\Documents\Faculty\Summer Semester\Object Oriented Programming\Auditory Exercises\Auditory Exercise 1\Task5\cmake-build-debug\CMakeFiles\Task5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task5.dir/depend

