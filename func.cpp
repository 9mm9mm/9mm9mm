#include "class.h"
void T::BubbleSort()
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

void T::print(ostream &os) const 
{
 os << P <<'\t';
 for (int i = 0; i<n; i++){os << v[i] << ' ';}
 os << '\n';
}