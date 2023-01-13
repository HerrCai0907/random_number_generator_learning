#include <array>
#include <cstdint>

namespace rng {

class mt19937 {
  static constexpr std::size_t w = 32U;
  static constexpr std::size_t n = 624U;
  static constexpr std::size_t m = 397U;
  static constexpr uint32_t a = 0x9908b0dfUL;
  static constexpr uint32_t b = 0x9d2c5680UL;
  static constexpr uint32_t c = 0xefc60000UL;
  static constexpr uint32_t f = 1812433253UL;

  static constexpr std::size_t tempering_u = 11U;
  static constexpr std::size_t tempering_s = 7U;
  static constexpr std::size_t tempering_t = 15U;
  static constexpr std::size_t tempering_l = 18U;

  static constexpr uint32_t kMaxBits = 0xffffffffUL;
  static constexpr uint32_t kUpperBits = 0x80000000UL;
  static constexpr uint32_t kLowerBits = 0x7fffffffUL;

public:
  mt19937() noexcept : mt19937{0} {}
  explicit mt19937(uint32_t seed) noexcept;
  uint32_t operator()() noexcept { return temper(); }

private:
  void twister() noexcept;
  uint32_t temper() noexcept;

private:
  std::array<uint32_t, n> x_;
  std::size_t p_;
};

} // namespace rng
