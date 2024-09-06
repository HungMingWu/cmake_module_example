cmake_minimum_required(VERSION 3.28)
project(Tutorial)

# Define configuration variables
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(AUTHOR_NAME "HungMing")

configure_file(config.h.in config.h)

include(FetchContent)
add_subdirectory(MathFunctions)
#find_package(MathFunctions REQUIRED)

add_executable(tutorial)

target_sources(tutorial
  PRIVATE
    tutorial.cxx
  PRIVATE
    FILE_SET generate_config
    TYPE HEADERS
    BASE_DIRS ${CMAKE_BINARY_DIR}
    FILES ${CMAKE_BINARY_DIR}/config.h
)

target_link_libraries(tutorial
  PRIVATE
    MathFunctions
)
