#include "sfc32.hpp"
#include <random>
#include <string>

extern "C" {
#include "bbattery.h"
}

uint32_t sfc32() {
  static rng::sfc32 sfc32{std::random_device{}()};
  return sfc32();
}

int main() {
  unif01_Gen *gen = unif01_CreateExternGenBits(std::string{"sfc32"}.data(), sfc32);
  bbattery_SmallCrush(gen);
  bbattery_BigCrush(gen);
  unif01_DeleteExternGenBits(gen);
  return 0;
}