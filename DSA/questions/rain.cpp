#include <iostream>
using namespace std;

int max1(int a,int b,int c){
	if(a>b and a>c) return a;
	else if(b>a and b>c) return b;
	else return c;
}

int min1(int a,int b,int c){
	if(a<b and a<c) return a;
	else if(b<a and b<c) return b;
	else return c;
}

int main() {
	// your code goes here
	//
	int n;
	cin>>n;
	while(n--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    cout<<max1(a,b,c)-min1(a,b,c)<<endl;
	}
	return 0;
}
