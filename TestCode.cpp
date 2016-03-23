#include<iostream>
using namespace std;
bool testcode(string str)
{
	int length=str.length();
	if(length<8)
		return false;
	int flag=0,flag1=0,flag2=0,flag3=0,flag4=0;
	for(int i=0;i<length;++i)
	{
		if(str[i]>='a'&&str[i]<='z')
			flag1=1;
		else if(str[i]>='A'&str[i]<='Z')
			flag2=1;
		else if(str[i]>='0'&&str[i]<='9')
			flag3=1;
		else 
			flag4=1;
	}
	flag=flag1+flag2+flag3+flag4;
	if(flag<3)
		return false;
	for(int i=0;i<length;++i)
	{
		string str1;
		string str2;
		if(i<length-2)
			for(int j=i;j<i+2;++j)
				str1+=str[j];
		else 
			return true;
		for(int j=0;j<length;++j)
		{	
			if(j<i||j>=i+2)
			str2+=str[j];
		}
		if((str2.find(str1)!=-1))
			return false;
	}
	return true;
}
int main(void)
{
	string input;
	while(cin>>input)
	{
		if(testcode(input))
			cout<<"OK"<<endl;
		else
			cout<<"NG"<<endl;
	}
	return 0;
}
