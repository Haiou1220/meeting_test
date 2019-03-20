/*
 * Bin2dec.h
 *
 *  Created on: 2019年3月20日
 *      Author: Haiou
 */

#ifndef BIN2DEC_H_
#define BIN2DEC_H_

#include <string>
using namespace std;

struct Err{
	int err_num ;
	string err_massa;
};

class Bin2dec {
public:
	Bin2dec();
	virtual ~Bin2dec();

private:
	string myBin;
	int myDec;
	Err err;
public:
	//输入方法
	void Input(void);
	//输出方法
	int Output(void);
	//处理方法
	void deal(void);
	//异常错误
	string error();
};

#endif /* BIN2DEC_H_ */
