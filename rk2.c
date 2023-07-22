#include<stdio.h>
float func(float x,float y)
{
return (x-y)/2;
}
void main()
{
float x0,y0,h,xf,k1,k2,yf;
printf("Intial x0:");
scanf("%f",&x0);
printf("\nIntial y0:");
scanf("%f",&y0);
h=0.1;
int n,i;
printf("\nIntial xf:");
scanf("%f",&xf);
n=xf/h;
for(i=0;i<n;i++)
{
k1=h*func(x0,y0);
k2=h*func((x0+h),(y0+k1));
yf=y0+(k1+k2)*0.5;
y0=yf;
x0=x0+h;
}
printf("The final ans is %f\n",yf);
}
