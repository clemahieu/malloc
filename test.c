#include <stdio.h>
#include "malloc.h"

int main(int argc, char *argv[]) {
  int* arrays[1000];
  int i, j, k;

  for (k = 0; k < 3; k++) {
    for (i = 0; i < 1000; i++) {
      arrays[i] = (int *)malloc(sizeof(int) * (i + 1));
      for (j = 0; j <= i; j++) {
        arrays[i][j] = j;
      }
    }

    for (i = 0; i < 1000; i++) {
      free(arrays[i]);
    }
  }

  return 0;
}

