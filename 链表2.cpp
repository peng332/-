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

		ListNode* head = new ListNode(0);//�����ڵ㣬ָ��headָ��0��
		ListNode* tem = head;			//������ָ̬�룬Ҳָ��0.
		
		if (l1 != nullptr && l2 != nullptr)//1��l1��l2����Ԫ�ء�
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
			cout <<"�ϲ�������"<< endl;
			while (tem)
			{
				cout << tem->val << "	";
				tem = tem->next;
			}
			cout << endl;
		}
		
		else if ((l1 == nullptr && l2 == nullptr) || l1 != nullptr && l2 == nullptr) {//2,��l1��l2����Ԫ�ػ���l1��Ԫ��
			return l1;
		}
		else if (l1 == nullptr && l2 != nullptr) {				//3��l2��Ԫ��
			return l2;
		}
	}
};

ListNode* list_Create()										//��������������������
{
		ListNode* pHead, *pCurrent, *pNew;
		int data, num1,num2;								
		pHead = new ListNode(0);
		pCurrent = pHead;
		cout << "����������Ԫ�صĸ���" << endl;
		cin >> num1;
		cout << "����������Ԫ��" << endl;
		num2 = 1;
		while (num2 <=num1)
		{
			cin >> data;
			num2++;
			pNew = new ListNode(data);			//1.�����½ڵ�
			pCurrent->next = pNew;				//2.�����½ڵ�
			pCurrent = pNew;					//3.���½ڵ��ɵ�ǰ�ڵ�
			
			
		}
		return pHead->next;						
}


void list_Print(ListNode* pHead)				//��ӡ������
	{
		ListNode* tem;
		if (pHead == NULL)
			return;
		tem = pHead;							//�Դ��������������һ����ʱ������ס
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
