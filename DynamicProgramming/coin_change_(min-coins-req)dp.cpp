#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,n,m,i,j,sum,ma,na,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;  sum=0;                     //n=sum m=no.of denominations
		long long coins[m+1],T[m+1][n+1];
		memset(coins,0,sizeof(coins));
		for(i=0;i<m+1;i++)
        { 
		  for(j=0;j<n+1;j++)
           T[i][j]=100000;
        }
        for(i=1;i<m+1;i++)
	    {    
	      T[i][0]=0;
	    } 
			
        for(i=1;i<m+1;i++)
         cin>>coins[i];
         
		for(i=1;i<m+1;i++)
		{
			for(j=1;j<n+1;j++)
			 {
			 	if(j>=coins[i])
	    	 		T[i][j]=min(T[i-1][j],1+T[i][j-coins[i]]);
				 else
				  T[i][j]=T[i-1][j];
			 }
		}
	
		cout<<"min no. of coins are "<<T[m][n]<<endl;
		x=T[m][n];ma=m;na=n;
//		cout<<ma<<na;
		while(T[m][n]!=0)
		{
			if(T[ma][na]==T[ma-1][na])
			{
			 ma=ma-1;
		    }
			else
			 {
			 na=na-coins[ma];
		     }
		    cout<<ma<<na<<endl;
		    sum+=coins[ma];
		 }
		 cout<<sum<<endl;
	}
}
