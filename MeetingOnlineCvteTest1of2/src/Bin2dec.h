/*
 * Bin2dec.h
 *
 *  Created on: 2019��3��20��
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
	//���뷽��
	void Input(void);
	//�������
	int Output(void);
	//������
	void deal(void);
	//�쳣����
	string error();
};

#endif /* BIN2DEC_H_ */
