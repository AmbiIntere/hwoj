#include<stdio.h>
int main(void)
{
	int input,temp;
	int count=0,a[5]={0},t=5;
	scanf("%d",&input);
	do
	{
		++count;
		a[--t]=input%10;
		input=input/10;
	}while(input);
	printf("%d\t",count);
	t=5;
	temp=t-count;
	for(;t>temp;)
		printf("%d",a[--t]);
	printf("\n");
	return 0;
}
