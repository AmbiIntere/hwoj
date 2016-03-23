#include<iostream>
#include<list>
using namespace std;

void countoff(int input)
{
	list<int> L;
	if(input<=0)
		return;
	for(int i=1;i<=input;i++)
		L.push_back(i);
	list<int>::iterator it;
	list<int>::iterator temp;
	it=L.begin();
	while(input>1)
	{	
		for(int count=1;count<3;++count)
		{
			++it;
			if(it==L.end())
			{
				it=L.begin();
			}
		}
		temp=++it;
		if(temp==L.end())
			temp=L.begin();
		L.erase(--it);
		--input;
		it=temp;
	}
	cout<<*it<<endl;
}
int main(void)
{
	int input;
	while(cin>>input)
		countoff(input);
	return 0;
}
