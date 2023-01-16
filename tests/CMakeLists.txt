add_executable(rng_test test.cpp)
target_link_libraries(rng_test PUBLIC rng_c rng_cpp)

add_executable(mt19937_test test_mt19937.cpp)
target_link_libraries(mt19937_test PUBLIC rng_c rng_cpp)

add_executable(sfc32_test test_sfc32.cpp)
target_link_libraries(sfc32_test PUBLIC rng_c rng_cpp)

