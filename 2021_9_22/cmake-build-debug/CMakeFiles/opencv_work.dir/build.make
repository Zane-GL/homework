# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Zane\2021_9_22

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Zane\2021_9_22\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opencv_work.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_work.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_work.dir/flags.make

CMakeFiles/opencv_work.dir/main.cpp.obj: CMakeFiles/opencv_work.dir/flags.make
CMakeFiles/opencv_work.dir/main.cpp.obj: CMakeFiles/opencv_work.dir/includes_CXX.rsp
CMakeFiles/opencv_work.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Zane\2021_9_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_work.dir/main.cpp.obj"
	D:\Users\Administrator\Desktop\mingw64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_work.dir\main.cpp.obj -c E:\Zane\2021_9_22\main.cpp

CMakeFiles/opencv_work.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_work.dir/main.cpp.i"
	D:\Users\Administrator\Desktop\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Zane\2021_9_22\main.cpp > CMakeFiles\opencv_work.dir\main.cpp.i

CMakeFiles/opencv_work.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_work.dir/main.cpp.s"
	D:\Users\Administrator\Desktop\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Zane\2021_9_22\main.cpp -o CMakeFiles\opencv_work.dir\main.cpp.s

# Object files for target opencv_work
opencv_work_OBJECTS = \
"CMakeFiles/opencv_work.dir/main.cpp.obj"

# External object files for target opencv_work
opencv_work_EXTERNAL_OBJECTS =

../opencv_work.exe: CMakeFiles/opencv_work.dir/main.cpp.obj
../opencv_work.exe: CMakeFiles/opencv_work.dir/build.make
../opencv_work.exe: CMakeFiles/opencv_work.dir/linklibs.rsp
../opencv_work.exe: CMakeFiles/opencv_work.dir/objects1.rsp
../opencv_work.exe: CMakeFiles/opencv_work.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Zane\2021_9_22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\opencv_work.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\opencv_work.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_work.dir/build: ../opencv_work.exe

.PHONY : CMakeFiles/opencv_work.dir/build

CMakeFiles/opencv_work.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\opencv_work.dir\cmake_clean.cmake
.PHONY : CMakeFiles/opencv_work.dir/clean

CMakeFiles/opencv_work.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Zane\2021_9_22 E:\Zane\2021_9_22 E:\Zane\2021_9_22\cmake-build-debug E:\Zane\2021_9_22\cmake-build-debug E:\Zane\2021_9_22\cmake-build-debug\CMakeFiles\opencv_work.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_work.dir/depend

