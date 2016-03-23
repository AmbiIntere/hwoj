#include<iostream>
#include<queue>
using namespace std;
void CountDidit(int input)
{
	if(input<=0)
		return;	
	queue<int> myqueue;
	do
	{	
		myqueue.push(input%10);
	}while(input=(input/10));
	cout<<myqueue.size()<<" ";
	while(!myqueue.empty())
	{	
		cout<<myqueue.front();
		myqueue.pop();
	}
	cout<<endl;
}
int main(void)
{
	int input;
	cin>>input;
	CountDidit(input);
	return 0;
}
