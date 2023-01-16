#ifndef SFC32_HPP
#define SFC32_HPP

#include <cstdint>

namespace rng {

class sfc32 {
public:
  sfc32() noexcept : sfc32{0} {}
  explicit sfc32(uint32_t seed) noexcept;
  uint32_t operator()() noexcept;

private:
  uint32_t a_;
  uint32_t b_;
  uint32_t c_;
  uint32_t counter_;
};

} // namespace rng

#endif
