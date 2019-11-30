#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ***p=NULL;//先简单一点，整两个矩阵的运算
	int **q=NULL;//存放运算后的矩阵 
	int m,n;//行数和列数
	int x,i,j;//矩阵个数，矩阵的行数和列数
	int k;//循环一下，给矩阵赋值,三维数组中表示第几个矩阵
	int t;//表示加减等运算的变量 
	int temp,a,b;//为了矩阵相乘而引入的变量 存储连加的值；为了矩阵相乘引入的变量，存中间相等的行列 
	x=0;//给x赋一个初值，为使用者输入错误设计 
	printf("输入一个大于零的数，这个数表示操作的矩阵的个数:");
	scanf("%d",&x);
	p=(int***)malloc(sizeof(int **) *x);
	for(k=0;k<x;k++)
	{
		printf("\n请输入第%d个矩阵的行数,要求输入的数大于0:",k+1);
		scanf("%d",&m);
		printf("\n请输入第%d个矩阵的列数，要求输入的数大于0:",k+1);
		scanf("%d",&n);
		if(m<=0||n<=0)
		{
			printf("输入错误，请再次输入\n");
			k=k-1;
		}
		else
		{
			p[k]=(int**)malloc(sizeof(int *) *m);//申请一组一维指针空间
			for(i=0;i<m;i++)
				p[k][i]=(int *)malloc(sizeof(int)*n);//对于每个一维指针，申请一行数据的空间
			for(i=0;i<m;i++)
			{
				printf("\n现在输入第%d行的数据，以空格分开，最后按回车",i+1);
				for(j=0;j<n;j++)
					scanf("%d",&p[k][i][j]);
			}
		}	
	}
	if(x==1)
	{
		printf("\n输入的矩阵为%d行%d列\n",m,n);
		while(t!=3)
		{
			printf("输入1表示输出原矩阵，输入2表示进行矩阵的转置，输入3表示你不想玩儿了:");
			scanf("%d",&t);	printf("\n");
			if(t==1)
			{
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
						printf("%d ",p[0][i][j]);
					printf("\n");
				}
			}
			if(t==2)//矩阵转置 
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
						printf("%d",p[0][j][i]);
					printf("\n");
				}
			}
		}
		for(i=0;i<m;i++)
		free(p[0][i]);
		free(p[0]);
	}//矩阵的输出与转置 
	else
	{
		for(;x>1;x--)
		{
			printf("进行两个矩阵的运算，输入1表示相加，输入2表示相减，输入3表示相乘:");
			scanf("%d",&t); printf("\n");
			k=0;
			if(t==1)
			{	
				if(k==0)
				{
					if((sizeof(p[k])/sizeof(p[k][0]))!=(sizeof(p[k+1])/sizeof(p[k+1][0]))||(sizeof(p[k][0])/sizeof(p[k][0][0]))!=(sizeof(p[k+1][0])/sizeof(p[k+1][0][0])))
					{
						printf("两矩阵不是同型矩阵，无法相加,请更换一种运算\n");
						x=x+1; 
					}
					else
					{
						m=sizeof(p[k])/sizeof(p[k][0]);
						n=sizeof(p[k][0])/sizeof(p[k][0][0]); 
						q=(int**)malloc(sizeof(int *) *m);//给q申请一个行 
						for(i=0;i<m;i++)
							q[i]=(int *)malloc(sizeof(int)*n);//给q申请一个列
						for(i=0;i<m;i++)
							for(j=0;j<n;j++)
								q[i][j]=p[k][i][j]+p[k+1][i][j];
					}		
				}
				else
				{
					if((sizeof(p[k])/sizeof(p[k][0]))!=(sizeof(q)/sizeof(q[0]))||(sizeof(p[k][0])/sizeof(p[k][0][0]))!=(sizeof(q[0])/sizeof(q[0][0])))
					{
						printf("之前运算所得结果与此矩阵不是同型矩阵，无法相加,请更换一种运算\n");
						x=x+1; 
					}
					else
					{
						for(i=0;i<m;i++)
							for(j=0;j<n;j++)
								q[i][j]=p[k][i][j]+q[i][j];
					}	
				}
			}//矩阵加法运算
			if(t==2)
			{	
				if(k==0)
				{
					if((sizeof(p[k])/sizeof(p[k][0]))!=(sizeof(p[k+1])/sizeof(p[k+1][0]))||(sizeof(p[k][0])/sizeof(p[k][0][0]))!=(sizeof(p[k+1][0])/sizeof(p[k+1][0][0])))
					{
						printf("两矩阵不是同型矩阵，无法相减,请更换一种运算\n");
						x=x+1; 
					}
					else
					{
						m=sizeof(p[k])/sizeof(p[k][0]);
						n=sizeof(p[k][0])/sizeof(p[k][0][0]);
						q=(int**)malloc(sizeof(int *) *m);//给q申请一个行 
						for(i=0;i<m;i++)
							q[i]=(int *)malloc(sizeof(int)*n);//给q申请一个列
						for(i=0;i<m;i++)
							for(j=0;j<n;j++)
								q[i][j]=p[k][i][j]-p[k+1][i][j];
					}		
				}
				else
				{
					if((sizeof(p[k])/sizeof(p[k][0]))!=(sizeof(q)/sizeof(q[0]))||(sizeof(p[k][0])/sizeof(p[k][0][0]))!=(sizeof(q[0])/sizeof(q[0][0])))
					{
						printf("之前运算所得结果与此矩阵不是同型矩阵，无法相减,请更换一种运算\n");
						x=x+1; 
					}
					else
					{
						for(i=0;i<m;i++)
							for(j=0;j<n;j++)
								q[i][j]=p[k][i][j]-q[i][j];
					}	
				}
			}//矩阵减法
			if(t==3)
			{
				if(k==0)
				{
					if((sizeof(p[k][0])/sizeof(p[k][0][0]))!=(sizeof(p[k+1])/sizeof(p[k+1][0])))
					{
						printf("第一个矩阵列数不等于第二个矩阵行数，无法相乘\n");
						x=x+1;
					}
					else
					{
						m=sizeof(p[k])/sizeof(p[k][0]);
						n=sizeof(p[k+1][0])/sizeof(p[k+1][0][0]);
						a=sizeof(p[k][0])/sizeof(p[k][0][0]);
						for(i=0;i<m;i++)
							for(j=0;j<n;j++)
							{
								temp=0;
								for(b=0;b<a;b++)
									temp+=p[k][i][b]*p[k+1][b][j];
								q[i][j]=temp;
							}
					}
				}
			} 
		}
	}
}
