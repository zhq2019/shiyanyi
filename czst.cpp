#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct customer
{
	char c_mkgsegment[11];
}customer;
typedef struct or
{
	int o_orderkey;
	int o_custkey;
	char c_orderdate[10];
}order;
typedef struct li
{
	int l_orderkey;
	float l_extendedprice;
	char l_shipdate[10];
}lineitem;
typedef struct re
{
	int custkey;
	int orderket;
	float price;
	char mkgsegment[11];
	char orderdate[10];
	char shipdate[10];
}result;
typedef struct find
{
	char mkgment[11];
	char order[11];
	char ship[11];
	int num;
}find;
typedef struct
{
	int l_order;
	char o_orderda[10];
	float revenue;
}last;
customer cum[100];
order ord[16000];
lineitem lin[1000];
result res[1000];
find fin[100];
int cust()
{
	FILE* fp = NULL;
	char ch;
	int i = 0, j = 0, flag = 0;
	fp = fopen("customer.txt", "r+");
	if (fp == NULL)
	{
		printf("´ò¿ªÊ§°Ü");
		return 0;
	}
	ch = getc(fp);
	while (ch != EOF)
	{
		if (ch == '|')
		{
			ch = getc(fp);
			flag = 1;
		}
		if (ch == '\n')
		{
			i++; j = 0; flag = 0; ch = getc(fp);
		}
		if (flag == 1)
		{
			cum[i].c_mkgsegment[j] = ch;
			j++;
		}
		ch = getc(fp);
	}
	fclose(fp);
	return 0;
}
int orde()
{
	FILE* fp = NULL;
	char ch;
	int a = 0, b = 0;
	int tag = 0, flag = 0, i = 0, j = 0, k = 0, l = 0;
	fp = fopen("orders.txt", "r+");
	if (fp == NULL)
	{
		printf("´ò¿ªÊ§°Ü");
		return 0;
	}
	ord[i].o_orderkey = 0;
	ch = getc(fp);
	while (ch != EOF)
	{
		if (ch == '|')
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 2;
			else
				flag = 0;
			ch = getc(fp);
		}
		if (ch == '\n')
		{
			i++; j = 0; k = 0; l = 0; flag = 0; tag = 0; ch = getc(fp); ord[i].o_orderkey = 0;
		}
		if (flag == 0)
		{
			ord[i].o_orderkey = ch - '0' + ord[i].o_orderkey * 10;
		}
		else if (flag == 1)
		{
			b = a * 10;
			a = ch - '0';
			ord[i].o_custkey = a + b;
		}
		else if (flag == 2)
		{
			ord[i].c_orderdate[k]=ch;
			k++;
		}
		ch = getc(fp);
	}
	fclose(fp);
	return 0;
}
int line()
{
	FILE* fp = NULL;
	char ch;
	float x;
	int flag = 0, i = 0, m = 0, j = 0, k = 1, z = 0;
	fp = fopen("lineitem.txt", "r+");
	if (fp == NULL)
	{
		printf("´ò¿ªÊ§°Ü");
		return 0;
	}
	lin[i].l_orderkey = 0;
	ch = getc(fp);
	while (ch != EOF)
	{
		if (ch == '|')
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 2;
			else
				flag = 0;
			ch = getc(fp);
		}
		if (ch == '\n')
		{
			i++; j = 0; m = 0; k = 1; flag = 0; ch = getc(fp); lin[i].l_orderkey = 0; z = 0;
		}
		if (flag == 0)
		{
			lin[i].l_orderkey = ch - '0' + lin[i].l_orderkey * 10;
		}
		else if (flag == 1)
		{
			if (ch == '.')
			{
				z = 1;
				ch = getc(fp);
			}
			if (z == 0)
			{
				x = ch - '0';
				lin[i].l_extendedprice = x + lin[i].l_extendedprice * 10;
			}
			else
			{
				x = ch - '0';
				for (j = 1; j <= k; j++)
					x = x * 0.1;
				lin[i].l_extendedprice = lin[i].l_extendedprice + x;
				k++;
			}
		}
		else if (flag == 2)
		{
			lin[i].l_shipdate[m]=ch;
			m++;
		}

		ch = getc(fp);
	}
//	ord[0].o_orderkey = 1;
	//ord[0].o_orderkey;
	fclose(fp);
	return 0;
}
int search(int x)
{
	int i;
	for (i = 0; i < 4000; i++)
	{
		if (ord[i].o_orderkey == x)
			return i;
		if (ord[i].o_orderkey >= x)
			break;
	}
	return(-1);
}
void connect()
{
	int i, j, z, k=0;
	for (i = 0; i < 1000; i++)
	{
		j = search(lin[i].l_orderkey);
		if (j == -1)
			continue;
		z = ord[j].o_custkey;
		if (z == 0)
			continue;
		res[i].orderket = lin[i].l_orderkey;
		res[i].custkey = ord[j].o_custkey;
		res[i].price = lin[i].l_extendedprice;
		strcpy(res[i].orderdate,ord[j].c_orderdate);
		strcpy(res[i].shipdate,lin[i].l_shipdate);
		for (k = 0; k < 10; k++)
			res[i].mkgsegment[k] = cum[z - 1].c_mkgsegment[k];
	}
}
int main()
{
	int i = 0, j, k, l,a,we1=0,we2=0,flag,tag=0;
	int z=0,n,p,q;
	float sd,sb;
	char sc[10];
	last falg[1000];
	cust();
	orde();
	line();
	connect();
	scanf("%d", &flag);
	for (i = 0; i < flag; i++)
	{
		scanf("%s %s %s %d", &fin[i].mkgment, &fin[i].order, &fin[i].ship,&fin[i].num);
	}
	falg[0].l_order=0;
	a=0;
	for(a=0;a<flag;a++)
	{
	for (i = 0; i < 1000; i++)
	{
	
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
			{
				we1=strcmp(res[i].orderdate,fin[a].order);
				we2=strcmp(res[i].shipdate,fin[a].ship);	
				if(we1<=0&&we2>=0)
				{
					if(falg[z].l_order!=res[i].orderket)
					{
						z++;
						falg[z].l_order=res[i].orderket;
						strcpy(falg[z].o_orderda,res[i].orderdate);
						falg[z].revenue+=res[i].price;
					}
					else
					{falg[z].l_order=res[i].orderket;
					strcpy(falg[z].o_orderda,res[i].orderdate);
					falg[z].revenue+=res[i].price;
					}
					
				}
				//
				
			}
			if (fin[a].mkgment[j] == res[i].mkgsegment[j])
					continue;
			else break;
		}
	}
	for(i=0;i<=1000;i++)//Ã°ÅÝÅÅÐò 
	{
		for(j=i;j<=1000;j++)
		{
			p=falg[i].revenue;
			q=falg[j].revenue;
			if(falg[i].l_order>=1000||falg[i].l_order<=0)
				break;
			if(falg[j].l_order>=1000||falg[j].l_order<=0)
				break;
			if(p<q)
			{
				
				sd=falg[j].revenue;
				sb=falg[i].revenue;
				falg[j].revenue=sd;;
				falg[i].revenue=sb;;
				k=falg[i].l_order;
				l=falg[j].l_order;
				falg[i].l_order=l;;
				falg[j].l_order=k;;
				strcpy(sc,falg[i].o_orderda);
				strcpy(falg[i].o_orderda,falg[j].o_orderda);
				strcpy(falg[j].o_orderda,sc);
			}
		}
	}

	printf("l_orderkey|o_orderdate|revenue\n");
	for(i=1;i<=fin[a].num;i++)
	{
		if(falg[i].l_order>=1000||falg[i].l_order<=0)
			break;
			printf("%d|",falg[i].l_order);
			for(k=0;k<10;k++)
				printf("%c",falg[i].o_orderda[k]);
			printf("|%7.2f",falg[i].revenue);
			printf("\n");
	}
	}	
	return 0;
}
