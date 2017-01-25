#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,i,j,ans;
	cin>>n>>m;
	long long coin[m];
	for(i=0;i<m;i++)
	 cin>>coin[i];
	long long T[m][n+1];
	for(i=0;i<m;i++)
	{   
		for(j=0;j<n+1;j++)
		   T[i][j]=0;
	}
	for(i=0;i<m;i++)
	 T[i][0]=1;
	 for(i=0;i<m;i++)
	{   
	   cout<<"\n";
		for(j=0;j<n+1;j++)
		 cout<<T[i][j]<<" ";
	}
	for(i=0;i<n;i++)
	{
	   	for(j=1;j<=m+1;j++)
		{
			if(coin[i]>j)
			 T[i][j]=T[i-1][j];
			else
			 T[i][j]=T[i-1][j]+T[i][j-coin[i]];
		}
	}
	for(i=0;i<m;i++)
	{   
	   cout<<"\n";
		for(j=0;j<n+1;j++)
		 cout<<T[i][j]<<" ";
	}
	ans=T[i-1][j-1];
	cout<<ans<<endl;
}
