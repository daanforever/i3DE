#include "pch.h"
#include "Lorem/Logger.h"

namespace Lorem {
  TEST(Logger, DEBUG) {
    LDEBUG << "Hello";
    EXPECT_TRUE(true);
  }
}
