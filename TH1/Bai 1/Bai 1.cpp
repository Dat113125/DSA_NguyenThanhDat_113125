#include<stdio.h>
#include<math.h>

void ptb1(float a, float b){
	float x;
	if(a != 0){
		x = -b/a;
		printf("%.2f", x);
	}
	else{
		if(b==0) printf("VSN");
		else printf("VN");
	}
}

void ptb2(float a, float b, float c){
	if(a==0) ptb1(b, a);
	else{
		float delta = b*b-4*a*c;
		if(delta > 0){
			float x1 = (-b - sqrt(delta)) / (2*a);
			float x2 = (-b + sqrt(delta)) / (2*a);
			printf("%.2f %.2f", x1, x2);
		}
		else if(delta == 0){
			float x = -b/(2*a);
			printf("%.2f", x);
		}
		else{
			printf("VN");
		}
	}
}

int main(){
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	ptb2(a, b, c);
}
