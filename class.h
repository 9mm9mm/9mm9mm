#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class T 
{
 public:
  int P{};
  vector<int> data;
  void sortRow() 
  {
   if (P == 1){sort(data.begin(), data.end());}
   else{sort(data.begin(), data.end(), greater<int>());}
  }
  void print(ofstream &fout) const 
  {
   fout << P;
   for (int x : data){fout << ' ' << x;}
   fout << '\n';
  }
};