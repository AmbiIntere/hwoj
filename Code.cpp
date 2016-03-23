#include<iostream>
#include<string>
using namespace std;

string code(string str)
{
	int length=str.length();
	string result="";
	if(length==0)
		return result;
	for(int i=length-1;i>=0;i--)
	{
		if((str[i]>='0')&&(str[i]<='9'))
		{
			result.insert(result.begin(),str[i]);
			continue;
		}
		if((str[i]>='A')&&(str[i]<='Z'))
		{
			if(str[i]=='Z')
			{
				result.insert(result.begin(),'a');
				continue;
			}
			str[i]=str[i]-'A'+'a'+1;
			result.insert(result.begin(),str[i]);
			continue;
		}
		if((str[i]>='a')&&(str[i]<='z'))
		{
			if((str[i]>='a')&&(str[i]<='o'))
			{
				result.insert(result.begin(),(str[i]-'a')/3+'2');
				continue;
			}
			else if((str[i]>='p')&&str[i]<='v')
				result.insert(result.begin(),(str[i]-'p')/4+'7');
			else
				result.insert(result.begin(),'9');
		}
	}
	return result;
}
int main(void)
{
	string input;
	while(cin>>input)
		cout<<code(input)<<endl;
	return 0;
}
