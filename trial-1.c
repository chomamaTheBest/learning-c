#include <stdio.h>
#include <stdlib.h>

int canWin (int xs[], int n, int r) {

  if(r == 1) {
    return xs[0] == 1;
  }
  
  int best = xs[0];

  for(int i = 1; i < r - 1; i++) {
    if (best > xs[i]) {
      best = xs[i];
    }
  }

  int target = 0;

  for(int i = r - 1; i < n ; i++) {
    if (best > xs[i]) {
      target = xs[i];
      break;
    }
  }

  return target == 1;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findMax(int xs[], int n) {
  int pos = 0;

  for (int i = 1; i < n; i++) {
    if(xs[i] > xs[pos]) {
      pos = i;
    }
  }
  
  return pos;
}


void f(int n, int xs[]) {

    int total = 1;
    
    int *c, *counter;

    c = (int*)malloc(sizeof(int) * n);

    counter = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        c[i] = 0;
        counter[i] = 0;
        total *= i + 1;
    }
    
    for(int j = 0; j < n; j++) {
      counter[j] += canWin(xs, n, j + 1);
    }

    int i = 1;

    while (i < n) {
        if (c[i] < i) {
            if (i%2 == 0) {
                swap(&xs[0], &xs[i]);
            } else {
                swap(&xs[c[i]], &xs[i]);
            }

            for(int j = 0; j < n; j++) {
              counter[j] += canWin(xs, n, j + 1);
            }
            
            c[i] ++;
            i = 1;
        } else {
            c[i] = 0;
            i++;
        }
    }

    int pos = findMax(counter, n);

    printf("r: %d, P(r): %f \n", pos + 1, (float)counter[pos]/total);

    free(c);
}

int main (int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int* arr;

  arr = (int*)malloc(sizeof(int) * n);

  for(int i = 0; i < n; i ++) {
    arr[i] = i + 1;
  }

  f(n, arr);

  free(arr);

  return 0;
}