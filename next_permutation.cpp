#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[1001];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	do{
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}while (next_permutation(a,a+n));
	return 0;
}
