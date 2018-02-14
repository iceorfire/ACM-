#include<iostream>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<min(a,b)<<" "<<max(a,b)<<endl;
	cout<<gcd(a,b)<<endl;
	return 0;
}
