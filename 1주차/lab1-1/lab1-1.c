#define _CRT_SECURE_NO_WARNINGS //scanf를 위한
#include <stdio.h> //입출력시스템
#include <stdlib.h> //rand(), srand()
#include <time.h> // 시드 설정
#define SIZE 100000 //배열 크기
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //매크로로 구현

//정렬하는 함수
void sort(int *list) { //list는 수 배열 n은 배열의 크기
	int i, j, min, temp; //i,j는 반복문 min 작은 값, temp는 swap을 위한
	for (i = 0; i < SIZE - 1; i++) {
		min = i;
		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < list[min]) min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}

//정렬이 잘 되어있는지 확인하는 함수
int is_sorted(int* A) {
	int i,j;
	for (i = 0; i < SIZE-1; i++) {
		if (A[i] > A[i + 1]) return 0;
	}
	return 1;
}

//랜덤수 배열을 만드는 함수
void random_num(int* list) {
	int max = 100000;
	int min = 0;
	int i;
	srand(time(NULL));

	for (i = 0; i < SIZE; i++) {
		list[i] = rand() % (max - min + 1) + min;
	}
}

int main() {
	int list[SIZE];
	random_num(list);
	sort(list);
	int boolsort = is_sorted(list);

	if (boolsort == 1) printf("정렬 성공");
	else printf("정렬 실패");

	return 0;
}
