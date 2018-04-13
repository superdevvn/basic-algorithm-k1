#include "stdio.h"

int n, m;
int a[100][100];
int flag[100];
int track[100];

int bigConfig = 1000;
int trackResult[100];

void excute(int thanh_pho_hien_tai, int so_thanh_pho_di_qua, int chi_phi){
	track[so_thanh_pho_di_qua-1] = thanh_pho_hien_tai;
	if(so_thanh_pho_di_qua == n) {
		if(chi_phi+a[thanh_pho_hien_tai][0]<bigConfig) {
			bigConfig = chi_phi+a[thanh_pho_hien_tai][0];
			for(int i=0;i<n;i++)
				trackResult[i] = track[i];
		}
		return;
	}
	for(int i=0;i<n;i++)
		if(a[thanh_pho_hien_tai][i] != 1000 && flag[i]==false){
			flag[i] = true;
			excute(i,so_thanh_pho_di_qua+1,chi_phi+a[thanh_pho_hien_tai][i]);
			flag[i] = false;
		}
}

int main(){
	int u, v, k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		flag[i] = false;
		for(int j=0;j<n;j++)
		if(i==j) a[i][j] = 0;
		else a[i][j] = 1000;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&k);
		a[u][v]=k;
		a[v][u]=k;
	}
	
	flag[0] = true;
	excute(0,1,0);
	printf("%d\n",bigConfig);
	for(int i=0;i<n;i++)
		printf("%d->",trackResult[i]);
	return 0;
}
