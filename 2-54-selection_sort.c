// Complexiy: O(n^2)

#include <stdio.h>
#include <stdlib.h>

#define S_INT(n) sizeof(n) / sizeof(int)
#define MAX 100

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int *s, int n) {
  int min = 0;
  for (int i = 0; i < n; i++) {
    min = i;
    for (int j = 0; j < n; j++) {
      if (s[j] > s[min]) {
        min = j;
      }
      swap(&s[i], &s[min]);
    }
  }
}

void print_int_array(int *s, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", s[i]);
  }
  puts("");
}

int main(int argc, char const *argv[]) {
  int a[MAX] = {0};
  if (argc < 3) {
    fprintf(stderr, "Usage: ./2-54-selection_sort [Size of Array] (< 100) "
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
  selection_sort(a, n);
  print_int_array(a, n);
  return 0;
}
