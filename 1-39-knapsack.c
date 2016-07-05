// TODO: User Input
#include <stdio.h>

typedef int (*Compare)(int a, int b);

int first_fit(int a, int b) {
	return 0;
}

int best_fit(int a, int b) {
	return b < a;
}

int largest_first(int a, int b) {
	return b > a;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int *set, int size, Compare cmp) {
  int min = 0;
  for (int i = 0; i < size; i++) {
    min = i;
    for (int j = 0; j < size; j++) {
      if (cmp(set[j], set[min])) {
        min = j;
      }
      swap(&set[i], &set[min]);
    }
  }
}

int check_knapsack(int *set, int size, int total) {
	int set_total = 0;
	for(int i = 0; i < size; i++) {
		if (set_total == total) {
			return i;
		} else {
			set_total += set[i];
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int u_set[3] = {1, 2, 3};
	sort(u_set, 3, first_fit);
	printf("Total at %d\n", check_knapsack(u_set, 3, 5));
	sort(u_set, 3, best_fit);
	printf("Total at %d\n", check_knapsack(u_set, 3, 5));
	sort(u_set, 3, largest_first);
	printf("Total at %d\n", check_knapsack(u_set, 3, 5));
	return 0;
}