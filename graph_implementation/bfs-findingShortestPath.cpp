#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define sc(a) scanf("%lld",&a)
vector< vector<ll> >adj;
bool visited[100005];
ll bfs(ll x){
	queue<pair<ll,ll> >q;
	visited[1]=true;
	q.push(make_pair(1,0));
	while(!q.empty()){
		pair<ll,ll> temp;
		temp=q.front();
		q.pop();
		ll v=temp.first, c=temp.second;
		if(v==x) return c;
		for(ll i=0;i<adj[v].size();i++){
			if(visited[adj[v][i]]==false){
				if(adj[v][i]==x) return c+1;
				visited[adj[v][i]]=true;
				q.push(make_pair(adj[v][i],c+1));
				}
			}
		}
		return -1;
	}


int main(){
	ll t,n,m,x,y,i;
	sc(t);
	while(t--){
		sc(n);sc(m);
		adj.clear();
		adj.resize(n+5);
		for(i=0;i<m;i++){
			sc(x);sc(y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(visited,false,sizeof(visited));
		cout<<bfs(n)<<endl;
	}
	
}
