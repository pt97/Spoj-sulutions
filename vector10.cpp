#include<bits/stdc++.h>
using namespace std;
bool prime[1000010];
long long int s[1000010];
void generatesieve(long long int n)
{
	long long int i,j,k;
	memset(prime, true, sizeof(prime));
	for(i=2;i*i<=n;i++)
	{
		if(prime[i]==true)
		{
			for(j=i*2;j<=n;j+=i)
				prime[j]=false;
		}
	}
}
int trun(long long int n)
{
	long long int a[20],temp,k=-1,i;
	temp=n;
	while(temp>0)
	{
		a[++k]=temp%10;
		temp/=10;
	}
	for(i=k;i>=0;i--)
	{
		long long int number=0,j;
		j=i;
		while(j>=0)
		{
			number=number*10+a[j];
			j--;
		}
		if(prime[number]==false)
			return 0;
	}
	return 1;
}
main()
{
	long long int i,j,n,check,t;
	generatesieve(1000010);
	prime[1]=false;
	prime[0]=false;
	for(i=2;i<1000010;i++)
	{
		if(prime[i]==true)
		{
			long long int temp,flag=0;
			temp=i;
			while(temp>0)
			{
				if(temp%10==0)
				{
					flag=1;
				}
				temp/=10;
			}
			temp=trun(i);
			if(temp==0)
				flag=1;
			if(flag==1)
			{
				prime[i]=false;
			}
		}
	}
	s[0]=0;
	s[1]=0;
	s[2]=1;
	for(i=3;i<1000010;i++)
	{
		if(prime[i]==true)
		{
			s[i]=s[i-1]+1;
		}
		else
		{
			s[i]=s[i-1];
		}
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",s[n]);
	}
	
}