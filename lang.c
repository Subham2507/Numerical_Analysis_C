#include<stdio.h>
#include<math.h>
float func(int x);
void main()
{
float ar[10][11],pi,y=0.0;
int i,j,k,x;
FILE *fp;
fp=fopen("lang.dat","r");
for(i=0;i<5;i++)
{
fscanf(fp,"%f\t%f",&ar[i][0],&ar[i][1]);
}
fclose(fp);
///Input
printf("Give the value for which we have to calculate:\n");
scanf("%d",&x);
/// Find Langrange interpolation
for(j=0;j<5;j++)
{
pi=1;
for(k=0;k<5;k++)
{
if(j!=k)
{
pi=pi*((x-ar[k][0])/(ar[j][0]-ar[k][0]));
}
}
y=y+(pi*ar[j][1]);
}
float m=func(x);
float rel_err=((m-y)/m)*100;
printf("\n Value is:%f,Real is:%f,Relative_Err:%.2f\n",y,m,fabs(rel_err));
}
float func(int x)
{
float theta=(M_PI/6),u=2815.58,g=127008;
return (tan(theta)*x) - (g*pow(x,2))/(2*pow(u,2)*pow(cos(theta),2));
}
