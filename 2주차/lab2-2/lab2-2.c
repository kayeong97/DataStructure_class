#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

// 순열을 출력하는 재귀함수
void perm(int* list, int i, int n) {
	int j, temp;
	if (i == n) {
		for (j = 0; j <= n; j++) {
			printf("%d", list[j]);
		}
		printf("   ");
	}
	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}

int main() {
	int i;
	double duration;
	clock_t start;
	int scanNum;

	// 정수 입력 받기
	printf("정수를 입력하시오>>");
	scanf("%d", &scanNum);

	//숫자 배열 만들기
	int* ptr = (int*)malloc(scanNum*sizeof(int));

	if (ptr == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (i = 0; i < scanNum; i++) {
		ptr[i] = i + 1;
	}

	// 정렬 및 실행 시간 측정
	start = clock();
	perm(ptr,0,scanNum-1);
	printf("\n");
	duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

	printf("%d 실행 시간: %f 초\n", scanNum, duration);

	free(ptr);

	return 0;
}
