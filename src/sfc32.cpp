#include "sfc32.hpp"
#include <array>
#include <cstdint>

namespace rng {

sfc32::sfc32(uint32_t seed) noexcept : a_(0), b_(0), c_(seed), counter_(1U) {
  uint32_t const INIT_CIRCLE = 12U;
  for (uint32_t i = 0; i < INIT_CIRCLE; i++) { (*this)(); }
}

uint32_t sfc32::operator()() noexcept {
  // good sets include {21,9,3},{15,8,3}; older versions used {25,8,3} which wasn't as good
  uint32_t const BARREL_SHIFT = 21U;
  uint32_t const RSHIFT = 9U;
  uint32_t const LSHIFT = 3U;
  uint32_t const tmp = a_ + b_ + counter_++;
  a_ = b_ ^ (b_ >> RSHIFT);
  b_ = c_ + (c_ << LSHIFT);
  c_ = ((c_ << BARREL_SHIFT) | (c_ >> (32 - BARREL_SHIFT))) + tmp;
  return tmp;
}

} // namespace rng
