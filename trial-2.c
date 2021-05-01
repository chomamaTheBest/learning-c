#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  int n = atoi(argv[1]);
  int* arr;

  float *p;

  p = (float*)malloc(sizeof(float) * n);

  p[0] = (float)1 / n;

  for(int i = 2; i <= n; i++) {

    float tmp = 0;

    for(int j = i; j <= n; j ++) {

      tmp += (float) 1 / (j - 1);

    }
    p[i - 1] = tmp * (i - 1) / n;
  }

  int pos = 0;

  for (int i = 1; i < n; i++) {
    if(p[i] > p[pos]) {
      pos = i;
    }
  }

  printf("r: %d, P(r): %f \n", pos + 1, p[pos]);

  free(p);

  return 0;
}