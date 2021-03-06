### 一、写一个算法合并两个已排序的线性表。（用两种方法：数组表示的线性表（顺序表）和指针表示的线性表（链表））  
要求：  
1. 定义线性表节点的结构，并定义节点的型和位置的型。  
2. 定义线性表的基本操作  
3. 在1，2的基础上，完成本题。  
4. 在main函数中进行测试：先构建两个有序的线性表，然后合并这两个线性表。  

### 二、已知一个单向链表，试给出复制该链表的算法。   
要求：  
1. 定义线性表的节点的结构以及节点的型和位置的型。
2. 定义线性表的基本操作
3. 在1，2的基础上，完成本题。
4. 在main函数中进行测试：先构建一个线性表，并定义一个空线性表，然后进行复制。

三、写出从一个带表头的单链表中删除其值等于给定值x的结点的算法函数：
	int delete(LIST &L, int x);如果x在该链表中，则删除对应结点，并返回其在链表中的位置（逻辑位置，第一个结点的逻辑位置为1），否则返回-1。
	要求：1、定义线性表的节点的结构以及节点的型和位置的型。
2、定义线性表的基本操作
3、在1，2的基础上，完成本题。
4、在main函数中进行测试：先构建一个线性表，然后调用函数删除值等于给定值的节点。

四、写出一个将两个静态链表（属于同一个存储池）合并的算法函数：
     void Merge(cursor M, cursor N); 合并的方法是将N链表中的所有结点添加到M链表的后面，并将N链表的表头结点添加到空闲结点链表中。
要求：1、定义静态链表的结点的结构以及结点的型SPACE以及位置（position）和游标（cursor）的型。
	2、定义静态链表的基本操作：void Initialize(); 初始化，将所有存储池中的结点设置为空闲；cursor GetNode(); 从空闲链中获取一个结点；void FreeNode(cursor q); 将结点q加入到空闲链； void Insert ( elementtype x, position p, cursor M ); 在链表M中的位置为p的元素后面添加一个值为x的结点；void Delete (cursor M,  position p ); 在链表M中删除位置为p的元素的后一个元素。
	3、在1、2的基础上完成本题。
4、在main函数中进行测试：先构建一个存储池，然后在该存储池中创建两个静态表，最后将这两个静态表合并。

五、利用指针表示的线性表(链表)表示一个多项式，并实现两个多项式的相加和相乘运算。假设多项式形式为： 
     其中，系数ai≠0，指数ei满足em>em-1>…>e2>e1>=0。
要求：1、定义多项式每一项的结构。
	2、定义两个多项式的相加和相乘运算函数。
	3、在main函数中，构建两个多项式，并测试相加和相乘运算。
六、试编写一个整数进制转换的通用函数convert(int num, STACK S, int n)，要求将整数m转换为n进制数，n进制数的各位依次存放在栈S中。并在主函数中进行测试。
要求：1、定义栈以及栈的型。
2、定义栈的各种操作。
             3、实现函数convert。
            4、在main函数中，通过调用函数convert将num的n进制数存放到一个栈中，并通过出栈的方法输出该n进制数

七、设有一个循环队列Queue，只有头指针front，不设尾指针，另设一个含有元素个数的计数器count，试写出相应的判断队列空、判断队列满、出队算法和入队算法。
要求：
1、定义相应的循环队列的型（只有头指针，没有尾指针，但有一个元素个数的计数器）；
2、定义该队列的四个算法：判断队列空、判断队列满、出队算法和入队算法；
3、在main函数验证算法的正确性。

八、假设表达式中允许包含三种括号：圆括号、方括号和大括号。设计一个算法采用顺序栈（用数组表示的栈）判断表达式中的括号是否正确配对。
要求：
    1、定义栈以及栈的型，栈中所存放元素的类型为字符型，定义枚举类型Boolean，其中两个元素分别为TRUE和FALSE。
2、定义栈的各种操作。
3、定义函数Boolean check(char *s); 判断s中的括号是否正确配对，如果正确配对，返回TRUE，否则返回FALSE。
4、在主函数中验证所编写函数的正确性。

九、设有一个带头结点的双向链表h，设计一个算法用于查找第一个元素之为x的结点，并将其与其前驱结点进行交换。
要求：
        1、定义带头结点的双向链表的型DLIST。
        2、定义双向链表DLIST的基本操作。
        3、定义函数int swap(elementtype x, DLIST &h)，查找第一个元素之为x的结点，如果在链表中存在元素值为x的结点，并其与其前驱结点进行交换，并返回1，否则返回0。
        4、在主函数中测试所编写函数的正确性。
