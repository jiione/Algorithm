#include<unordered_set>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int N, M, Cnt;
unordered_set<string> Set;


int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string S;
		cin >> S;
		Set.insert(S);
	}


	int Cnt = 0;

	for (int i = 0; i < M; i++)
	{
		string S;
		cin >> S;

		stringstream SS(S);
		string Token;

		while (getline(SS, Token, ','))
		{
			if (Set.find(Token) != Set.end())
			{
				Set.erase(Token);
			}
		}

		cout << Set.size() << '\n';

	}

}