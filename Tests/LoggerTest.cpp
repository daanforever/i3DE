#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem {
  TEST(loggerTest, debug) {
    ASSERT_NO_THROW(lorem::logger::debug() << "Hello");
  }
}
