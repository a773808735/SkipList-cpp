# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\tiaobiao

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\tiaobiao\build

# Include any dependencies generated for this target.
include CMakeFiles/skiplist.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/skiplist.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/skiplist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/skiplist.dir/flags.make

CMakeFiles/skiplist.dir/main.cpp.obj: CMakeFiles/skiplist.dir/flags.make
CMakeFiles/skiplist.dir/main.cpp.obj: CMakeFiles/skiplist.dir/includes_CXX.rsp
CMakeFiles/skiplist.dir/main.cpp.obj: D:/C++/tiaobiao/main.cpp
CMakeFiles/skiplist.dir/main.cpp.obj: CMakeFiles/skiplist.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C++\tiaobiao\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/skiplist.dir/main.cpp.obj"
	C:\Users\lwx\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/skiplist.dir/main.cpp.obj -MF CMakeFiles\skiplist.dir\main.cpp.obj.d -o CMakeFiles\skiplist.dir\main.cpp.obj -c D:\C++\tiaobiao\main.cpp

CMakeFiles/skiplist.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/skiplist.dir/main.cpp.i"
	C:\Users\lwx\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\tiaobiao\main.cpp > CMakeFiles\skiplist.dir\main.cpp.i

CMakeFiles/skiplist.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/skiplist.dir/main.cpp.s"
	C:\Users\lwx\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\tiaobiao\main.cpp -o CMakeFiles\skiplist.dir\main.cpp.s

# Object files for target skiplist
skiplist_OBJECTS = \
"CMakeFiles/skiplist.dir/main.cpp.obj"

# External object files for target skiplist
skiplist_EXTERNAL_OBJECTS =

skiplist.exe: CMakeFiles/skiplist.dir/main.cpp.obj
skiplist.exe: CMakeFiles/skiplist.dir/build.make
skiplist.exe: libMyLibrary.dll.a
skiplist.exe: CMakeFiles/skiplist.dir/linkLibs.rsp
skiplist.exe: CMakeFiles/skiplist.dir/objects1.rsp
skiplist.exe: CMakeFiles/skiplist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\C++\tiaobiao\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable skiplist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\skiplist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/skiplist.dir/build: skiplist.exe
.PHONY : CMakeFiles/skiplist.dir/build

CMakeFiles/skiplist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\skiplist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/skiplist.dir/clean

CMakeFiles/skiplist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\tiaobiao D:\C++\tiaobiao D:\C++\tiaobiao\build D:\C++\tiaobiao\build D:\C++\tiaobiao\build\CMakeFiles\skiplist.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/skiplist.dir/depend

