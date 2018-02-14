//搜索求解相差的最小值
#include<cstdio>
#include<cmath>
using namespace std;
int w[25],total,n;
int m;
int dfs (int cur ,int sum);
int main()
{
	int i;
	while(scanf("%d",&n)!=EOF){
		total=0;
		m=100000;
		for(i=0;i<n;i++){
			scanf("%d",&w[i]);
			total+=w[i];
		}
		dfs(0,0);
		printf("%d\n",m);
	}
	return 0;
}
int dfs(int cur,int sum){
	if(cur==n) return 0;
	int t;
	t=(int)fabs(total-2*sum);
	if(t<m) m=t;
	dfs(cur+1,sum+w[cur]);
	dfs(cur+1,sum);
	return 0;
}
