#include <string>
#include <vector>
#include <cmath>

#define l "L"
#define r "R"

using namespace std;

string solution(vector<int> numbers, string hand) {
    
    vector<pair<int,int>> board(10);
    
    int k =1;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            board[k++] =make_pair(i,j);
        }
    }
    board[0] = make_pair(3,1);
    string answer = "";
    
    bool rCheck = false;
    if(hand.compare("right")==0) rCheck=true;
    int ly = 3;
    int lx = 0;
    int ry = 3;
    int rx = 2;
    
    for(int n : numbers){
        int x= board[n].second;
        int y= board[n].first;
        if(n == 1 || n == 4 || n== 7){
            ly = y;
            lx = x;
            answer+=l;
        }
        else if(n==3 || n == 6 || n == 9 ){
            ry= y;
            rx= x;
            answer+=r;
        }
        else{
            int ld = abs(ly - y) + abs(lx - x);
            int rd = abs(ry - y) + abs(rx - x);
            
            if(ld>rd){
                answer+=r;
                ry = y;
                rx = x;
            }
            else if(ld<rd){
                answer+=l;
                ly = y;
                lx = x;
            }
            else{
                if(rCheck){
                    answer+=r;
                    ry = y;
                    rx = x;
                }
                else{
                    answer+=l;
                    ly = y;
                    lx = x;
                }
            }
        }
    }
    return answer;
}