/************************************************/
/************   unionfind.cpp        ************/
/************   by Gara Pruesse      ************/
/************   Sept 2015            ************/
/************************************************/
/************************************************/

#include "unionfind.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

char getcommand();
bool processcommand(char cmd);


int main()
{
   
   int n;
   int p,q; 
   int ending=0;
   string fileName;
   char cmd;
   ifstream ins;

   cout << "Enter the input file name: ";
   cin >> fileName;
   ins.open(fileName.c_str());
   if (ins.fail ())
   {
	cerr << "*** Error: Cannot open file "<< fileName << endl;
   }

   
   ins >> n;
   unionfind Set;
   Set.size(n);

   ins >> cmd ;
   while (!ins.eof())
	{
   	switch (cmd) {
      		case 'f': ins >> p ;
			Set.find(p);
			ins >> cmd;
                	break;
      		case 'u': ins >> p >> q;
			Set.merge(p,q);
			ins >> cmd;
                	break;
      		case 'd': cout << "The array data is:" << endl;
                	Set.debugprint();
			ins >> cmd;
                	break; 
      		default:  
			ins >> cmd;
   		}
	
   	}
   ins.close();
   return 1;
}

