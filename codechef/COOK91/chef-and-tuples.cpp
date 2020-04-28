#include<bits/stdc++.h>
using namespace std;
int countDivisors(int n,int *a,int l)
{
    int cnt = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
         if (n%i==0)
         {
            
            if (n/i == i)
               a[l++]=i;
 
            else {
                a[l++]=i;
				a[l++]=n/i;
			}
         }
     }
    return l;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int l=0;
		int a[100000];
		int n;
		cin>>n;
		l=countDivisors(n,a,l);
		sort(a,a+l);
		int A,b,c;
		cin>>A>>b>>c;
		int l1=0,l2=0,l3=0;
		int count=0;
//		cout<<l<<endl;
		while(a[l1]<=A&&l1<l) { l2=0;
			long temp=n/a[l1];
//			cout<<"1st"<<temp<<endl;
			while(a[l2]<=b&&l2<l) { 
//				cout<<a[l1]<<" "<<a[l2]<<" "<<a[l3]<<endl;
				l3=0;
				if(temp%a[l2]==0) {
				long temp2=temp/a[l2];	
				if(temp2<=c) {
				while(temp2!=a[l3]&&l3<l) { l3++; }
				if(l3<l) {
				count++;
				//cout<<"*"<<a[l1]<<" "<<a[l2]<<" "<<a[l3]<<endl;
				}
				}
				}
				l2++;

		}
		l1++;
		}
			cout<<count<<endl;
	}
	return 0;
}
 
