#include<bits/stdc++.h>
using namespace std;
int minvalue;
int firstindex(int *a,int n){
	for(int i=0;i<n;i++)
		if(a[i]>0)
			return i;
	return -1;}
int lastindex(int *a,int n){
	for(int i=n-1;i>=0;i++)
		if(a[i]>0)
			return i;
	return -1;}
bool checkinf(int *a,int n,int start){
	for(int i=start+1;i<n;i++)
		if(a[i]!=-1)
		if((a[i]-a[start])!=(i-start))
			return false;
	return true;}
int maxElementValue(int *a,int n){
	int max=-1,maxindex=-1;
	for(int i=0;i<n;i++)
		if(a[i]>max){
			max=a[i];
			maxindex=i;
		}
	int i;
	for(i=maxindex+1;i<n;i++)
		if(a[i]!=-1)
			break;
	minvalue=max;
	return i-maxindex+max-1;}
bool possible(int *a,int n,int k,int start){
	int sum=a[start];
	for(int i=start+1;i<n;i++){
		sum=sum%k+1;
		if(a[i]!=-1)
			if(sum!=a[i])
				return false;
	}
	return true;
}
int BST(int *a,int end,int n,int start){
	int i;
	for(i=end;i>=minvalue;i--)
		if(possible(a,n,i,start))
			return i;
	return -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int flag=0,start=firstindex(a,n);
		int end=lastindex(a,n);
		if(start==-1)
			cout<<"inf\n";
		else{
			if(checkinf(a,n,start))
				cout<<"inf\n";
			else{
				int maxvalue=maxElementValue(a,n);
				int temp=BST(a,maxvalue,n,start);
				if(temp==-1)
					cout<<"impossible"<<endl;
				else
					cout<<temp<<endl;
			}
		}
	}
	return 0;
}