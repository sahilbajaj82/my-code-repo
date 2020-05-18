#include<bits/stdc++.h>
using namespace std;
std::vector<long long> v;
bool isPerfectSquare(long double x) {   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 
bool next_permutation(long long *a,long long n) {
	long long x=-1;
	long long count=0;
	if(a[n-1]>0) {
		count=a[n-1];
		a[n-1]=0;
		for(long long j=n-1-1;j>=0;j--) {
			if(a[j]>0) {
				x=j+1;
				break;
			}
		}
	}
	for(long long i=n-1;i>=0;i--) {
		if(a[i]>0) {
			a[i]--;
			a[i+1]++;
			break;
		}
	}
	if(x!=-1) {
		a[x]+=count;
	}
	return true;
}
int main() {  
	#ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif  
    for(long long i=1;i<60000;i++) {
		v.push_back(i*i);
	}
	long long count=0;
	int t;
	cin>>t;
	while(t--) {

		long long a[10],p;
		cin>>p;
		//cout<<p<<" ";
		for(long long i=0;i<9;i++)
			a[i]=0;
		a[0]=p;
		
		while(true) {
			long long sum=0;
			for(long long j=1;j<10;j++) {
				sum=sum+j*j*a[j-1];
			}
			//cout<<sum<<endl;
			if(binary_search(v.begin(), v.end(),sum)) {
				for(long long k=0;k<9;k++) {
					for(long long j=0;j<a[k];j++) {
						cout<<k+1;
					}
				}	
				cout<<endl;
				
				break;
			}
			count++;
			next_permutation(a,9);
		} 
		
	}
	//cout<<count<<endl;
	return 0;
}

