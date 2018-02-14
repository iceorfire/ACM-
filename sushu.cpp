#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int vis[1000];
	cin>>n;
	int m=sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=m;i++) if(!vis[i])
		for(int j=i*i;j<=n;j+=i) vis[j]=1;
	for(int i=2;i<=n;i++)
		if(!vis[i]) cout<<i<<endl;
	return 0;
}
