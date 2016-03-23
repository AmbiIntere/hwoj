#include<iostream>

using namespace std;

int intSplit[1000000];
int split(int n)
{
	if(n<1||n>1000000)
		return -1;
	intSplit[1]=1;
	intSplit[2]=2;
	for(int i=3;i<=n;++i)
	{
		if(i%2)
		{
			intSplit[i]=intSplit[i-1];
		}
		else
		{
			intSplit[i]=(intSplit[i-2]+intSplit[i/2])%1000000000;
		}
	}
	return intSplit[n];
}
int main(void)
{
	int input;
	while(cin>>input)
	{
		cout<<split(input)<<endl;
	}
	return 0;
}
