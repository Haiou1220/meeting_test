/******************************************************************************
��ȡ�ַ����е�����-�汾һ
******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

unsigned int getHdcpKeyID(const char *str)
{
	cout<<str<<endl;
    unsigned int  mycount=0;
    string my_num;

    for(int i = 0 ;  *(str+i)!='\0';  i++)//ȡ������
    {
        char nowchar = *(str+i);

        if(( '0'<=nowchar&&'9'>=nowchar))
        {
            my_num.push_back(*(str+i));
            //cout<<my_num<<endl;
        }

    }
    //��������
    int char_len =my_num.length();
    for(int i=0;i<char_len;i++)
    {
     mycount +=  (my_num[i]-'0')*pow( 10,(char_len-1)-i );


    }
     return mycount;

}
int main() {

    cout <<  getHdcpKeyID("HDCPkey31415926.bin") << endl;

    return 0;
}

