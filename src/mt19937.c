#include "mt19937.h"

#define w 32U
#define m 397U
#define a 0x9908b0dfUL
#define b 0x9d2c5680UL
#define c 0xefc60000UL
#define f 1812433253UL

#define tempering_u 11U
#define tempering_s 7U
#define tempering_t 15U
#define tempering_l 18U

#define kMaxBits 0xffffffffUL
#define kUpperBits 0x80000000UL
#define kLowerBits 0x7fffffffUL

void mt19937_init(struct mt19937 *mt, uint32_t seed) {
  mt->x_[0] = seed & kMaxBits;
  mt->p_ = mt19937_n;
  for (uint32_t i = 1; i < mt19937_n; ++i) {
    uint32_t z = mt->x_[i - 1];
    z ^= z >> (w - 2U);
    z *= f;
    z += i;
    mt->x_[i] = z & kMaxBits;
  }
}

static void mt19937_twister(struct mt19937 *mt) {
  for (uint32_t i = 0; i < mt19937_n; ++i) {
    uint32_t z = (mt->x_[i] & kUpperBits) | (mt->x_[(i + 1) % mt19937_n] & kLowerBits);
    mt->x_[i] = mt->x_[(i + m) % mt19937_n] ^ (z >> 1U);
    mt->x_[i] ^= (z & 0x01U) ? a : 0;
  }
  mt->p_ = 0;
}
uint32_t mt19937_generate_random_number(struct mt19937 *mt) {
  if (mt->p_ >= mt19937_n) { mt19937_twister(mt); }
  uint32_t z = mt->x_[mt->p_];
  z ^= (z >> tempering_u) & kMaxBits;
  z ^= (z << tempering_s) & b;
  z ^= (z << tempering_t) & c;
  z ^= (z >> tempering_l);
  mt->p_++;
  return z;
}