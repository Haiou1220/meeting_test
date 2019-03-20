//============================================================================
// Name        : MeetingOnlineCvteTest1of2.cpp
// Author      : Haiou
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Bin2dec.h"
#include <exception>

using namespace std;

int main() {
	cout << "请输入二进制字符串bin:" <<endl;

    Bin2dec a;

    try {
        a.Input();//输入二进制字符串且判断有效性  第一个输入不可以为零
        a.deal();//转换
        cout <<"转换成十进制结果dec:"<< a.Output() <<endl;

	} catch (const Err &) { // a.Input()异常处理，如果二进制无效

		cout<<"二进制输入错误:"<<a.error()<<endl;

	}


	return 0;
}
