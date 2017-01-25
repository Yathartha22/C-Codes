#include<bits/stdc++.h>
using namespace std;
string a,b;
int max(int a, int b){
	return (a>b) ? a : b;
}
int lcs(){
	int i,j;
	int m=a.length();
	int n=b.length();
	int l[m+1]
	[n+1];
	for ( i=0;i<=m;i++){
		for( j=0;j<=n;j++){
			if(i==0 || j==0) l[i][j]=0;
			else if(a[i-1]==b[j-1])  l[i][j]=1+l[i-1][j-1];
			else l[i][j]=max(l[i-1][j],l[i][j-1]);
		}
	}
	for(i=1;i<=m;i++){
		cout<<endl;
		for(j=1;j<=n;i++) cout<<l[i][j]<<" ";
	}
		return l[m][n];
}
int main(){
	cin>>a>>b;
	cout<<lcs();
}
