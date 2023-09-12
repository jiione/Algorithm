#include<iostream>
#include<queue>

#define endl '\n'

using namespace std;

priority_queue<int,vector<int>,greater<int> > ppq;
priority_queue<int> mpq;

int N;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>N;

	for(int i=0; i<N; ++i){
		int tmp;
		cin>>tmp;
		if(tmp == 0){
			if(ppq.empty() && mpq.empty()) cout <<0<<endl;
			else if(ppq.empty()){
				cout<<mpq.top()<<endl;
				mpq.pop();
			}
			else if(mpq.empty()){
				cout<<ppq.top()<<endl;
				ppq.pop();
			}
			else{
				int p = ppq.top();
				int m = mpq.top();
				if(p<-m){
					cout<<p<<endl;
					ppq.pop();
				}
				else{
					cout<<m<<endl;
					mpq.pop();
				}
			}
		}
		else if(tmp<0){
			mpq.push(tmp);
		}
		else{
			ppq.push(tmp);
		}
	}

	return 0;
}