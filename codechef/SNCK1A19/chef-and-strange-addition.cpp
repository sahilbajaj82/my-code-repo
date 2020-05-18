#include<bits/stdc++.h>
using namespace std;
int *converttobits(long a) {
	int *A=new int[32];
	for(int i=0;i<32;i++) {
		A[i]=a&1;
		a=a>>1;
	//	cout<<A[i]<<" ";
	}
	//cout<<endl;
	return A;
}
int dp[32][32][32][2];

int rec(int *A,int count1,int count2,int count3 ,int i,int carry) {
	if(count1+count2<count3)
		return 0;
	if(count1<0||count2<0)
		return 0;
	if(dp[count1][count2][i][carry]!=-1)
		return dp[count1][count2][i][carry];
	if(i==0){ int ans;
		if(carry==1&&A[i]==1)
			ans = 0;
		else if(carry==1) {
			if(count1==1&&count2==1)
				ans = 1;
			else
				ans = 0;
		}
		else {
			if(A[i]==0) {
				if(count1==0&&count2==0)
					ans =1;
				else
					ans =0;
			}
			else {
				if(count1+count2==1)
					ans= 1;
				else
					ans= 0;
			}
		}
		dp[count1][count2][i][carry]=ans;
		return ans;
	}
	else {
		if(A[i]&&carry) {
			dp[count1][count2][i][carry]=rec(A,count1-1,count2-1,count3-1,i-1,1);
			return dp[count1][count2][i][carry];
		}
		else if(A[i]) {
			dp[count1][count2][i][carry]=rec(A,count1,count2,count3-1,i-1,1)+rec(A,count1-1,count2,count3-1,i-1,0)+rec(A,count1,count2-1,count3-1,i-1,0);
			return dp[count1][count2][i][carry];
		}
		else if(A[i]==0&&carry) {
			dp[count1][count2][i][carry]=rec(A,count1-1,count2,count3,i-1,1)+rec(A,count1-1,count2-1,count3,i-1,0)+rec(A,count1,count2-1,count3,i-1,1);
			return dp[count1][count2][i][carry];
		}
		else {
			dp[count1][count2][i][carry]=rec(A,count1,count2,count3,i-1,0);
			return dp[count1][count2][i][carry];
		}
	}
	
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		long a,b,c;
		cin>>a>>b>>c;
		int *A=new int[32];
		int *B=new int[32];
		int *C=new int[32];
		A=converttobits(a);
		B=converttobits(b);
		C=converttobits(c);
		int count1=0,count2=0,count3=0;
		int last=0;
		for(int i=0;i<32;i++) {
			if(A[i])
				count1++;
			if(B[i])
				count2++;
			if(C[i])
				last=i,count3++;
		}
	//	cout<<count1<<" "<<count2<<endl;
		for(int i=0;i<=count1;i++)
			for(int j=0;j<=count2;j++)
				for(int p=0;p<=last;p++)
					for(int k=0;k<2;k++)
						dp[i][j][p][k]=-1;
		int x=rec(C,count1-1,count2,count3-1,last-1,0);
		int y=rec(C,count1,count2-1,count3-1,last-1,0);
		int z=rec(C,count1,count2,count3-1,last-1,1);
		cout<<x+y+z<<endl;
	}
}
