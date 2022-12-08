cmake_minimum_required(VERSION 3.25)
project(minesweeper)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_library(Button src/Button.cpp)
target_link_libraries(Button sfml-graphics sfml-audio)

add_library(GameState src/GameState.cpp)
target_link_libraries(GameState sfml-graphics sfml-audio)

add_library(Tile src/Tile.cpp)
target_link_libraries(Tile sfml-graphics sfml-audio)

add_library(Toolbox src/Toolbox.cpp)
target_link_libraries(Toolbox sfml-graphics sfml-audio)

add_executable (minesweeper src/minesweeper.cpp)
target_link_libraries(minesweeper Button GameState Tile Toolbox sfml-graphics sfml-audio)