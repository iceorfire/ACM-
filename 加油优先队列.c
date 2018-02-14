#include<cstdio>
#include<iostream>
#include<algorithm>


int N,L,P;
int  A[MAX_N+1],B[MAX_N+1];
void solve(){
	A[N]=L;
	B[N]=0;
	N++;
	priority_queue<int>que;
	//ans:加油次数，pos:现在所在位置,tank:邮箱中汽油的量
	int ans=0,pos=0,tank=p;
	for(int i=0;i<N;i++){
		int d=A[i]-pos;
		while(tank-d<0){
			if(que.empty()){
				puts("-1");
				return 0;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		tank-=d;
		pos=A[i];
		que.push(B[i]);
	}
	printf("%d\n",ans);
}
