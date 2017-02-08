#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
const ll MAX = 1e6 + 5;
ll id[MAX], nodes, edges;
pair <long long, pair<ll, ll> > p[MAX];
vector<ll> ff;
void initialize()
{
    for(ll i = 0;i < MAX;++i)
        id[i] = i;
}

ll root(ll x)
{
   while(id[x]!=x){
   	id[x]=id[id[x]];
   	x=id[x];
   }
   return x;
}

void union1(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = q;
}

long long kruskal(pair<long long, pair<ll, ll> > p[])
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
            ff.push_back(cost);
        }    
    }
    return minimumCost;
}

int main()
{
    ll x, y;
    long long weight,c=0, minimumCost,i;
    initialize();
    cin >> nodes >> edges;
//    if(k<nodes-1) {cout<<"-1"<<endl;return 0;}
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout<<minimumCost<<endl;
//    reverse(ff.begin(),ff.end());
//    i=0;
//    while(minimumCost > k){
//    	minimumCost-=ff[i++] - 1;
//    	c++;
//	}
//	for(ll i=2;i<=nodes;i++)
//		if(p[root(i)] !=p[root(1)]){
//			cout<<"-1"<<endl;
//			return 0;
//		}
//	cout<<c<<endl;
	
    return 0;
}	
