#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char Hten[30];
	int masv;
	float d1, d2, d3;
}SV;

void nhap(SV *a, int n){
	int i;
	for(i=0; i<n; i++){
		while(getchar() != '\n');
		printf("Moi ban nhap ho ten (sinh vien %d): ", i+1);
		fgets((a+i)->Hten, sizeof((a+i)->Hten), stdin);
		(a+i)->Hten[strcspn((a+i)->Hten, "\n")] = '\0';
		printf("Moi ban nhap ma sinh vien (sinh vien %d): ", i+1);
		scanf("%d", &(a+i)->masv);
		printf("Moi ban nhap diem mon 1 (sinh vien %d): ", i+1);
		scanf("%f", &(a+i)->d1);
		printf("Moi ban nhap diem mon 2 (sinh vien %d): ", i+1);
		scanf("%f", &(a+i)->d2);
		printf("Moi ban nhap diem mon 3 (sinh vien %d): ", i+1);
		scanf("%f", &(a+i)->d3);
	}
}

void in(SV *a, int n){
	int i;
	for(i=0; i<n; i++){
		SV *sv = a + i;
		printf("%s %d %.2f %.2f %.2f", (a+i)->Hten, (a+i)->masv, (a+i)->d1, (a+i)->d2, (a+i)->d3);
		printf("\n");
	}
}

int main(){
	SV *a;
	int n;
	printf("Moi ban nhap so sinh vien: ");
	scanf("%d", &n);
	a = (SV*)malloc(n*sizeof(SV));
	if(a==NULL){
		printf("Khong du bo nho\n");
		return 1;
	} 
	nhap(a, n);
	printf("Danh sach sinh vien:\n");
	in(a, n);
	free(a);
}
