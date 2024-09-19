#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

// 선택 정렬 함수
void sort(int* a, int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        SWAP(a[i], a[min], temp);
    }
}

int main() {
    int i, n;
    double duration;
    clock_t start;

    // SIZE 100부터 1000000까지 증가하는 반복문
    for (n = 100; n <= 1000000; ) {
        // 동적으로 배열 할당
        int* a = (int*)malloc(n * sizeof(int));
        // 예외처리
        if (a == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }

        // 역순으로 배열 초기화
        for (i = 0; i < n; i++) {
            a[i] = n - i;
        }

        // 정렬 및 실행 시간 측정
        start = clock();
        sort(a, n);
        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

        printf("n = %6d, 실행 시간: %f 초\n", n, duration);

        // 메모리 해제
        free(a);

        // SIZE 증가
        if (n < 1000) {
            n += 100; // 100부터 1000까지는 100씩 증가
        }
        else if (n < 10000) {
            n += 1000; // 1000부터 10000까지는 1000씩 증가
        }
        else if (n < 100000) {
            n += 10000; //10000부터 100000까지는 10000씩 증가
        }
        else {
            n += 100000; // 100,000부터 1,000,000까지는 10000씩 증가
        }
    }

    return 0;
}
