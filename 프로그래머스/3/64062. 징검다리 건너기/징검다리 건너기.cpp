#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int max = 0;
    
    for(int i : stones){
        if(i>max) max = i;
    }
    
    int min = 0;
    int mid = 0;
    int answer = 0;
    while(max>=min){
        mid = (max+min)/2;
        int count = 0;
        for(int s: stones){
            if(s-mid<=0){
                count++;
            }
            else count =0;
            if(count == k) break;
        }
        
        if(count<k){
            answer = mid+1;
            min = mid+1;
        }
        else max = mid-1;
    }
    return answer;
}