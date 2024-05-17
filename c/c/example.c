// c example
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char c[100];

	printf("문장을 입력하세요.\n");
	scanf("%s", c);

	printf("입력한 문장 : %s", c);

}
