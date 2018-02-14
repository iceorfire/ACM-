#include<iostream>
#include<cstring>
using namespace std;
int a[100][100];
int main(){
	memset(a,0,sizeof(a));
	int m,n;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>a[1][i];
	//q代表着步数
	
	for(int q=2;q<=m;q++){
		for(int j=1;j<=m-q;j++){
			for(int i=j;i<=j+q;i++){
				a[q][j]+=a[1][i];
			}
		}
	}

	for(int i=2;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
