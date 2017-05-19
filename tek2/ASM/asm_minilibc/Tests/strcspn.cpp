#include		<gtest/gtest.h>

TEST(Strcspn, NullString) {
  char		*string = strdup("");

  ASSERT_EQ(0, strcspn(string, "azerty"));
  free(string);
}

TEST(Strcspn, OneByte) {
  char		*string = strdup("a");

  ASSERT_EQ(0, strcspn(string, "edcbazer"));
  ASSERT_EQ(1, strcspn(string, "edcbzer"));
}

TEST(Strcspn, MediumString) {
  char		*string = strdup("This is my string");

  ASSERT_EQ(8, strcspn(string, "zeomzu"));

  ASSERT_EQ(4, strcspn(string, "zeom zu"));

  ASSERT_EQ(17, strcspn(string, "ze*$ozlua"));
}