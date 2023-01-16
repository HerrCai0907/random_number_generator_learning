#ifndef MT19937_H
#define MT19937_H

#include <stddef.h>
#include <stdint.h>

#define mt19937_n 624U

struct mt19937 {
  uint32_t x_[mt19937_n];
  size_t p_;
};

void mt19937_init(struct mt19937 *mt, uint32_t seed);
uint32_t mt19937_generate_random_number(struct mt19937 *mt);

#endif
