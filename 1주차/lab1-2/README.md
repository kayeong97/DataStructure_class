## 선택정렬 실습

## 1.2

-n의 크기를 100부터 1,000,000까지 바꾸면서 sort 함
-수의 실행 시간을 측정하여 관찰지에 기록
-역순 정렬된 배열 활용
-입력 정수 범위는 1 ~ 배열크기
-배열의 크기를 최대한 크게 할 수 있는 방법 모색

# 힌트

#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 1001
void main(void){
  int i, n, step = 10;
  int a[MAX_SIZE];
  double duration;
  clock_t start;

  /* times for n = 0, 10, ... , 100, 200, .... 1000 */
  printf("    n     time\n");
  for( n=0; n<=100; n+=step){
  /* get time for size n */
    /* initialize with worst-case data */
    for( i=0; i<n; i++)
      a[i] = n - i;
    start = clock();
    sort(a,n);
    duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("%6d %f\n", n, duration);
    if(n==100) step = 100;
  }
}
