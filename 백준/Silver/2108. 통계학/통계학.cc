#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    int arr[8001] = { 0, };
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[4000 + tmp]++;
        sum += tmp;
        v.push_back(tmp);
    }
    int cnt = 0, tmp_cnt = 0;
    int n = 5000, tmp_n = 5000;
    int idx = 0;
    for (int i = 0; i < 8001; i++) {
        if (cnt < arr[i]) {
            cnt = arr[i];
            n = i;
            idx = 0;
        }
        else if (cnt == arr[i] && idx < 1) {
            idx++;
            n = i;
        }
    }
    n -= 4000;

 
    sort(v.begin(), v.end());
    cout << (int)round(sum / (double)N) << endl;
    cout << v[N / 2] << endl;
    cout << n << endl;
    cout << v.back() - v.front();
    

}