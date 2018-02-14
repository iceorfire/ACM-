#include<iostream>
#include<vector>
#include<string>
using namespace std;
class BigNumber{
	public:
		BigNumber(const string &NumA,const string & NumB);
		string getSum();
	private:
		vector<char>Left,Right;
};
BigNumber::BigNumber(const string &NumA,const string &NumB){
	for(int i=0;i<NumA.length();i++){
		Left.push_back(NumA[i]);
	}
	for(int i=0;i<NumB.length();i++){
		Right.push_back(NumB[i]);
	}
}
string BigNumber::getSum(){
	vector<char>sum;
	short in=0;
	int Aindex=Left.size()-1,Bindex=Right.size()-1;
	while(Aindex>=0&&Bindex>=0){
		short sumTmp=Left[Aindex] + Right[Bindex]-2*'0' + in;
		if(sumTmp>9){in=1;sum.push_back(sumTmp-10 + '0');
		}
		else {in=0;sum.push_back(sumTmp+'0');
		}
		--Aindex;
		--Bindex;
	}
	while(Aindex>=0){
		short sumTmp=Left[Aindex]-'0'+in;
		if(sumTmp>9){
			in = 1;
			sum.push_back(sumTmp-10+'0');
		}
		else 
		{
			in=0;sum.push_back(sumTmp+'0');
		}
		Aindex--;
	}
	while(Bindex>=0){
		short sumTmp=Right[Bindex]-'0'+in;
		if(sumTmp>9){
			in=1;sum.push_back(sumTmp-10-'0');
		}
		else{
			in=0;sum.push_back(sumTmp+'0');
		}
		Bindex--;
	}
	if(in==1)
		sum.push_back('1');
	string armString;
	for(int i=sum.size()-1;i>=0;i--){
		armString +=sum[i];
	}
	return armString;
}
int main()
{
	int T;
	cin>>T;
	int i=1;
	string left,right;
	while(i<=T){
		cin>>left<<right;
		printf("Case %d:\n",i);
		BigNumber bn(left,right);
		cout<<left<<" + "<<right<<" = "<<bn.getSum()<<endl;
		if(i!=T) cout<<endl;
		i++;
	}
	return 0;
}
