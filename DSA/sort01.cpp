#include <iostream>
using namespace std;

int main()
{
  int n = 8;
  int left = 0;
  int right = n - 1;

  int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

  while (left < right)
  {
    while (arr[left] == 0 && left < right)
    {
      left++;
    }
    while (arr[right] == 1 && left < right)
    {
      right--;
    }
    if (left < right)
    {

      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i]<<" ";
  }
  return 0;
}