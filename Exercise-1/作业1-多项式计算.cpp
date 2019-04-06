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
		cout << " �Ƚϳ���" << endl;
		return 0;
}

polypointer Attach(int c, int e,polypointer d)  //����һ���½�㣬ϵ��coef=c,ָ��exp=e,�������ӵ�d��ָ���֮�󣬲�����һ���½���ָ�롣 
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
	polypointer Poly_head = new polynode;			//�˴�һ��Ҫnew�������� 
	polypointer newPoly = new polynode;
	newPoly = Poly_head;
	cout << " ��ֱ�����ϵ����ָ��������-1��������" ;
	cin >> c >> e; 
	while(c != -1)
	{
		newPoly = Attach(c, e, newPoly);
		cout << " ��ֱ�����ϵ����ָ��������-1��������" ;
		cin >> c >> e;
	}
	newPoly->link = NULL;
	newPoly = Poly_head;
	Poly_head = Poly_head->link;
	delete newPoly;				//������ʱ���    ָ����ջ��   �����ڶ��� 
	newPoly = NULL;				//����ָ��
	return Poly_head;
}

void Print(polypointer p)		//��ӡ 
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
	q = NULL;					//������ʱָ�� 
}

polypointer PolyAdd(polypointer a,polypointer b)	//�Ѷ���ʽa�Ͷ���ʽb��ӣ����Ϊ����ʽc��ʹ��Attach()����ӽ�� 
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
				if(x != 0)								//��Ϊ�����и�ϵ���Ĵ��ڣ�������Ӻ�Ҳ����Ϊ�� 
					d = Attach(x,p->exp,d);				//���½�����
				p = p->link;
				q = q->link;
				break;
			case '>':
				d = Attach( p->coef, p->exp, d);		//����p��ָ��㲢����c��
				p = p->link;
				break;
			case '<':
				d = Attach( q->coef, q->exp, d);		//����q��ָ��㲢����c�� 
				q = q->link;							//qǰ��һ��
				break; 
			default:
				cout << "ERROR" << endl;
		}
	}
	while( p!=NULL )
	{
		//cout << " ��������0x01" << endl;
		d = Attach( p->coef, p->exp, d);
		p = p->link;
	}
	while( q!=NULL )
	{
		//cout << " ��������0x02" << endl;
		d = Attach( q->coef, q->exp, d);
		q = q->link;
	}
	d->link = NULL;					//�������ָ��� 
	p = c; c = c->link; delete p;	//ɾ����ʱ���
	return c; 
}

/*
	������һ�������ǣ���δ����½���ͷ���. 
*/
polypointer PolyMul(polypointer a, polypointer b)
{
	polypointer aa,bb;
	aa = a; bb = b;
	polypointer newPoly = new polynode;
	newPoly->coef=0;newPoly->exp=0;		//��ʼ����Ž���������ͷ��� 
	newPoly->link=NULL;					//�����ʼ��Ҳ����Ҫ 
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

