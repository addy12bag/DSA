#include<iostream>
#include <climits>

using namespace std;

int main(){
  int ans = 0;
  int x;
  cout<<"Enter the integer"<<endl;
  cin>>x;
  while(x!=0){
    int digit = x % 10;
    if ((ans > INT_MAX) || (ans < INT_MIN/10)){
      return 0;
    }
    ans = (ans * 10)+digit;
    x = x/10;
    
  }
  cout<<ans<<endl;
  return 0;
}