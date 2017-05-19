#include		<gtest/gtest.h>

TEST(Memmove, LeftMove) {
  char		*mem = (char *) malloc(10);
  char		*string = (char *) malloc(10);

  string[0] = 'a';
  string[1] = 'z';
  string[2] = 'e';
  string[3] = 'r';
  string[4] = 't';
  string[5] = 'y';
  string[6] = 0;
//  strdup("azerty");

  memset(mem, 0, 10);
  memcpy(mem, string, strlen(string));
  free(string);
  ASSERT_EQ(0, strcmp("azerty", mem));
//  memmove(mem, mem + 4, 2);
//  ASSERT_EQ(0, strcmp("tyerty", mem));
}
/*
TEST(Memmove, RightMove) {
  char		*mem = (char *) malloc(10);
  char		*string = strdup("azerty");

  memset(mem, 0, 10);
  memcpy(mem, string, strlen(string));
  free(string);
  ASSERT_EQ(0, strcmp("azerty", mem));
  memmove(mem + 4, mem, 5);
  ASSERT_EQ(0, strcmp("azerazert", mem));
}*/