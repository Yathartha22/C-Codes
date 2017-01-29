#include<bits/stdc++.h>
using namespace std;
int ar[100005];
vector< vector<int> > adj;
bool visited[100005];
long long  dfs(int pos){
	if(visited[pos]==true)
	 return 0;
	visited[pos]=true;
	long long sum=ar[pos];
	for(int i=0;i<adj[pos].size();i++){
		if(visited[adj[pos][i]]==false)
		 sum+=dfs(adj[pos][i]);
	}
	return sum;
	
}
int main(){
	int t;
	cin>>t;
	int n,m,x,y;
	while(t--){
        
		long long res=10000000,ans;
		cin>>n>>m;
		// for(int i=0;i<m;i++){
		// 	for(int j=0;j<m;j++)
  //          	adj[i][j].clear();
  //      }
         adj.clear();
		adj.resize(n+5);
		for(int i=0;i<m;i++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=n;i++){
			if(visited[i]==false){
			  ans=dfs(i);
			  //cout<<ans<<endl;
			  res=min(res,ans);
			}
		}
		cout<<res<<endl;
	
	}
}	
