//Complexiy: O(n^2)
#include <stdio.h>

#define S_INT(n) sizeof(n) / sizeof(int)

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
  int a[6] = {3, 1, 2, 2, 9, 8};
  int n = S_INT(a);
  print_int_array(a, n);
  selection_sort(a, n);
  print_int_array(a, n);
  return 0;
}
