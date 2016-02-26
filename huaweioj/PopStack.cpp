#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void swap(char* a,char* b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
bool ispopstack(string s)
{
	int length=s.length();
	char max=s[0];
	for(int i=0;i<length-1;++i)
	{
		int flag=0;
		int tag=0;
		for(int k=i+1;k<length;++k)
		{
			if(s[i]>s[k])
			{
				if(tag==0)
					max=s[k];
				tag=1;
				if(max<s[k])
					return false;
			}
		}
	}
	return true;
}
void perm(string str,int m,int n)
{
	if(m<n)
	{
		for(int i=m;i<=n;++i)
		{
			if(i!=m)
				swap(&str[m],&str[i]);
			perm(str,m+1,n);
		}
	}
	else
	{
		if(ispopstack(str))
		{
			for(int i=0;i<str.length()-1;++i)
				cout<<str[i]<<" ";
			cout<<str[str.length()-1]<<endl;
		}
	}	
}
void sort(string s,int left,int right)
{
	if(left<right)
	{
		char temp=s[left];
		int i=left;
		int j=right;
		while(i<j)
		{
			while(i<j&&s[j]>temp)
				j--;
			s[i]=s[j];
			while(i<j&&s[i]<temp)
				i++;
			s[j]=s[i];
		}
		s[i]=temp;
		sort(s,left,i-1);
		sort(s,i+1,right);
	}
	cout<<s<<endl;
}
int main(void)
{
	int n;
	while(cin>>n)
	{
		string s="";
		string input;
		if(n<=0)
			continue;
		cin.get();
		getline(cin,input);
		if(input.length()==0)
			continue;
		for(int i=0;i<input.length();++i)
			if(input[i]!=' ')
				s+=input[i];
		sort(s,0,s.length()-1);
		perm(s,0,n-1);
	}
	return 0;	 
}
