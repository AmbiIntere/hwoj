#include<stdio.h>
#include<string.h>
void sort(int s[], int left, int right)
{
	if (left<right)
	{
		char temp = s[left];
		int i = left;
		int j = right;
		while (i<j)
		{
			while (i<j&&s[j]>=temp)
				j--;
			if (i<j)
				s[i] = s[j];
			while (i<j&&s[i]<=temp)
				i++;
			if (i<j)
				s[j] = s[i];
		}
		s[i] = temp;
		sort(s, left, i - 1);
		sort(s, i + 1, right);
	}
}
int main(void)
{
	int i;
	int a[4]={3,1,4,2};
	sort(a,0,4);
	for(i=0;i<4;++i)
		printf("%d ",a[i]);
	return 0;
}
