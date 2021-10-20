#include <bits/stdc++.h>

using namespace std;


class UF {
	vector<long long> parent, rank;
public:
	
	UF(long long n)
	{
		this->parent.resize(n,0);
		this->rank.resize(n,1);
		for(long long i=0;i<n;i++)
			this->parent[i] = i;
	}
	long long find(long long a)
	{
		if(this->parent[a] == a)
			return a;

		return this->parent[a] = find(this->parent[a]);
	}

	bool unify(long long a, long long b)
	{
		long long x = this->find(a);
		long long y = this->find(b);

		if(x==y)
			return false;

		if(this->rank[x] > this->rank[y])
		{
			this->parent[y] = x;
			this->rank[x] += this->rank[y];
		}
		else
		{
			this->parent[x] = y;
			rank[y] += rank[x];
		}
		return true;
	}

};

int main() {
	long long n,m;
	cin>>n>>m;
	vector<vector<long long>> g;

	long long _e = m;
	while(_e--)
	{
		long long a, b,w;
		cin>>a>>b>>w;
		g.push_back({w,a,b});
	}
	sort(g.begin(), g.end());

	UF dsu(n);

	long long idx = 0;
	long long cost = 0;
	for(long long i=1;i<=m-1 && idx<m;i++)
	{
		auto x = g[idx++];
		long long wt = x[0], a = x[1], b = x[2];
		if(!dsu.unify(a,b))
		{
			i--;
			continue;
		}
		cost += wt;
	}
	cout<<cost<<endl;
	return 0;
}
