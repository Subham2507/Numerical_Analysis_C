#include<stdio.h>
#include<math.h>

float func(float x,float y)
{
return (4*exp(0.8*x))-0.5*y;
}
float ans(float x)
{
return ((4/1.3)*(exp(0.8*x)-exp(-0.5*x))) - 2*exp(-0.5*x);
}

void main()
{
float x0,y0,xn,yn,x_i,x_f,m,yh,y0_1,j;
x0=0.0;//given
y0=2.0;//given
y0_1=2.0;
float h=1;//given
printf("Enter the value of x_final");
scanf("%f",&xn);
int n=fabs((xn-x0)/h);
 printf("\nx0\ty0\tslope\tyn\ty_huen\n");
 printf("------------------------------\n");
for(int i=0;i<n;i++)
{
////////////Eular/////////////////
m=func(x0,y0);
yn=y0+(m*h);
///////////////////////////////////
/////////////////Huen//////////////
j=(h/2)*(func(x0,y0_1)+func(x0+h,y0_1+h*func(x0,y0_1)));
yh=y0_1+j;
printf("%.4f\t%.4f\t%0.4f\t%.4f\t%.4f\n",x0+1,y0,m,yn,yh);
y0=yn;
x0=x0+h;
}
float k=ans(xn);
printf("\nValue of y at x = %0.2f is %0.3f.........Original Ans= %.3f....error=%.2fpercent\n....Ans for huen: %.4f........Error:%.2fpercent",xn, yn,k,fabs((k-yn)/k)*100,yh,fabs((k-yh)/k)*100);
}
