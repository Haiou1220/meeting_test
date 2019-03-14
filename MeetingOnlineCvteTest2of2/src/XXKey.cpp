/*
 * XXKey.cpp
 *
 *  Created on: 2019年3月9日
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

	 this->MyKeyString =keyStr; //输入的key保存

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

bool XXKey::IsMyChar(char char_key )//十六进制字符串范围
{
	bool ismychar;

	if( ( (char_key>='a')&&(char_key<='f') )||\
		( (char_key>='A')&&(char_key<='F') )||\
		( (char_key>='0')&&(char_key<='9') )   )//十六进制范围
	{
		ismychar = true;
	}else{
		ismychar = false;
		cout<<"第"<< this->keyLoca1 <<"个key的"<<this->keyLoca2<<"个字符错误:"<<char_key<<endl;
		//cout<<"第"<< this->keyLoca1 <<"个key的"<< this->keyLoca2<<"个字符错误:"<<char_key<<"-";
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

			}else{//只要一次匹配失败 就返回错误
				flagMatch = false;
				cout<<"XXKey的mask格式错误,格式为xx:xx:xx:xx:xx"<<endl;

			}

		}

		if(flagMatch == true)
		{
			this->MarkMatch=true;

			cout<<"XXKey的mask格式正确"<<endl;
			return true;
		}else{
			cout<<"XXKey的mask格式错误"<<endl;
			return false;
		}

}


bool XXKey::XXKeyVaild( )//字符串XXKey xx:xx:xx:xx:xx
{
	string StrKey = this->MyKeyString;
	bool ok = false;

	//if( !IsLenRight(StrKey) )//IsLenRight()===1,废弃函数
	//{
	//	cout<<"XXKey长度不对，应该为xx:xx:xx:xx:xx";
	//	return -1;
	//}

	if( IsMarkRight( StrKey) )//标号正确情况下才继续继续下面操作
	{
		if(	IsKeyMatch(StrKey) && IsKeyUpOrder(StrKey)  )//匹配 与 升序同时成立
		{
			cout<<"XXKey格式正确且为升序，XXkey为:"<<StrKey<<endl;
			ok = true;
		}
	}else{

		ok = false;
		cout<<"标号不匹配"<<endl;
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
cout<<"在IsKeyMatch我的Key字符串为"<<str_key<<endl;

	if(this->MarkMatch)//只有在mark标号（：或者-）正确情况下才进行
	{
		for(int i=0;i<(this->KeyLen);i+=3)//循环判断Key的有效性
		{
			static int KeyArrayCount = 0;
			//cout<<"循环"<< i <<"判断Key的有效性"<<endl;
			 this->keyLoca1 = KeyArrayCount+1;
			 this->keyLoca2 =  1 ;//定位到Key的第二个元素
			if( IsMyChar(  str_key[i] ) )//前一位
			{
				temp1 = str_key[i] ;

				KeyMatchCycle = true;
			}else{
				KeyMatchCycle = false;

			}
			this->keyLoca2 =  2 ; //定位到Key的第二个元素
			if( KeyMatchCycle && IsMyChar( str_key[i+1] ))//后一位，if条件是前一位是有效
			{
				temp2 = str_key[i+1] ;

				KeyMatchCycle = true;
			}else{
				KeyMatchCycle = false;

			}

			if(KeyMatchCycle == true)//条件两位都有效
			{
				string str01(&temp1,0,1);
				string str02(&temp2,0,1);
				string str1 = str01+str02;

	 //cout<<"第"<<KeyArrayCount+1<<"次循环匹配环节十六进制数字符串为"<<str1<<endl;

				stringstream ss;
				 ss<<str1;
				 ss>>hex>>ten;

				 this->KeyArray[KeyArrayCount] = ten;//存储Key的十进制，用以比较数值
				 KeyArrayCount++;

	 cout<<"第"<<KeyArrayCount<<"次循环匹配环节十进制数为"<<ten<<endl;

			}else{//循环匹配环节环节错误了，要终结

				int coutTemp =KeyArrayCount;
				cout<<"第"<<coutTemp+1<<"次匹配kEY环节环节错误了，要终结"<<endl;

				memset(this->KeyArray,0,this->KeyNum*sizeof(this->KeyArray));

				return false;//循环判断Key的有效性 为无效
			}

		}//for(;;)

		return true;

	}else{//不是正确情况

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

	for(int i=0;i<this->KeyNum;i++)//复制
	{
		a_keyArray.push_back(KeyArray[i]);

	}

	cout<<"\n-------------------";
	for(int i=0;i<this->KeyNum;i++)//备份好的输出
	{
		cout<< a_keyArray.at(i)<<" ";

	}
	cout<<"-------------------\n";

	sort(KeyArray,(KeyArray+this->KeyNum));//小到大排序

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
			cout<<"没有升序\n";
			//this->err_str_vec->push_back("没有升序");
			break;
		}

	}



	return iskeyuporder;
}
///////////////////////////////////////////

