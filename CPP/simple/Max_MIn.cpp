#include<iostream>
#include<climits>

using namespace std;

int getmin(int num[],int n){
  int min = INT_MAX;
   for(int i=0;i<n;i++){
    if(num[i]<min){
      min = num[i];
    }
   }
   return min;
}

int getmax(int num[],int n){
  int max = INT_MIN;
   for(int i=0;i<n;i++){
    if(num[i]>max){
      max = num[i];
    }
   }
   return max;
}

int main(){
  int size;
  cin>>size;
  int num[100];

  for(int i = 0;i<size;i++){
    cin>>num[i];
  }

  int max = getmax(num,size);
  int min = getmin(num,size);
  cout<<"Maximum "<<max<<endl;
  cout<<"Minimum "<<min<<endl;


  return 0;
}