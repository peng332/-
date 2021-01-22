#include<iostream>
#include<list>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;

	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	//ListNode() :val(0), next(nullptr) {}
	ListNode(int x, ListNode *next) :val(x), next(nullptr) {}
};

class solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{

		ListNode* head = new ListNode(0);//创建节点，指针head指向0。
		ListNode* tem = head;			//创建动态指针，也指向0.
		
		if (l1 != nullptr && l2 != nullptr)//1、l1和l2都有元素。
		{
			while (l1 != nullptr && l2 != nullptr) 
			{
				if ((l1->val < l2->val) && l1 != nullptr && l2 != nullptr)
				{
					tem->next = l1;
					l1= l1->next;
				}
				else
				{
					tem->next = l2;
					l2 = l2->next;
					
				}
				tem = tem->next;
			}
			if (l1 == nullptr)
			{
				tem->next = l2;
			}
			else
			{
				tem->next = l1;
			}
			ListNode* tem;
			tem = head->next;							
			cout <<"合并后链表："<< endl;
			while (tem)
			{
				cout << tem->val << "	";
				tem = tem->next;
			}
			cout << endl;
		}
		
		else if ((l1 == nullptr && l2 == nullptr) || l1 != nullptr && l2 == nullptr) {//2,、l1和l2都无元素或者l1无元素
			return l1;
		}
		else if (l1 == nullptr && l2 != nullptr) {				//3、l2无元素
			return l2;
		}
	}
};

ListNode* list_Create()										//创建链表，输入链表数据
{
		ListNode* pHead, *pCurrent, *pNew;
		int data, num1,num2;								
		pHead = new ListNode(0);
		pCurrent = pHead;
		cout << "请输入链表元素的个数" << endl;
		cin >> num1;
		cout << "请输入链表元素" << endl;
		num2 = 1;
		while (num2 <=num1)
		{
			cin >> data;
			num2++;
			pNew = new ListNode(data);			//1.创建新节点
			pCurrent->next = pNew;				//2.插入新节点
			pCurrent = pNew;					//3.让新节点变成当前节点
			
			
		}
		return pHead->next;						
}


void list_Print(ListNode* pHead)				//打印链表函数
	{
		ListNode* tem;
		if (pHead == NULL)
			return;
		tem = pHead;							//对传入的数据用另外一个临时变量接住
		while (tem)
		{
			cout << tem->val << "	";
			tem = tem->next;
		}
		cout << endl;
}

int main()
{
	ListNode* L1 = list_Create();
	list_Print(L1);
	ListNode* L2 = list_Create();
	list_Print(L2);
	
	solution test;
	test.mergeTwoLists(L1, L2);
	
	system("pause");
	return 0;
}
