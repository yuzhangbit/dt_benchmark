cmake_minimum_required(VERSION 2.8.3)

project(dt_benchmark)

add_definitions(-std=c++11)

# benchmark lib need threads
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread -fPIC ${CMAKE_CXX_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


find_package(OpenCV REQUIRED)
find_package(benchmark REQUIRED)
include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${benchmark_INCLUDE_DIRS}
)

# the benchmark excutalbe file
add_executable(dt_benchmark
  src/dt_benchmark.cpp)

target_link_libraries(dt_benchmark
  ${OpenCV_LIBRARIES}
  ${benchmark_LIBRARIES})

add_executable(example
  src/example.cpp)

target_link_libraries(example
  ${OpenCV_LIBRARIES})