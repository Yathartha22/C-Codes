#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v[2000+10];
ll dis[1000+10];
int main(){
	ll n,m,from,next,weight,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		v[i].clear();
		dis[i]=2e9;
	}
	for(i=1;i<=m;i++){
		cin>>from>>next>>weight;
		v[i].push_back(from);
		v[i].push_back(next);
		v[i].push_back(weight);
	}
	dis[1]=0;
//    for(i=1;i<=m;i++){
//    	for(j=0;j<v[i].size();j++){
//    		cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
   for(j=1;j<=m;j++){
   	 i=1;
//   	 cout<<v[i].size()<<endl;
   	 while(v[i].size()!=0){
   	 	if((dis[v[i][0]] + v[i][2]) < dis[v[i][1]] ){
   	 		dis[v[i][1]] = dis[v[i][0]] + v[i][2];
			}
			i++;
		}
   }
   for(i=2;i<=m;i++)
    cout<<dis[i]<<" ";
}
