#include<iostream>
#include<vector>

using namespace std;

int N;

vector<int> arr;
vector<int> memo;
void update(int n){
	int start = 0;
	int end = memo.size()-1;
	int ret = memo.size();

	while(end>=start){
		int mid = (start+end)/2;
		if(memo[mid]>= n){
			if(ret>mid) ret = mid;
			end = mid-1;
		}
		else{
			start = mid +1;
		}
	}

	memo[ret] = n;
}
int main(){
    cin>>N;

    arr.resize(N);

    for(int i =0; i<N; ++i){
        cin>>arr[i];
    }

	memo.push_back(arr[0]);

	for(int i=1; i<N; ++i){
		if(memo.back()<arr[i]){
			memo.push_back(arr[i]);
		}
		else if(memo.back()>arr[i]){
			update(arr[i]);
		}
	}

	cout<<memo.size();
}