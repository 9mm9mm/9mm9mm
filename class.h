#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
class T
{
 int P;   
 int *v;
 public:
  int n;
  T(int P, int n=0){if(n){this->P=P;v=new int[this->n=n]; for(int i; i<n; i++){v[i]= int();}}else{SetZero();}};
  T(){SetZero();}
  ~T(){Clean();}
  T(const T&b){CopyOnly(b);}
  T& operator=(const T&b){if(&b!=this){Clean();CopyOnly(b);}return *this;}
  void SetZero(){v=nullptr; n=0; P=0;};
  void Clean(){delete[] v; SetZero();};
  void CopyOnly(const T& b)
  { 
   if(b.n != 0)
   {
    v = new int[n=b.n];
    for(int i=0;i<n;i++){v[i] = b.v[i];}
    P = b.P;
   }
   else{SetZero();}
  }
  T(const vector<int>&b)
  {
   if(!b.empty())
   {
    this->n = b.size() - 1; 
    v = new int[n];
    P=b[0];
    for(int i=0; i<this->n;i++){v[i]=b[i+1];}
   }
   else{SetZero();}
  }
  int& operator[](int i){if(i>=n){cout<<i<<"bad index";}return v[i];}
  const int& operator[](int i)const{return v[i];}
  void BubbleSort();            
  void print(ostream &os) const;
};