#include<iostream>
#include<string>
using namespace std;
int number=0;
string result[8];
void errorrecord(string str)
{
	string temp="";
	int length=str.length();
	if(length==0)
		return;
	int flag=0;
	int count=0;
	for(int i=0;i<length;++i)
	{
		if(str[i]=='\\')
			flag=i+1;
	}
	temp=str.substr(flag);
	int p;
	p=temp.find(' ');
	if(p>16)
		temp=temp.substr(p-16);
	p=temp.find(' ')+1;
	while(temp[p]==' ')
		temp.erase(p,1);
	bool isrepeat=false;
	int repeatpos;
	for(int i=0;i<8;++i)
	{
		int n=result[i].length();
		if(n!=0)
			while(result[i][--n]==' ');
		if(n!=0)
			while(result[i][--n]!=' ');
		if(temp==result[i].substr(0,n))
		{
			isrepeat=true;
			repeatpos=i;
			break;
		}
	}
	if(!isrepeat)
	{
		result[number]=temp;
		result[number]+=" ";
		result[number]+=count+1+'0';
		++number;
	}
	else
	{
		int len=result[repeatpos].length();
		while(result[repeatpos][--len]>='0'&&result[repeatpos][len]<='9')
		{
			int k=result[repeatpos][len]-'0';
			int l=result[repeatpos].length()-1-len;
			while(l--)
				k*=10;
			count+=k;
			
		}
		result[repeatpos]=temp;
		result[repeatpos]+=" ";
		++count;
		string c;
		if(count>9)
		{
			while(count)
			{
				c+=count%10+'0';
				count=count/10;
			}
			for(int i=c.length()-1;i>=0;--i)
			result[repeatpos]+=c[i];
		}
		else
			result[repeatpos]+=count+'0';
	}
	for(int i=0;i<8;++i)
		if(!result[i].empty())
			cout<<result[i]<<endl;
	if(number==8)
		number=0;
}
int main(void)
{
	string input;
	while(getline(cin,input))
	{
		errorrecord(input);
	}
	return 0;
}
