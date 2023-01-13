#include "mt19937.hpp"
#include <_types/_uint32_t.h>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <random>

extern "C" {
#include "mt19937.h"
}

int main() {
  std::mt19937 engine0{12345};
  rng::mt19937 engine1{12345};
  struct mt19937 engine2 {};
  mt19937_init(&engine2, 12345);

  for (uint32_t i = 0; i < UINT16_MAX; ++i) {
    auto v0 = engine0();
    auto v1 = engine1();
    auto v2 = mt19937_generate_random_number(&engine2);
    // std::cout << v0 << "-" << v1 << "-" << v2 << std::endl;
    assert(v0 == v1 && "mt19937_cpp value is not same as std");
    assert(v0 == v2 && "mt19937_c value is not same as std");
  }
  std::cout << "test successfully\n";
}