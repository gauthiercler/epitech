#include		<gtest/gtest.h>

TEST(Rindex, EmptyString) {
  char		*string = strdup("");

//  printf("Pointer : %p\n", rindex(string, 'a'));
  ASSERT_EQ(0, rindex(string, 'a'));
  ASSERT_EQ(string, rindex(string, 0));
}

TEST(Rindex, OneByte) {
  char			*string = strdup("a");

  ASSERT_EQ('a', *(rindex(string, 'a')));
  ASSERT_EQ(0, (rindex(string, 'z')));
  ASSERT_EQ(string + 1, strchr(string, 0));
}

TEST(Rindex, MediumString) {
  char			*string = strdup("hello my friends");

  ASSERT_EQ('o', *(rindex(string, 'o')));
  ASSERT_EQ(string + 4, rindex(string, 'o'));

  ASSERT_EQ('l', *(rindex(string, 'l')));
  ASSERT_EQ(string + 3, rindex(string, 'l'));

  ASSERT_EQ('s', *(rindex(string, 's')));
  ASSERT_EQ(string + 15, rindex(string, 's'));

  ASSERT_EQ(' ', *(rindex(string, ' ')));
  ASSERT_EQ(string + 8, rindex(string, ' '));

  ASSERT_EQ(string + 16, strchr(string, 0));
}