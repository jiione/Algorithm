#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

void Hanoi(int n, int a, int b, int c) {
	if (n == 1) {
		cout<<a<<" "<<c<<'\n';
		return;
	}
    Hanoi(n - 1, a, c, b);
    cout<<a<<" "<<c<<'\n';
    Hanoi(n - 1, b, a, c);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    cout<< (int)pow(2,N)-1<<'\n';
	Hanoi(N, 1, 2, 3);
	
	return 0;
}