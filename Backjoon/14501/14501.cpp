#include<iostream>
#include "vector"
using namespace std;
int main()
{
    int date, T, P;
    cin >> date;
    vector<int> v_t(date, 0);
    vector<int> v_p(date, 0);
    vector<int> check(date, 0);
    vector<int> max(date, 0);
    for (int i = 0; i < date; i++)
    {
        cin >> T >> P;
        if (i + T > date)continue;
        v_t[i] = T;
        v_p[i] = P;
        check[i] = i + T;
        max[i] = P;
    }
    for (int a = 0; a < date; a++)   
    {
        for (int b = 0; b < date; b++)
        {
            if (check[b] == 0)continue;
            for (int c = check[b]; c < date; c++)
            {
                if (v_p[b] + max[c] >= max[b]) max[b] = v_p[b] + max[c];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < date; i++)
    {
        if (max[i] >= result) result = max[i];
    }
    cout << result << endl;
}