#include <iostream>
typedef int elementtype;
using namespace std;

struct LISTNODE {
	elementtype Value;
	LISTNODE* Next;
};
typedef LISTNODE* list;

typedef LISTNODE* position; 



position End(list L)
{
	position q;
	q = L;
	while( q-> Next != NULL)
	{
		q = q->Next;
	}
	return q;
}

void Insert(elementtype x, position p)		//插入结点 
{
	position temp;
	temp = p->Next;
	p->Next = new LISTNODE;
	p->Next->Value = x;
	p->Next->Next = temp;
}

void MakeList(list &L)  //创建一个带表头的链表 
{
	elementtype value_user;
	struct LISTNODE* L_head = L;
	L_head->Value = NULL;
	L_head->Next = NULL;
	cout << " 请输入存入的值(输入-1来结束)：";
	cin >> value_user;
	while(value_user != -1)
	{
		Insert(value_user,L);
		L = L->Next;
		cout << " 请输入存入的值(输入-1来结束)：";
		cin >> value_user;			//将cin放到最后，防止将-1存入 
	}
	L = L_head;			//指针回归到表头 
}

void Delete(position p)		//删除链表中某结点 
{
	position q;
	if(p->Next != NULL)
	{
		q = p->Next;
		p->Next = p->Next->Next;
		delete q;
	}
	else
	{
		cout << "Error,invalid position!" << endl;
	}
	q=NULL;		//制空指针q避免成为野指针  
}

position Locate(elementtype x, list L)	//在链表中找到元素x，并返回位置 
{
	position p;
	p = L;
	if(p->Value == x)
		return p;
	while(p->Next!=NULL)
	{
		if(p->Next->Value == x)
			return p;
		else
			p = p->Next;
	}
	return 0;  //如果没找到，返回空 
} 

position Locate2(elementtype x, list L)  //第二个可以找到链表中元素x的位置的算法 
{
	
	while(L->Next->Value != x && L->Next != NULL)
	{
		L = L->Next;
	}
	if(L->Next == NULL)
		return 0;
	else
		return L;
}

elementtype Retrieve(position p, list L)		//返回链表中某位置的值 
{
	if(L == p)
		return L->Value;
		 
	while(L->Next != NULL)
	{
		if(L->Next == p)
		 	return L->Next->Value;
		else
			L = L->Next;
	} 
}

void MakeNull(list &L)	//制空链表 
{
	position p = L;
	while(p->Next!=NULL)
	{
		Delete(p);
	}
	delete p;
	p = NULL;
}

void Print(list L)		//打印链表 
{
	if(L->Value == NULL)
	{
		L = L->Next;
	}
	while(L->Next!=NULL)
	{
		 cout << L->Value << " ";
		 L = L->Next;
	}
	cout << L->Value << endl; 
	cout << "Print Over!"<< endl;
}

void ListCopy(list &L,list R)		//将链表R复制到L 
{
	list L_head = L;
	while(R!=NULL)
	{
		Insert(R->Value,L);
		L = L->Next;
		R = R->Next;
	}
	L = L_head->Next;
}

list MergeList(list L,list R)
{
	list T = new LISTNODE;
	position T_head = new LISTNODE;
	T_head = T;
	while(L != NULL && R != NULL)
	{
		if(L->Value <= R->Value)
		{
			Insert(L->Value,T);
			L = L->Next;
			T = T->Next; 
		}
		else
		{
			Insert(R->Value,T);
			R = R->Next;
			T = T->Next;
		}
	}
	
	if(R != NULL)
	{
		T->Next = R; 
	}
	else
	{
		T->Next = L; 
	}
	return (T_head = T_head->Next);
}

elementtype DeleteVal(list &L, elementtype x)
{
	struct LISTNODE* L_backup = new LISTNODE;
	L_backup = L;
	int key = 0 ;
	while(L_backup->Next != NULL)
	{
		if(L_backup->Next->Value == x)
		{
			position p1 = L_backup;
			L_backup->Next = L_backup->Next->Next;   //与结点断开连接 
			delete p1;								//删除结点 
			p1 = NULL;								//删除指针 
			key++;
			return key;
		}
		else
		{
			L_backup = L_backup->Next;
			key++;
		}
	}
	if(L_backup->Value == x)
	{
		delete L_backup;
		L_backup == NULL;
	}
	else
	{
		return -1;
	}
}

int main()
{
	struct LISTNODE* myList1 = new LISTNODE;
	struct LISTNODE* myList2 = new LISTNODE;
	myList1->Value=1;
	myList1->Next=NULL;
	Insert(3,End(myList1));
	Insert(5,End(myList1));
	Insert(7,End(myList1));
	Insert(9,End(myList1));
	myList2->Value=2;
	myList2->Next=NULL;
	Insert(4,End(myList2));
	Insert(5,End(myList2));
	Insert(6,End(myList2));
	Insert(7,End(myList2));
	Print(myList1);
	Print(myList2);
	list final = MergeList(myList1,myList2);
	Print(final); 
	list copylist = new LISTNODE;
	ListCopy(copylist,myList1);
	Print(copylist);
	list newlist = new LISTNODE;
	MakeList(newlist);
	Print(newlist);
	cout << DeleteVal(newlist,5) << endl;
	Print(newlist);
}
