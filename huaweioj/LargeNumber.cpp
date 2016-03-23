#include<iostream>
#include<string>
using namespace std;
void largenumber(string str1,string str2)
{	
	int lengtha=str1.length();
	int lengthb=str2.length();
	int a[lengtha];
	int b[lengthb];
	int length=(lengtha>lengthb?lengtha:lengthb);
	int minlen=(lengtha<lengthb?lengtha:lengthb);
	int result[length+1];
	int carry=0;
	for(int i=0;i<lengtha;++i)
		a[i]=str1[lengtha-i-1]-'0';
	for(int i=0;i<lengthb;++i)
		b[i]=str2[lengthb-i-1]-'0';
	for(int i=0;i<length;++i)
	{
		if(i<minlen)
		{
			result[i]=a[i]+b[i]+carry;
			carry=0;
		}
		else
		{
			if(lengtha>lengthb)
				result[i]=a[i]+carry;
			else
				result[i]=b[i]+carry;
			carry=0;
		}
		if((result[i])>9)
		{
			carry=result[i]/10;
			result[i]=result[i]%10;
		}
	}
	if(carry>0)
		result[length]=carry;
	else
		--length;
	for(int i=length;i>=0;--i)
		cout<<result[i];
	cout<<endl;
}
int main(void)
{
	string a;
	string b;
	while(cin>>a>>b)
		largenumber(a,b);
	return 0;
}
