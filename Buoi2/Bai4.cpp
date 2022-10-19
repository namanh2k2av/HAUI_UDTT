#include<iostream>
#define max 1000

using namespace std;

int dem=0;
struct stack{
    int e[max];
    char a[max];
    char b[max];
    char c[max];
    int top;
};

void create(stack &s){
    s.top=-1;
}

int empty(stack s){   
	return (s.top==-1);
}

void push(stack &s, int &x, char &a, char &b, char &c)
{
    if (s.top==max-1) exit(0);
    memcpy(&s.e[++s.top],&x,sizeof(int));
    memcpy(&s.a[s.top],&a,sizeof(int));
    memcpy(&s.b[s.top],&b,sizeof(int));
    memcpy(&s.c[s.top],&c,sizeof(int));
}

void pop(stack &s, int &x, char &a, char &b, char &c){
    if (s.top==-1) exit(0);
    memcpy(&x,&s.e[s.top],sizeof(int));
    memcpy(&a,&s.a[s.top],sizeof(int));
    memcpy(&b,&s.b[s.top],sizeof(int));
    memcpy(&c,&s.c[s.top--],sizeof(int));
}

void chuyen(int n, char a, char b, char c){
	stack s;
	int l, k=1;
	create(s);
	push(s, n, a, b, c);
	while(!empty(s)){
		pop(s, n, a, b, c);
		if(n==1){
			cout<<dem+1<<": "<<a<<" sang "<<c<<endl;
			dem++;
		}	
		else{
			l = n-1;
			push(s, l, b, a, c);
			push(s, k, a, b, c);
			push(s, l, a, c, b);
		}
	}
}

int main(){
	int n;
	cin>>n;
	chuyen(n,'A','B','C');
	cout<<"So lan chuyen: "<<dem;
}
