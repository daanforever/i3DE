#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace lorem {
  // A predicate-formatter for output in HEX
  template<typename T>
  testing::AssertionResult AssertHexEQ(const char* m_expr, const char* n_expr, T m, T n) {
    if (m == n) return testing::AssertionSuccess();

    ::testing::Message msg;

    auto format = std::hex;

    if (std::is_floating_point_v<T>) {
      format = std::hexfloat;
    }
      

    msg << std::endl << std::endl
      << format << m << " expected " << m_expr << std::endl
      << format << n << " got " << n_expr << std::endl;

    return testing::AssertionFailure(msg);
  }
}
