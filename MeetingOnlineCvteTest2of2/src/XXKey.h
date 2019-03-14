/*
 * XXKey.h
 *
 *  Created on: 2019��3��9��
 *      Author: Haiou
 */

#ifndef XXKEY_H_
#define XXKEY_H_
#include <iostream>
#include<vector>
#include<string>

using namespace std;

class XXKey {
public:
	XXKey(string);
	virtual ~XXKey();
	 int keyLoca1,keyLoca2;
private:

	bool KeyMatch ;
	bool MarkMatch ;

	int MarkNum ;
	int KeyNum ;

	int KeyLen ;//�ַ���XXKey xx:xx:xx:xx:xx
	int* KeyArray;

	vector<string>* err_str_vec;

	string MyKeyString;

public:
	bool XXKeyVaild( );

private:

	bool sort_complare(int a,int b);
	bool IsKeyUpOrder(string str_key);
	bool IsKeyMatch(string StrKey) ;
	bool IsMarkRight(string StrKey);//���λ����ȷ��
	bool IsMyChar(char char_key );//ʮ�������ַ�����Χ
	bool IsLenRight(string StrKey);
	int MyXXKeyInputLen(string str);
};

#endif /* XXKEY_H_ */
