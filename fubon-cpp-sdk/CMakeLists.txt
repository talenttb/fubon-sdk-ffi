cmake_minimum_required(VERSION 3.17)
project(FubonCpp)
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/bindings)

# Link directories
link_directories(${CMAKE_SOURCE_DIR}/bindings)

# Build example executable
add_executable(fubon_example 
    ${CMAKE_SOURCE_DIR}/Example/main.cpp
    ${CMAKE_SOURCE_DIR}/bindings/fubon.cpp
    ${CMAKE_SOURCE_DIR}/bindings/pretty_print.cpp
)

# Platform-specific settings
if(WIN32)
  set(DLL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bindings/fubon.dll")
  add_custom_command(TARGET fubon_example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DLL_PATH}" $<TARGET_FILE_DIR:fubon_example>)
  target_link_libraries(fubon_example fubon ws2_32)
elseif(APPLE)
  target_link_libraries(fubon_example fubon)
else()
  target_link_libraries(fubon_example fubon pthread)
endif()

