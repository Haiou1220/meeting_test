/*#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*int main(int argc, char** argv) {
	return 0;
}*/

/*#include<iostream> 
using namespace std;
int f(int);
int main()
{	
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}

int f(int n)//1,1,2,3,5,8,13//  f(1)=1,f(2)=1,f(3)=2
{
	if(n<=0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		return (f(n-1)+f(n-2) );
		
	}
	
	return 0;
}*/

#include<iostream>
using namespace std;

void print_tri(int);

int main()
{
	int in;
	cin>>in;
	
	print_tri(in);
	
	return 0;
}


void p_star(int a)
{
	static char flag_max=1;		
			
			
			 	if(flag_max){
			 		flag_max =0;
			 		for(int ii=a;ii>=1;ii--)
					 cout<<"* ";
					 
				 }
			 	else{
			 		flag_max = 1;
			 		for(int ii=a;ii>=1;ii--)
			 		cout<<" *";
				 }
			
			
}
void p_blank(int a)
{
			for(int ii=a;ii>=1;ii--)
			{	

			cout<<"  ";
			
			}	
}

void print_tri(int cr)
{
//	int cr=10;
	for(int i=0;i<cr;i++)
	{	

        p_blank(i/2);p_star(cr-i);p_blank(i/2);
		

			
		cout<<endl; 
	}
	
}

















