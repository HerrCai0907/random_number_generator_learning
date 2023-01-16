#ifndef SFC32_H
#define SFC32_H

#include <stdint.h>

struct sfc32 {
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t counter;
};

void sfc32_init(struct sfc32 *sfc, uint32_t const seed);
uint32_t sfc32_generate_random_number(struct sfc32 *sfc);

#endif
