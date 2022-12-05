#include<bits/stdc++.h>
#define N 100

using namespace std;

int n = 6;
int c[N], f[N], vet[N];
int m = 20;

void coin_changing(){
	for(int i=1;i<=m;i++)
		f[i] = 0;
	for(int i=1;i<=n;i++)
		f[c[i]] = 1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[j] <= i) {
				if((f[i] > f[i-c[j]] + 1 && f[i-c[j]] != 0) || (f[i] == 0 && f[i-c[j]] != 0))
				f[i] = f[i - c[j]] + 1;
				vet[i] = j;
			}
		}
	}
}

void result(){
	int j = vet[m];
	int i = m;
	while(j != 0){
		cout<<c[j]<<" ";
		i = i - j;
		j = vet[i];
	}
}

int main(){
	srand(time(NULL));
	for(int i=1;i<=n;i++)
		c[i] = rand() % 10 + 1;
	for(int i=1;i<=n;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	coin_changing();
	result();
	return 0;
}

