#include<cstdio>
int x[4]={1,0,0,-1},y[4]={0,1,-1,0};
int a[1010][101],h,l;
int dfs(int i,int j){
	int k;
	if(a[i][j]==0||i<0||i>=h||j<0||j>=l)
		return 0;
	a[i][j]=0;
	for(k=0;k<4;k++)
		dfs(i+x[k],j+y[k]);
	return 0;
}
int main(){
	int t,sum=0;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d%d",&h,&l);
		for(int i=0;i<h;i++)
			for(int j=0;j<l;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<h;i++)
			for(int j=0;j<l;j++)
				if(a[i][j]==1){
					dfs(i,j);
					sum++;
				}
		printf("%d\n",sum);
	}
	return 0;
}
