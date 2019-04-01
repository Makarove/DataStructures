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

void Initialize()	//��ʼ���������д洢���еĽ������Ϊ���� 
{
	int i = 0;
	for(i;i<MAXSIZE-1;i++)
	{
		spacestr[i].data = 0;
		spacestr[i].cur = i+1;
	}
	spacestr[i].cur = -1;
	available = 0;	//���н���ͷ��� 
}

cursor GetNode()	//�ӿ������л�ȡһ�����  ���ص��Ǳ�ȡ������������±� 
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

void FreeNode(cursor q)		//�����q���뵽��������   �����α�ָ��Ľ�������г� 
{
	spacestr[q].cur = spacestr[available].cur;		//�ѽ��q�����˿���������    
	spacestr[available].cur = q;					//�ò���Ӧ����delete֮��ʹ�� 
}


void Delete(position p)	//������M��ɾ��λ��Ϊp��Ԫ�صĺ�һ��Ԫ�� 
{
	position q;
	if(spacestr[p].cur != -1)
	{
		q = spacestr[p].cur;			//qΪ��һ��Ԫ�ص��±� 
		spacestr[p].cur = spacestr[q].cur;		//p���α�ָ���һ��Ԫ����ָ��Ľ�� 
		spacestr[q].data = 0;			//����һ��Ԫ���������
		FreeNode(q);					//����һ��Ԫ�ط���������� 
	}
}

cursor CreatList()
{
	elementtype x;
	cursor head,p,last;
	if(spacestr[available].cur != -1)		
	{
		head = GetNode();		//��¼���½�����ͷ�����±� 
		last = head;			//last��¼����ĩβ�±� 
		cout << " ���������������ֵ(����-1����)��" ;
		cin >> x;
		spacestr[last].data = x;
		spacestr[last].cur = -1;
		cout << " ���������������ֵ(����-1����)��" ;
		cin >> x;
		while(x != -1)
		{
			p=GetNode();
			if(p==-1)		//�ж��Ƿ�ɹ�ȡ�ÿ��н�� 
				break;
			spacestr[last].cur = p;
			spacestr[p].data = x;
			spacestr[p].cur = -1;
			last = p;
			cout << " ���������������ֵ(����-1����)��" ;
			cin >> x;
		}
		return head;		//���շ���ͷ����±� 
	}
	else
	{
		cout << " �洢���������޷��½�����" << endl;
		return -1;
	}
}

void Insert(elementtype x,position p)		//������M�е�λ��Ϊp��Ԫ�غ������һ��ֵΪx�Ľ�� 
{
	cursor q;
	q = GetNode();		//ȡ��һ�����н��
	if(q == -1) 
		cout << " �洢���������޿��н��" <<endl;
	else
	{
		spacestr[q].data = x;
		spacestr[q].cur = spacestr[p].cur;
		spacestr[p].cur = q;
	}
}

void Merge(cursor M, cursor N)	//�ϲ�������̬����
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
		cout << " ��ӡʧ��" << endl;
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



