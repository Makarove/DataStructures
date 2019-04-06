#include <iostream>
using namespace std;
#define MAXLENGTH 100
typedef int Elementtype ;
struct STACK {
	int top;			//top指向最后进的那个元素的位置 
	Elementtype elements [MAXLENGTH];
};

typedef enum {
	FALSE,
	TRUE,
}boolean;

void MakeNull(STACK &S)							//将栈S置空 
{
	S.top = MAXLENGTH;
}

boolean isEmpty(STACK S)						//判断栈是否为空  
{
	if(S.top > MAXLENGTH-1)
		return TRUE;
	else
		return FALSE;
}

Elementtype Top(STACK S)					//返回栈顶元素 
{
	if(isEmpty(S))
		return 0;
	else
		return (S.elements[S.top]);
}

void Pop(STACK &S) 							//删除栈顶元素（并不是真正删除，只是指针回退一格 
{
	if(isEmpty(S))
	{
		cout << "ERROR:IS EMPTY" << endl; 
		return;
	}
	else
		S.top = S.top + 1;
} 

void Push(Elementtype x, STACK &S)			//入栈 
{
	if(S.top == 0)
	{
		cout << "ERROR:STACK IS FULL" << endl;
		return;
	} 
	else
	{
		S.top = S.top - 1;
		S.elements[S.top] = x;
	}
} 

void InitStack(STACK &S)
{
	S.top = MAXLENGTH;				//这里初始化时top应当等于MAXLENGTH还是MAXLENGTH-1值得推究 
}

//void Print(STACK S)					//打印效果保证为后进入的在前，先进入的在后 
//{
//	for(int i=S.top;i<=MAXLENGTH-1;i++)
//	{
//		cout << S.elements[i] << ' ';
//	}
//	cout << endl;
//}

boolean Check(char *s)
{
	STACK M;
	InitStack(M);
	while(*s != '\0')
	{
		if(*s=='(' || *s=='[' || *s=='{')
		{
			Push(*s,M);
		}
		else if(*s==')' || *s==']' || *s=='}')
		{
			switch(*s)										//本来想用ASCII码判断匹配，但是()之间相差1，而{}、[]之间却相差2，遂作罢
			{
				case ')':
					if(Top(M)=='(')
						Pop(M);
					break;
				case ']':
					if(Top(M)=='[')
						Pop(M);
					break;
				case '}':
					if(Top(M)=='{')
						Pop(M);
					break;
			}
		}
		else
		{
			cout << " 包含无效字符！" << endl;
			return FALSE; 
		}
		s++;
	}
//	if(isEmpty(M))
//		return TRUE;
//	else
//		return FALSE;
	return isEmpty(M);
}

void Convert(int num, STACK &S, int n)		//将十进制数转换为n进制 
{
	switch(n)
	{
		case 2:
			while(num != 0)
			{
				int temp;
				temp = num%2;
				Push(temp,S);
				num = num/2;
			}
			
			break;
		case 8:
			while(num != 0)
			{
				int temp;
				temp = num%8;
				Push(temp,S);
				num = num/8;
			} 
			break;
		case 16:
			while(num != 0)
			{
				int temp;
				temp = num%16;
				if(temp>=10)
				{
					int x = temp - 10;
					char c = 'A'+x;
					Push(c,S) ;
				} 
				else
				{
					Push(temp,S);
				}
				num = num/16;
			}
			break;
		default:
			cout << "无效进制" << endl;
	}
}

void Print(STACK S)
{
	for(int i=S.top;i<=MAXLENGTH-1;i++)
	{
		if(S.elements[i]<=9)
		{
			cout << S.elements[i] << ' ';
		}
		else											//该行判断为了适应16进制的输出 
		{
			cout << (char)(S.elements[i]) << ' '; 		//使用强制转换 
		}
	}
	cout << endl;
}

int main()
{
	cout << "**************以下测试栈基本功能******************" << endl;
	STACK s;
	InitStack(s);
	Push(3,s);
	Push(4,s);
	Push(5,s);
	Push(6,s);
	Pop(s); 
	Print(s);
	cout << "**********************测试结束********************" << endl;
	cout << endl; 
	cout << "**************以下测试括号匹配功能****************" << endl;
	char len[] = "{[()]}";
	char* p=len;
	while(*p!='\0')
	{
		cout << *p << ' ';
		p++;
	} 
	cout << endl;
	if(Check(len))
		cout << " 匹配" << endl;
	else
		cout << " 不匹配" << endl; 
	char len2[] = "{{{]]";
	p = len2;
	while(*p!='\0')
	{
		cout << *p << ' ';
		p++;
	} 
	cout << endl;
	
	if(Check(len2))
		cout << " 匹配" << endl;
	else
		cout << " 不匹配" << endl;
	cout << "**********************测试结束********************" << endl;
	//cout << s.elements[MAXLENGTH-1];
	cout << endl;
	cout << "**************以下测试n进制转换功能***************" << endl;
	STACK h;
	InitStack(h);
	Convert(15,h,8);
	Print(h);
	InitStack(h);
	Convert(45,h,16);
	Print(h);
}
