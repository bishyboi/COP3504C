# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10"

# Include any dependencies generated for this target.
include CMakeFiles/memer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/memer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/memer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memer.dir/flags.make

CMakeFiles/memer.dir/memer.obj: CMakeFiles/memer.dir/flags.make
CMakeFiles/memer.dir/memer.obj: CMakeFiles/memer.dir/includes_CXX.rsp
CMakeFiles/memer.dir/memer.obj: memer.cpp
CMakeFiles/memer.dir/memer.obj: CMakeFiles/memer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memer.dir/memer.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/memer.dir/memer.obj -MF CMakeFiles\memer.dir\memer.obj.d -o CMakeFiles\memer.dir\memer.obj -c "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\memer.cpp"

CMakeFiles/memer.dir/memer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memer.dir/memer.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\memer.cpp" > CMakeFiles\memer.dir\memer.i

CMakeFiles/memer.dir/memer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memer.dir/memer.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\memer.cpp" -o CMakeFiles\memer.dir\memer.s

# Object files for target memer
memer_OBJECTS = \
"CMakeFiles/memer.dir/memer.obj"

# External object files for target memer
memer_EXTERNAL_OBJECTS =

libmemer.a: CMakeFiles/memer.dir/memer.obj
libmemer.a: CMakeFiles/memer.dir/build.make
libmemer.a: CMakeFiles/memer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmemer.a"
	$(CMAKE_COMMAND) -P CMakeFiles\memer.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\memer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memer.dir/build: libmemer.a
.PHONY : CMakeFiles/memer.dir/build

CMakeFiles/memer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\memer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/memer.dir/clean

CMakeFiles/memer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Lab 10\CMakeFiles\memer.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/memer.dir/depend

