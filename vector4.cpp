#include<bits/stdc++.h>
using namespace std;
main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,b,ans;
		cin>>n;
		b=sqrt(n);
		ans=2*b-1;
		if(b*b==n)
			cout<<ans<<endl;
		else if((n-(b*b))<=b)
			cout<<ans+1<<endl;
		else
			cout<<ans+2<<endl;
	}
}