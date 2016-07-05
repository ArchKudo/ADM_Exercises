/*
	Running Time = O(xyz)
	In general O(n^3)
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
        > . - Represents Memory Location
        1|		2
        .|.........
        .|.........
        .|.........
*/

int **allocate_matrix(int rows, int cols) {
  // Setup Rows #1
  int **matrix = calloc(rows, sizeof(matrix));

  // Setup Corresponding Columns #2
  for (int i = 0; i < rows; i++) {
    matrix[i] = calloc(cols, sizeof(matrix[i]));
  }

  // Return matrix
  return matrix;
}

void free_matrix(int **matrix, int rows) {
  // Free all elements inside a row
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void display_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", *(*(matrix + i) + j));
    }
    printf("\n");
  }
}

int **matrix_product(int **mat_a, int **mat_b, int rows_a, int cols_a,
                     int rows_b, int cols_b) {
  // Check
  if (cols_a != rows_b) {
    fprintf(stderr, "Multiplication not Possible!\n");
    exit(1);
  }

  // Allocate matrix
  int **mat_product = allocate_matrix(rows_a, cols_b);

  // Start Matrix multiplication
  for (int i = 0; i < rows_a; i++) {
    for (int j = 0; j < cols_b; j++) {
      for (int k = 0; k < rows_b; k++) {
     		*(*(mat_product + i) + j) += *(*(mat_a + i) + k) * *(*(mat_b + k) + j);
      }
    }
  }

  return mat_product;
}

/*
        Matrix is always pass by reference.
        Hence all elements get asssigned to parent matrix
*/
void fetch_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("[%d, %d] = ", i, j);
      scanf("%d", (*(matrix + i) + j));
      printf("\n");
    }
  }
}

int main() {

  int **mat_a, **mat_b,  rows_a, rows_b, cols_a, cols_b;
	int **mat_product;
  printf("Enter Rows and Columns of First Matrix: \n");
  scanf("%d %d", &rows_a, &cols_a);
  printf("Enter Rows and Columns of Second Matrix: \n");
  scanf("%d %d", &rows_b, &cols_b);

  mat_a = allocate_matrix(rows_a, cols_a);
  mat_b = allocate_matrix(rows_b, cols_b);

  printf("Enter Elements of First Matrix\n");
  fetch_matrix(mat_a, rows_a, cols_a);

  printf("Enter Elements of Second Matrix\n");
  fetch_matrix(mat_b, rows_b, cols_b);

  mat_product = matrix_product(mat_a, mat_b, rows_a, cols_a, rows_b, cols_b);
  display_matrix(mat_a, rows_a, cols_a);
  display_matrix(mat_b, rows_b, cols_b);
  display_matrix(mat_product, rows_a, cols_b);

  free_matrix(mat_a, rows_a);
  free_matrix(mat_b, rows_b);
  free_matrix(mat_product, rows_a);
  return 0;
}