#include<cstdio>

int gcd(int a, int b)//求最大公约数
{
	return a%b?gcd(b,a%b):b;
}

main()
{
	int n,cases=1;//cases用来记录次数
	char ch[1000];//ch为小数的字符串
	while(~scanf("%d",&n)&&n!=-1)
	{
		scanf("%s",ch);
		int den=1,num=0;
		for(int i=2;ch[i];++i)//从ch字符串的第三位开始，即忽略0和.
		{
			den*=10;//10的k+j次方，即10小数位次方
			num=num*10+(ch[i]-'0')*1;//10的k+j次方乘以小数位部分
		}
		if(n)
		{
			int temp=1;
			for(int i=0;i<n;++i)
				temp=temp*10;//10的k次方
			num=num-num/temp;//10的k+j次方乘以小数位部分减去10的k次方乘以小数部分，分子
			den=den-den/temp;//10的k+j次方减去10的k次方，分母
		}
		int red=gcd(num,den);//约
		printf("Case %d: %d/%d\n",cases++,num/red,den/red);
	}
}
