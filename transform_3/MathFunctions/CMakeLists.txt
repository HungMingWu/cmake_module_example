add_library(MathFunctions)

if (ENABLE_MODULE_BUILD)
target_sources(MathFunctions
  PUBLIC
    FILE_SET export_headers
    TYPE HEADERS
    BASE_DIRS include/
    FILES
      include/MathFunctions.h
      include/mysqrt.h
  PUBLIC
    FILE_SET primary_interface
    TYPE CXX_MODULES
    FILES
      MathFunctions.cppm
  PRIVATE
    src/MathFunctions.cxx
    src/mysqrt.cxx
)
else()
target_sources(MathFunctions
  PUBLIC
    FILE_SET export_headers
    TYPE HEADERS
    BASE_DIRS include/
    FILES
      include/MathFunctions.h
  PRIVATE
    include/mysqrt.h
    src/MathFunctions.cxx
    src/mysqrt.cxx
)
endif()

target_compile_features(MathFunctions
  PUBLIC
    cxx_std_20
)

target_compile_definitions(MathFunctions
  PRIVATE
    $<$<BOOL:${ENABLE_MODULE_BUILD}>:IN_MODULE_INTERFACE>
)

target_link_libraries(MathFunctions
  PRIVATE
    m
)

if (ENABLE_MODULE_BUILD)
install(TARGETS MathFunctions
  EXPORT MathFunctionsTargets
  ARCHIVE
  FILE_SET export_headers
  FILE_SET primary_interface
    DESTINATION lib/cmake/MathFunctions/src
)
else()
install(TARGETS MathFunctions
  EXPORT MathFunctionsTargets
  ARCHIVE
  FILE_SET export_headers
)
endif()

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
