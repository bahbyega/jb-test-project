cmake_minimum_required(VERSION 3.1.0)
project(JB2021-test-task)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++17")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(LIBS Core Gui Widgets Concurrent)
set(QT_LIBS Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Concurrent)

find_package(Qt5 COMPONENTS ${LIBS} REQUIRED)

set(SOURCES 
    src/mainwindow.cpp 
    src/main.cpp
    src/searcher.cpp
)

set(MOC_HEADERS
    src/mainwindow.hpp
    src/searcher.hpp
)

set(UI src/mainwindow.ui)

QT5_WRAP_UI(UI_HEADERS ${UI})
QT5_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${MOC_SRCS}
    ${UI_HEADERS}
)

target_link_libraries(${PROJECT_NAME} ${QT_LIBS})

if (WIN32)
    set(DEBUG_SUFFIX d)
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        set(DEBUG_SUFFIX)
    endif ()

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()

    foreach (LIB ${LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (LIB)
endif ()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_CURRENT_SOURCE_DIR}/dict/words.txt"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/")