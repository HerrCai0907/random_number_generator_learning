#include "sfc32.h"
#include <stdint.h>

void sfc32_init(struct sfc32 *sfc, uint32_t const seed) {
  uint32_t const INIT_CIRCLE = 12U;
  sfc->a = 0; // a gets mixed in the slowest
  sfc->b = 0;
  sfc->c = seed;
  sfc->counter = 1;
  for (uint32_t i = 0; i < INIT_CIRCLE; i++) { sfc32_generate_random_number(sfc); }
}

uint32_t sfc32_generate_random_number(struct sfc32 *sfc) {
  // good sets include {21,9,3},{15,8,3}; older versions used {25,8,3} which wasn't as good
  uint32_t const BARREL_SHIFT = 21U;
  uint32_t const RSHIFT = 9U;
  uint32_t const LSHIFT = 3U;
  uint32_t const tmp = sfc->a + sfc->b + sfc->counter++;
  sfc->a = sfc->b ^ (sfc->b >> RSHIFT);
  sfc->b = sfc->c + (sfc->c << LSHIFT);
  sfc->c = ((sfc->c << BARREL_SHIFT) | (sfc->c >> (32 - BARREL_SHIFT))) + tmp;
  return tmp;
}
