/*
 * XXKey.cpp
 *
 *  Created on: 2019��3��9��
 *      Author: Haiou
 */

#include "XXKey.h"
#include <iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

XXKey::XXKey(string keyStr)
{
	//err_str_vec->clear();
	KeyLen = MyXXKeyInputLen(keyStr);
	MarkNum = (KeyLen-2)/3;
	KeyNum = (MarkNum+1);

	 KeyMatch = false;
	 MarkMatch = false;

	 KeyArray = new int(KeyNum);

	 this->MyKeyString =keyStr; //�����key����

	//KeyNum = (MarkNum+1);
		//KeyLen = MarkNum+(2*KeyNum);
		//MarkNum = myXXKeyMaskNum;


	// TODO Auto-generated constructor stub

}

XXKey::~XXKey() {
	// TODO Auto-generated destructor stub
}

int XXKey::MyXXKeyInputLen(string str)
{

	return str.size();
}
bool XXKey::IsLenRight(string StrKey)
{
/*	if((signed int)StrKey.size()==(signed int)this->KeyLen)
	{
		return true;

	}else{
		return false;
	}
	*/

	return true;

}

bool XXKey::IsMyChar(char char_key )//ʮ�������ַ�����Χ
{
	bool ismychar;

	if( ( (char_key>='a')&&(char_key<='f') )||\
		( (char_key>='A')&&(char_key<='F') )||\
		( (char_key>='0')&&(char_key<='9') )   )//ʮ�����Ʒ�Χ
	{
		ismychar = true;
	}else{
		ismychar = false;
		cout<<"��"<< this->keyLoca1 <<"��key��"<<this->keyLoca2<<"���ַ�����:"<<char_key<<endl;
		//cout<<"��"<< this->keyLoca1 <<"��key��"<< this->keyLoca2<<"���ַ�����:"<<char_key<<"-";
	}

	return 	ismychar;
}

bool XXKey::IsMarkRight(string str_key)
{
	bool flagMatch  = true;
		cout<<"this->MarkNum:"<<this->MarkNum<<endl;
		for(int i=2;i<(this->MarkNum);i+=3)
		{
			cout<<this->MarkNum<<endl;

			if(/*(flagMatch == true)&&*/((str_key[i] ==':')||(str_key[i] =='-') ))
			{
				flagMatch = true;

			}else{//ֻҪһ��ƥ��ʧ�� �ͷ��ش���
				flagMatch = false;
				cout<<"XXKey��mask��ʽ����,��ʽΪxx:xx:xx:xx:xx"<<endl;

			}

		}

		if(flagMatch == true)
		{
			this->MarkMatch=true;

			cout<<"XXKey��mask��ʽ��ȷ"<<endl;
			return true;
		}else{
			cout<<"XXKey��mask��ʽ����"<<endl;
			return false;
		}

}


bool XXKey::XXKeyVaild( )//�ַ���XXKey xx:xx:xx:xx:xx
{
	string StrKey = this->MyKeyString;
	bool ok = false;

	//if( !IsLenRight(StrKey) )//IsLenRight()===1,��������
	//{
	//	cout<<"XXKey���Ȳ��ԣ�Ӧ��Ϊxx:xx:xx:xx:xx";
	//	return -1;
	//}

	if( IsMarkRight( StrKey) )//�����ȷ����²ż��������������
	{
		if(	IsKeyMatch(StrKey) && IsKeyUpOrder(StrKey)  )//ƥ�� �� ����ͬʱ����
		{
			cout<<"XXKey��ʽ��ȷ��Ϊ����XXkeyΪ:"<<StrKey<<endl;
			ok = true;
		}
	}else{

		ok = false;
		cout<<"��Ų�ƥ��"<<endl;
	}

	return ok;
}
////////////////////////////////////////////////////////////////
bool XXKey::IsKeyMatch(string str_key)
{
	char temp1;
	char temp2;
	int ten;
	bool KeyMatchCycle = false;
cout<<"��IsKeyMatch�ҵ�Key�ַ���Ϊ"<<str_key<<endl;

	if(this->MarkMatch)//ֻ����mark��ţ�������-����ȷ����²Ž���
	{
		for(int i=0;i<(this->KeyLen);i+=3)//ѭ���ж�Key����Ч��
		{
			static int KeyArrayCount = 0;
			//cout<<"ѭ��"<< i <<"�ж�Key����Ч��"<<endl;
			 this->keyLoca1 = KeyArrayCount+1;
			 this->keyLoca2 =  1 ;//��λ��Key�ĵڶ���Ԫ��
			if( IsMyChar(  str_key[i] ) )//ǰһλ
			{
				temp1 = str_key[i] ;

				KeyMatchCycle = true;
			}else{
				KeyMatchCycle = false;

			}
			this->keyLoca2 =  2 ; //��λ��Key�ĵڶ���Ԫ��
			if( KeyMatchCycle && IsMyChar( str_key[i+1] ))//��һλ��if������ǰһλ����Ч
			{
				temp2 = str_key[i+1] ;

				KeyMatchCycle = true;
			}else{
				KeyMatchCycle = false;

			}

			if(KeyMatchCycle == true)//������λ����Ч
			{
				string str01(&temp1,0,1);
				string str02(&temp2,0,1);
				string str1 = str01+str02;

	 //cout<<"��"<<KeyArrayCount+1<<"��ѭ��ƥ�价��ʮ���������ַ���Ϊ"<<str1<<endl;

				stringstream ss;
				 ss<<str1;
				 ss>>hex>>ten;

				 this->KeyArray[KeyArrayCount] = ten;//�洢Key��ʮ���ƣ����ԱȽ���ֵ
				 KeyArrayCount++;

	 cout<<"��"<<KeyArrayCount<<"��ѭ��ƥ�价��ʮ������Ϊ"<<ten<<endl;

			}else{//ѭ��ƥ�价�ڻ��ڴ����ˣ�Ҫ�ս�

				int coutTemp =KeyArrayCount;
				cout<<"��"<<coutTemp+1<<"��ƥ��kEY���ڻ��ڴ����ˣ�Ҫ�ս�"<<endl;

				memset(this->KeyArray,0,this->KeyNum*sizeof(this->KeyArray));

				return false;//ѭ���ж�Key����Ч�� Ϊ��Ч
			}

		}//for(;;)

		return true;

	}else{//������ȷ���

		return false;
	}

}
//////////////////////////////
bool XXKey::sort_complare(int a,int b)
{
	return (a>b);
}
////////////////////////////////////////////////
bool XXKey::IsKeyUpOrder(string StrKey)
{
	bool iskeyuporder = false;

	vector<int> a_keyArray;
	a_keyArray.clear();

	for(int i=0;i<this->KeyNum;i++)//����
	{
		a_keyArray.push_back(KeyArray[i]);

	}

	cout<<"\n-------------------";
	for(int i=0;i<this->KeyNum;i++)//���ݺõ����
	{
		cout<< a_keyArray.at(i)<<" ";

	}
	cout<<"-------------------\n";

	sort(KeyArray,(KeyArray+this->KeyNum));//С��������

	using namespace std;




	cout<<"\n-------------------";
	for(int i=0;i<this->KeyNum;i++)
	{
		cout<< KeyArray[i]<<" ";

	}
	cout<<"-------------------\n";


	for(int i=0;i<this->KeyNum;i++)
	{
		if ( KeyArray[i]==a_keyArray.at(i) )
		{
			iskeyuporder=true;
		}else{
			iskeyuporder=false;
			cout<<"û������\n";
			//this->err_str_vec->push_back("û������");
			break;
		}

	}



	return iskeyuporder;
}
///////////////////////////////////////////

