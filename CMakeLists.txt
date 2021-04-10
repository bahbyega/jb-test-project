cmake_minimum_required(VERSION 3.1.0)
project(JB2021-test-task)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++17")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(SOURCES 
    src/mainwindow.cpp 
    src/main.cpp
)

set(MOC_HEADERS
    src/mainwindow.hpp
)

set(UI src/mainwindow.ui)

QT5_WRAP_UI(UI_HEADERS ${UI})
QT5_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${MOC_SRCS}
    ${UI_HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)