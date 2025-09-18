#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  ASSERT_STREQ("", disemvowel((char*) ""));
}

TEST(Disemvowel, HandleNoVowels) {
  ASSERT_STREQ("pqrst", disemvowel((char*) "pqrst"));
}

TEST(Disemvowel, HandleOnlyVowels) {
  ASSERT_STREQ("", disemvowel((char*) "aeiouAEIOUOIEAuoiea"));
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  ASSERT_STREQ("Mrrs, Mnnst",
		      disemvowel((char*) "Morris, Minnesota"));
}

TEST(Disemvowel, HandlePunctuation) {
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      disemvowel((char*) "An (Unexplained) Elephant!"));
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  ASSERT_STREQ("xyz", disemvowel(str));

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
