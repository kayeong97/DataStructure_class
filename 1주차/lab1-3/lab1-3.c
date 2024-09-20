#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
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
void sort(int* list) { 
	int i, j, min, temp; 
	for (i = 0; i < SIZE - 1; i++) {
		min = i;
		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < list[min]) min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}

//랜덤수 배열 함수
void random_num(int* list) {
	int max = SIZE;
	int min = 0;
	int i;
	srand(time(NULL));

	for (i = 0; i < SIZE; i++) {
		list[i] = rand() % (max - min + 1) + min;
	}
}

int main() {
	int i;
	int searchnum[22] = { 1,10, 100, 1000, 10000, 12500, 50000, 53125, 75000, 75195, 100000,
		120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130 };
	int list[SIZE];
	int counter;
	int searchnumInt;
	for (i = 0; i < 22;i++) {
		random_num(list);
		sort(list);
		searchnumInt = searchnum[i];
		counter = binsearch(list, searchnumInt, 0, SIZE - 1);
		if (counter == -1) printf("%d 못찾았어요ㅠ\n", searchnum[i]);
		else printf("%d 찾은 횟수: %d \n", searchnum[i], counter);
	}
	return 0;
}
