#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
void delchar(string array)
{
	map<char,int> mymap;
	map<char,int>::iterator it;
	int length=array.length();
	if(length==0)
		return;
	int count;
	for(int i=0;i<length;++i)
	{
		count=(mymap.count(array[i])>0?mymap.find(array[i])->second:0);
		if(count>0)
			mymap.erase(mymap.find(array[i]));
		mymap.insert(pair<char,int>(array[i],++count));
	}
	int min=0;
	for(it=mymap.begin(),min=it->second;it!=mymap.end();++it)
	{
		if(min>it->second)
			min=it->second;
	}
	set<char> myset;
	for(it=mymap.begin();it!=mymap.end();++it)
	{
		if(min==it->second)
			myset.insert(it->first);
	}
	for(int i=0;i<length;++i)
	{
		if(myset.find(array[i])==myset.end())
			cout<<array[i];
	}
	cout<<endl;
}
int main(void)
{
	string str;
	while(cin>>str)
		delchar(str);
	return 0;
}
