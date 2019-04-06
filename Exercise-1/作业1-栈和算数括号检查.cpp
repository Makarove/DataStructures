#include <iostream>
using namespace std;
#define MAXLENGTH 100
typedef int Elementtype ;
struct STACK {
	int top;			//topָ���������Ǹ�Ԫ�ص�λ�� 
	Elementtype elements [MAXLENGTH];
};

typedef enum {
	FALSE,
	TRUE,
}boolean;

void MakeNull(STACK &S)							//��ջS�ÿ� 
{
	S.top = MAXLENGTH;
}

boolean isEmpty(STACK S)						//�ж�ջ�Ƿ�Ϊ��  
{
	if(S.top > MAXLENGTH-1)
		return TRUE;
	else
		return FALSE;
}

Elementtype Top(STACK S)					//����ջ��Ԫ�� 
{
	if(isEmpty(S))
		return 0;
	else
		return (S.elements[S.top]);
}

void Pop(STACK &S) 							//ɾ��ջ��Ԫ�أ�����������ɾ����ֻ��ָ�����һ�� 
{
	if(isEmpty(S))
	{
		cout << "ERROR:IS EMPTY" << endl; 
		return;
	}
	else
		S.top = S.top + 1;
} 

void Push(Elementtype x, STACK &S)			//��ջ 
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
	S.top = MAXLENGTH;				//�����ʼ��ʱtopӦ������MAXLENGTH����MAXLENGTH-1ֵ���ƾ� 
}

//void Print(STACK S)					//��ӡЧ����֤Ϊ��������ǰ���Ƚ�����ں� 
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
			switch(*s)										//��������ASCII���ж�ƥ�䣬����()֮�����1����{}��[]֮��ȴ���2��������
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
			cout << " ������Ч�ַ���" << endl;
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

void Convert(int num, STACK &S, int n)		//��ʮ������ת��Ϊn���� 
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
			cout << "��Ч����" << endl;
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
		else											//�����ж�Ϊ����Ӧ16���Ƶ���� 
		{
			cout << (char)(S.elements[i]) << ' '; 		//ʹ��ǿ��ת�� 
		}
	}
	cout << endl;
}

int main()
{
	cout << "**************���²���ջ��������******************" << endl;
	STACK s;
	InitStack(s);
	Push(3,s);
	Push(4,s);
	Push(5,s);
	Push(6,s);
	Pop(s); 
	Print(s);
	cout << "**********************���Խ���********************" << endl;
	cout << endl; 
	cout << "**************���²�������ƥ�书��****************" << endl;
	char len[] = "{[()]}";
	char* p=len;
	while(*p!='\0')
	{
		cout << *p << ' ';
		p++;
	} 
	cout << endl;
	if(Check(len))
		cout << " ƥ��" << endl;
	else
		cout << " ��ƥ��" << endl; 
	char len2[] = "{{{]]";
	p = len2;
	while(*p!='\0')
	{
		cout << *p << ' ';
		p++;
	} 
	cout << endl;
	
	if(Check(len2))
		cout << " ƥ��" << endl;
	else
		cout << " ��ƥ��" << endl;
	cout << "**********************���Խ���********************" << endl;
	//cout << s.elements[MAXLENGTH-1];
	cout << endl;
	cout << "**************���²���n����ת������***************" << endl;
	STACK h;
	InitStack(h);
	Convert(15,h,8);
	Print(h);
	InitStack(h);
	Convert(45,h,16);
	Print(h);
}
