 /*
  Finding number of nodes in a particular level using bfs
*/

#include<bits/stdc++.h>
using namespace std;
vector< vector<int> >adj;
bool visited[100005];
int bfs(int x){
	queue<int>q;
	vector<int> l[100005];
	int c=0,k=2;
	l[1].push_back(1);
	visited[1]=true;
	q.push(1);	
	while(!q.empty()){
		int current=q.front();
		q.pop();
		for(int i=0;i<adj[current].size();i++){
			if(visited[adj[current][i]]==false){
				l[k].push_back(adj[current][i]);
				q.push(adj[current][i]);
				visited[adj[current][i]]=true;
			}
			 
		}
		c++;
		if(c==l[k-1].size()){
			k++;
			c=0;
		}
	}
	return l[x].size();
}
int main(){
	int n,x,y,i,ans,a;
    cin>>n;
    adj.clear();
    adj.resize(n+5);
    for(i=0;i<n-1;i++){
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
	}
	cin>>a;
	memset(visited,false,sizeof(visited));
	ans=bfs(a);
	cout<<ans<<endl;
	
}
