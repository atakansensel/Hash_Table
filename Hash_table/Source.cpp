#include <iostream>
#include <stdlib.h>
#include "Hash.h"
#include <fstream>

#include <ostream>


using namespace std;


int main(){
	
	
	const int m =3547;// choose prime number 
	int i= 2;
	int d = 1;
	int f = 5;
	int trans = 0;
	int curr = 0;
	Hash hash(m);
	double p ;
	ofstream result("result.csv",ios::trunc);

 

	int ins_success[m+1][2]={{0}};
	int ins_fail[m+1][2]={{0}};
	int find_success[m+1][2]={{0}};
	int find_fail[m+1][2]={{0}};
	int del_success[m+1][2]={{0}};
	int del_fail[m+1][2]={{0}};
	

	

	while (trans < 1000000 && !hash.isfull())
	{
	
		int prob = 0 ;
		int t = rand()%8;
		int num = rand()%(10*m);


		if(t<i)// insert 
		{

			if(hash.insert(num,prob))//insert success
			{
				
				 
				ins_success[curr][0]=ins_success[curr][0]+prob;
				ins_success[curr][1]=ins_success[curr][1]+1;

					trans++;
					curr++;
			}
			else// insert fail
			{
				trans++;
				ins_fail[curr][0]=ins_fail[curr][0]+prob;
				ins_fail[curr][1]=ins_fail[curr][1]+1;
			
			}



			 
		}
		else if ( i<=t  && t <i+d) //delete
		{

			if(hash.del(num,prob))// delete success
			{
				
				trans++;
				del_success[curr][0]=del_success[curr][0]+prob;
				del_success[curr][1]=del_success[curr][1]+1;
				
				curr--;
			}
			else
			{
				trans++;
				
				del_fail[curr][0]=del_fail[curr][0]+prob;
				del_fail[curr][1]=del_fail[curr][1]+1;
				
			}


			
		}
		else // find  
		{
			if(hash.find(num,prob))
			{
				trans++;
				
			   find_success[curr][0]=find_success[curr][0]+prob;
			   find_success[curr][1]=find_success[curr][1]+1;


			}

			else
			{
				trans++;
				

			   find_fail[curr][0]=find_fail[curr][0]+prob;
			   find_fail[curr][1]=find_fail[curr][1]+1;

			}
			
		}

		

	}
	
	result <<"Insert Success"<<endl;
	

	for(int a=0;a<m+1;a++)
	{

	    if(ins_success[a][1]!=0){
			p = double(a)/m;
			result << p <<",";
			result<< ins_success[a][0]/ins_success[a][1]<<endl;
		}
	
	}

	result<<"Insert Fail"<<endl;
	
	for(int a=0;a<m+1;a++)
	{

	    if(ins_fail[a][1]!=0){
			p = double(a)/m;
			result << p <<",";
			result<< ins_fail[a][0]/ins_fail[a][1]<<endl;
			
		}
	
	}

	
	result<<"Delete Success"<<endl;
	
	for(int a=0;a<m+1;a++)
	{

	    if(del_success[a][1]!=0){
			p = double(a)/m;
			result<< p <<",";
			result<<del_success[a][0]/del_success[a][1]<<endl;
		
		}
	
	}
	
	result<<"Delete Fail"<<endl;

	for(int a=0;a<m+1;a++)
	{

	    if(del_fail[a][1]!=0){
			p = double(a)/m;
			result<< p <<",";
			result<< del_fail[a][0]/del_fail[a][1]<<endl;
			
		}
	
	}

	result<<"Find success"<<endl;
	
	
	for(int a=0;a<m+1;a++)
	{

	    if(find_success[a][1]!=0){
			p = double(a)/m;
			result<< p <<",";
			result<< find_success[a][0]/find_success[a][1]<<endl;
			
		}
	
	}

	result <<"Find fail"<<endl;
	
	
	for(int a=0;a<m+1;a++)
	{

	    if(find_fail[a][1]!=0){
			p = double(a)/m;
			result << p <<",";
			result<< find_fail[a][0]/find_fail[a][1]<<endl;
		}
	
	}

	result.close();

	cout << "DONE!"; 
//	cin.ignore();
	//cin.get();

return 0;
}