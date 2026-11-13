#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char Hten[30];
	int masv;
	float d1, d2, d3;
}SV;

typedef struct tagNode{
	SV infor;
	struct tagNode *link;
}Node;

typedef struct{
	Node pHead;
	Node pTail;
	int ssv;
}LList;
