#include<iostream>

using namespace std;

void quick_sort(int a[], int left, int right){
	if(left<right){
		int k=(left+right)/2;
		int t = a[k];
		int i=left, j=right;
		do{
			while(a[i]>t) // > giam , < tang
				i += 1;
			while(a[j]<t) // < giam , > tang
				j -= 1;
			if(i<=j){
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
				i += 1;
				j -= 1;
			}
		}while(i<=j);
		quick_sort(a,left,j);
		quick_sort(a,i,right);
	}
}

bool coin_changing(int *a, int n, int m, int *s, int &j){
	int i=0;
	quick_sort(a,0,n-1);
	while(m>0 && i<n){
		if(m-a[i]>=0){
			s[j] = a[i];
			m = m - a[i];
			j++;	
		}else{
			i++;
		}
	}
	if(m==0)
		return true;
	else
		return false;
}

int main(){
	int *a,n,m,*s,j=0;
	cin>>n>>m;
	a = new int[n];
	s = new int[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(coin_changing(a,n,m,s,j)){
		for(int i=0;i<j;i++)
			cout<<s[i]<<" ";
	}else{
		cout<<"Khong tim duoc!";
	}
}
