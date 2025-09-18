#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t size = 0;

  // read lines from standard input until EOF
  while (getline(&line, &size, stdin) > 0) {
    char *res = disemvowel(line);
    if (res) {
      printf("%s\n", res);
      free(res);
    }
  }
  
  free(line);
  return 0;
}
