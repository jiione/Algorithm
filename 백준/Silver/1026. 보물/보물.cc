#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int num;
	cin>>num;
	vector<int> a(num);
	vector<int> b(num);
	int tmp;
	for(int i=0;i<num;i++)
	{
		cin>>tmp;
		a[i]=tmp;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<num;i++)
	{
		cin>>tmp;
		b[i]=tmp;
	}
	sort(b.begin(),b.end(),greater<>());
	int sum=0;
	for(int i=0; i<num;i++){
		sum+=a[i]*b[i];
	}
	cout<<sum<<endl;

}
