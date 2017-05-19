#include		<gtest/gtest.h>

TEST(Memcpy, MediumMemoryFullCopy) {
  char		*src = (char *) malloc(10);
  char		*dest = (char *) malloc(10);

  memset(src, 0, 10);
  memcpy(dest, src, 10);
  memset(src, 's', 1);
  memcpy(dest, src, 1);
  ASSERT_EQ(0, strcmp("s", src));
  ASSERT_EQ(0, strcmp("s", dest));
  memset(src, 'z', 7);
  memcpy(dest, src, 7);
  ASSERT_EQ(0, strcmp("zzzzzzz", src));
  ASSERT_EQ(0, strcmp("zzzzzzz", dest));
  memset(src, 'a', 3);
  memcpy(dest, src, 3);
  ASSERT_EQ(0, strcmp("aaazzzz", src));
  ASSERT_EQ(0, strcmp("aaazzzz", dest));
  memset(src + 4, 49, 2);
  memcpy(dest + 4, src + 4, 2);
  ASSERT_EQ(0, strcmp("aaaz11z", src));
  ASSERT_EQ(0, strcmp("aaaz11z", dest));
}
