#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <random>

int main() {
  std::minstd_rand engine{std::random_device{}()};
  for (;;) {
    auto v0 = engine();
    fwrite(static_cast<void *>(&v0), sizeof(v0), 1, stdout);
  }
}