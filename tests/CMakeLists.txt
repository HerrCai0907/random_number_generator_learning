add_executable(pracrand_test pracrand_test.cpp)
target_link_libraries(pracrand_test PUBLIC rng_c rng_cpp)

add_executable(testu01_test testu01_test.cpp)
target_link_libraries(testu01_test PUBLIC rng_c rng_cpp
    ${CMAKE_SOURCE_DIR}/build_testu01/lib/libtestu01.a
    ${CMAKE_SOURCE_DIR}/build_testu01/lib/libprobdist.a
    ${CMAKE_SOURCE_DIR}/build_testu01/lib/libmylib.a
)
target_include_directories(testu01_test PRIVATE ${CMAKE_SOURCE_DIR}/build_testu01/include)

add_executable(mt19937_test test_mt19937.cpp)
target_link_libraries(mt19937_test PUBLIC rng_c rng_cpp)

add_executable(sfc32_test test_sfc32.cpp)
target_link_libraries(sfc32_test PUBLIC rng_c rng_cpp)
