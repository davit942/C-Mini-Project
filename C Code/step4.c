#include <ctype.h>
int getInput(char* s) {
  // Declare variables
  char c = '\0';
  int i = 0;

  // Read characters from the terminal and store them in the string s
  while (c != '\n' && i < maxInput) {
    c = getchar();
    if (isdigit(c)) {
      s[i] = c;
      i++;
    }
  }

  // Discard any remaining characters
  if (i == maxInput) {
    while (c != '\n') {
      c = getchar();
    }
  }

  // Return the number of digits read
  return i;
}
