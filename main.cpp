#include "class.h"
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
    for(int j=0;j<n;j++){matrix[j].BubbleSort();}
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