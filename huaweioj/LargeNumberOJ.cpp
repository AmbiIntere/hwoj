#include<iostream>
#include<string>
using namespace std;
string largenumber(string a,string b)
{	
	int lengtha=a.length();
	if(lengtha==0)
		return b;
	int lengthb=b.length();
	if(lengthb==0)
		return a;
	string result;
	int carry=0;
	int temp,digit1,digit2;
	for(int i=lengtha-1,j=lengthb-1;i>=0||j>=0;--i,--j)
	{
		digit1=(i>=0?(a[i]-'0'):0);
		digit2=(j>=0?(b[j]-'0'):0);
		temp=digit1+digit2+carry;
		carry=temp/10;
		result.insert(result.begin(),temp%10+'0');
	}
	if(carry>0)
		result.insert(result.begin(),carry+'0');
	return result;
}
int main(void)
{
	string a;
	string b;
	while(cin>>a>>b)
		cout<<largenumber(a,b)<<endl;;
	return 0;
}
