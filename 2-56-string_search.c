// Complexity O(nm)

#include <stdio.h>
#include <string.h>

int find_match(char *pin, char *hay) {
  int m = strlen(pin);
  int n = strlen(hay);
  int i, j;
  for (i = 0; i <= (n - m); i++) {
    j = 0;
    while ((j < m) && (hay[i + j] == pin[j])) {
      j += 1;
    }
    if (j == m) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./string_search hay pin\n");
    return 1;
  }
  int check = find_match(argv[1], argv[2]);
  if (check == -1) {
    printf("Not found.\n");
  } else {
    printf("Found at %d\n", check);
  }
  return 0;
}
