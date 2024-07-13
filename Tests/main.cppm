#include "tests.cppm"

int main(int argc, char** argv) {
  // Almost a copy of the Google Test's main
  testing::InitGoogleTest(&argc, argv);
  try {
    RUN_ALL_TESTS();
  }
  catch (...)
  {
    std::cout << "Error!" << std::endl;
  }
  // returning an error in all cases
  return 1;
}