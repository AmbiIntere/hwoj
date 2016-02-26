#include<iostream>
#include<string>
using namespace std;
struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char x):val(x),left(NULL),right(NULL){}
};
void TreeRestore(string pre,string in,TreeNode*& result)
{
	int preindex=0;
	result=new TreeNode(pre[preindex]);
	int temp=in.find(pre[preindex]);
	int lnum=temp;
	int rnum=in.length()-temp-1;
	if(lnum!=0)
	TreeRestore(pre.substr(1,temp),in.substr(0,temp),result->left);
	if(rnum!=0)
	TreeRestore(pre.substr(temp+1),in.substr(temp+1),result->right);
	return;
}
void PostOrder(TreeNode* t,string* post)
{
	if(!t)
		return;
	PostOrder(t->left,post);
	PostOrder(t->right,post);
	*post+=t->val;
}
int main(void)
{
	string a,b;
	while(cin>>a>>b)
	{
		TreeNode* result;
		string post="";
		if(a.length()==0||b.length()==0)
			continue;
		TreeRestore(a,b,result);
		PostOrder(result,&post);
		cout<<post<<endl;
		
	}
	return 0;
}
