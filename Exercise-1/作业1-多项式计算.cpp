#include <iostream>
using namespace std;
struct polynode
{
	double coef;
	int exp;
	polynode* link;
} ;
typedef polynode* polypointer;

int Compare(int i, int j)
{
	if( i < j )
		return '<';
	else if( i > j)
		return '>';
	else if( i == j) 
		return '=';
	else
		cout << " 比较出错" << endl;
		return 0;
}

polypointer Attach(int c, int e,polypointer d)  //建立一个新结点，系数coef=c,指数exp=e,把它链接到d所指结点之后，并返回一个新结点的指针。 
{
	polypointer x;
	x = new polynode;
	x->coef = c;
	x->exp = e;
	d->link = x;
	return x; 
}

polypointer CreatPoly()
{
	int c,e;
	polypointer Poly_head = new polynode;			//此处一定要new！！！！ 
	polypointer newPoly = new polynode;
	newPoly = Poly_head;
	cout << " 请分别输入系数和指数（输入-1结束）：" ;
	cin >> c >> e; 
	while(c != -1)
	{
		newPoly = Attach(c, e, newPoly);
		cout << " 请分别输入系数和指数（输入-1结束）：" ;
		cin >> c >> e;
	}
	newPoly->link = NULL;
	newPoly = Poly_head;
	Poly_head = Poly_head->link;
	delete newPoly;				//清理临时结点    指针在栈里   数据在堆里 
	newPoly = NULL;				//回收指针
	return Poly_head;
}

void Print(polypointer p)		//打印 
{
	polypointer q;
	q = p;
	while(q != NULL) 
	{
		if(q->coef == 0)
			q = q->link;
		else
		{
			cout << q->coef << "x^" << q->exp;
			if(q->link != NULL && q->link->coef != 0)
				cout << "+";
			q = q->link;
		}
	}
	cout << endl;
	q = NULL;					//清理临时指针 
}

polypointer PolyAdd(polypointer a,polypointer b)	//把多项式a和多项式b相加，结果为多项式c。使用Attach()来添加结点 
{
	polypointer p,q,d,c;
	int x;
	p = a;
	q = b;
	c = new polynode;
	d = c;
	while(( p != NULL) && ( q != NULL) )
	{
		switch( Compare( p->exp,q->exp)) 
		{
			case '=':
				x = p->coef + q->coef;
				if(x != 0)								//因为可能有负系数的存在，所以相加后也可能为零 
					d = Attach(x,p->exp,d);				//将新结点加入
				p = p->link;
				q = q->link;
				break;
			case '>':
				d = Attach( p->coef, p->exp, d);		//复制p所指结点并链入c中
				p = p->link;
				break;
			case '<':
				d = Attach( q->coef, q->exp, d);		//复制q所指结点并链入c中 
				q = q->link;							//q前进一步
				break; 
			default:
				cout << "ERROR" << endl;
		}
	}
	while( p!=NULL )
	{
		//cout << " 我运行了0x01" << endl;
		d = Attach( p->coef, p->exp, d);
		p = p->link;
	}
	while( q!=NULL )
	{
		//cout << " 我运行了0x02" << endl;
		d = Attach( q->coef, q->exp, d);
		q = q->link;
	}
	d->link = NULL;					//把最后结点指向空 
	p = c; c = c->link; delete p;	//删除临时结点
	return c; 
}

/*
	遇到的一个问题是，如何处理新建的头结点. 
*/
polypointer PolyMul(polypointer a, polypointer b)
{
	polypointer aa,bb;
	aa = a; bb = b;
	polypointer newPoly = new polynode;
	newPoly->coef=0;newPoly->exp=0;		//初始化存放结果的链表的头结点 
	newPoly->link=NULL;					//这个初始化也很重要 
	polypointer newPoly_head = newPoly;
	polypointer temp = new polynode;
	while( aa!=NULL )
	{
		while( bb!=NULL )
		{
			temp->coef = aa->coef * bb->coef;
			temp->exp = aa->exp + bb->exp;
//			cout << temp->coef << " " << temp->exp << endl;
			polypointer pp = new polynode;
			pp = PolyAdd(newPoly,temp);
			newPoly = pp;
			delete pp;
			pp = NULL;
			bb = bb->link;
		}
		aa = aa->link;
		bb = b;
	}
	
	return newPoly;
}

int main()
{
	polypointer poly1;
	polypointer poly2;
	polypointer poly3;
	poly1 = CreatPoly();
	Print(poly1);
	poly2 = CreatPoly();
	Print(poly2);
	//poly3 = PolyAdd(poly1,poly2);
	//Print(poly3);
	polypointer poly4;
	poly4 = PolyMul(poly1,poly2);
	Print(poly4);
}

