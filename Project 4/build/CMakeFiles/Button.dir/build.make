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
CMAKE_SOURCE_DIR = "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build"

# Include any dependencies generated for this target.
include CMakeFiles/Button.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Button.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Button.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Button.dir/flags.make

CMakeFiles/Button.dir/src/Button.cpp.obj: CMakeFiles/Button.dir/flags.make
CMakeFiles/Button.dir/src/Button.cpp.obj: CMakeFiles/Button.dir/includes_CXX.rsp
CMakeFiles/Button.dir/src/Button.cpp.obj: C:/Users/bisho/Documents/UF/Programming\ Fundamentals/COP3504C/Project\ 4/src/Button.cpp
CMakeFiles/Button.dir/src/Button.cpp.obj: CMakeFiles/Button.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Button.dir/src/Button.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Button.dir/src/Button.cpp.obj -MF CMakeFiles\Button.dir\src\Button.cpp.obj.d -o CMakeFiles\Button.dir\src\Button.cpp.obj -c "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\Button.cpp"

CMakeFiles/Button.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Button.dir/src/Button.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\Button.cpp" > CMakeFiles\Button.dir\src\Button.cpp.i

CMakeFiles/Button.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Button.dir/src/Button.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\Button.cpp" -o CMakeFiles\Button.dir\src\Button.cpp.s

# Object files for target Button
Button_OBJECTS = \
"CMakeFiles/Button.dir/src/Button.cpp.obj"

# External object files for target Button
Button_EXTERNAL_OBJECTS =

libButton.a: CMakeFiles/Button.dir/src/Button.cpp.obj
libButton.a: CMakeFiles/Button.dir/build.make
libButton.a: CMakeFiles/Button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libButton.a"
	$(CMAKE_COMMAND) -P CMakeFiles\Button.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Button.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Button.dir/build: libButton.a
.PHONY : CMakeFiles/Button.dir/build

CMakeFiles/Button.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Button.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Button.dir/clean

CMakeFiles/Button.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles\Button.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Button.dir/depend

