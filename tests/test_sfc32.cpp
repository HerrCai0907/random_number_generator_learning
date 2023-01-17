#include "sfc32.hpp"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <random>

extern "C" {
#include "sfc32.h"
}

int main() {
  rng::sfc32 engine1{12345};
  struct sfc32 engine2 {};
  sfc32_init(&engine2, 12345);

  for (uint32_t i = 0; i < UINT16_MAX; ++i) {
    auto v1 = engine1();
    auto v2 = sfc32_generate_random_number(&engine2);
    // std::cout << v0 << "-" << v1 << "-" << v2 << std::endl;
    assert(v1 == v2 && "mt19937_c value is not same as std");
  }
  std::cout << "test successfully\n";
}