#include "pch.h"
#include "Lorem/Logger.h"

namespace Lorem {
  TEST(LoggerTestCase, DEBUG) {
    LDEBUG << "Hello";
    EXPECT_TRUE(true);
  }
}
