file(GLOB SRC_FILES *.c)
add_library(rng_c ${SRC_FILES})
target_include_directories(rng_c INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC_FILES *.cpp)
add_library(rng_cpp ${SRC_FILES})
target_include_directories(rng_cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
