#include		<gtest/gtest.h>

TEST(Strpbrk, NullString) {
  char		*string = strdup("");

  ASSERT_EQ(0, strpbrk(string, "azerty"));
  free(string);
}

TEST(Strpbrk, OneByte) {
  char		*string = strdup("a");

  ASSERT_EQ('a', *(strpbrk(string, "edcbazer")));
  ASSERT_EQ(0, strpbrk(string, "edcbzer"));
}

TEST(Strpbrk, MediumString) {
  char		*string = strdup("This is my string");

  ASSERT_EQ('m', *(strpbrk(string, "zeomzu")));
  ASSERT_EQ(string + 8, strpbrk(string, "zeomzu"));

  ASSERT_EQ(' ', *(strpbrk(string, "zeom zu")));
  ASSERT_EQ(string + 4, strpbrk(string, "ze omzu   a"));

  ASSERT_EQ(0, strpbrk(string, "ze*$ozlua"));
}