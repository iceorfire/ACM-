#include<iostream>
using namespace std;
int cal(int n,int m){
	int i,a,b,p;
	if(n<m){i=m;m=n;n=i;}
	p=1;
	a=n-m<m?n-m:m;
	b=n-m>m?n-m:m;
	for(i=1;i<=a;i++)
		p+=p*b/i;
	return p;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int q=cal(3,5);
	cout<<q<<endl;
	return 0;
}
