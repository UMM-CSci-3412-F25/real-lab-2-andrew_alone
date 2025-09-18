#include <gtest/gtest.h>

#include "palindrome.h"
#include <cstdlib>

void is_palindrome(char const *str) {
  char *ans = palindrome(str);
  ASSERT_STREQ("Yes", ans);
  free(ans);
}

void not_palindrome(char const *str) {
  char *ans = palindrome(str);
  ASSERT_STREQ("No", ans);
  free(ans);
}

TEST(Palindrome, HandlesEmptyString) {
  is_palindrome("");
}

TEST(Palindrome, HandlesSingletons) {
  is_palindrome("a");
  is_palindrome("b");
  is_palindrome("c");
}

TEST(Palindrome, HandlesLengthTwo) {
  is_palindrome("aa");
  is_palindrome("bb");
  not_palindrome("ab");
}

TEST(Palindrome, HandlesLengthThree) {
  is_palindrome("aaa");
  is_palindrome("bab");
  not_palindrome("abc");
  not_palindrome("abb");
}

TEST(Palindrome, HandlesLengthFour) {
  is_palindrome("aaaa");
  is_palindrome("baab");
  not_palindrome("abcd");
  not_palindrome("aabb");
  not_palindrome("abbc");
  not_palindrome("abca");
}

TEST(Palindrome, HandlesLongerStrings) {
  is_palindrome("aaaaaaaaaaa");
  is_palindrome("aaaaaaaaaaaa");
  is_palindrome("abcdefgfedcba");
  is_palindrome("abcdefggfedcba");
  not_palindrome("abcdefghijk");
  not_palindrome("aaaaaaaaaaaabaaaa");
  not_palindrome("abcdxfgfedcba");
  not_palindrome("abcdefggfexcba");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
