//
// unionfind.Cpp
// Author: Gara Pruesse
// Date: September 4, 2015
//
// This unionfind class implements disjoint sets as an array of integers 
//
//
#include "unionfind.h"


unionfind::unionfind()
{
//do this tonight
}

void unionfind::size(int k)
{
    n = k;
    parent = new int[k];
    for (int i=0; i< k;i++)
        parent[i]=i;
}

int unionfind::find(int p )
// returning the integer representing the set containing element p
//
{
    if (p != parent[p])
        parent[p] = find(parent[p]);
    return parent[p];
    //return(parent[p]);
}


void unionfind::merge(int p, int q)
//    merge the set containing p with the set containing q 
{
if (parent[p] > parent[q])
			parent[q] = p;
		else if (parent[p] < parent[q])
			parent[p] = q;
		else {
			parent[q] = p;
			++parent[p];
		}
	
}


void unionfind::debugprint()
// display the contents and structure of parent array
{
	for (int i=0; i<n; i++)  
		cout << "[" << i << "]" << parent[i];
	cout << endl << endl;
}


