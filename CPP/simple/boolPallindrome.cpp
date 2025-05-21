#include<iostream>
#include<climits>

using namespace std;

int main(){
  int ans =0;
  int x;
  cin>>x;
  int orginal = x;
  while(x!=0){
    int digit = x%10;

    if((ans>INT_MAX)||(ans<INT_MIN)){
      return 0;
    }
    ans = (ans*10)+digit;
    x = x/10;
    
  }


  cout<<ans<<endl;

  if(ans == orginal){
    cout<<"Integer is Pallindrome"<<endl;
  }
  else{
    cout<<"Not Pallindrome"<<endl;
  }
  return 0;

}