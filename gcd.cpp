#include<iostream>
using namespace std;
unsigned long gcd(unsigned long a,unsigned long b)
{	
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

int  main(void)
{
	unsigned long a,b;
	while(cin>>a>>b)
	{
		if(a<0||b<0)
			continue;
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}
