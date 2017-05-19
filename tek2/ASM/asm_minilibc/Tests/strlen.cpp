#include		<gtest/gtest.h>

TEST(Strlen, EmptyString) {
  char		*string = strdup("");
  ASSERT_EQ(0, strlen(string));
  free(string);
}

TEST(Strlen, OneByte) {
  char		*string = strdup("a");
  ASSERT_EQ(1, strlen(string));
  free(string);string = strdup("ç");
  ASSERT_EQ(2, strlen(string));
  free(string);string = strdup("0");
  ASSERT_EQ(1, strlen(string));
  free(string);string = strdup("$");
  ASSERT_EQ(1, strlen(string));
}

TEST(Strlen, SmallBuffer) {
  char		*string = strdup("Hello");
  ASSERT_EQ(5, strlen(string));
  free(string);string = strdup("Everyone");
  ASSERT_EQ(8, strlen(string));
  free(string);string = strdup("How ");
  ASSERT_EQ(4, strlen(string));
  free(string);string = strdup("Are");
  ASSERT_EQ(3, strlen(string));
  free(string);string = strdup(" You ");
  ASSERT_EQ(5, strlen(string));
  free(string);string = strdup("Doing ?");
  ASSERT_EQ(7, strlen("Doing ?"));
}