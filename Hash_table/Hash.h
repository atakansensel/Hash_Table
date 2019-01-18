#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>

using namespace std;

struct element{
	int num;
	char str; // e for empty , a for active ,d for deleted 

	element(){
	str = 'e';
	}

};

class Hash 
{
public:
	Hash(int m);
	
	bool insert(int i,int &p);
	bool del(int i,int &p);
	bool find(int i,int &p);
	bool isfull();
	int hash (int i,int max);


private:
   	int size;
	vector<element> arr;
	
	
	

};


	
#endif
