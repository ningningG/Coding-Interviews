#include <iostream>

using namespace std;

class Solution
{
public:
	void replaceSpace(char *str, int length)
	{
		if (str == NULL || length <= 0)
			return;
		int i = length - 1, j;
		int len = length;

		//  从后往前遍历
		for (i = length - 1; i >= 0; i--)
		{
			//cout <<str[i] <<endl;
			//  如果当前字符是空格
			if (str[i] == ' ')
			{
				//  从空格变成%20长度增加了2
				len += 2;

				for (j = len - 1; j > i + 2; j--)
				{
					str[j] = str[j - 2];
				}
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '\%';
			}
			//cout <<str <<endl;
		}
		str[len] = '\0';
	}
};

int main()
{
	Solution solu;

	// 空格在句子中间
	char string1[100] = "hello world";
	solu.replaceSpace(string1, 100);
	cout << "string1:" << string1 << endl;

	// 空格在句子开头
	char string2[100] = " helloworld";
	solu.replaceSpace(string2, 100);
	cout << "string2:" << string2 << endl;

	// 空格在句子末尾
	char string3[100] = "helloworld ";
	solu.replaceSpace(string3, 100);
	cout << "string3:" << string3 << endl;


	// 连续有两个空格
	char string4[100] = "hello  world";
	solu.replaceSpace(string4, 100);
	cout << "string4:" << string4 << endl;


	// 传入NULL
	char string5[100];
	solu.replaceSpace(string5, 100);
	cout << "string5:" << string5 << endl;


	// 传入内容为空的字符串
	char string6[100] = "";
	solu.replaceSpace(string6, 100);
	cout << "string6:" << string6 << endl;


	//传入内容为一个空格的字符串
	char string7[100] = " ";
	solu.replaceSpace(string7, 100);
	cout << "string7:" << string7 << endl;


	// 传入的字符串没有空格
	char string8[100] = "helloworld";
	solu.replaceSpace(string8, 100);
	cout << "string8:" << string8 << endl;

	// 传入的字符串全是空格
	char string9[100] = "   ";
	solu.replaceSpace(string9, 100);
	cout << "string9:" << string9 << endl;

	system("pause");

	return 0;
}