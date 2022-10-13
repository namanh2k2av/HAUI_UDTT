#include<iostream>

using namespace std;

void output(int a[], int n){
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
}

void sinh_nhi_phan(int n){
	int i;
	int a[n+1] = {0};
	do{
		output(a,n);
		i=n;
		while(i>0 && a[i]==1){
			i--;
		}
		if(i>0){
			a[i]=1;
			i++;
			while(i<=n){
				a[i]=0;
				i++;
			}
		}
	}while(i>0);
}

int main(){
	int n;
	cout<<"Nhap do dai chuoi nhi phan: ";
	cin>>n;
	sinh_nhi_phan(n);
}
