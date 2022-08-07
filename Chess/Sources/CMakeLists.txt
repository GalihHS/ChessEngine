cmake_minimum_required(VERSION 3.0)
project(ChessEngine CXX)


set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

set (HEADER_FILES inc/Coordinates.hpp inc/Piece.hpp inc/Board.hpp)

set (SOURCE_FILES src/Coordinates.cpp src/Piece.cpp src/Board.cpp 
    src/main.cpp)


add_executable(engine ${HEADER_FILES} ${SOURCE_FILES})
