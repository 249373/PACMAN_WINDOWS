cmake_minimum_required(VERSION 3.14)
project(PacMan)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(PacMan main.cpp
        Engine.cpp
        Engine.h
        Data.cpp
        Data.h
        View.cpp
        View.h
        PacMan.cpp
        PacMan.h
        Event.cpp
        Event.h
        Ghost.cpp
        Ghost.h
        RandomGhost.cpp
        RandomGhost.h
        BlinkyGhost.cpp
        BlinkyGhost.h
        PinkyGhost.cpp PinkyGhost.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR}${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})
    target_link_libraries(PacMan ${SFML_LIBRARIES}${SFML_DEPENDENCIES} ${PROJECT_SOURCE_DIR} )
    set(SOURCE_FILES Pac1.png)
endif()