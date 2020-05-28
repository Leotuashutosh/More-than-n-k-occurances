#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count(int a[],int n, int k);
int main(){
	int t;
	cout<<"enter no. of test cases";
	cin>>t;
	int n,k,i;
	while(t--){
		cout<<"enter length of array";
		cin>>n;
		int a[n];
		cout<<"enter array";
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<"enter the divisions";
		cin>>k;
		cout<<count(a,n,k)<<endl;
	}
	return 0;
	
}
struct ele{
	int e; int c;
};
int count(int a[],int n, int k){
	int count=0;
	if(k<2)return 0;
	ele temp[k];
	for(int i=0;i<k-1;i++){
		temp[i].e=0;
		temp[i].c=0;
	}
	for(int i=0;i<n;i++){
		int j;
		for( j=0;j<k-1;j++){
			if(temp[j].e==a[i]){
				temp[j].c+=1;
				break;
			}
		}
		if(j==k-1){
			int l;
			for(int l=0;l<k-1;l++){
				if(temp[l].c==0){
					temp[l].e=a[i];
					temp[l].c=1;
					break;
				}
			}
			if(l==k-1)
			for(l=0;l<k-1;l++)
			temp[l].c-=1;
		}
	}
	for(int i=0;i<k-1;i++){
		int ac=0;
		for(int j=0;j<n;j++){
			if(temp[i].e==a[j])
			ac++;
			
		}
		if(ac>n/k)
		count++;
	}
	return(count);
}
