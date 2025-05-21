#include<iostream>
using namespace std;

class integer
{
  int m,n;
  public:
  integer(int,int);

  void display(void){
    cout<<"m = "<<m<<"\n";
    cout<<"n = "<<n<<"\n";
  }
};
 integer::integer(int x ,int y){
  m = x;
  n = y;
 }

 int main(){
  integer int1(0,100);
  integer int2(25,75);
  int1.display();
  int2.display();
  return 0;
}
