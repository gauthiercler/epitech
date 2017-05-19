#include		<gtest/gtest.h>

TEST(Strstr, NullString) {
  char		*string = strdup("");

  ASSERT_EQ(0, strstr(string, "needle"));
  ASSERT_EQ(string, strstr(string, ""));
  free(string);
}

TEST(Strstr, OneByte) {
  char		*string = strdup("a");

  ASSERT_EQ(string, strstr(string, "a"));
  ASSERT_EQ(0, strstr(string, "z"));
}

TEST(Strstr, MediumString) {
  char		*string = strdup("This string needs a needle");

  ASSERT_EQ(string + 10, strstr(string, "g n"));
  ASSERT_EQ(string + 20, strstr(string, "needle"));
  ASSERT_EQ(0, strstr(string, "needles"));
  ASSERT_EQ(0, strstr(string, " his"));
  ASSERT_EQ(string + 5, strstr(string, "string"));
}