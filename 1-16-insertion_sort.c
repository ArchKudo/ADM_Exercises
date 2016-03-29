//Complexity: O(n^2)
#include <stdio.h>

#define S_INT(n) sizeof(n) / sizeof(int)

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int *insert_sort(int *s, int n) {
  int i = 0, j = 0, temp = 0;
  for (i = 1; i < n; i++) {
    j = i;
    while ((j > 0) && (s[j] < s[j - 1])) {
      swap(&s[j], &s[j - 1]);
      j -= 1;
    }
  }
  return s;
}
void print_int_array(int *s) {
  for (int i = 0; i < 6; i++) {
    printf("%d\t", s[i]);
  }
  puts("");
}

int main() {
  int s[6] = {14, 12, 19, 1, 32, 11};
  print_int_array(s);
  int size = S_INT(s);
  insert_sort(s, size);
  print_int_array(s);
  return 0;
}

/*
  Worst-case running time follows from multiplying the largest number of times
  each nested loop can iterate
*/
