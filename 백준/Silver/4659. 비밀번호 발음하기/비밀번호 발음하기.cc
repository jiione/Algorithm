#include<iostream>
#include<string>

#define aa "is acceptable."
#define na "is not acceptable."
#define endl '\n'
using namespace std;

char vowels[5] = {'a','e','i','o','u'};

void print(string s, bool check){
    if(check) cout<<"<"<<s<<"> "<<aa<<endl;
    else cout<<"<"<<s<<"> "<<na<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    while(true){
        cin>>s;
        if(s=="end") break;

        int cnt=0;
        bool isExist = false;
        bool vow = false;
        

        for(int i=0; i<5; ++i){
            if(s.find(vowels[i])!= string::npos){
                isExist = true;
                break;
            }
        }
        if(!isExist){
            print(s,false);
            continue;
        }

        char prev =' ';
        bool success = true;
        for(char c : s){
            if(c==prev && c!='e' && c!='o'){
                success = false;
                print(s,false);
                break;
            }
            bool check = false;
            for(int i=0; i<5; ++i){
                if(c==vowels[i]){
                    if(vow){
                        cnt++;
                    }
                    else{
                        cnt=1;
                    }
                    check = true;
                    vow = true;
                    break;
                }
            }

            if(!check){
                if(!vow){
                    cnt++;
                }
                else cnt=1;
                vow = false;
            }

            if(cnt == 3){
                print(s,false);
                success = false;
                break;
            }

            prev=c;
        }
        if(success) print(s,true);
    }
}