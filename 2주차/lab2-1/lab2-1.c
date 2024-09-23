#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

// 순열을 출력하는 재귀함수
void perm(char* list, int i, int n) {
	int j, temp;
	if (i == n) {
		for (j = 0; j <= n; j++) {
			printf("%c", list[j]);
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
	char charArr[4][10] = { "GO","BOY","GIRL","GIRLS" };
	int i;

	for (i = 0; i < 4; i++) {
		perm(charArr[i], 0, i+1);
		printf("\n");
	}
}
