#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	static void PreOrder(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->val;
		PreOrder(root->left);
		PreOrder(root->right);
	}

	static void InOrder(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		InOrder(root->left);
		cout << root->val;
		InOrder(root->right);
	}

	static void PostOrder(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val;
	}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int inlen = vin.size();
		if (inlen == 0) return NULL;
		vector<int> left_pre, right_pre, left_in, right_in;
		TreeNode* TreeRoot = new TreeNode(pre[0]);
		int indexRoot = 0;
		for (int i = 0; i<inlen; i++)
		{
			if (vin[i] == pre[0])
			{
				indexRoot = i;
				break;
			}
		}
		for (int i = 0; i<indexRoot; i++)
		{
			left_in.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = indexRoot + 1; i<inlen; i++)
		{
			right_in.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		TreeRoot->left = reConstructBinaryTree(left_pre, left_in);
		TreeRoot->right = reConstructBinaryTree(right_pre, right_in);
		return TreeRoot;
	}

};

int main()
{
	// 普通二叉树
	//              1
	//           /     \
	//          2       3  
	//         /       / \
	//        4       5   6
	//         \         /
	//          7       8
	int preorder1[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder1[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> preOrder1(preorder1, preorder1 + 8);
	vector<int>  inOrder1(inorder1, inorder1 + 8);
	Solution solu1;
	TreeNode *root1 = solu1.reConstructBinaryTree(preOrder1, inOrder1);
	cout << "Tree1" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root1);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root1);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root1);
	cout << endl;

	// 所有结点都没有右子结点
	//            1
	//           / 
	//          2   
	//         / 
	//        3 
	//       /
	//      4
	//     /
	//    5
	int preorder2[5] = { 1, 2, 3, 4, 5 };
	int inorder2[5] = { 5, 4, 3, 2, 1 };
	vector<int> preOrder2(preorder2, preorder2 + 5);
	vector<int>  inOrder2(inorder2, inorder2 + 5);
	Solution solu2;
	TreeNode *root2 = solu2.reConstructBinaryTree(preOrder2, inOrder2);
	cout << "Tree2" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root2);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root2);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root2);
	cout << endl;

	// 所有结点都没有左子结点
	//            1
	//             \ 
	//              2   
	//               \ 
	//                3 
	//                 \
	//                  4
	//                   \
	//                    5
	int preorder3[5] = { 1, 2, 3, 4, 5 };
	int inorder3[5] = { 1, 2, 3, 4, 5 };
	vector<int> preOrder3(preorder3, preorder3 + 5);
	vector<int>  inOrder3(inorder3, inorder3 + 5);
	Solution solu3;
	TreeNode *root3 = solu3.reConstructBinaryTree(preOrder3, inOrder3);
	cout << "Tree3" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root3);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root3);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root3);
	cout << endl;

	// 树中只有一个结点
	int preorder4[1] = { 1 };
	int inorder4[1] = { 1 };
	vector<int> preOrder4(preorder4, preorder4 + 5);
	vector<int>  inOrder4(inorder4, inorder4 + 5);
	Solution solu4;
	TreeNode *root4 = solu4.reConstructBinaryTree(preOrder4, inOrder4);
	cout << "Tree4" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root4);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root4);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root4);
	cout << endl;

	// 完全二叉树
	//              1
	//           /     \
	//          2       3  
	//         / \     / \
	//        4   5   6   7
	int preorder5[7] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder5[7] = { 4, 2, 5, 1, 6, 3, 7 };
	vector<int> preOrder5(preorder5, preorder5 + 5);
	vector<int>  inOrder5(inorder5, inorder5 + 5);
	Solution solu5;
	TreeNode *root5 = solu5.reConstructBinaryTree(preOrder5, inOrder5);
	cout << "Tree5" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root5);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root5);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root5);
	cout << endl;

	// 输入空指针
	Solution solu6;
	TreeNode *root6 = NULL;
	cout << "Tree6" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root6);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root6);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root6);
	cout << endl;

	// 输入的两个序列不匹配
	int preorder7[7] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder7[7] = { 4, 2, 8, 1, 6, 3, 7 };
	vector<int> preOrder7(preorder7, preorder7 + 5);
	vector<int>  inOrder7(inorder7, inorder7 + 5);
	Solution solu7;
	TreeNode *root7 = solu4.reConstructBinaryTree(preOrder7, inOrder7);
	cout << "Tree7" << endl;
	cout << "PreOrder" << endl;   //  12345678
	TreeNode::PreOrder(root7);
	cout << endl;

	cout << "InOrder " << endl;   //  47215386
	TreeNode::InOrder(root7);
	cout << endl;

	cout << "PostOrder " << endl; //
	TreeNode::PostOrder(root7);
	cout << endl;

	system("pause");

	return 0;
}
