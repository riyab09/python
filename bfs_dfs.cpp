#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void dfs(int adj_mat[10][10],int n,int node,int visited[10]){
    int i;
    cout<<"dfs ";
    stack<int>stk;
    stk.push(node);
    visited[node]=1;
    while(!stk.empty()){
        i=stk.top();
        stk.pop();
        cout<<i<<"-->";
       
            for(int j=n-1;j>=0;j--){
                if(adj_mat[i][j]==1 && visited[j]!=1){
                    visited[j]=1;
                    stk.push(j);
                }
            }
        

    }
    cout<<"NULL"<<endl;
}

void bfs(int adj_mat[10][10],int n,int node,int visited[10]){
    int i;
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        i=q.front();
        q.pop();
        cout<<i<<"-->";
       
            for(int j=n-1;j>=0;j--){
                if(adj_mat[i][j]==1 && visited[j]!=1){
                    visited[j]=1;
                    q.push(j);
                }
            }
        

    }
    cout<<"NULL"<<endl;
}

int main(){
    int n;
    char s;
    int adj_mat[10][10]={0},visited[10]={0};
    cout<<"enter how many nodes do you want";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"do you want edge in between"<<i <<"and"<<j;
            cin>>s;
            if(s=='y' || s=='Y'){
                adj_mat[i][j]=adj_mat[j][i]=1;
            }
        }
    }
    int ch;
    do{
      cout<<"1. dfs"<<endl;
      cout<<"2. bfs"<<endl;
      cout<<"3. exit"<<endl;
      cin>>ch; 
      
      switch(ch){
        case 1: for(int i=0;i<n;i++)	visited[i] = 0;
                dfs(adj_mat,n,0,visited);
                break;
        case 2: for(int i=0;i<n;i++)	visited[i] = 0; 
                bfs(adj_mat,n,0,visited);
                break;
        case 3:  break;
    }
    }while (ch!=3);
    
   

}