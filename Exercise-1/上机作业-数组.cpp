#include <iostream>
#define maxlength 100
using namespace std;

struct LIST
{
	int data[maxlength];
	int last;
};
typedef int position;

position End(LIST L)
{
	return (L.last+1) ;
}

bool isEmpty(LIST L)
{
	return !L.data[1];     //如果元素1不为空，那么返回  !元素1 
}

void MakaNull(LIST &L)
{
	position i=1;
	for(i;i<=L.last;i++)
		L.data[i]=0; 
	L.last = 0 ;
}

void Insert(int data,position p, LIST &L)
{
	position q;
	if( L.last >= maxlength -1)
		cout << "ERROR:LIST IS FULL" << endl;
	else if( (p> L.last + 1) || (p < 1))
		cout << "Position does not exist" << endl;
	else
	{
		for ( q = L.last; q>=p; q--)
			L.data[q+1] = L.data[q];			//从最后到q ，元素往后一位 
		L.last = L.last + 1;	
		L.data[p] = data;
	}
}

void Delete(position p, LIST &L)
{
	position q;
	L.last--;
	for(q=p;q<=L.last;q++)
	{
		L.data[q] = L.data[q+1];   //last后面的都是空元素 
	}
}

position Locate(int x, LIST L)   //不用对实参进行修改，所以不用引用 
{
	position q;
	for(q=1;q<=L.last;q++)
	{
		if(L.data[q] == x)
			return q;
	}
	cout << " 数组不存在"<< endl;
	return 0;
}

position Previous(position p, LIST L)
{
	if(p<2 || p>L.last+1)
		cout << "Position does not exist" << endl;
	else if(isEmpty(L))
		return End(L);
	else
		return L.data[p-1];
}

position Next(position p, LIST L)
{
	if(p<1 || p>L.last)
		cout << "Position does not exist" << endl;
	else if(isEmpty(L))
		return End(L);
	else
		return L.data[p+1];
}

position First(LIST L)
{
	if(isEmpty(L))
		return End(L);
	else
		return 1;
}

int Retrieve(position p, LIST L)	//返回L中位置为P的元素 
{
	if(p<1||p>=L.last)
	{
		cout << "This position does not exist" << endl;
		return 0;
	}
	else
		return L.data[p];
}

void Print(LIST L)
{
	for(int i=1;i < L.last; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;	
}

struct LIST MergeList(LIST L1, LIST L2)
{
	struct LIST L3 ;
	L3.last = L1.last+L2.last-1;
	int i = 1,h = 1, len = 1;
	while(i<L1.last && h<L2.last)
	{
		if(L1.data[i]<L2.data[h])
		{
			L3.data[len] = L1.data[i];
			i++;
			len++;
		}
		else
		{
			L3.data[len] = L2.data[h];
			len++;
			h++;
		}
	}
	while(i < L1.last)
	{
		L3.data[len] = L1.data[i];
		i++;
		len++;
	}
	while(h < L2.last)
	{
		L3.data[len] = L2.data[h];
		h++;
		len++;
	}
	return L3;
}

int main(){
	struct LIST myList1 = {{0,1,2,3,4,5},6};
	struct LIST myList2 = {{0,2,4,6,7,8,10},7};
	struct LIST myList3 = {{0},0}; 
	myList3 = MergeList(myList1,myList2);
	Print(myList3);
} 


