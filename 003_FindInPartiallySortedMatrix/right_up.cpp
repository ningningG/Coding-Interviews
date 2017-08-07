#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())  return false;
		int rows = array.size();
		int cols = array[0].size();
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				--col;
			else
				++row;
		}
		return false;
	}
};

// ====================测试代码====================

int main()
{
	//  1   2   8   9
	//  2   4   9   12
	//  4   7   10  13
	//  6   8   11  15
	int a1[] = { 1, 2, 8, 9, };
	int a2[] = { 2, 4, 9, 12, };
	int a3[] = { 4, 7, 10, 13, };
	int a4[] = { 6, 8, 11, 15, };

	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 4));
	array.push_back(vector<int>(a2, a2 + 4));
	array.push_back(vector<int>(a3, a3 + 4));
	array.push_back(vector<int>(a4, a4 + 4));

	// 鲁棒性测试，输入空指针
	vector<vector<int>> array_empty;
	
	Solution solu;
	// 要查找的数在数组中
	cout << "Is 7 in the array?" << solu.Find(7, array) << endl;
	// 要查找的数不在数组中
	cout << "Is 5 in the array?" << solu.Find(5, array) << endl;
	// 要查找的数是数组中最小的数字
	cout << "Is 1 in the array?" << solu.Find(1, array) << endl;
	// 要查找的数是数组中最大的数字
	cout << "Is 15 in the array?" << solu.Find(15, array) << endl;
	// 要查找的数比数组中最小的数字还小
	cout << "Is 0 in the array?" << solu.Find(0, array) << endl;
	// 要查找的数比数组中最大的数字还大
	cout << "Is 16 in the array?" << solu.Find(16, array) << endl;
	// 鲁棒性测试，输入空指针
	cout << "Is 16 in the array(null)?" << solu.Find(16, array_empty) << endl;
	system("pause");

	return 0;
}