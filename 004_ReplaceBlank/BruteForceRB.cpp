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

		//  �Ӻ���ǰ����
		for (i = length - 1; i >= 0; i--)
		{
			//cout <<str[i] <<endl;
			//  �����ǰ�ַ��ǿո�
			if (str[i] == ' ')
			{
				//  �ӿո���%20����������2
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

	// �ո��ھ����м�
	char string1[100] = "hello world";
	solu.replaceSpace(string1, 100);
	cout << "string1:" << string1 << endl;

	// �ո��ھ��ӿ�ͷ
	char string2[100] = " helloworld";
	solu.replaceSpace(string2, 100);
	cout << "string2:" << string2 << endl;

	// �ո��ھ���ĩβ
	char string3[100] = "helloworld ";
	solu.replaceSpace(string3, 100);
	cout << "string3:" << string3 << endl;


	// �����������ո�
	char string4[100] = "hello  world";
	solu.replaceSpace(string4, 100);
	cout << "string4:" << string4 << endl;


	// ����NULL
	char string5[100];
	solu.replaceSpace(string5, 100);
	cout << "string5:" << string5 << endl;


	// ��������Ϊ�յ��ַ���
	char string6[100] = "";
	solu.replaceSpace(string6, 100);
	cout << "string6:" << string6 << endl;


	//��������Ϊһ���ո���ַ���
	char string7[100] = " ";
	solu.replaceSpace(string7, 100);
	cout << "string7:" << string7 << endl;


	// ������ַ���û�пո�
	char string8[100] = "helloworld";
	solu.replaceSpace(string8, 100);
	cout << "string8:" << string8 << endl;

	// ������ַ���ȫ�ǿո�
	char string9[100] = "   ";
	solu.replaceSpace(string9, 100);
	cout << "string9:" << string9 << endl;

	system("pause");

	return 0;
}