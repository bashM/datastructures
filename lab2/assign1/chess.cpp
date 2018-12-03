/*****************************************************************
*****************************7
************************7
*** BasheeR, Mohammad.
*** 565-266-905.
*** CSCI 260.
*** Gara Pruesse. 
************************7
*****************************7
*****************************************************************/
#include<iostream>  
#include<iomanip>   
#include "math.h"
   
using namespace std;  
      
void Trom(int **a,int B,int V,int BoardSide,int x,int y );  
int Traget=2;  
int main()  
{  
   int k,s;
     
   cout<< "Enter the width of your screen, for printing (in characters): "; 
   cin >> s;     
   cout<<"Enter the power k, making a chessboard of dimensions 2^k x 2^k:";
   cin>>k;  

   int i=(int)pow((double)2,(double)k);  
   

//here is the chessboard memory and the demantion look
   int **chessboard=NULL;  
   chessboard=new int* [i];           
     
   for(int j=0;j<i;j++)              
   {  
      chessboard[j]=new int[i];  
   }  
      
   for(int j=0;j<i;j++)              
     for(int k=0;k<i;k++)  
         chessboard[j][k]=0;  
         

   int a,b;   //a?b  
   
   cout<<"Enter the the row and column of the missing square, separated by a space:";   
// every time you check for the row or the squer that need to be covered. it will put # 7 on that gap   
   cin>>b>>a;  
   chessboard[a][b]=7;              
   cout<<""<<a+1<<""<<b+1<<""<<endl;  
   Trom(chessboard,0,0,i,a,b);  
   cout<<endl;   
// to compute the value of the chessboard       
   for(int j=0;j<i;j++)  
   {  
      for(int k=0;k<i;k++)  
         cout<<setw(4)<<left<<chessboard[j][k];  
      cout<<""<<endl;  
   }  
   delete chessboard;  
    
   return 0;  
}  
//a?B,V? BoardSide?x,y
// As well as the Tromino length for all the possible answers or looks   
void Trom(int **a,int B,int V,int BoardSide,int x,int y)   
{                                                            
   int i=BoardSide/2;              
   if(i-1==0)  
   {  
      if(x <= B + i-1 && y > V +i-1)      
         a[B+i-1][V+i-1]= a[B+i][V+i-1] = a[B+i][V+i]= Traget++;     
      else if(x<=B+i-1&&y<=V+i-1)   
         a[B+i-1][V+i] = a[B+i][V+i] = a[B+i][V+i-1]= Traget++;       
      else if(x>B+i-1&&y<=V+i-1)    
         a[B+i-1][V+i-1] = a[B+i-1][V+i] = a[B+i][V+i] = Traget++;     
      else  
         a[B+i-1][V+i-1] = a[B+i-1][V+i] = a[B+i][V+i-1] = Traget++;   
   }  
   else  
   {  
      if(x <= B+i-1 && y > V+i-1)   
      {     
         a[B+i-1][V+i-1] = a[B+i][V+i-1] = a[B+i][V+i] = Traget++;  
         Trom(a,B,V+i,i,x,y);                
         Trom(a,B,V,i,B+i-1,V+i-1);              
         Trom(a,B+i,V,i,B+i,V+i-1);           
         Trom(a,B+i,V+i,i,B+i,V+i);              
      }  
      else if(x <= B+i-1 && y<=V+i-1)  
      {  
         a[B+i-1][V+i] = a[B+i][V+i] = a[B+i][V+i-1] = Traget++;  
         Trom(a,B,V+i,i,B+i-1,V+i);            
         Trom(a,B,V,i,x,y);              
         Trom(a,B+i,V,i,B+i,V+i-1);           
         Trom(a,B+i,V+i,i,B+i,V+i);             
      }  
      else if(x > B+i-1 && y <= V+i-1)  
      {  
         a[B+i-1][V+i-1] = a[B+i-1][V+i] = a[B+i][V+i] = Traget++;  
         Trom(a,B,V+i,i,B+i-1,V+i);            
         Trom(a,B,V,i,B+i-1,V+i-1);         
         Trom(a,B+i,V,i,x,y);           
         Trom(a,B+i,V+i,i,B+i,V+i);             
      }  
      else  
      {  
         a[B+i-1][V+i-1] = a[B+i-1][V+i] = a[B+i][V+i-1] = Traget++;   
         Trom(a,B,V+i,i,B+i-1,V+i);            
         Trom(a,B,V,i,B+i-1,V+i-1);        
         Trom(a,B+i,V,i,B+i,V+i-1);          
         Trom(a,+i,V+i,i,x,y);              
      }  
   }  
}   
