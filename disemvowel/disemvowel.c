#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

// this helper function checks if a is a vowel for both upper and lower character case
// return 1 if it is true, otherwise return 0
static int is_vowel(char c) {
  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      return 1;
    default:
      return 0;
  }
}

char *disemvowel(char *str) {
  if (!str) return NULL;
  size_t n = strlen(str), keep = 0;

  // count how many characters are not vowels
  for (size_t i = 0; i < n; ++i) if (!is_vowel(str[i])) ++keep;

  // allocate space for the output string
  char *out = (char*) malloc(keep + 1);
  if (!out) return NULL;

  // copy non vowel characters into new string
  size_t j = 0;
  for (size_t i = 0; i < n; ++i) if (!is_vowel(str[i])) out[j++] = str[i];
  
  out[j] = '\0';
  return out;
}
