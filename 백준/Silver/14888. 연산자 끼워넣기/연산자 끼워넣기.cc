#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> numbers;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    vector<char> op;
    cin>>temp;
    for(int i=0;i<temp;i++){
        op.push_back('a');
    }

    cin>>temp;
    for(int i=0;i<temp;i++){
        op.push_back('s');
    }

    cin>>temp;
    for(int i=0;i<temp;i++){
        op.push_back('m');
    }

    cin>>temp;
    for(int i=0;i<temp;i++){
        op.push_back('d');
    }

    sort(op.begin(),op.end());

    int min = 2000000000;
    int max=-2000000000;
    do{
        int i=0;
        int result=numbers[i++];
        for(auto it: op){
            if(it == 'a'){
                result+=numbers[i++];
            }
            else if(it == 's'){
                result-=numbers[i++];
            }
            else if(it == 'm'){
                result*=numbers[i++];
            }
            else if(it=='d'){
                result/=numbers[i++];
            }
        }
        if(result<min) min = result;
        if(result>max) max = result;
    }while(next_permutation(op.begin(),op.end()));

    cout<<max<<'\n'<<min<<'\n';

}