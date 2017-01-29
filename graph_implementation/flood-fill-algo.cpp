/* MAZE PROBLEM */

#include<bits/stdc++.h>
using namespace std;
int n,m;
int ar[15][15];
bool visited[15][15];
bool dfs(int x, int y,int dest_x, int dest_y){
	if(x==dest_x && y==dest_y) return true;
	if(x>n || y>m) return false;
	if(x<0 || y<0) return false;
	if(visited[x][y]) return false;
	if(ar[x][y]==0) return false;
	visited[x][y]=true;
	if(dfs(x+1,y,dest_x,dest_y)== true) return true;
	if(dfs(x-1,y,dest_x,dest_y)==true) return true;
	if(dfs(x,y+1,dest_x,dest_y)==true) return true;
	if(dfs(x,y-1,dest_x,dest_y)==true) return true;
}
int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		 cin>>ar[i][j];
	}
	memset(visited,false,sizeof(visited));
	bool ans=dfs(1,1,n,m);
	if(ans) cout<<"Yes";
	else cout<<"No";
	
}
