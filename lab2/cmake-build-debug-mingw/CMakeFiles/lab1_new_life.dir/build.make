# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\textbooks\labs\asd\practice\lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/lab1_new_life.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab1_new_life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1_new_life.dir/flags.make

CMakeFiles/lab1_new_life.dir/main.cpp.obj: CMakeFiles/lab1_new_life.dir/flags.make
CMakeFiles/lab1_new_life.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab1_new_life.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab1_new_life.dir\main.cpp.obj -c C:\textbooks\labs\asd\practice\lab2\main.cpp

CMakeFiles/lab1_new_life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_new_life.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\textbooks\labs\asd\practice\lab2\main.cpp > CMakeFiles\lab1_new_life.dir\main.cpp.i

CMakeFiles/lab1_new_life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_new_life.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\textbooks\labs\asd\practice\lab2\main.cpp -o CMakeFiles\lab1_new_life.dir\main.cpp.s

# Object files for target lab1_new_life
lab1_new_life_OBJECTS = \
"CMakeFiles/lab1_new_life.dir/main.cpp.obj"

# External object files for target lab1_new_life
lab1_new_life_EXTERNAL_OBJECTS =

lab1_new_life.exe: CMakeFiles/lab1_new_life.dir/main.cpp.obj
lab1_new_life.exe: CMakeFiles/lab1_new_life.dir/build.make
lab1_new_life.exe: CMakeFiles/lab1_new_life.dir/linklibs.rsp
lab1_new_life.exe: CMakeFiles/lab1_new_life.dir/objects1.rsp
lab1_new_life.exe: CMakeFiles/lab1_new_life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab1_new_life.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab1_new_life.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1_new_life.dir/build: lab1_new_life.exe
.PHONY : CMakeFiles/lab1_new_life.dir/build

CMakeFiles/lab1_new_life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab1_new_life.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab1_new_life.dir/clean

CMakeFiles/lab1_new_life.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\textbooks\labs\asd\practice\lab2 C:\textbooks\labs\asd\practice\lab2 C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw C:\textbooks\labs\asd\practice\lab2\cmake-build-debug-mingw\CMakeFiles\lab1_new_life.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab1_new_life.dir/depend

