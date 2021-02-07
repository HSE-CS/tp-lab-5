// Copyright 2021 Smirnov Grigory

#include <gtest/gtest.h>
#include <string>
#include "Deanery.h"

TEST(TestStudent, testId) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  EXPECT_EQ(s.getId(), 100);
}

TEST(TestStudent, testFio) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(120, name);
  EXPECT_EQ(s.getFio(), "Pupkin Egor Fedorovich");
}
