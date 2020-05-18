#include<bits/stdc++.h>
using namespace std;
bool prime[20000001+1];
void SieveOfEratosthenes(int n) { 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) {  
        if (prime[p] == true) {  
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
int main() {
	int n;
	cin>>n;
	SieveOfEratosthenes(20000001);
	int *a=new int[n+1];
	int *b=new int[n+1];
	vector<int> v;
	long tsum=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		v.push_back(i);
		tsum=tsum+a[i];
	}
	int k=0;
	int sum=0;
	int check1=0,check2=0;
	prime[1]=false;
	while(v.empty()==false) {
		int v1=v.front();
		v.erase(v.begin());
		if(prime[sum+a[v1]]&&(prime[tsum-sum-a[v1]])) {
			b[k++]=v1;
			sum+=a[v1];
			check1=0;
		}
		else if(prime[tsum-sum-a[v1]]&&check1>=2*v.size()) {
			b[k++]=v1;
			sum+=a[v1];
			check1=0;
		}
		else if(prime[sum+a[v1]]&&check1>=v.size()) {
			b[k++]=v1;
			sum+=a[v1];
			check1=0;
		}
		else if(check1>=3*v.size()) {
			b[k++]=v1;
			sum+=a[v1];
			check1=0;
		}
		else {
			check1++;
			v.push_back(v1);
		}
		/* cout<<sum;
		for (auto it = v.begin(); it != v.end(); ++it) 
        cout << ' ' << *it; 
    	cout<<endl; */
	}
	for(int i=0;i<k-1;i++)
		cout<<b[i]<<" "<<b[i+1]<<endl;
	return 0;
}

