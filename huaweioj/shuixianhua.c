#include<stdio.h>

int main(void)
{
	int a,k,n,input;
	int m=0,t=1;
	scanf("%d",&input);
	n=input;
	while(n=n/10)
		++t;
	k=t;
	n=input;
	while(k--){
		a=n%10;
		n=n/10;
		while(--t)
			a*=a;
		m=m+a;
	}
	if(input==m)
                printf("%d\n",input);
                  
        return 0;
}
	
