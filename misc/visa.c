#include<stdio.h>
#include<conio.h>
// https://www.codechef.com/COOK130C/problems/VISA
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x1,x2,y1,y2,z1,z2,c=0;
		scanf("%d",&x1);
		scanf("%d",&x2);
		scanf("%d",&y1);
		scanf("%d",&y2);
		scanf("%d",&z1);
		scanf("%d",&z2);
		if(x2>=x1 && y2>=y1 && z1>=z2)
		{
			c=1;
		}
		if(c==1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
