#include "src/memdev.hpp"
#include "src/buffer.h"
#include <fmt/core.h>

#include <gtest/gtest.h>

TEST(CommonDevice, Sequential) {
  auto device = cooldev::memory::make_device(
      cooldev::memory::device_type::sequential, 1024);

  auto addr = device.space();

  ASSERT_NO_THROW(std::get<cooldev::memory::sq_address>(addr));

  ASSERT_THROW(std::get<cooldev::memory::nd_address>(addr),
               std::bad_variant_access);
}

TEST(CommonDevice, Ranked) {
  auto device = cooldev::memory::make_device(
      cooldev::memory::device_type::ndimensional, 1024);

  auto addr = device.space();

  ASSERT_NO_THROW(std::get<cooldev::memory::nd_address>(addr));

  ASSERT_THROW(std::get<cooldev::memory::sq_address>(addr),
               std::bad_variant_access);
}

//We want to have next code
TEST(CommontDevice, Access) {
  auto device = cooldev::memory::make_device(
      cooldev::memory::device_type::sequential, 1024);


  buffer<int> buf(device.space(), 1024);

  buf[10] = 0;
  ASSERT_EQ(buf[10], 0);

  buf[10] = 5;

  if (buf[10] == 5){
    fmt::print("Equal");
  }

  ASSERT_EQ(buf[10], 5);

  buf[10] = buf[10] * 2;
  ASSERT_EQ(buf[10], 10);


  buf[5] = buf[10];
  ASSERT_EQ(buf[5], buf[10]);

  for (auto v : buf){
    fmt::print("{} ", v);
  }
}

// homework
TEST(Iterator, check_methods) {
    auto device = cooldev::memory::make_device(
            cooldev::memory::device_type::sequential, 128);

    buffer<int> buf(device.space(), 128);

    buf[0] = 10;
    auto it = buf.begin();
    ASSERT_EQ(*it, 10);

    buf[127] = 20;
    ASSERT_EQ(*(buf.end() - 1), buf[127]);

    buf[1] = 5;
    ASSERT_EQ(*(++buf.begin()), buf[1]);

    it++;
    ASSERT_EQ(*it, buf[1]);

    it += 5;
    ASSERT_EQ(*it, buf[6]);

    buf[11] = 42;
    ASSERT_EQ(it[5], buf[11]);

    auto newIt = buf.end() - 5;
    ASSERT_TRUE(newIt > it);
}
