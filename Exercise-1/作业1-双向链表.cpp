#include <iostream>
using namespace std;
typedef int Elementtype;

/*	
	实现双向链表的型和指定结点的交换 
	有头结点的双向链表 
*/
struct celltype{
	Elementtype element;
	celltype* next;
	celltype* previous;
};
typedef celltype* position;
typedef celltype* DLIST;

position End(DLIST H)					//返回链表最后一个元素的位置 
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

void InitDlist(DLIST &H)			//初始化一个链表 
{
	position temp;
	temp = First(H);
	temp -> element = -1;
	temp -> previous = NULL;
	temp -> next = NULL;
}

void Insert(Elementtype x, position p)	//在位置p后添加一个结点 
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
		cout << " 空链表" << endl;
		return;
	}
	//H = H->next;						//跳过表头结点 
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
	temp = H;								//temp指向头结点 
	while(temp->next != NULL )
	{
		if(temp->next->element == x)		//找到第一个元素为x的结点，退出循环 
		{
			break;
		}
		else
		{	
			temp = temp->next;
		}
	}
	if(temp->next==NULL)					//有两种可能退出循环，一种是找到元素x的结点，一种是未找到，下一个为空。 
		return 0;
	temp = temp->next;
	position before = temp->previous;		//temp前一个被交换到后面的结点的指针before 
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
	cout << " 请输入你要寻找的元素:";			//设定用户交互界面 
	cin >> x;  
	if(Swap(x,list1))
		Print(list1);		
	else
		cout << " 未找到" << endl;

}

