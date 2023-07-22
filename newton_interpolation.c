#include<stdio.h>
#include<math.h>
float fun(float x);
void main()
{
float ar[100][110],x,h,p,y,px=1;
int i,j,k,n,ch=30;
//Enter the order
printf("Enter the order:");
scanf("%d",&n);
//Enter the values that are given ////x and f(x)
FILE *fp;
fp=fopen("nfi-input.dat","r");
for(i=0;i<n;i++)
{
fscanf(fp,"%f\t%f",&ar[i][0],&ar[i][1]);
}
fclose(fp);
//Calculate difference y0,y1,y2........ 
for(j=2;j<=n;j++)
{
for(i=0;i<n-1;i++)
{
ar[i][j]=(ar[i+1][j-1]-ar[i][j-1])/(ar[i+1+j-2][0]-ar[i][0]);
}
}
//take the value of x
printf("Enter the value of the x\n:");
scanf("%f",&x);
//Printing table
printf("\nDifference table is:-");
printf("\n\tx\tY");
for(i=0;i<=n-2;i++)
printf("\t^%dY",i+1);
for(i=0;i<n;i++)
{printf("\n");
for(j=0;j<n+1-i;j++)
{printf("\t%.4f",ar[i][j]);
}
}
//calculate the f(x) for the above x;
float m=fun(x);
float y0=0.0;
y=ar[0][1];
printf("\n----------------------------------------------------------------------------------\n");
printf("order\texact_value\tcalculated_value\tAbs_err\tRel_Err\n");
printf("-----------------------------------------------------------------------------------");
for(i=1;i<=n;i++)
{
px=px*(x-ar[i-1][0]);
y=y+ar[0][i+1]*px;
printf("\n%d\t%f\t\t%f\t%.2f\t%.2f\n",i-1,m,y,fabs((m-y)/m)*100,fabs((y-y0)/y)*100);
y0=y;
}


}
float fun(float x)
{
int N=1,u=1;
return (N*u*((1/tanh(x))-1/x));
}
