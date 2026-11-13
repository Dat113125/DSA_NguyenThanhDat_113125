#include<stdio.h>
#include<stdlib.h>

void nhap(float *a, int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%f", a+i);
	}
}

void in(float *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%.2f ", *(a+i));
	}
	printf("\n");
}

int main(){
	float *a;
	int n;
	scanf("%d", &n);
	a = (float*)malloc(n*sizeof(float));
	if(a==NULL){
		printf("Khong hop le\n");
		return 1;	
	}
	nhap(a, n);
	printf("Mang vua nhap:\n");
	in(a, n);
	free(a);
}
