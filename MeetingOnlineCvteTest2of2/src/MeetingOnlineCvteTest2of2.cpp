//============================================================================
// Name        : MeetingOnlineCvteTest2of2.cpp
// Author      : Haiou
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "XXKey.h"

using namespace std;

int main() {



	cout << "XXKey xx:xx:xx:xx:xx" << endl; // prints !!!Hello World!!!

	cout << "Your XXKey input" << endl;

	string myKeyStr;
	cin>>myKeyStr;

	XXKey myKey(myKeyStr);

	if(!myKey.XXKeyVaild() )
	{
		cout<< "false" ;
	}


	//system("pause");
	return 0;
}

