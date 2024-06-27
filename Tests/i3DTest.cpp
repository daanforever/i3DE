#include "pch.h"

#include "Lorem/i3D.cpp"

namespace i3D {
  const std::string filename = "../../../../Tests/Samples/pln_3_35.i3d";
  const auto file_ptr = Lorem::Utils::loadFile(filename);

  TEST(i3DCase, DefaultConstructor) {
    EXPECT_NO_THROW(Lorem::I3DDocument());
  };

  TEST(I3DDocumentCase, ParseXML) {
    EXPECT_NO_THROW(Lorem::I3DDocument().parseXML(file_ptr));
  };

  TEST(I3DDocumentCase, NameAndVersion) {
    EXPECT_NO_THROW(Lorem::I3DDocument().parseXML(file_ptr));
  };

}
