#include		<gtest/gtest.h>

TEST(Strcmp, EmptyString) {
  char		*string = strdup("");
  ASSERT_EQ(0, strcmp(string, string));
  free(string);
}

TEST(Strcmp, TwoOneByte) {
  char		*string1 = strdup("a");
  char		*string2 = strdup("a");
  ASSERT_EQ(0, strcmp(string1, string2));
  free(string1);string1 = strdup("ç");
  free(string2);string2 = strdup("ç");
  ASSERT_EQ(0, strcmp(string1, string2));
  free(string1);string1 = strdup("z");
  ASSERT_EQ(-73, strcmp(string1, string2));
}

TEST(Strcmp, SameSize) {
  char		*string1 = strdup("stringA");
  char		*string2 = strdup("stringZ");

  ASSERT_EQ(-25, strcmp(string1, string2));
  free(string2);string2 = strdup("stringA");
  ASSERT_EQ(0, strcmp(string1, string2));
  free(string1);string1 = strdup("stringZ");
  ASSERT_EQ(25, strcmp(string1, string2));
}

TEST(Strcmp, FirstShorter) {
  char		*string1 = strdup("string");
  char		*string2 = strdup("stringA");

  ASSERT_EQ(-65, strcmp(string1, string2));
  free(string1);string1 = strdup("hello");
  ASSERT_EQ(-11, strcmp(string1, string2));
  free(string1);string1 = strdup("z");
  ASSERT_EQ(7, strcmp(string1, string2));
}

TEST(Strcmp, FirstLonger) {
  char		*string1 = strdup("stringA");
  char		*string2 = strdup("string");

  ASSERT_EQ(65, strcmp(string1, string2));
  free(string1);string1 = strdup("hello there");
  free(string2);string2 = strdup("wow");
  ASSERT_EQ(-15, strcmp(string1, string2));
  free(string2);string2 = strdup("hey there");
  ASSERT_EQ(-13, strcmp(string1, string2));
}
