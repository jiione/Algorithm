#include <iostream>
#include <set>

using namespace std;

int main()
{
	int height;
	int diff=-100;
	set<int> s;
	for(int i=0;i<9;i++){
		cin>>height;
		s.insert(height);
		diff+=height;
	}

	int sum;
	for(auto it=s.begin();it!=s.end();it++)
	{
		for(auto it2=it;it2!=s.end();it2++)
		{
			if(it==it2) continue;
			sum=*it+*it2;
			if(sum==diff)
			{
				s.erase(it2);
				s.erase(it);
				break;
			}
		}
		if(sum==diff) break;
	}
	for(auto it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
}

