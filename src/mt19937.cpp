#include "mt19937.hpp"

namespace rng {

mt19937::mt19937(uint32_t seed) noexcept : p_{n}, x_() {
  x_[0] = seed & kMaxBits;
  for (uint32_t i = 1; i < n; ++i) {
    uint32_t z = x_[i - 1];
    z ^= z >> (w - 2U);
    z *= f;
    z += i;
    x_[i] = z & kMaxBits;
  }
}

void mt19937::twister() noexcept {
  for (uint32_t i = 0; i < n; ++i) {
    uint32_t z = (x_[i] & kUpperBits) | (x_[(i + 1) % n] & kLowerBits);
    x_[i] = x_[(i + m) % n] ^ (z >> 1U);
    x_[i] ^= (z & 0x01U) != 0U ? a : 0;
  }
  p_ = 0;
}

uint32_t mt19937::temper() noexcept {
  if (p_ >= n) { twister(); }
  uint32_t z = x_[p_];
  z ^= (z >> tempering_u) & kMaxBits;
  z ^= (z << tempering_s) & b;
  z ^= (z << tempering_t) & c;
  z ^= (z >> tempering_l);
  p_++;
  return z;
}

} // namespace rng
