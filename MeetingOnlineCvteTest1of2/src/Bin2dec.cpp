/*
 * Bin2dec.cpp
 *
 *  Created on: 2019年3月20日
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

//输入方法
void Bin2dec::Input(void)
{

	cin>>this->myBin;
	if(this->myBin[0]=='0')//以零开始的字符串
	{
		this->err.err_massa =  "零开头";
		this->myBin.clear();

		throw this->err;
	}

	int len = this->myBin.length();
	for(int i=0;i<len;i++)//大于1的字符，小于0无效
	{
		if(   !((this->myBin[i]=='1')||\
				(this->myBin[i]=='0'))     ) //大于1的字符，小于0无效

		{
			this->err.err_massa =  "不是有效bit(0/1)";
			this->myBin.clear();

			throw this->err;
		}
	}



}
//输出方法
int Bin2dec::Output(void)
{
	return this->myDec;
}
//处理方法
void Bin2dec::deal(void)
{
	int sum = 0;
	int plus =0;
	int len = this->myBin.length();
	for(int loc=len; loc>=1;loc--)//遍历字符串从 权值的低位开始
	{
		plus = pow(2,len-loc);//1,2,4,8...//10101010(len=8)


		if('1' == this->myBin[loc-1] )//loc=len,len-,..,1//低位到高位//最低位pow(2,0)=1
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



