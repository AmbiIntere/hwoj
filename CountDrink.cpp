#include<iostream>
using namespace std;
void countdrink(int n)
{
	int result=0;
	if(n<2)
	{
		cout<<0<<endl;
		return;
	}
	while(n>=2)
	{
		if(n==2)
		{
			result+=1;
			n=0;
		}
		else
		{
			n=n-3;
			++result;
			n=n+1;
		}
	}
	cout<<result<<endl;
}
int main(void)
{
	int input;
	while(cin>>input)
	{
		if(input<=0)
			return 0;
		countdrink(input);
	}
	return 0;
}
