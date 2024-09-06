add_library(MathFunctions)
target_sources(MathFunctions
  PUBLIC
    FILE_SET export_headers
    TYPE HEADERS
    BASE_DIRS include/
    FILES include/MathFunctions.h
  PRIVATE
    src/MathFunctions.cxx 
    src/mysqrt.h
    src/mysqrt.cxx
)

target_link_libraries(MathFunctions
  PRIVATE
    m
)

install(TARGETS MathFunctions
  EXPORT MathFunctionsTargets
  ARCHIVE
  FILE_SET export_headers
)

install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)

include(CMakePackageConfigHelpers)
# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/MathFunctions"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  DESTINATION lib/cmake/MathFunctions
)
