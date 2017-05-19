#include		<gtest/gtest.h>

TEST(Strcasecmp, EmptyString) {
  char		*string = strdup("");
  ASSERT_EQ(0, strcasecmp(string, string));
  free(string);
}

TEST(Strcasecmp, TwoOneByte) {
  char		*string1 = strdup("a");
  char		*string2 = strdup("a");
  ASSERT_EQ(0, strcasecmp(string1, string2));
  free(string1);string1 = strdup("ç");
  free(string2);string2 = strdup("ç");
  ASSERT_EQ(0, strcasecmp(string1, string2));
  free(string1);string1 = strdup("z");
  ASSERT_EQ(-73, strcasecmp(string1, string2));
}

TEST(Strcasecmp, SameSize) {
  char		*string1 = strdup("strIngA");
  char		*string2 = strdup("sTringZ");

  ASSERT_EQ(-25, strcasecmp(string1, string2));
  free(string2);string2 = strdup("sTringA");
  ASSERT_EQ(0, strcasecmp(string1, string2));
  free(string1);string1 = strdup("strIngZ");
  ASSERT_EQ(25, strcasecmp(string1, string2));
}

TEST(Strcasecmp, FirstShorter) {
  char		*string1 = strdup("string");
  char		*string2 = strdup("striNgA");

  ASSERT_EQ(-97, strcasecmp(string1, string2));
  free(string1);string1 = strdup("heLLo");
  ASSERT_EQ(-11, strcasecmp(string1, string2));
  free(string1);string1 = strdup("z");
  ASSERT_EQ(7, strcasecmp(string1, string2));
}

TEST(Strcasecmp, FirstLonger) {
  char		*string1 = strdup("sTRIngA");
  char		*string2 = strdup("sTRiNg");

  ASSERT_EQ(97, strcasecmp(string1, string2));
  free(string1);string1 = strdup("hello there");
  free(string2);string2 = strdup("wOw");
  ASSERT_EQ(-15, strcasecmp(string1, string2));
  free(string2);string2 = strdup("hey There");
  ASSERT_EQ(-13, strcasecmp(string1, string2));
}

TEST(Strcasecmp, SameStrings) {
  char		*string1 = strdup("FirstSTRing");
  char		*string2 = strdup("FirstSTRing");

  ASSERT_EQ(0, strcasecmp(string1, string2));
  string1 = strdup("A test.");
  string2 = strdup("A test.");
  ASSERT_EQ(0, strcasecmp(string1, string2));
}
