#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int stud[n];
		int mini=0,ind=0;
		int ct=0,ct1=0,ct2=0,flag=0,flag1=0;
		for(int i=0;i<n;i++){
			cin >> stud[i];
				if(i==0){
					mini=stud[i];
					ind=i;
				}
				else if(mini>stud[i])
				{
					mini=stud[i];
					ind=i;
				}
		}
		if(n==1)
			cout <<"YES" << endl;
		else{
		for(int i=ind;i%n<n;i=(i+1)%n)
		{
			ct++;
			if(stud[i]>stud[(i+1)%n])
				break;
			else if(ct==n-1)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			for(int i=ind;;i--)
			{
				ct1++;
				int j=i-1;
				//cout << i << " " << j <<endl;
				if(j<0){
					j=n+j;
					flag1=1;
				}
				if(stud[i]>stud[(j)%n])
					break;
				else if(ct1==n-1)
				{
					flag=1;
					break;
				}
				//cout << j << endl;
				if(flag1){
					i=j+1;
					flag1=0;
				}
				//cout << stud[i] << " " << stud[j]<< endl;
			}
			//ct1++;
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
		}
	}
	return 0;
}