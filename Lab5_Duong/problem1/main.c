#include <stdio.h>
#include <limits.h>

int main() {
  char fileName[PATH_MAX];

  // prompt
  fputs ("Enter input filename: ", stdout);
  //
  if (!fgets (fname, MAXC, stdin) || *fname == '\n') {
    return 1;
  }

  return 0;
}