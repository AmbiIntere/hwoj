#include<iostream>
#include<string>
using namespace std;
struct treenode
{
	char val;
	treenode *left;
	treenode *right;
	treenode(char x):val(x),left(NULL),right(NULL){}
};
void createnode(treenode*& root,char a)
{
	treenode* node=new treenode(a);
	if(root==NULL)
	{
		root=node;
		return;
	}
	treenode* p=root;
	treenode* temp=NULL;
	while(p)
	{
		temp=p;
		if(a<p->val)
			p=p->left;
		else
			p=p->right;
	}
	if(a<temp->val)
		temp->left=node;
	else 
		temp->right=node;
}

treenode* createtree(string s)
{
	int len=s.length();
	treenode* root=NULL;
	if(len<=0)
		return root;
	for(int i=0;i<len;++i)
	{
		createnode(root,s[i]);
		
	}
	return root;
}
void traverse(treenode* t,string* result)
{
	if(!t)
		return;
	*result+=t->val;
	traverse(t->left,result);
	traverse(t->right,result);		
}
void issametree(string input,string a)
{
	treenode* inptree=createtree(input);
	treenode* atree=createtree(a);
	string inpresult="";
	string aresult="";
	traverse(inptree,&inpresult);
	traverse(atree,&aresult);
	if(inpresult==aresult)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
int main(void)
{
	int n;
	string input,test;
	while(cin>>n)
	{	
		if(n==0)
			break;
		cin>>input;
		while(n--)
		{
			cin>>test;
			issametree(input,test);
		}
	}
	return 0;
}
