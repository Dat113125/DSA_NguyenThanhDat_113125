#include<stdio.h>
#include<math.h>

int ktranto(int n){
	if(n<2) return 0;
	for(int i = 2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	if(ktranto) printf("%d la so nguyen to", n);
	else printf("%d khong la so nguyen to");
}
