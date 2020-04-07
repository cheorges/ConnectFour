cmake_minimum_required(VERSION 3.15)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(ConnectFour main.cpp
        view/viewmanager.cpp
        view/viewmanager.h
        object/field.cpp
        object/field.h
        object/token.h
        object/key.h
        engine/controller/gameengine.cpp
        engine/controller/gameengine.h
        view/view.h
        engine/controller/gamestate.h
        engine/game.cpp
        engine/game.h
        object/character.h
        object/player.h)