#include "class.h"
bool compareByP(const T &a, const T &b){return a.P > b.P;}

int main() 
{
 ifstream fin("data.dat");
 ofstream fout("data.res");
 if (!fin){fout << "error";return 0;}
 vector<T> rows;
 string line;
 while(getline(fin, line)) 
 {
  if (line.empty()) continue;
  istringstream iss(line);
  T temp;
  if (!(iss >> temp.P)) continue;
  int x;
  while (iss >> x) temp.data.push_back(x);
  if (!temp.data.empty())
  rows.push_back(temp);
 }
 if (rows.empty()){fout << "no empty";}
 for (auto &r : rows){r.sortRow();}
 sort(rows.begin(), rows.end(), compareByP);
 for (const auto &r : rows){r.print(fout);}
 return 0;
}