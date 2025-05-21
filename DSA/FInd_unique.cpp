#include<iostream>
using namespace std;

int findunique(int num[],int size){
  int ans = 0;
  for(int i =0;i<size;i++){
    ans =ans^num[i];
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  int arr[100];
  for(int i = 0;i<n;i++){
    cin>>arr[i];
  }

  int val=findunique(arr,n);
  cout<<val<<endl;

  return 0;

}