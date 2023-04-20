cmake_minimum_required(VERSION 3.0.0)

IF(NOT CMAKE_CXX_STANDARD EQUAL 20)
    MESSAGE(FATAL_ERROR "C++20 is required to build this lib")
ENDIF()

add_library(cpp-logger
    ConsoleColor.hpp
        Includes/Logger.hpp
    Logger.tpp
    Logger.cpp
)

SET(TESTING_LOGGER OFF)

IF(${TESTING_LOGGER})
    add_subdirectory(tests)
ENDIF()