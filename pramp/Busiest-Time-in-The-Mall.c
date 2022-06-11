// https://velog.io/@soopsaram/pramp-Busiest-Time-in-The-Mall

#include <stdio.h>
#include <stdlib.h>

int findBusiestPeriod(size_t dataArrayLength, int const data[dataArrayLength][3])
{
  int max_p = 0;
  int curr_p = 0;
  int max_time = 0;

  for (int i = 0; i < dataArrayLength; i++) {
    /* 1. update count */
    curr_p = data[i][2] == 1 ? curr_p + data[i][1] : curr_p - data[i][1];

    /* 2. check next timestapmp is same with current */
    if (i+1 < dataArrayLength && data[i][0] == data[i+1][0])
      continue;

    /* 3. update maximum */
    if (curr_p > max_p) {
      max_p = curr_p;
      max_time = data[i][0];
    }
  }
  return max_time;
}

int main() {
  return 0;
}
