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
	cout << "������������ַ���bin:" <<endl;

    Bin2dec a;

    try {
        a.Input();//����������ַ������ж���Ч��  ��һ�����벻����Ϊ��
        a.deal();//ת��
        cout <<"ת����ʮ���ƽ��dec:"<< a.Output() <<endl;

	} catch (const Err &) { // a.Input()�쳣���������������Ч

		cout<<"�������������:"<<a.error()<<endl;

	}


	return 0;
}
