#include<iostream>

//卢卡斯数字
using namespace std;
long long lukasi[100]={2,1};

int main()
{
	for(int i=2;i<30;i++)
		lukasi[i]=lukasi[i-1]+lukasi[i-2];
	for(int i=0;i<30;i++)
		cout<<lukasi[i]<<" ";
	
	return 0;
}
