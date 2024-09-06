add_library(MathFunctions)
target_sources(MathFunctions
  PUBLIC
    FILE_SET primary_interface
    TYPE CXX_MODULES
    FILES
      MathFunctions.cppm
      src/mysqrt.cppm
  PRIVATE
    src/MathFunctions.cxx
)

target_compile_features(MathFunctions
  PUBLIC
    cxx_std_20
)

target_link_libraries(MathFunctions
  PRIVATE
    m
)

install(TARGETS MathFunctions
  EXPORT MathFunctionsTargets
  ARCHIVE
  FILE_SET primary_interface
    DESTINATION lib/cmake/MathFunctions/src
)

install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
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
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  DESTINATION lib/cmake/MathFunctions
)
