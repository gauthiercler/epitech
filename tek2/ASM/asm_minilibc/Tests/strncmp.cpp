#include		<gtest/gtest.h>

TEST(Strncmp, EmptyString) {
  char		*string = strdup("");
  ASSERT_EQ(0, strncmp(string, string, 1000));
  free(string);
}

TEST(Strncmp, NegativeSize) {
  char		*string1 = strdup("stringA");
  char		*string2 = strdup("stringZ");
  ASSERT_EQ(-25, strncmp(string1, string2, -666));
  free(string1);string1 = strdup("does it work ?");
  free(string2);string2 = strdup("seems like it does");
  ASSERT_EQ(-15, strncmp(string1, string2, -1));
}

TEST(Strncmp, TwoOneByte) {
  char		*string1 = strdup("a");
  char		*string2 = strdup("a");
  ASSERT_EQ(0, strncmp(string1, string2, 1));
  free(string1);string1 = strdup("ç");
  free(string2);string2 = strdup("ç");
  ASSERT_EQ(0, strncmp(string1, string2, 4));
  free(string1);string1 = strdup("z");
  ASSERT_EQ(-73, strncmp(string1, string2, 666));
  ASSERT_EQ(-73, strncmp(string1, string2, 1));
  ASSERT_EQ(0, strncmp(string1, string2, 0));
}

TEST(Strncmp, SameSize) {
  char		*string1 = strdup("stringA");
  char		*string2 = strdup("stringZ");

  ASSERT_EQ(0, strncmp(string1, string2, 3));
  free(string2);string2 = strdup("stRingA");
  ASSERT_EQ(32, strncmp(string1, string2, 5));
  free(string1);string1 = strdup("stRingZ");
  ASSERT_EQ(25, strncmp(string1, string2, 666));
}

TEST(Strncmp, FirstShorter) {
  char		*string1 = strdup("string");
  char		*string2 = strdup("stringA");

  ASSERT_EQ(-65, strncmp(string1, string2, 666));
  free(string1);string1 = strdup("hello");
  ASSERT_EQ(-11, strncmp(string1, string2, 2));
  free(string1);string1 = strdup("sz");
  ASSERT_EQ(0, strncmp(string1, string2, 1));
}

TEST(Strncmp, FirstLonger) {
  char		*string1 = strdup("stringA");
  char		*string2 = strdup("string");

  ASSERT_EQ(65, strncmp(string1, string2, 666));
  free(string1);string1 = strdup("hello there");
  free(string2);string2 = strdup("wow");
  ASSERT_EQ(-15, strncmp(string1, string2, 4));
  free(string2);string2 = strdup("hey there");
  ASSERT_EQ(-13, strncmp(string1, string2, 8));
}