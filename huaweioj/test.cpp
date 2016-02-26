#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
string a;
 while(cin>>a)
{
 for(int i=0;i<a.length();i++)
 cout<<a[i]<<endl;
 sort(a,a+a.length()-1,greater<char>());
 for(int i=0;i<a.length();i++)
 cout<<a[i]<<endl;
}
 return 0;
}
