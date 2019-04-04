#include <iostream>
using namespace std;
typedef int Elementtype;

/*	
	ʵ��˫��������ͺ�ָ�����Ľ��� 
	��ͷ����˫������ 
*/
struct celltype{
	Elementtype element;
	celltype* next;
	celltype* previous;
};
typedef celltype* position;
typedef celltype* DLIST;

position End(DLIST H)					//�����������һ��Ԫ�ص�λ�� 
{
	position q;
	q = H;
	while(q->next != NULL)
	{
		q = q->next;
	}
	return q;
}

position First(DLIST H)
{
	position first;
	first = H;
	while(first->previous != NULL)
	{
		first = first->previous; 
	}
	return first;
} 

void InitDlist(DLIST &H)			//��ʼ��һ������ 
{
	position temp;
	temp = First(H);
	temp -> element = -1;
	temp -> previous = NULL;
	temp -> next = NULL;
}

void Insert(Elementtype x, position p)	//��λ��p�����һ����� 
{
	position temp = new celltype;
	temp -> previous = p;
	temp -> next = p->next;
	if(p->next != NULL)
		p -> next ->previous = temp;
	p -> next = temp;
	
	temp->element = x;
	return;
}

void Delete(position p)
{
	if(p->previous != NULL)
	{
		p->previous->next = p->next;
	}
	if( p->next != NULL)
	{
		p->next->previous = p->previous;
	}
}

void Print(DLIST H)
{
	if(H->next == NULL)
	{
		cout << " ������" << endl;
		return;
	}
	//H = H->next;						//������ͷ��� 
	while(H->next!=NULL)
	{
		 cout << H->next->element << " ";
		 H = H->next;
	}
	//cout << H->element << endl; 
	cout << "Print Over!"<< endl;
} 

int Swap(Elementtype x, DLIST &H)
{
	position temp = new celltype;
	position H_head = new celltype;
	temp = H;								//tempָ��ͷ��� 
	while(temp->next != NULL )
	{
		if(temp->next->element == x)		//�ҵ���һ��Ԫ��Ϊx�Ľ�㣬�˳�ѭ�� 
		{
			break;
		}
		else
		{	
			temp = temp->next;
		}
	}
	if(temp->next==NULL)					//�����ֿ����˳�ѭ����һ�����ҵ�Ԫ��x�Ľ�㣬һ����δ�ҵ�����һ��Ϊ�ա� 
		return 0;
	temp = temp->next;
	position before = temp->previous;		//tempǰһ��������������Ľ���ָ��before 
	position after = temp->next;			
	temp->previous = before->previous;
	temp->next = before;
	before->previous->next = temp;
	before->previous = temp;
	before->next = after;
	after->previous = before;
	return 1;
} 

int main()
{
	DLIST list1 = new celltype;
	InitDlist(list1);
	//cout << list1->element;
	Insert(3,list1);
	Insert(4,End(list1));
	Insert(5,End(list1));
	Insert(6,End(list1));
	Insert(7,End(list1));
	//cout << list1->element;
	Print(list1);
	int x;
	cout << " ��������ҪѰ�ҵ�Ԫ��:";			//�趨�û��������� 
	cin >> x;  
	if(Swap(x,list1))
		Print(list1);		
	else
		cout << " δ�ҵ�" << endl;

}

