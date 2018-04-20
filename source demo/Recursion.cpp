#include "stdio.h"

// De quy tim uoc chung lon nhat
int UCLN(int a, int b){
	if(a==b) return a; // Dieu kien stop de quy
	else if(a>b) return (a-b,b); // Goi de quy
	else return (a,b-a); // Goi de quy
}
// De quy tim phan tu Fibonanci thu n
int Fibonanci(int n){
	if(n==1) return 1; // Dieu kien stop de quy
	if(n==2) return 2; // Dieu kien stop de quy
	return Fibonanci(n-1) + Fibonanci(n-2); // Goi de quy
}

// De quy tim to hop chap k cua n
long int ToHop(int n, int k) {
	if (n==k||k==0)	return 1; // Dieu kien stop de quy
	return ToHop(n-1,k-1)+ToHop(n-1,k); // Goi de quy
}

int main(){
	printf("UCLN: %d\n", UCLN(36,48));
	printf("Fibonanci: %d\n", Fibonanci(7));
	printf("ToHop: %d\n", ToHop(5,2));
}

