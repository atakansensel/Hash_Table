#include <iostream>
#include "Hash.h"
#include <vector>
#include <string>

using namespace std;

Hash::Hash(int m):
	arr(m)
{
size=m;
}


bool Hash::isfull()
{
  
	for (int i = 0 ; i< size ; i++)
	{

		if(arr[i].str != 'a')
		{
			return false;
		}
	
	}

	return true;
}

int Hash::hash(int i,int s)
{
	return i%s;
}



bool Hash::insert(int i ,int &p)
{
	int index = hash(i,size);

	while(arr[index].str == 'a')
	{
		if(arr[index].num == i)
		{
			return false ;
		}


		index++;
		p++;

		if(index == size)
		{
			index = 0 ;
		}

	}

	arr[index].num = i;
	arr[index].str = 'a';
	return true;
}


bool Hash::del(int i,int &p)
{
	int index = hash(i,size);

	while(arr[index].str != 'e')
	{
		if(arr[index].str != 'd')
		{

			if(arr[index].num == i)
			{
			arr[index].num = -1;
			arr[index].str = 'd';
			return true;
			}

		}

		index++;
		p++;
		if(index == size)
		{
			index=0;
		}


	}
	return false;

}

bool Hash::find(int i,int &p)
{
	int index = hash(i,size);

	while(arr[index].str != 'e')
	{
		if(arr[index].num == i )
		{
			return true;
		}

		index++;
		p++;
		if(index == size)
		{
			index=0;
		}


	}
	return false;
}

