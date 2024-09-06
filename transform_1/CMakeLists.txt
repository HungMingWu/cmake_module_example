cmake_minimum_required(VERSION 3.28)
project(Tutorial)

# Define configuration variables
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(AUTHOR_NAME "HungMing")

option(ENABLE_MODULE_BUILD "Enable module build" ON)
configure_file(config.h.in config.h)

include(FetchContent)
add_subdirectory(MathFunctions)
#find_package(MathFunctions)

add_executable(tutorial)

target_compile_definitions(tutorial
  PRIVATE
    $<$<BOOL:${ENABLE_MODULE_BUILD}>:ENABLE_MODULE_BUILD>
)

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
