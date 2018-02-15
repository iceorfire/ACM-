#include<iostream>
#include<algorithm>
using namespace std;

int a[100000];

bool cmp(int a,int b){return a>b;}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);//增序
	sort(a,a+n,cmp);//降序
	
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
