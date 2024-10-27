#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int,bool> m;
    int answer = 0;
    for(int n:nums){
        if(m[n]==false) {
            answer++;
            if(answer==nums.size()/2) break;
        }
        m[n]=true;
    }
    return answer;
}