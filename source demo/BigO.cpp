#include "stdio.h"
#include <iostream>
using namespace std;

void VD1(){
	int n;
	int sum = 0;
	printf("Input n: ");
	scanf("%d",&n);
//	O(n)
//	for(int i=1;i<=n;i++)
//		sum+=i;
//	O(1)
	sum = n*(n+1);
	printf("Sum: %d",sum);
}

int recursiveVD2(int a[], int x, int y, int k)
{
	if(x>y) return -1;
	int middle = (x+y)/2;
	if(a[middle] == k) return middle;
	else if(a[middle] > k) return recursive(a,x,middle-1,k);
	else return recursive(a,middle+1,y,k);
}

void VD2(){
	int a[] = {2,3,5,6,8,10,15,17,21,25,31,37,45,52,55,76,293,532};
	int length = sizeof(a)/sizeof(int);
	int x = 58;
	// O(n)
//	for(int i=0;i<length;i++)
//		if(a[i] == x) {
//			cout<<i;
//			return;
//		}
//	cout<<-1;
	// O(logn)
	 cout<<recursiveVD2(a,0,length-1,x);
}

int recursiveVD3(int n)
{
	if(n==0) return 1;
	else if(n==1) return 1;
	else return recursiveVD3(n-1) + recursiveVD3(n-2);
}

// Fibonanci
void VD3(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	if(n==0) cout<<1;
	else if(n==1) cout<<1;
	else
	{
		int first = 1;
		int last = 1;
		for(int i=2;i<=n;i++)
		{
			int temp = last;
			last = last+first;
			first = temp;
		}
		cout<<last;
	}
}

int main(){
	VD3();
	return 0;
}
