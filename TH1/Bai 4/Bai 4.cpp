#include<stdio.h>

int ucnn(int a, int b){
	while(a*b!=0){
		if(a>b) a%=b;
		else b%=a;
	}
	return a+b;
}

void bcnn(int a, int b){
	int tama = a;
	int tamb = b;
	int uc = ucnn(a, b);
	printf("%d", (tama*tamb)/ uc);
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	bcnn(a, b);
}
