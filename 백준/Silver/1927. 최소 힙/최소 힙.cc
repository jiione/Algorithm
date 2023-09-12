#include<iostream>
#include<queue>

#define endl '\n'

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int N;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>N;

	for(int i=0; i<N; ++i){
		int tmp;
		cin>>tmp;
		if(tmp!=0){
			pq.push(tmp);
		}
		else if(pq.empty()){
			cout<<0<<endl;
		}
		else{
			cout<<pq.top()<<endl;
			pq.pop();
		}
	}

	return 0;
}