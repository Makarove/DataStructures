#include <iostream>
#define MAXSIZE 200
using namespace std;
typedef int elementtype;
typedef struct {
	elementtype data;
	int cur;
}SPACE;
SPACE spacestr[MAXSIZE];
typedef int position,cursor;
cursor available;

void Initialize()	//初始化，将所有存储池中的结点设置为空闲 
{
	int i = 0;
	for(i;i<MAXSIZE-1;i++)
	{
		spacestr[i].data = 0;
		spacestr[i].cur = i+1;
	}
	spacestr[i].cur = -1;
	available = 0;	//空闲结点的头结点 
}

cursor GetNode()	//从空闲链中获取一个结点  返回的是被取出的这个结点的下标 
{
	cursor p;
	if(spacestr[available].cur==-1)
		return -1;
	else
	{
		p = spacestr[available].cur;
		spacestr[available].cur = spacestr[p].cur;
	}
	return p;
}

void FreeNode(cursor q)		//将结点q加入到空闲链中   将该游标指向的结点放入空闲池 
{
	spacestr[q].cur = spacestr[available].cur;		//把结点q插入了空闲链表首    
	spacestr[available].cur = q;					//该操作应该在delete之后使用 
}


void Delete(position p)	//在链表M中删除位置为p的元素的后一个元素 
{
	position q;
	if(spacestr[p].cur != -1)
	{
		q = spacestr[p].cur;			//q为后一个元素的下标 
		spacestr[p].cur = spacestr[q].cur;		//p的游标指向后一个元素所指向的结点 
		spacestr[q].data = 0;			//将后一个元素数据清空
		FreeNode(q);					//将后一个元素放入空闲链表 
	}
}

cursor CreatList()
{
	elementtype x;
	cursor head,p,last;
	if(spacestr[available].cur != -1)		
	{
		head = GetNode();		//记录下新建链表头结点的下标 
		last = head;			//last记录链表末尾下标 
		cout << " 请依次输入链表的值(输入-1结束)：" ;
		cin >> x;
		spacestr[last].data = x;
		spacestr[last].cur = -1;
		cout << " 请依次输入链表的值(输入-1结束)：" ;
		cin >> x;
		while(x != -1)
		{
			p=GetNode();
			if(p==-1)		//判断是否成功取得空闲结点 
				break;
			spacestr[last].cur = p;
			spacestr[p].data = x;
			spacestr[p].cur = -1;
			last = p;
			cout << " 请依次输入链表的值(输入-1结束)：" ;
			cin >> x;
		}
		return head;		//最终返回头结点下标 
	}
	else
	{
		cout << " 存储池已满，无法新建链表" << endl;
		return -1;
	}
}

void Insert(elementtype x,position p)		//在链表M中的位置为p的元素后面添加一个值为x的结点 
{
	cursor q;
	q = GetNode();		//取出一个空闲结点
	if(q == -1) 
		cout << " 存储池已满，无空闲结点" <<endl;
	else
	{
		spacestr[q].data = x;
		spacestr[q].cur = spacestr[p].cur;
		spacestr[p].cur = q;
	}
}

void Merge(cursor M, cursor N)	//合并两个静态链表
{
	int i=M;
	while(spacestr[i].cur != -1)
	{
		i = spacestr[i].cur;
	}
	spacestr[i].cur = N;
}

void Print(cursor p)
{
	cursor q = p;
	if(q == -1)
	{
		cout << " 打印失败" << endl;
		return;
	}
	while(spacestr[q].cur != -1)
	{
		cout << spacestr[q].data << " ";
		q = spacestr[q].cur;
	}
	cout << spacestr[q].data;
	return;
}

int main()
{
	Initialize();
	cursor list1 = CreatList();
	Print(list1);
	cout << endl;
	cursor list2 = CreatList();
	Print(list2);
	Merge(list1,list2);
	cout << endl; 
	Print(list1);
}



