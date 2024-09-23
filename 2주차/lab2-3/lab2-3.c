#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y) { int t = (x); (x) = (y); (y) = t; }

// 순열을 출력하는 재귀함수
void perm(int* list, int i, int n) {
    int j;
    for (j = i; j <= n; j++) {
        SWAP(list[i], list[j]);
        perm(list, i + 1, n);
        SWAP(list[i], list[j]);
    }
}

int main() {
    int i, j;
    double duration;
    clock_t start;

    // 반복
    for (i = 1; i < 11; i++) {
        // 동적 배열 생성
        int* list = (int*)malloc(i * sizeof(int));

        if (list == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }

        for (j = 0; j < i; j++) {
            list[j] = j;
        }

        start = clock();
        perm(list, 0, i - 1);
        printf("\n");
        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

        printf("%d 실행 시간: %f 초\n", i, duration);

        free(list);
        list = NULL;  // Avoid using the freed memory
    }

    return 0;
}
