#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#define MAX 2147483647
#define maxn 50001
using namespace std;
struct node
{
    int to,next=0,w;
}edge[maxn];
int head[maxn];
int dis[maxn],n,m,k,t;    //struct存边 ，dis存距离，vis判断遍历条件；                         
void dj(int k)
{
    bool vis[maxn]={false};
    for(int i=1;i<=n;i++)
    {    
        int mi=MAX,t=-1;                    //定义判断条件； 
        for(int j=1;j<=n;j++)                //遍历每个点； 
        {
            if(!vis[j] && dis[j]<mi)        //未遍历过且连接有边 ； 
            {
                mi=dis[j];
                t=j;                        //存边，存最小值 ； 
            } 
        }    
        if(t==-1 || mi==MAX)                //MAX就是无限大，也就理解为没有边； 
        break;
        vis[t]=true;                        //即第j个点已经遍历过了； 
        //接下来是本羸弱最不能理解的地方（链表没学好 ~ —o —~ ）； 
        for(int j=head[t];j;j=edge[j].next)    //从head头找起，一个一个连上找； 
        {
                                            //如果该点没有找过，并且源点到该点的距离更小；
            if(!vis[edge[j].to] && dis[edge[j].to]>(edge[j].w+dis[t]))
            dis[edge[j].to]=edge[j].w+dis[t];
                                            //那么更新；
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)                    //初始化所有的点都不连接； 
    dis[i]=MAX;                                 
    dis[k]=0;                                //到开始的点的距离为0 ； 
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);            //简化输入，应该都懂吧（如果不懂请见《啊哈，算法》）； 
        edge[i].to=y;
        edge[i].w=z;
        edge[i].next=head[x];
        head[x]=i; 
    }    
    dj(n);//开始查询！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！                                    
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    //完美输出 
    return 0;
}
