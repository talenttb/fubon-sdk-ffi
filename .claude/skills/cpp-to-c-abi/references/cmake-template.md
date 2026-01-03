# CMake Template

Template for `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.16)
project({libname}_wrapper VERSION 1.0.0 LANGUAGES CXX C)

# ============================================================================
# Configuration
# ============================================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build shared library by default
option(BUILD_SHARED_LIBS "Build shared library" ON)
option(BUILD_TESTS "Build tests" ON)

# ============================================================================
# Platform Detection
# ============================================================================

if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    set(CMAKE_INSTALL_RPATH "@loader_path")
elseif(UNIX)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

# ============================================================================
# Find Original Library
# ============================================================================

# Option 1: Find via pkg-config
# find_package(PkgConfig REQUIRED)
# pkg_check_modules({LIBNAME} REQUIRED {original-lib})

# Option 2: Find via CMake find_package
# find_package({OriginalLib} REQUIRED)

# Option 3: Manual specification
# set({LIBNAME}_INCLUDE_DIRS "/path/to/include")
# set({LIBNAME}_LIBRARIES "/path/to/lib{name}.dylib")

# ============================================================================
# Wrapper Library
# ============================================================================

add_library({libname}_wrapper
    src/{libname}_wrapper.cpp
)

target_include_directories({libname}_wrapper
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        # ${{{LIBNAME}_INCLUDE_DIRS}}  # Uncomment when using original library
)

target_link_libraries({libname}_wrapper
    PRIVATE
        # ${{{LIBNAME}_LIBRARIES}}  # Uncomment when using original library
)

# Set library properties
set_target_properties({libname}_wrapper PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/{libname}_wrapper.h
)

# Compiler warnings
target_compile_options({libname}_wrapper PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -Wpedantic>
)

# ============================================================================
# Tests
# ============================================================================

if(BUILD_TESTS)
    # Fetch Catch2
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.0
    )
    FetchContent_MakeAvailable(Catch2)
    
    # Test executable
    add_executable(test_{libname}_wrapper
        test/test_{libname}_wrapper.cpp
    )
    
    target_link_libraries(test_{libname}_wrapper
        PRIVATE
            {libname}_wrapper
            Catch2::Catch2WithMain
    )
    
    # Enable CTest
    enable_testing()
    include(Catch)
    catch_discover_tests(test_{libname}_wrapper)
endif()

# ============================================================================
# Installation
# ============================================================================

include(GNUInstallDirs)

install(TARGETS {libname}_wrapper
    EXPORT {libname}_wrapperTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ============================================================================
# Package Config
# ============================================================================

install(EXPORT {libname}_wrapperTargets
    FILE {libname}_wrapperTargets.cmake
    NAMESPACE {libname}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{libname}_wrapper
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/{libname}_wrapperConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/{libname}_wrapperConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/{libname}_wrapperConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{libname}_wrapper
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/{libname}_wrapperConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/{libname}_wrapperConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{libname}_wrapper
)
```

## Build Commands

```bash
# Configure
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build .

# Run tests
ctest --output-on-failure

# Install (optional)
cmake --install . --prefix /usr/local
```

## Platform-Specific Notes

### macOS
- Output: `lib{libname}_wrapper.dylib`
- Uses `@loader_path` for rpath
- Compiler: Apple Clang

### Linux  
- Output: `lib{libname}_wrapper.so`
- Uses `$ORIGIN` for rpath
- Compiler: GCC or Clang

## Linking Original Library

Three common patterns:

### 1. System-installed (pkg-config)
```cmake
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED opencv4)
target_include_directories(... PRIVATE ${OPENCV_INCLUDE_DIRS})
target_link_libraries(... PRIVATE ${OPENCV_LIBRARIES})
```

### 2. CMake find_package
```cmake
find_package(OpenCV REQUIRED)
target_link_libraries(... PRIVATE ${OpenCV_LIBS})
```

### 3. Manual paths
```cmake
set(MYLIB_ROOT "/opt/mylib")
target_include_directories(... PRIVATE ${MYLIB_ROOT}/include)
target_link_libraries(... PRIVATE ${MYLIB_ROOT}/lib/libmylib.dylib)
```
