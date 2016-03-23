#include<iostream>
using namespace std;
int digitroot(int input)
{
	if(input<0)
		return -1;	
	if(input<10)
		return input;
	int sum=0;
	do{
		sum+=input%10;
	}while(input=input/10);
	digitroot(sum);
}
int main(void)
{
	int input;
	while(cin>>input)
		cout<<digitroot(input)<<endl;
	return 0;
}
