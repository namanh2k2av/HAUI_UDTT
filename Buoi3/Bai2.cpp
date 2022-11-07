#include<iostream>

using namespace std;

void merge(int *a, int bt1, int w1, int bt2, int w2, int *b){
	int i = bt1;
	int j = bt2;
	int bp1 = bt1+w1-1;
	int bp2 = bt2+w2-1;
	int k = bt1;
	while(i<=bp1 && j<=bp2){
		if(a[i] < a[j]){ // > giam , < tang
			b[k] = a[i];
			i++;
			k++;
		} else {
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while(i<=bp1){
		b[k] = a[i];
		i++;
		k++;
	}
	while(j<=bp2){
		b[k] = a[j];
		j++;
		k++;
	}
}

void merge_pass(int *a, int n, int k, int *b){
	int cv = n/(2*k);
	int s = 2*k*cv;
	int r = n-s;
	
	for(int j=1; j<=cv; j++){
		int b1 = (2*j - 2)*k;
		merge(a, b1, k, b1+k, k, b);
	}
	if(r <= k){
		for(int j=0; j<r; j++)
			b[s+j] = a[s+j];
	} else {
		merge(a, s, k, s+k, r-k, b);
	}
}

void merge_sort(int *a, int n){
	int k=1;
	int b[n];
	while(k<n){
		merge_pass(a, n, k, b);
		merge_pass(b, n, 2*k, a);
		k = k*4;
	}
}

void donuoc(int *a, int n, int k){
	int dem=0;
	int i=0;
	merge_sort(a,n);
	while(k-a[i]>0){
		dem++;
		k-=a[i];
		i++;
	}
	if(dem==0){
		cout<<"Khong co chai nao day!";
	} else {
		cout<<"So chai day: "<<dem;
	}
}

int main(){
	int *a,n,k;
	cin>>n>>k;
	a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	donuoc(a,n,k);
}
