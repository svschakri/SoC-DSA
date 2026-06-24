
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj,int start){
    int n=adj.size();
    vector<bool> visited(n,false);
    queue<int> q;
    vector<int> order;
    q.push(start);
    visited[start-1] = true;

    while(!q.empty()){
        int val = q.front();
        q.pop();
        order.push_back(val);
        for(auto a : adj[val-1]){
        if(!visited[a-1]){
            visited[a-1] = true;
            q.push(a);
            }
        }
    }
    return order;
}
vector<int> dfs(vector<vector<int>>& adj,int start){
    int n=adj.size();
    vector<bool> visited(n,false);
    stack<int> q;
    vector<int> order;
    q.push(start);
    visited[start-1] = true;
    
    while(!q.empty()){
        int val = q.top();
        q.pop();
        order.push_back(val);


        for(int i=adj[val-1].size()-1;i>-1;i--){
            int a=adj[val-1][i];
            if(!visited[a-1]){
                visited[a-1] = true;
                q.push(a);
                }
            }
        }
    return order;
}

int main(){
    vector<vector<int>>v(5);
    v[0]={2,3};
    v[1]={1,4}; 
    v[2]={1,4}; 
    v[3]={2,3,5}; 
    v[4]={4}; 
    vector<int> b=bfs(v,1),d=dfs(v,1);
    for(auto c : d){
        cout<<c<<' ';
    }
    cout<<'\n';
    for(auto c : b){
        cout<<c<<' ';
    }
    cout<<'\n';
}