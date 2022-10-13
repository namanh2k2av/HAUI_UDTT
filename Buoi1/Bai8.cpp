#include<bits/stdc++.h>

using namespace std;

bool flag[100][100];
int a[100][100];

void loang(int i, int j){
	flag[i][j] = true;
	if(a[i-1][j]==a[i][j] && !flag[i-1][j])
		loang(i-1,j);
	if(a[i+1][j]==a[i][j] && !flag[i+1][j])
		loang(i+1,j);
	if(a[i][j-1]==a[i][j] && !flag[i][j-1])
		loang(i,j-1);
	if(a[i][j+1]==a[i][j] && !flag[i+1][j])
		loang(i,j+1);
}

int main(){
	vector<int> ans;
	int n,m;
	cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    	for(int j = 1 ; j <= m ; ++j) 
			cin >> a[i][j];
	
    for(int i = 1 ; i <= n ; ++i)
    	for(int j = 1 ; j <= m ; ++j){
    		if(a[i][j] == 1 && !flag[i][j]) 
				loang(i,j);
		}
	int dem=0;
    for(int i = 1 ; i <= n ; ++i){
    	for(int j = 1 ; j <= m ; ++j){
    		if(flag[i][j] && flag[i-1][j] || flag[i+1][j] || flag[i][j-1] || flag[i][j+1]){
    			dem++;
			}
				
		}
	}
    cout<<dem;		
//	cout << ans.size() << endl;
//    sort(ans.begin(), ans.end());
//    for(int i=0 ; ans.size();i++)
//		cout << ans[i] << " ";
}
