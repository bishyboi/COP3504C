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
include CMakeFiles/GameState.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GameState.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GameState.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameState.dir/flags.make

CMakeFiles/GameState.dir/src/GameState.cpp.obj: CMakeFiles/GameState.dir/flags.make
CMakeFiles/GameState.dir/src/GameState.cpp.obj: CMakeFiles/GameState.dir/includes_CXX.rsp
CMakeFiles/GameState.dir/src/GameState.cpp.obj: C:/Users/bisho/Documents/UF/Programming\ Fundamentals/COP3504C/Project\ 4/src/GameState.cpp
CMakeFiles/GameState.dir/src/GameState.cpp.obj: CMakeFiles/GameState.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameState.dir/src/GameState.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameState.dir/src/GameState.cpp.obj -MF CMakeFiles\GameState.dir\src\GameState.cpp.obj.d -o CMakeFiles\GameState.dir\src\GameState.cpp.obj -c "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\GameState.cpp"

CMakeFiles/GameState.dir/src/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameState.dir/src/GameState.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\GameState.cpp" > CMakeFiles\GameState.dir\src\GameState.cpp.i

CMakeFiles/GameState.dir/src/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameState.dir/src/GameState.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\src\GameState.cpp" -o CMakeFiles\GameState.dir\src\GameState.cpp.s

# Object files for target GameState
GameState_OBJECTS = \
"CMakeFiles/GameState.dir/src/GameState.cpp.obj"

# External object files for target GameState
GameState_EXTERNAL_OBJECTS =

libGameState.a: CMakeFiles/GameState.dir/src/GameState.cpp.obj
libGameState.a: CMakeFiles/GameState.dir/build.make
libGameState.a: CMakeFiles/GameState.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libGameState.a"
	$(CMAKE_COMMAND) -P CMakeFiles\GameState.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GameState.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameState.dir/build: libGameState.a
.PHONY : CMakeFiles/GameState.dir/build

CMakeFiles/GameState.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GameState.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GameState.dir/clean

CMakeFiles/GameState.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build" "C:\Users\bisho\Documents\UF\Programming Fundamentals\COP3504C\Project 4\build\CMakeFiles\GameState.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GameState.dir/depend

