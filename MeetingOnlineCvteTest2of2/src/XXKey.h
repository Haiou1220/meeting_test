/*
 * XXKey.h
 *
 *  Created on: 2019年3月9日
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

	int KeyLen ;//字符串XXKey xx:xx:xx:xx:xx
	int* KeyArray;

	vector<string>* err_str_vec;

	string MyKeyString;

public:
	bool XXKeyVaild( );

private:

	bool sort_complare(int a,int b);
	bool IsKeyUpOrder(string str_key);
	bool IsKeyMatch(string StrKey) ;
	bool IsMarkRight(string StrKey);//标号位置正确吗
	bool IsMyChar(char char_key );//十六进制字符串范围
	bool IsLenRight(string StrKey);
	int MyXXKeyInputLen(string str);
};

#endif /* XXKEY_H_ */
