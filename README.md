# RNG learning

## accuracy test

```bash
./tests/mt19937_test
./tests/sfc32_test
```

## Test Result Undetstanding

```bash
git submodule update --init
# build testU01 library
./scripts/build_testu01.sh
# build project
mkdir build && cd build && cmake .. && make -j4
```

### pracrand

```bash
# run test
./tests/pracrand_test | ./third_party/pracrand/practrand_rng_test stdin32
```

[source](https://pracrand.sourceforge.net/Tests_engines.txt)

- BCFN: 检查长程线性相关性（位计数)
- DC6: 检查短程线性相关性（位计数）
- Gap16: 经典“Gap”测试的变体
- BRank: 二进制矩阵秩测试
- FPF: “浮点频率”测试。这会检查非常短的范围相关性，甚至比 DC6 更短，尤其是那些涉及大量 0 位的相关性。这个测试是对存储原始数据的重叠窗口的整数值的浮点数的二进制格式进行频率测试

### testU01

```bash
# run test
./tests/testu01_test
```
