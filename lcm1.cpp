#include<iostream>
using namespace std;
#define N 1010
int n,a[N],dp[N];
int solve(){
	int res=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++) if(a[j]<a[i]){
			dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve();
	return 0;
}
