#include<iostream>
#include<string>
#include<vector>
using namespace std;
void moveNum(string str,int *x,int *y)
{
	if(str[0]!='A'&&str[0]!='D'&&str[0]!='W'&&str[0]!='S')
		return;
	int len=str.length();
	int movenum=0;
	for(int i=1;i<len;++i)
	{
		if(str[i]<'0'||str[i]>'9')
			return;
		movenum=movenum*10+(str[i]-'0');
	}
	if(str[0]=='A')
                *x-=movenum;
        else if(str[0]=='D')
                *x+=movenum;
        else if(str[0]=='W')
                *y+=movenum;
        else if(str[0]=='S')
                *y-=movenum;
}
void pointMove(string str,int *x,int *y)
{
	int start=0;
	int end=str.find(";");
	vector<string> vec;
	while(end!=-1)
	{
		vec.push_back(str.substr(start,end-start));
		start=end+1;
		end=str.find(";",start);	
	}
	int count=vec.size();
	for(int i=0;i<count;++i)
	{
		if(vec[i].length()<2||vec[i].length()>3)
			continue;
		moveNum(vec[i],x,y);
	}
	
}
int main(void)
{
	string input;
	while(getline(cin,input))
	{
		if(input.length()==0)
			continue;
		int x=0;
		int y=0;
		pointMove(input,&x,&y);
		cout<<x<<","<<y<<endl;
	}
	return 0;
}
