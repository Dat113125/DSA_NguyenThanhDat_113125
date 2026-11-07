#include<stdio.h>

void nhap(int a[], int n){
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
}

void in(int a[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
}

void tmax(int a[], int n){
	int i;
	int vt = 0;
	for(i = 0; i<n; i++){
		if(a[i] > a[vt]) vt=i;
	}
	printf("%d", a[vt]);
}

int main(){
	int a[100];
	int n;
	scanf("%d", &n);
	nhap(a, n);
	tmax(a, n);
}
