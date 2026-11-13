#include<stdio.h>
#include<stdlib.h>

void nhap(float **a, int sh, int sc){
	int i, j;
	for(i=0; i<sh; i++){
		for(j=0; j<sc; j++){
			scanf("%f", &a[i][j]);
		}
	}
}

void in(float **a, int sh, int sc){
	int i, j;
	for(i=0; i<sh; i++){
		for(j=0; j<sc; j++){
			printf("%.2f ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	float **a;
	int sh, sc;
	scanf("%d%d", &sh, &sc);
	a = (float**)malloc(sh*sizeof(float*));
	if(a==NULL){
		printf("Khong hop le\n");
		return 1;
	}
	for(int i = 0; i<sh; i++){
		a[i] = (float*)malloc(sc*sizeof(float));
		if(a[i]==NULL) {
			printf("Khong du bo nho tai dong %d\n");
			return 1;
		}
	}
	nhap(a, sh, sc);
	printf("Mang vua nhap:\n");
	in(a, sh, sc);
	for(int i = 0; i<sh; i++){
		free(a[i]);
	}
	free(a);
}
