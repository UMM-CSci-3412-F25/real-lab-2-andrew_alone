#include <gtest/gtest.h>
#include <cstdlib>
#include "disemvowel.h"

// Test cases for disemvowel function
TEST(Disemvowel, HandleEmptyString) {
  char *res = disemvowel((char*) "");
  ASSERT_STREQ("", res);
  free(res);
}

// Test case for NULL input
TEST(Disemvowel, HandleNoVowels) {
  char *res = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", res);
  free(res);
}
// Test case for string with only vowels
TEST(Disemvowel, HandleOnlyVowels) {
  char *res = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", res);
  free(res);
}

// Test case for mixed string
TEST(Disemvowel, HandleMorrisMinnesota) {
  char *res = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", res);
  free(res);
}

// Test case for mixed string with punctuation
TEST(Disemvowel, HandlePunctuation) {
  char *res = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", res);
  free(res);
}

// Test case for long string
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
  char *res = disemvowel(str);
  ASSERT_STREQ("xyz", res);
  
  free(res);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
