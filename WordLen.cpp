#include<iostream>
#include<string>
using namespace std;
void LastWordLength(string str)
{
	int length=0;
	int end=str.size()-1;
	if(str.size()==0)
		cout<<0<<endl;
	while((end>=0)&&(str[end]==' '))
		--end;
	while((end>=0)&&(str[end]!=' '))
	{
		--end;
		++length;
	}
	cout<<length<<endl;
}
int main(void)
{
	string str;
	getline(cin,str);
	LastWordLength(str);
	
	return 0;
}
