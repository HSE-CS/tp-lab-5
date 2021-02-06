// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(deanary, test1) {
  Student st();
  EXPECT_EQ(0, st.getId());
}
