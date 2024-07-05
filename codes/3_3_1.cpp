#include <iostream>
using namespace std;
#define MaxSize 10
bool bracketCheck(char str[], int length)
{
	char data[MaxSize]={0};
	int top=-1;
	for(int i=0;i<length;i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')	
			data[++top] = str[i];
		else
		{
			if(top<0) return false;
			char topElem = data[top];
			if(str[i]==')' && topElem!='(')
				return false;
			if(str[i]==']' && topElem!='[')
				return false;
			if(str[i]=='}' && topElem!='{')
				return false;
			top--;
		}
	}
	return top==-1;
}

int main()
{
	char str[]={'(', '(', ')','(', ')', ')'};
	int len=sizeof(str) / sizeof(char);
	if(bracketCheck(str, len))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
