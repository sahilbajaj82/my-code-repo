#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

int main() {
	int n,k;
	cin>>n;
	cin>>k;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	int count[n];
	for(int i=0;i<n;i++) {
		int h=binarySearch(b,0,n-1,a[i]);
		for(;h>=0;h--) {
			if(b[h]!=a[i])
				break;
		}
		count[i]=h+1;
	}
	for(int i=0;i<k;i++) {
		int x,y;
		cin>>x>>y;
		if(a[x-1]>a[y-1])
			count[x-1]--;
		if(a[y-1]>a[x-1])
			count[y-1]--;
		if(count[x-1]<0)
			count[x-1]=0;
		if(count[y-1]<0)
			count[y-1]=0;

	}
	for(int i=0;i<n;i++) {
		cout<<count[i]<<" ";
	}
	cout<<endl;
	return 0;
}