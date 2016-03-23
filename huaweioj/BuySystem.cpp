#include<stream>
#include<string>
using namespace std;
#define MAX 10
#define GoodNum 5

int initmoney;
int score;
typedef struct
{
	int goodID;
	int goodNums;
}Good;
void init()
{
	intmoney=3000;
	score=150;
	cout<<S001<<endl;
}
void order()
{
}
getparam(string input,&param1,&param2)
{
	
}
int main(void)
{
	while(1)
	{
		string input;
		getline(input);
		switch(input[0])
		{
			case 'r':
				init();
				break;
			case 'o':
				order();
				break;
			case 'c':
				cancel();
				break;
			case 'b':
				buy();
				break;
			case 'l'
				list();
				break;
			case 'e':
				return 0;
			default:
				break;
		}
	}
	return 0;
}
