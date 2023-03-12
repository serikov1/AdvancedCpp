This is home task  "Aligned Storage"

1) You can check my realization over there :point_right: [Aligned Storage](https://github.com/serikov1/AdvancedCpp/blob/main/firstLesson/alignedStorage/library.h)

2) Tests over there :point_right: [gtest](https://github.com/serikov1/AdvancedCpp/blob/main/firstLesson/testStorage/main.cpp)

> Interesting notes :point_down:
- tests do not always pass (sometimes all tests were successfully), there is an error in the size
```
Expected equality of these values:
  std::find(dummy, dummy + sizeof(dummy), mem_dump[i])
    Which is: 0x7ffd8c79b9dc
  dummy + sizeof(dummy)
    Which is: 0x7ffd8c79b9e1
```
- I tryed check it with with `class` which we considered at lesson and with `class` which was proposed me by ChatGPT(!) :rofl:, this problem was both there and there. Maybe I wrote tests incorrectly. UPD: this problem only with tests for `std::string`  and `std::vector<int>`

- smt about `sizeof(ProbeObject)` and why `sizeof(ProbeObject)` is not equal to `sizeof(uint8_t) + sizeof(uint64_t) + sizeof(uint32_t) == 13 bytes`.
The compiler aligns the data in memory itself, so the size of the object will depend on the data types, and even their order of declaration in the structure. For example,I tryed to put `uint8_t` as the first element and size of `ProbeObject` was 16 byte, but when I put `uint32_t` as the first element size of `ProbeObject` was 24 (!) byte :thinking:
