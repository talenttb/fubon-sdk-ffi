cmake_minimum_required(VERSION 3.17)
project(fubon_c_wrapper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings
)

# Link directories
link_directories(${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings)

# Build C wrapper library
add_library(fubon_c SHARED
    src/fubon_c.cpp
    src/helpers.cpp
    ${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings/fubon.cpp
)

# Link with the Fubon Rust core library
target_link_libraries(fubon_c
    ${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings/libfubon.dylib
)

# Set install rpath for macOS
if(APPLE)
    set_target_properties(fubon_c PROPERTIES
        INSTALL_RPATH "@loader_path;@loader_path/../fubon-cpp-sdk/bindings"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
endif()

# Test program
add_executable(test_sdk test/test_sdk.c)
target_link_libraries(test_sdk fubon_c)

# Set rpath for test executable
if(APPLE)
    set_target_properties(test_sdk PROPERTIES
        INSTALL_RPATH "@loader_path;@loader_path/../fubon-cpp-sdk/bindings"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
endif()

# Installation
install(TARGETS fubon_c DESTINATION lib)
install(FILES include/fubon_c.h DESTINATION include)
