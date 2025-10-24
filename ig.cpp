#include <iostream>
using namespace std;

// Функция для нахождения максимума в двумерном массиве
int func(int arr[][3], int m, int n) 
{
 int maxx = arr[0][0]; // начинаем с первого элемента
 for (int i = 0; i < m; i++) 
 {
  for (int j = 0; j < n; j++) 
  {
   if (arr[i][j] > maxx) 
   {
    maxx = arr[i][j];
   }
  }
 }
 return maxx;
}

int main() 
{
 int arr[2][3] = {{1, 5, 3}, {4, 2, 6}};
 int maxNumber = func(arr, 2, 3);
 cout << maxNumber << endl;
 return 0;
}