#include "pch.h"
#include "Lorem/Logger.h"

namespace Logger {
  TEST(LoggerTestCase, DEBUG) {
    LDEBUG << "Hello";
    EXPECT_TRUE(true);
  }
}
