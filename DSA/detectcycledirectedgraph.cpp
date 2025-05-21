#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class solution{
  public:
    bool iscycle(int v,vector<int>adj[]){
      int indegree[v]={0};
      for(int i=0;i<v;i++){
        for(auto it:adj[i]){
          if(indegree[it]==0){
            indegree[it]++;
          }
        }
      }
      queue<int>q;
      for(int i=0;i<v;i++){
        if(indegree[i]==0){
          q.push(i);
        }
      }
      vector<int>ans;

      while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
          indegree[it]--;
          if(indegree[it]==0){
            q.push(it);
          }
        }
      }
      if(ans.size()==v){
        return false;
      }
      return true;
    }
};

int main(){
  int v,e;
  cin>>v>>e;
  vector<int>adj[v];
 for(int i=0;i<e;i++){
  int u,w;
  cin>>u>>w;
  adj[u].push_back(w);
 }
 solution s;
 bool ans = s.iscycle(v,adj);
 if(ans){
  cout<<"cycle is present"<<endl;
 }
 else{
  cout<<"cycle is not present"<<endl;
 }
 return 0;
}