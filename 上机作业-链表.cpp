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

void Insert(elementtype x, position p)		//������ 
{
	position temp;
	temp = p->Next;
	p->Next = new LISTNODE;
	p->Next->Value = x;
	p->Next->Next = temp;
}

void MakeList(list &L)  //����һ������ͷ������ 
{
	elementtype value_user;
	struct LISTNODE* L_head = L;
	L_head->Value = NULL;
	L_head->Next = NULL;
	cout << " ����������ֵ(����-1������)��";
	cin >> value_user;
	while(value_user != -1)
	{
		Insert(value_user,L);
		L = L->Next;
		cout << " ����������ֵ(����-1������)��";
		cin >> value_user;			//��cin�ŵ���󣬷�ֹ��-1���� 
	}
	L = L_head;			//ָ��ع鵽��ͷ 
}

void Delete(position p)		//ɾ��������ĳ��� 
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
	q=NULL;		//�ƿ�ָ��q�����ΪҰָ��  
}

position Locate(elementtype x, list L)	//���������ҵ�Ԫ��x��������λ�� 
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
	return 0;  //���û�ҵ������ؿ� 
} 

position Locate2(elementtype x, list L)  //�ڶ��������ҵ�������Ԫ��x��λ�õ��㷨 
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

elementtype Retrieve(position p, list L)		//����������ĳλ�õ�ֵ 
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

void MakeNull(list &L)	//�ƿ����� 
{
	position p = L;
	while(p->Next!=NULL)
	{
		Delete(p);
	}
	delete p;
	p = NULL;
}

void Print(list L)		//��ӡ���� 
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

void ListCopy(list &L,list R)		//������R���Ƶ�L 
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
			L_backup->Next = L_backup->Next->Next;   //����Ͽ����� 
			delete p1;								//ɾ����� 
			p1 = NULL;								//ɾ��ָ�� 
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
