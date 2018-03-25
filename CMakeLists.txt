cmake_minimum_required(VERSION 3.4)

################################
# BLT
################################

if (NOT EXISTS ${PROJECT_SOURCE_DIR}/blt/SetupBLT.cmake)
  message(FATAL_ERROR "\
  The BLT submodule is not present. \
  If in git repository run the following two commands:\n \
  git submodule init\n \
  git submodule update")
endif()

include(${PROJECT_SOURCE_DIR}/blt/SetupBLT.cmake)

add_subdirectory(tpl/RAJA)

set(CUDA_NVCC_FLAGS ${RAJA_NVCC_FLAGS})

message(STATUS "Building PENNANT")
add_subdirectory(pennant)

