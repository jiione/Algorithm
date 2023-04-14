#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cnt=0;

int white=0, blue=0;
int N;
int board[129][129];

void divide(int x, int y, int size){
    int check = board[y][x];

    for(int i = y; i<=y+size-1;i++){
        for(int j=x; j<=x+size-1;j++){
            if(check != board[i][j]){
                divide(x,y,size/2);
                divide(x,y+(size/2),size/2);
                divide(x+(size/2),y,size/2);
                divide(x+(size/2),y+(size/2),size/2);
                return;
            }
        }
    }

    if(check == 1){
        blue++;
    }
    else{
        white++;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }

    divide(1,1,N);
    
    cout<<white<<endl<<blue<<endl;
    return 0;
}
