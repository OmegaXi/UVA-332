#include<cstdio>
#include<iostream>

using namespace std;

int gcd(int a,int b)//求最大公约数
{
	return a%b?gcd(b, a%b):b;
}

main()
{
	int n,cases=1;
	char ch[1001];
	while(cin>>n && n!=-1)
	{
		cin>>ch;
		int den=1,num=0;
		for(int i=2;ch[i];++i)
		{
			den*=10;
			num=num*10+(ch[i]-'0')*1;
		}
		if(n)
		{
			int temp=1;
			for(int i=0;i<n;++i)
			{
				temp=temp*10;
			num=num-num/temp;
			den=den-den/temp;
			}
			int red=gcd(num,den);
			printf("Case %d: %d/%d\n",cases ++,num/red,den/red); 
		}
	}
}