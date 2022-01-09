#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define tt "\n"
#define loop(n) for(int i = 0 ; i < n; i++)
#define Fast ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
using namespace std;
void marge2Array(int a[] ,  int l1 , int r1 , int l2 , int r2){
	int l = min(l1 , l2);
	int n = (r1-l1+1) + (r2-l2+1);
	int *temp = new int [n];
	int k = 0;
	while(l1 <= r1 && l2 <= r2){
		if(a[l1] <= a[l2])
			temp[k++] = a[l1++];
		if(a[l1] >= a[l2])
			temp[k++] = a[l2++];
	}
	while(l1 <= r1) temp[k++] = a[l1++];
	while(l2 <= r2) temp[k++] = a[l2++];
	loop(n)
		a[l++] = temp[i];
}

void nsort(int a[] ,int l , int r){
	int mid = (l+r) / 2;
	if(mid == l && mid == r)
		return;
	nsort(a,l,mid);
	nsort(a,mid + 1 , r);
	marge2Array(a , l , mid , mid+1 , r);
}
void sort(int a[] , int n){
	nsort(a,0,n-1);
}
int main(){
	int a[] = {4,7,5,2,1,4,3,15,22,13,4,15};
	int n = sizeof(a) / sizeof(a[0]);
	sort(a,n);
	for(int i =0 ; i < n ; i++)
		cout << a[i] << " ";
}

