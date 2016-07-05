// Complexity: O(n^2)

#include <stdio.h>
#include <stdlib.h>

#define SIZE_INT(n) sizeof(n) / sizeof(int)
#define MAX 100

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int *s, int n) {
  int i = 0, j = 0;
  for (i = 1; i < n; i++) {
    j = i;
    while ((j > 0) && (s[j] < s[j - 1])) {
      swap(&s[j], &s[j - 1]);
      j -= 1;
    }
  }
}
void print_int_array(int *s, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", s[i]);
  }
  puts("");
}

int main(int argc, char *argv[]) {
  int a[MAX] = {0};
  if (argc < 3) {
    fprintf(stderr, "Usage: ./1-16-insertion_sort [Size of Array] (< 100) "
                    "[Array Elements]\n");
    return 1;
  }
  int n = atoi(argv[1]);
  if (((argc - 2) != n) || (n > MAX)) {
    fprintf(stderr, "%d elements are expected.\n", n);
    return 1;
  }
  for (int i = 0; i < n; i++) {
    a[i] = atoi(argv[i + 2]);
  }
  print_int_array(a, n);
  insertion_sort(a, n);
  print_int_array(a, n);
  return 0;
}

/*
  Worst-case running time follows from multiplying the largest number of times
  each nested loop can iterate
*/
