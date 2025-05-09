#include <iostream>
using namespace std;
#include <stack>
#include <queue>


//adj_mat,n,0,visited
void dfs(int adj_mat[10][10],int n,int node,int visited[10])
{
	cout<<"DFS"<<endl;

//	return;
	

  stack<int> stk; // ✅ define stack object
  stk.push(node);
	visited[node] = 1;

	while(!stk.empty()){
		int i = stk.top();
		stk.pop();
		cout<<i<<"-->";
		for(int j=n-1;j>=0;j--){
			if(adj_mat[i][j]==1 && visited[j]!=1){
				stk.push(j);
				visited[j] = 1;
			}
		}
	}
	cout<<"NULL"<<endl;
}
void bfs(int adj_mat[10][10],int n,int node,int visited[10])
{
	cout<<"BFS"<<endl;
//	return;

	queue<int> q;
	q.push(node);
	visited[node] = 1;

	while(!q.empty()){
		int i = q.front();
		q.pop();

		cout<<i<<"-->";
		for(int j=0;j<n;j++){
			if(adj_mat[i][j]==1 && visited[j]!=1){
				q.push(j);
				visited[j] = 1;
			}
		}
	}
	cout<<"NULL"<<endl;

}




int main() {

	int n;
	int adj_mat[10][10] = {0},visited[10] = {0};

	cout<<"Enter the total number of nodes in the graph --> ";
	cin>>n;


	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<"Do you want to add the Edge between "<<i<<" and "<<j<<"?. (Y or N) ";
			char s;	cin>>s;
			if(s=='y' || s=='Y'){
				adj_mat[i][j] = adj_mat[j][i] = 1;
			}
		}
	}

	int ch;
	do{

		cout<<"\n\n";
		cout<<"1. DFS"<<endl;
		cout<<"2. BFS"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Enter Choice:- ";
		cin>>ch;
		switch(ch){
			case 1:
				for(int i=0;i<n;i++)	visited[i] = 0;
				cout<<"DFS on the given graph is :- ";
				dfs(adj_mat,n,0,visited);
				break;
			case 2:
				for(int i=0;i<n;i++)	visited[i] = 0;
				cout<<"BFS on the given graph is :- ";
				bfs(adj_mat,n,0,visited);
				break;
			case 0:
				break;
			default:
				cout<<"Invalid Choice \n\n";
			break;
		}

	}while(ch!=0);

	cout<<"Program Finished ";




	return 0;
}








// #include<bits/stdc++.h>
// using namespace std;
// void bfs_rec(vector<int>vec[],vector<int> &visit, queue<int> & q,vector<int> & ans)
// {
//     if(q.empty())
//     {
//         return ;
//     }
//     int ele=q.front();
//     q.pop();
//     ans.push_back(ele);
//     vector<int>a=vec[ele];
//     for(int i=0;i<a.size();i++)
//     {
//         if(!visit[a[i]])
//         {
//             visit[a[i]]=1;
//             cout<<"Visiting "<<a[i]<<" Vertex and inserting it into queue\n";
//             q.push(a[i]);
//         }
//     }
//     bfs_rec(vec,visit,q,ans);
// }
// void BFS(vector<int>vec[],int n)
// {
//     vector<int>visit(n+1,0);
//     queue<int>q;
//     vector<int>ans;
//     for(int i=1;i<=n;i++)
//     {
//         if(visit[i]==0)
//         {

//             visit[i]=1;
//             cout<<"Visiting "<<i<<" Vertex and inserting it into stack\n";
//             q.push(i);
//              bfs_rec(vec,visit,q,ans);
//         }
//     }
//     cout<<"\nBFS Traversal is : ";
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<"\n";

// }
// void bfs_rec_search(vector<int>vec[],vector<int> &visit, queue<int> & q,vector<int> & ans,int & find,int target)
// {
//     if(q.empty())
//     {
//         return ;
//     }
//     int ele=q.front();
//     q.pop();
//     ans.push_back(ele);
//     if(ele==target)
//     {
//         find=1;
//         return ;
//     }

//     vector<int>a=vec[ele];
//     for(int i=0;i<a.size();i++)
//     {
//         if(!visit[a[i]])
//         {
//             visit[a[i]]=1;

//             q.push(a[i]);
//         }
//         if(find==1)
//         {
//             break;
//         }
//     }
//     if(find!=1)
//     {
//         bfs_rec_search(vec,visit,q,ans,find,target);
//     }
// }
// void BFS_Search(vector<int>vec[],int n,int target)
// {
//      vector<int>visit(n+1,0);
//     queue<int>q;
//     vector<int>ans;
//     int find=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(visit[i]==0)
//         {
//             visit[i]=1;
//             q.push(i);
//             bfs_rec_search(vec,visit,q,ans,find,target);
//         }
//         if(find==1)
//         {
//             break;
//         }
//     }
//     if(find==1)
//     {
//         cout<<"\nVertex Found \n";
//         cout<<"\nBFS Traversal for vertex "<< target <<" is : ";
//         for(int i=0;i<ans.size();i++)
//         {
//             cout<<ans[i]<<" ";
//         }
//         cout<<"\n";
//     }
//     else
//     {
//         cout<<"\nVertex Not Found \n";
//     }

// }
// void dfs_rec(vector<int>vec[],vector<int> &visit,stack<int>st,vector<int> &ans)
// {
//     int n=st.top();
//     st.pop();
//      vector<int>a=vec[n];
//      ans.push_back(n);
//     // cout<<n<<" ";
//      for(int i=0;i<a.size();i++)
//      {
//          int ele=a[i];
//          if(visit[a[i]]==0)
//          {
//              visit[a[i]]=1;
//              cout<<"Visiting "<<a[i]<<" Vertex and inserting it into stack\n";
//             st.push(a[i]);
//              dfs_rec(vec,visit,st,ans);
//          }
//      }
// }
// void dfs_rec_search(vector<int>vec[],vector<int> &visit,stack<int>st,vector<int> &ans,int & find,int target)
//  {
//       int n=st.top();
//     st.pop();
//      vector<int>a=vec[n];
//      ans.push_back(n);
//      if(n==target)
//      {
//          find=1;
//          return;
//      }

//      for(int i=0;i<a.size();i++)
//      {
//          int ele=a[i];
//          if(visit[a[i]]==0)
//          {
//              visit[a[i]]=1;

//              st.push(a[i]);
//              dfs_rec_search(vec,visit,st,ans,find,target);
//              if(find==1)
//              {
//                  break;
//              }
//          }
//      }
//  }
// void DFS_Search(vector<int>vec[],int n,int target)
// {
//     vector<int>ans;
//     vector<int>visit(n+1,0);
//     stack<int>st;
//       int find=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(visit[i]==0)
//         {
//             visit[i]=1;

//             st.push(i);
//             dfs_rec_search(vec,visit,st,ans,find,target);
//         }
//         if(find==1)
//         {
//             break;
//         }
//     }
//      if(find==1)
//     {
//         cout<<"\nVertex Found \n";
//         cout<<"\nDFS Traversal for vertex is : ";
//         for(int i=0;i<ans.size();i++)
//         {
//             cout<<ans[i]<<" ";
//         }
//         cout<<"\n";
//     }
//     else
//     {
//         cout<<"\nVertex Not Found \n";
//     }
// }
// void DFS(vector<int>vec[],int n)
// {
//     vector<int>ans;
//     vector<int>visit(n+1,0);
//     stack<int>st;
//     for(int i=1;i<=n;i++)
//     {
//         if(visit[i]==0)
//         {
//             visit[i]=1;
//             cout<<"Visiting "<<i<<" Vertex and inserting it into stack\n";
//             st.push(i);
//             dfs_rec(vec,visit,st,ans);
//         }
//     }

//      cout<<"\nDFS Traversal is : ";
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<"\n";


// }

// int main()
// {
//     int n,edge,u,v;
//     cout<<"Enter Number of Vertices : ";
//     cin>>n;
//     vector<int>vec[n+1];
//     cout<<"Enter Number of Edges : ";
//     cin>>edge;
//     for(int i=0;i<edge;i++)
//     {
//         cout<<"Enter source index : ";
//         cin>>u;
//         cout<<"Enter destination vertex : ";
//         cin>>v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }

//     cout<<"\nGraph\n";

//     for(int i=1;i<n+1;i++)
//     {
//         cout<<i<<" -> ";
//         vector<int>a=vec[i];
//         for(int j=0;j<vec[i].size();j++)
//          {
//              cout<<a[j]<<" ";
//          }
//         cout<<"\n";
//     }

//     cout<<"\n\nBFS Treversal \n\n";
//     BFS(vec,n);

//     cout<<"\n\nDFS Treversal \n\n";
//     DFS(vec,n);

//     while(1)
//     {
//         cout<<"\n\nEnter the node to search : ";
//         int node;
//         cin>>node;
//         cout<<"\n1. BFS";
//         cout<<"\n 2.DFS";
//         cout<<"\n 3. Exit";
//         cout<<"\nChoice : ";
//         int ch;
//         cin>>ch;
//         switch(ch)
//         {
//             case 0:
//                 exit(1);
//                 break;
//             case 1:
//                 BFS_Search(vec,n,node);
//                 break;
//             case 2:
//                 DFS_Search(vec,n,node);
//                 break;
//             default:
//             cout<<"Invalid choice\n";
//         }
//     }
// }