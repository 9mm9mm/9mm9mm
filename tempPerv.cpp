#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
  void sort()
  {
   if (n == 0) return;
   if (P == 1) 
   {
    for (int i = 0; i < n - 1; i++)
    {
     for (int j = 0; j < n - i - 1; j++) 
     {
      if (v[j] < v[j + 1]){swap(v[j], v[j + 1]);}
     }
    }
   } 
   else 
   {
    for (int i = 0; i < n - 1; i++) 
    {
     for (int j = 0; j < n - i - 1; j++)
     {
      if (v[j] > v[j + 1]){swap(v[j], v[j + 1]);}
     }
    } 
   }
  }

  void print(ostream &os) const 
  {
   os << P <<'\t';
   for (int i = 0; i<n; i++){os << v[i] << ' ';}
   os << '\n';
  }

};


int main()
{
 ofstream out("data.res");
 T* matrix = nullptr;
 int n=0;
 for(int I=0;I<2;I++)
 {
  ifstream in("data.dat");
  if(!in){out<<"ERROR"<<endl;return -1;}
  string line;
  if(I==0)
  {
   while(getline(in, line)){if(line.empty()){continue;} n++;}
   matrix = new T[n]; 
  }
  else
  {
   int i=0;
   int all = 0, max_elem = 0, n_elem;
   while(getline(in, line))
   {
    int value;
    if(line.empty()){continue;}
    istringstream iss(line);
    vector<int> values;
    while(iss>>value){values.push_back(value);}
    matrix[i] = values;
    n_elem = values.size();
    all += n_elem;
    if(n_elem>max_elem){max_elem=n_elem-1;}
    i++; 
   }
   if((all-i)%max_elem != 0){out<<"ERROR"<<endl;delete [] matrix;return -1;}
   else
   {
    for(int j=0;j<n;j++){matrix[j].sort();}
    for (int i = 0; i < n - 1; i++) 
    {
     for (int j = 0; j < n - i - 1; j++) 
     {                                      
      if (matrix[j].n > 0 && matrix[j+1].n > 0)
      { 
       if (matrix[j][0] < matrix[j + 1][0]){swap(matrix[j],matrix[j + 1]);}
      }
     }
    }
    for(int j=0;j<n;j++){matrix[j].print(out);}
    out<<endl;
   }
  }
  in.close();
 }
 delete [] matrix;
 out.close();
 return 0;
}