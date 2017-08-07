#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution
{
public:
	vector<int> res;

	vector<int> printListFromTailToHead(struct ListNode* pHead)
	{
		if (pHead != NULL)
		{
			if (pHead->next!=NULL) {
				printListFromTailToHead(pHead->next);
			}
			res.push_back(pHead->val);
		}
		return res;
	}
};


int main()
{
	// 1->2->3->4->5
	//ListNode *head = new ListNode(1);

	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);
	//pNode1->val = 1;
	pNode1->next = pNode2;
	//pNode2->val = 2;
	pNode2->next = pNode3;
	//pNode3->val = 3;
	pNode3->next = pNode4;
	//pNode4->val = 4;
	pNode4->next = pNode5;
	//pNode5->val = 5;
	pNode5->next = NULL;

	Solution solu1;
	vector<int> res1 = solu1.printListFromTailToHead(pNode1);

	cout << "there are " << res1.size() << "datas in vector1" << endl;
	for (int i = 0; i < res1.size(); i++)
	{
		cout << res1[i] << endl;
	}


	// 只有一个结点的链表: 1
	ListNode* pNode6;
	pNode1->val = 1;
	pNode1->next = NULL;
	Solution solu2;
	vector<int> res2 = solu2.printListFromTailToHead(pNode1);

	cout << "there are " << res2.size() << "datas in vector2" << endl;
	for (int i = 0; i < res2.size(); i++)
	{
		cout << res2[i] << endl;
	}

	// 空链表
	ListNode* pNode = NULL;

	Solution solu3;
	vector<int> res3 = solu3.printListFromTailToHead(pNode);

	cout << "there are " << res3.size() << "datas in vector3" << endl;
	for (int i = 0; i < res3.size(); i++)
	{
		cout << res3[i] << endl;
	}

	system("pause");

	return 0;
}