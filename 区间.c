/* ----------------
 * 大概思路就是把数组中的一个元素看成一个单位区间，然后将区间划分
 * 每输入一次区间就扫描一次，自增相应区间的元素大小，这个元素的大小就代表区间的重叠的次数，也就是讲师数。
 ** */

#include<stdio.h>
#include<memory.h>
int a[30];
int main()
{
	int n,i,j,sum,s,t;
	n=i=j=sum=s=t=0;
	while(scanf("%d",&n)!=EOF){
		sum=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;++i){
			scanf("%d%d",&s,&t);
			for(j=s;j<t;++j){
				a[j]++;
				if(a[j]>sum){
					sum=a[j];
				}
			}
		}
		printf("%d\n",sum);
	}return 0;
}

