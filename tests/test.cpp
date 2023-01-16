#include <random>

extern "C" {
#include "sfc32.h"
}

int main() {
  auto seed = std::random_device{}();
  struct sfc32 sfc {};
  sfc32_init(&sfc, seed);
  for (;;) {
    auto v0 = sfc32_generate_random_number(&sfc);
    fwrite(static_cast<void *>(&v0), sizeof(v0), 1, stdout);
  }
}