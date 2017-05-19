#include		<gtest/gtest.h>

TEST(Strchr, EmptyString) {
  char		*string = strdup("");

//  printf("Pointer : %p\n", strchr(string, 'a'));
  ASSERT_EQ(0, strchr(string, 'a'));
  ASSERT_EQ(string, strchr(string, 0));
}

TEST(Strchr, OneByte) {
  char			*string = strdup("a");

  ASSERT_EQ('a', *(strchr(string, 'a')));
  ASSERT_EQ(0, (strchr(string, 'z')));
  ASSERT_EQ(string + 1, strchr(string, 0));
}

TEST(Strchr, MediumString) {
  char			*string = strdup("hello my friends");

  ASSERT_EQ('o', *(strchr(string, 'o')));
  ASSERT_EQ(string + 4, strchr(string, 'o'));

  ASSERT_EQ('l', *(strchr(string, 'l')));
  ASSERT_EQ(string + 2, strchr(string, 'l'));

  ASSERT_EQ('s', *(strchr(string, 's')));
  ASSERT_EQ(string + 15, strchr(string, 's'));

  ASSERT_EQ(' ', *(strchr(string, ' ')));
  ASSERT_EQ(string + 5, strchr(string, ' '));

  ASSERT_EQ(string + 16, strchr(string, 0));
}