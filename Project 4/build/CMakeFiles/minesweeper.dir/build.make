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
include CMakeFiles/minesweeper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minesweeper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minesweeper.dir/flags.make

CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj: CMakeFiles/minesweeper.dir/includes_CXX.rsp
CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj: C:/Users/bisho/Documents/UF/Programming\ Fundamentals/COP3504C/Project\ 4/src/minesweeper.cpp
CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj: CMakeFiles/minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj -MF CMakeFiles\minesweeper.dir\src\minesweeper.cpp.obj.d -o CMakeFiles\minesweeper.dir\src\minesweeper.cpp.obj -c "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\minesweeper.cpp"

CMakeFiles/minesweeper.dir/src/minesweeper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/src/minesweeper.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\minesweeper.cpp" > CMakeFiles\minesweeper.dir\src\minesweeper.cpp.i

CMakeFiles/minesweeper.dir/src/minesweeper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/src/minesweeper.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\minesweeper.cpp" -o CMakeFiles\minesweeper.dir\src\minesweeper.cpp.s

# Object files for target minesweeper
minesweeper_OBJECTS = \
"CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj"

# External object files for target minesweeper
minesweeper_EXTERNAL_OBJECTS =

minesweeper.exe: CMakeFiles/minesweeper.dir/src/minesweeper.cpp.obj
minesweeper.exe: CMakeFiles/minesweeper.dir/build.make
minesweeper.exe: libButton.a
minesweeper.exe: libGameState.a
minesweeper.exe: libTile.a
minesweeper.exe: libToolbox.a
minesweeper.exe: C:/Libraries/SFML-2.5.1/lib/libsfml-graphics-d.a
minesweeper.exe: C:/Libraries/SFML-2.5.1/lib/libsfml-audio-d.a
minesweeper.exe: C:/Libraries/SFML-2.5.1/lib/libsfml-window-d.a
minesweeper.exe: C:/Libraries/SFML-2.5.1/lib/libsfml-system-d.a
minesweeper.exe: CMakeFiles/minesweeper.dir/linkLibs.rsp
minesweeper.exe: CMakeFiles/minesweeper.dir/objects1
minesweeper.exe: CMakeFiles/minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minesweeper.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\minesweeper.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minesweeper.dir/build: minesweeper.exe
.PHONY : CMakeFiles/minesweeper.dir/build

CMakeFiles/minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\minesweeper.dir\cmake_clean.cmake
.PHONY : CMakeFiles/minesweeper.dir/clean

CMakeFiles/minesweeper.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles\minesweeper.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/minesweeper.dir/depend

