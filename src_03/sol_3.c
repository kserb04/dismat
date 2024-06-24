#include <stdbool.h>
#include <stdio.h>

void output(int n, int matrix[][n]) {
  printf("Matrix: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int degree(int n, int matrix[][n], int i) {
  int count = 0;
  for (int j = 0; j < n; j++) {
    if (matrix[i][j] == 1) {
      count++;
    }
  }
  return count;
}

void remove_(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    int count = 0, first, second;
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1) {
        if (count == 0)
          first = j;
        else
          second = j;
        count++;
      }
    }
    if (count == 2) {
      matrix[first][second] = 1;
      matrix[second][first] = 1;
      matrix[i][first] = 0;
      matrix[i][second] = 0;
      matrix[first][i] = 0;
      matrix[second][i] = 0;
    }
  }
  return;
}

bool check5(int n, int matrix[][n]) {
  int count = 0;
  int second[n] = {};

  for (int i = 0; i < n; i++) {
    int row[n];
    int count = 0;
    for (int j = 0; j < n; j++) {
      second[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      row[j] = matrix[i][j];
    }

    for (int j = 0; j < n; j++) {
      if (row[j] == 1) {
        for (int k = 0; k < n; k++) {
          if ((row[k] == 1) && (matrix[j][k] == 1)) {
            second[k]++;
          }
        }
      }
    }

    for (int j = 0; j < n; j++) {
      if (second[j] >= 3) {
        count++;
      }
    }

    if (count >= 4)
      return true;
  }

  return false;
}

bool check33(int n, int matrix[][n]) {
  int row[n] = {};
  int setA[n] = {};
  int count;

  for (int i = 0; i < n; i++) {
    int c = 0;
    if (degree(n, matrix, i) < 3)
      continue;

    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1) {
        row[j] = 1;
      } else {
        row[j] = 0;
      }
    }

    for (int k = 0; k < n; k++) {
      setA[k] = 0;
    }

    for (int j = 0; j < n; j++) {
      count = 0;
      if (row[j] == 1 && (degree(n, matrix, j) >= 3)) {
        if (c == 0) {
          for (int k = 0; k < n; k++) {
            if (matrix[k][j] == 1) {
              setA[k] = 1;
            }
          }
        }
        for (int k = j + 1; k < n; k++) {
          if (row[k] == 1) {
            for (int l = 0; l < n; l++) {
              if ((setA[k] == 1) && (matrix[k][l] == 1))
                continue;
              else if ((setA[k] == 1) && (matrix[k][l] == 0)) {
                setA[k] = 0;
              }
            }
          }
        }
        c++;

        if (c >= 3) {
          for (int a = 0; a < n; a++) {
            if (setA[a] == 1)
              count++;
          }

          if (count >= 3)
            return true;
        }
      }
    }
  }
  return false;
}

int main(void) {
  FILE *file = fopen("graph.txt", "r");

  int n;
  fscanf(file, "%d", &n);

  char newline;
  fscanf(file, "%c", &newline);

  int matrix[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fscanf(file, "%d", &matrix[i][j]);
    }
  }

  printf("Matrix: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  fclose(file);

  remove_(n, matrix);

  if (n < 5) {
    printf("Graph is planar.\n");
  } else {
    if (check5(n, matrix) == true)
      printf("Graph not planar, contains subgraph homeomorphic with K_5.\n");
    else if (check33(n, matrix) == true)
      printf("Graph not planar, contains subgraph homeomorphic with K_3,3.\n");
    else
      printf("Graph is planar.\n");
  }

  return 0;
}
