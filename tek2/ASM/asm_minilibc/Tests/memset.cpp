#include		<gtest/gtest.h>

TEST(Memset, MediumMemory) {
  char		*mem = (char *) malloc(10);

  memset(mem, 0, 10);
  memset(mem, 's', 1);
  ASSERT_EQ(0, strcmp("s", mem));
  memset(mem, 'z', 7);
  ASSERT_EQ(0, strcmp("zzzzzzz", mem));
  memset(mem, 'a', 3);
  ASSERT_EQ(0, strcmp("aaazzzz", mem));
  memset(mem + 4, 49, 2);
  ASSERT_EQ(0, strcmp("aaaz11z", mem));
}