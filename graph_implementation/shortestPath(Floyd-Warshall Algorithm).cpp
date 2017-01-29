#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	map<string,int>mp;
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]=i;
	}
	long long dis[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		 dis[i][j]=INT_MAX;
	}
	while(m--){
		string src,dest;
		long long d;
		cin>>src>>dest>>d;
		dis[mp[src]][mp[dest]]=d;
		dis[mp[dest]][mp[src]]=d;
	}
	for(int k=0;k<n;k++)
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    		}
    	}
    }
    int q;
    cin>>q;
    while(q--){
    	string src,dest;
    	cin>>src>>dest;
    	cout<<dis[mp[src]][mp[dest]]<<endl;
	}
}
