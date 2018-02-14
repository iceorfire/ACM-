#include<iostream>
#define N 1010
using namespace std;
int a[N];
int n,k;
bool dfs(int i,int sum){
	if(i==n) return sum==k;
	if(dfs(i+1,sum)) return true;
	if(dfs(i+1,sum+a[i])) return true;
	return false;
}
int solve(){
	if(dfs(0,0)) cout<<"YES"<<endl;
	return 0;
}
int main()
{
	cin>>n;
	int k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	if(dfs(0,k)) cout<<"YES"<<endl;
	return 0;
}
