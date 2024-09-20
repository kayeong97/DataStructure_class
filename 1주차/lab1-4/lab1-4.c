#include <stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)

// 이진검색 함수
int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	int counter = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
		case -1:
			left = middle + 1;
			counter++;
			break;
		case 0:
			return counter + 1;
		case 1: right = middle - 1;
			counter++;
			break;
		}
	}
	return -1;
}

// 오름차순 정렬 함수
void sort(int* list, int SIZE) {
	int i, j, min, temp;
	for (i = 0; i < SIZE - 1; i++) {
		min = i;
		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < list[min]) min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}

int run(int*searchnum,int SIZE) {
	int counter;
	int i;
	// 동적으로 배열 할당
	int* list = (int*)malloc(SIZE * sizeof(int));
	// 예외처리
	if (list == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}
	// 역순으로 배열 초기화
	for (i = 0; i < SIZE; i++) {
		list[i] = SIZE - i;
	}
	sort(list, SIZE);
	for (i = 0; i < 11; i++) {
		counter = binsearch(list, searchnum[i], 0, SIZE - 1);
		printf("%d 찾은 횟수: %d \n", searchnum[i], counter);
	}
	free(list);
}

int main() {
	int searchnum1[11] = { 1,10, 100, 1000, 10000, 12500, 50000, 53125, 75000, 75195, 100000 };
	int searchnum2[11] = {5,50,195,500,781,5000,12548,25012,28125,37500,50000};

	run(searchnum1, 100000);
	run(searchnum2, 50000);

	return 0;
