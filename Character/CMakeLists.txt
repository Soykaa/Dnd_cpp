cmake_minimum_required(VERSION 3.15)
project(DND_CPP)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

if(WINDOWS)
    add_executable(DND_CPP
            src/Character.cpp
            src/CharacterSkills.cpp
            src/main.cpp
            src/Item.cpp
            src/Backpack.cpp
            )
elseif(LINUX)
    add_executable(DND_CPP
            src/Character.cpp
            src/CharacterSkills.cpp
            src/main.cpp
            src/Item.cpp
            src/Backpack.cpp
            )
elseif(MACOSX)
    add_executable(DND_CPP
        src/Character.cpp
        src/CharacterSkills.cpp
        src/main.cpp
        src/Item.cpp
        src/Backpack.cpp
    )
endif()