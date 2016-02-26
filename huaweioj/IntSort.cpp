#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void intsort(string str)
{
	int length=str.length();
	vector<int> vec;
	vector<int>::iterator it;
	if(length==0)
		return;
	for(int temp=0,i=0;i<length;++i)
	{
		if(str[i]!=',')
		{
			temp*=10;
			temp+=(str[i]-'0');
			if(i==length-1)
				vec.push_back(temp);
		}
		else
		{
			vec.push_back(temp);
			temp=0;
		}
	}
	sort(vec.begin(),vec.end());
	int temp;
	for(it=vec.begin()+1,temp=*(it-1);it!=vec.end()-1;++it)
	{	
		if((*it==temp+1)&&(*it==*(it+1)-1))
		{
			temp=*it;
			vec.erase(it);
			--it;
		}
		else
			temp=*it;
	}
	for(it=vec.begin();it!=vec.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}
int main(void)
{
	string input;
	while(cin>>input)
		intsort(input);
	return 0;
}
