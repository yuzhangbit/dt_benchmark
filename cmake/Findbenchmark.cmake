# Find FCL
#
# This sets the following variables:
# FCL_FOUND
# FCL_INCLUDE_DIRS
# FCL_LIBRARIES
# FCL_DEFINITIONS
# FCL_VERSION

find_package(PkgConfig)

pkg_check_modules(PC_BENCHMARK REQUIRED benchmark>=1.4.0)

set(benchmark_DEFINITIONS ${PC_BENCHMARK_CFLAGS_OTHER})
set(benchmark_INCLUDE_DIRS ${PC_BENCHMARK_INCLUDE_DIRS})
set(benchmark_LIBRARIES ${PC_BENCHMARK_LIBRARIES})
set(benchmark_VERSION ${PC_BENCHMARK_VERSION})
include(FindPackageHandleStandardArgs)
# if all listed variables are TRUE
find_package_handle_standard_args(benchmark DEFAULT_MSG
  benchmark_LIBRARIES benchmark_INCLUDE_DIRS)
mark_as_advanced(benchmark_INCLUDE_DIRS benchmark_LIBRARIES)

if(${benchmark_FOUND})
  message(STATUS "Found benchmark version: " ${benchmark_VERSION} " installed in: " ${PC_BENCHMARK_PREFIX})
else()
  message(SEND_ERROR "Could not find benchmark")
endif()