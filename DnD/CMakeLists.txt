cmake_minimum_required(VERSION 3.10)
project(DnD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(HEADERS 
			include/board.h
			include/character.h
			include/character_skills.h
			include/dice.h
			include/encounter.h
			include/game_board.h
			include/game_menu.h
			include/gift.h
			include/message.h
			include/obstacle.h
			include/player.h
			include/ui_game_menu.h
			include/utility.h
			)


set(SOURCES
			src/board.cpp
			src/character.cpp
			src/character_skills.cpp
			src/dice.cpp
			src/encounter.cpp
			src/game_board.cpp
			src/game_menu.cpp
			src/gift.cpp
			src/main.cpp 
			src/message.cpp
			src/obstacle.cpp
			src/player.cpp
			)

add_executable(DnD ${HEADERS} ${SOURCES})
target_link_libraries(DnD Qt5::Widgets)