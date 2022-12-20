#include <iostream>
#include <queue>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    queue<pair<int,int>> q;
    pair<int,int>p;
    vector<int> v;
    int size;
    int num=0;
    cin>>size;
    string* map = new string[size];
    for(int i=0; i<size;i++){
        cin>>map[i];
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(map[i][j]=='1')
            {
                q.push(make_pair(i,j));
                map[i][j]='0';
                num=1;
                while(!q.empty())
                {
                    p.first=q.front().first;
                    p.second=q.front().second;
                    q.pop();
                    if(p.first==0){
                        if(map[p.first+1][p.second]=='1')
                        {
                            q.push(make_pair(p.first+1,p.second));
                            num++;
                            map[p.first+1][p.second]='0';
                        }
                    }
                    else if(p.first==size-1){
                        if(map[p.first-1][p.second]=='1')
                        {
                            q.push(make_pair(p.first-1,p.second));
                            num++;
                            map[p.first-1][p.second]='0';
                        }
                    }
                    else{
                        if(map[p.first-1][p.second]=='1')
                        {
                            q.push(make_pair(p.first-1,p.second));
                            num++;
                            map[p.first-1][p.second]='0';
                        }
                        if(map[p.first+1][p.second]=='1')
                        {
                            q.push(make_pair(p.first+1,p.second));
                            num++;
                            map[p.first+1][p.second]='0';
                        }
                    }

                    if(p.second==0){
                        if(map[p.first][p.second+1]=='1')
                        {
                            q.push(make_pair(p.first,p.second+1));
                            num++;
                            map[p.first][p.second+1]='0';
                        }
                    }
                    else if(p.second==size-1){
                        if(map[p.first][p.second-1]=='1')
                        {
                            q.push(make_pair(p.first,p.second-1));
                            num++;
                            map[p.first][p.second-1]='0';
                        }
                    }
                    else{
                        if(map[p.first][p.second+1]=='1')
                        {
                            q.push(make_pair(p.first,p.second+1));
                            num++;
                            map[p.first][p.second+1]='0';
                        }
                        if(map[p.first][p.second-1]=='1')
                        {
                            q.push(make_pair(p.first,p.second-1));
                            num++;
                            map[p.first][p.second-1]='0';
                        }
                    }
                }
                v.push_back(num);
                num=0;
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
}