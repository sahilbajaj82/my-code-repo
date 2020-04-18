#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
#define M 1000000007
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
vector<long long> pr;
long long N = 1200000;
long long lp[1200000+1];
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}
struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
ll countdivisors(vector<pair<long long,long long>> p) {
	ll count=1;
	for(auto i:p) {
		long long x=i.second;
		count=(count*(x+1))%M;
	}
	return count;
}
std::vector<pair<long long,long long>> demerge(std::vector<pair<long long,long long>> p1,vector<pair<long long,long long>> p2) {
	vector<pair<long long,long long>> p3;
	long long i1=p1.size();
	long long i2=p2.size();
	long long i=0,j=0;
	while(i<i1&&j<i2) {
		long long t1=p1[i].first;
		long long t2=p2[j].first;
		if(t1==t2) {
			p3.push_back(make_pair(t1,(p1[i].second-2*p2[j].second)));
			i++;
			j++;
		}
		else if(t1<t2) {
			p3.push_back(make_pair(t1,p1[i].second));
			i++;
		}
		else {
			p3.push_back(make_pair(t2,p2[j].second));
			j++;	
		}
	}
	while(i<i1) {
		p3.push_back(make_pair(p1[i].first,p1[i].second));
		i++;
	}
	return p3;
}
std::vector<pair<long long,long long>> merge(std::vector<pair<long long,long long>> p1,vector<pair<long long,long long>> p2) {
	vector<pair<long long,long long>> p3;
	long long i1=p1.size();
	long long i2=p2.size();
	long long i=0,j=0;
	while(i<i1&&j<i2) {
		long long t1=p1[i].first;
		long long t2=p2[j].first;
		if(t1==t2) {
			p3.push_back(make_pair(t1,(p1[i].second+p2[j].second)));
			i++;
			j++;
		}
		else if(t1<t2) {
			p3.push_back(make_pair(t1,p1[i].second));
			i++;
		}
		else {
			p3.push_back(make_pair(t2,p2[j].second));
			j++;	
		}
	}
	while(i<i1) {
		p3.push_back(make_pair(p1[i].first,p1[i].second));
		i++;
	}
	while(j<i2) {
		p3.push_back(make_pair(p2[j].first,p2[j].second));
		j++;
	}
	return p3;

}
ll change(ll x) {
    ll n=x;
    if(n>1000&&lp[n]==n)
        return n;
    for (long long d : pr) {
            if (d * d > n)
                break;
            if(lp[n]==n&&n>1000) {
                return n;
            }
            long long count=0;
            while (n % d == 0) {
                n /= d;
            }
    }
    if(n>1000&&lp[n]==n)
        return n;
    return 1;
}
vector<pair<long long,long long>> trial_division4(long long n) {
    vector<pair<long long,long long>> factorization;
    if(lp[n]==n&&n>1000)
    	return factorization;
    for (long long d : pr) {
        if (d * d > n)
            break;
        if(lp[n]==n&&n>1000) {
        	return factorization;
        }
        long long count=0;
        while (n % d == 0) {
        	count++;
            n /= d;
        }
        if(count>0) {
        	factorization.push_back(make_pair(d,count));
            }
        }
        if(n > 1) {
            if(n>1000&&lp[n]==n) {
            }
            else
                factorization.push_back(make_pair(n,1));
        }
    return factorization;
}

vector<ll> order;
ll tier=0;
std::vector<ll> st(100001),et(100001);
void dfsorder(ll i,std::vector<ll> *v,bool *visit) {
	order.push_back(i);
	visit[i]=true;
	st[i]=tier;
	tier++;
	for(auto j:v[i]) {
		if(!visit[j])
			dfsorder(j,v,visit);
	}
	et[i]=tier;
	tier++;
	order.push_back(i);
}
int block;
struct Query {
	int l, r, idx, lca;
	bool sp;
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};
inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}
ll get_answer(gp_hash_table<ll,ll> u1) {
	ll count=1;
	for(auto i:u1) {
		long long y=i.first;
		long long x=i.second;
		count=(count*binpow(y+1,x))%M; 
	}
	return count;
}
vector<ll> mo_s_algorithm(vector<Query> queries,vector<ll> val) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    gp_hash_table<ll,ll> store;
    gp_hash_table<ll,ll> freq;
    gp_hash_table<ll,ll> freq1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            if(lp[val[order[cur_l]]]==val[order[cur_l]]) {
            if(store[order[cur_l]]==1) {
            	store[order[cur_l]]=2;
            	ll x=val[order[cur_l]];
            	freq1[freq[x]]--;
            	freq[x]=freq[x]-1;
            	freq1[freq[x]]++;
            }
            else  {
            	store[order[cur_l]]=1;
            	ll x=val[order[cur_l]];
            	freq[x]=freq[x]+1;
            	if(freq[x]==1) {
            		freq1[freq[x]]++;
            	}
            	else {
            		freq1[freq[x]-1]--;
            		freq1[freq[x]]++;
            	}
            }
        	}
        }
        while (cur_r < q.r) {
            cur_r++;
            if(lp[val[order[cur_r]]]==val[order[cur_r]]) {
            if(store[order[cur_r]]==1) {
            	store[order[cur_r]]=2;
            	ll x=val[order[cur_r]];
            	freq1[freq[x]]--;
            	freq[x]=freq[x]-1;
            	freq1[freq[x]]++;
            }
            else  {
            	store[order[cur_r]]=1;
            	ll x=val[order[cur_r]];
            	freq[x]=freq[x]+1;
            	if(freq[x]==1) {
            		freq1[freq[x]]++;
            	}
            	else {
            		freq1[freq[x]-1]--;
            		freq1[freq[x]]++;
            	}
            }
        }
        }
        while (cur_l < q.l) {
        	if(lp[val[order[cur_l]]]==val[order[cur_l]]) {
             if(store[order[cur_l]]==1) {
            	store[order[cur_l]]=0;
            	ll x=val[order[cur_l]];
            	freq1[freq[x]]--;
            	freq[x]=freq[x]-1;
            	freq1[freq[x]]++;
            }
            else  {
            	store[order[cur_l]]=1;
            	ll x=val[order[cur_l]];
            	freq[x]=freq[x]+1;
            	if(freq[x]==1) {
            		freq1[freq[x]]++;
            	}
            	else {
            		freq1[freq[x]-1]--;
            		freq1[freq[x]]++;
            	}
            }
        }
            cur_l++;
        }
        while (cur_r > q.r) {
        	if(lp[val[order[cur_r]]]==val[order[cur_r]]) {
             if(store[order[cur_r]]==1) {
            	store[order[cur_r]]=0;
            	ll x=val[order[cur_r]];
            	freq1[freq[x]]--;
            	freq[x]=freq[x]-1;
            	freq1[freq[x]]++;
            }
            else  {
            	store[order[cur_r]]=1;
            	ll x=val[order[cur_r]];
            	freq[x]=freq[x]+1;
            	if(freq[x]==1) {
            		freq1[freq[x]]++;
            	}
            	else {
            		freq1[freq[x]-1]--;
            		freq1[freq[x]]++;
            	}
            }
        }
            cur_r--;
        }
        if(q.sp==false) {
        	 ll count=1;
                for(auto i:freq1) {
                    long long y=i.first;
                    long long x=i.second;
                    count=(count*binpow(y+1,x))%M; 
                }
                answers[q.idx]=count;
        }
        else {
        	// gp_hash_table <ll,ll> l1=freq1;
        	ll x=val[order[st[q.lca]]];
            if(lp[x]==x) {
        	    if(freq[x]==0) {
        		   freq1[1]++;
        	    }
        	    else {
        		    freq1[freq[x]]--;
        		    freq1[freq[x]+1]++;
        	    }
                ll count=1;
                for(auto i:freq1) {
                    long long y=i.first;
                    long long x=i.second;
                    count=(count*binpow(y+1,x))%M; 
                }
                answers[q.idx]=count;
                if(freq[x]==0) {
                    freq1[1]--;
                }
                else {
                     freq1[freq[x]]++;
                    freq1[freq[x]+1]--;
                }
           
            }
            else {
                  ll count=1;
                for(auto i:freq1) {
                    long long y=i.first;
                    long long x=i.second;
                    count=(count*binpow(y+1,x))%M; 
                }
                answers[q.idx]=count;
            }
            
        }
    }
    return answers;
}
int solve() {
    order.clear();
	long long n;
    tier=0;
	cin>>n;
	std::vector<ll> v[n];
	vector<vector<ll>> adj;
	for(long long i=0;i<n-1;i++) {
		long long x,y;
		cin>>x>>y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for(ll i=0;i<n;i++) {
		adj.push_back(v[i]);
	}
	LCA tree(adj,0);
	bool visit[n];
	for(int i=0;i<n;i++) {
		visit[i]=false;
	}
	dfsorder(0,v,visit);
	block=sqrt(2*n)+1;
	vector<ll> val(n);
	vector<pair<long long,long long>> fac[n];
	vector<pair<long long,long long>> fac1[n];
	for(long long i=0;i<n;i++) {
		cin>>val[i];
		fac1[i]=trial_division4(val[i]);
        val[i]=change(val[i]);
        // cout<<val[i]<<" ";
	}
	int q;
	cin>>q;
	vector<Query> query;
	std::vector<pair<ll,ll>> nnn;
	for(int i=0;i<q;i++) {
		Query temp;
		temp.idx=i;
		ll x,y;
		cin>>x;
		cin>>y;
		nnn.push_back(make_pair(x,y));
		if(st[x-1]>st[y-1]){
			swap(x,y);
		}
		x--;
		y--;
		ll l=tree.lca(x,y);
		temp.lca=l;
		if(l==x) {
			temp.l=st[x];
			temp.r=st[y];
			temp.sp=false;
		}
		else {
			temp.l=et[x];
			temp.r=st[y];
			temp.sp=true;
		}
		query.push_back(temp);
	}
	vector<ll> ans=mo_s_algorithm(query,val);
	for(long long i=0;i<1;i++) {
		queue<pair<long long,long long>>q;
		long long visit[n];
		for(long long i=0;i<n;i++) {
			visit[i]=0;
		}
		q.push(make_pair(i,i));
		while(!q.empty()) {
			pair<long long,long long> p=q.front();
			q.pop();
			long long x=p.first;
			long long par=p.second;
			if(x==i) {
				fac[x]=fac1[x];
			}
			else if(fac[x].size()==0) {
				fac[x]=merge(fac1[x],fac[par]);
			}
			visit[x]=1;
			for(auto j:v[x]) {
				if(visit[j]==0) {
					q.push(make_pair(j,x));
				}
			}
		}
	}
	for(int i=0;i<q;i++) {
		ll x,y;
		x=nnn[i].first;
		y=nnn[i].second;
		ll l=tree.lca(x-1,y-1);
        // cout<<ans[i]<<" ";
		cout<<(countdivisors(merge(demerge(merge(fac[x-1],fac[y-1]),fac[l]),fac1[l]))*ans[i])%M<<endl;
    }
    return 0;
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    for (long long i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (long long j=0; j<(long long)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    long long t;
    cin>>t;
    while (t--) {     
        ll p=solve();
    }   
    return 0;  
}   