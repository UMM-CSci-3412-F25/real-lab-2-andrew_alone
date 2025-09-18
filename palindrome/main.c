#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;

  size = 100;
  line = (char*) calloc(size + 1, sizeof(char));
  if (!line) return 1;

  // Read lines until EOF
  while (fgets(line, size, stdin) != NULL) {
    // Strip trailing newline so comparisons work as expected
    line[strcspn(line, "\n")] = '\0';

    // Get answer, print, then free to avoid leaks
    char *ans = palindrome(line);
    if (ans) {
      printf("Is the string <%s> a palindrome? %s\n", line, ans);
      free(ans);
    }
  }

  free(line);
  return 0;
}
