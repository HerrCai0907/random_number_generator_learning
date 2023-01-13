file(GLOB SRC_FILES src/*.cpp src/RNGs/*.cpp src/RNGs/other/*.cpp)

add_library(practrand ${SRC_FILES})
target_include_directories(practrand PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(practrand_rng_test tools/RNG_test.cpp)
target_link_libraries(practrand_rng_test PUBLIC practrand)
