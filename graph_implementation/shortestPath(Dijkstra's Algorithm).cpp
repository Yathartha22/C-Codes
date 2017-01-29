#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> >v[100005];
ll dis[100005];
bool visited[100005];
multiset<pair <ll,ll> > s;
int main(){
	ll n,m,from,next,weight,i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		v[i].clear();
		dis[i]=2e9;
	}
	for(i=1;i<=m;i++){
		cin>>from>>next>>weight;
	    v[from].push_back(make_pair(next,weight));
	    v[next].push_back(make_pair(from,weight));
	}
//	    for(i=1;i<=m;i++){
//    	for(ll j=0;j<v[i].size();j++){
//    		cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
    dis[1]=0;
    s.insert({0,1});
    memset(visited,false,sizeof(visited));
    while(!s.empty()){
    	pair<ll,ll>p= *s.begin();
    	s.erase(s.begin());
    	ll x=p.second;
    	ll wei=p.first;
    	if(visited[x]) continue;
    	for(i=0;i<v[x].size();i++){
    		ll e=v[x][i].first;
    		ll w=v[x][i].second;
    		if(dis[x]+w < dis[e]){
    			dis[e]=dis[x]+w;
    			s.insert({dis[e],e});
			}
		}
	}
    for(i=2;i<=m;i++)
     cout<<dis[i]<<" ";
}
