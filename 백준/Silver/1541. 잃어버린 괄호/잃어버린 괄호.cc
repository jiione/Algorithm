#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int result=0;

    string str;
    bool plus = true;

    cin >>str;
    int sum=0;
    string tmp;

    for(int i=0; i<str.length();i++){
        if(str[i]=='-'){
            sum+=stoi(tmp);
            tmp.clear();
            if(plus == false) result -=sum;
            else result +=sum;
            sum = 0; 
            plus = false;
        }
        else if(str[i]=='+'){
            sum+=stoi(tmp);
            tmp.clear();
        }
        else{
            tmp.push_back(str[i]);
        }
    }
    sum+=stoi(tmp);
    tmp.clear();
    if(plus == false) result -=sum;
    else result +=sum;
    cout << result;
    return 0;
}
