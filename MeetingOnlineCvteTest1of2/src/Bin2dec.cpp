/*
 * Bin2dec.cpp
 *
 *  Created on: 2019��3��20��
 *      Author: Haiou
 */

#include "Bin2dec.h"
#include <iostream>
#include <math.h>

Bin2dec::Bin2dec() {
	// TODO Auto-generated constructor stub
   this->myDec = 0;

}

Bin2dec::~Bin2dec() {
	// TODO Auto-generated destructor stub
}

//���뷽��
void Bin2dec::Input(void)
{

	cin>>this->myBin;
	if(this->myBin[0]=='0')//���㿪ʼ���ַ���
	{
		this->err.err_massa =  "�㿪ͷ";
		this->myBin.clear();

		throw this->err;
	}

	int len = this->myBin.length();
	for(int i=0;i<len;i++)//����1���ַ���С��0��Ч
	{
		if(   !((this->myBin[i]=='1')||\
				(this->myBin[i]=='0'))     ) //����1���ַ���С��0��Ч

		{
			this->err.err_massa =  "������Чbit(0/1)";
			this->myBin.clear();

			throw this->err;
		}
	}



}
//�������
int Bin2dec::Output(void)
{
	return this->myDec;
}
//������
void Bin2dec::deal(void)
{
	int sum = 0;
	int plus =0;
	int len = this->myBin.length();
	for(int loc=len; loc>=1;loc--)//�����ַ����� Ȩֵ�ĵ�λ��ʼ
	{
		plus = pow(2,len-loc);//1,2,4,8...//10101010(len=8)


		if('1' == this->myBin[loc-1] )//loc=len,len-,..,1//��λ����λ//���λpow(2,0)=1
		{
			sum+=plus;

		}
	}
	this->myDec = sum;
}

string Bin2dec::error()
{

	return this->err.err_massa;
}



