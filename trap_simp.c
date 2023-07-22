#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

float f(float x) 
{
return (2.0) *x*pow(sin(PI * x),2);
}
float trap(float a,float b,float dx)
{
    float h,x,sum=0,integral;
  /*Begin Trapezoidal Method: */
  int n=fabs(b-a)/dx;
  for(int i=1;i<n;i++){
    x=a+i*dx;
    sum=sum+f(x);
  }
  integral=(dx/2)*(f(a)+f(b)+2*sum);
  return integral;
}

float simp(float a,float b,float dx)
{
    float h,x,sum=0,integral_1;
  /*Begin Simp1/3 Method: */
  int n=fabs(b-a)/dx;
  for(int i=1;i<n;i++){
    x=a+i*dx;
    if(i%2==0)
    {
    sum=sum+2*f(x);
    }
    else
    {
    sum=sum+4*f(x);
    }
  }
  integral_1=(dx/3)*(f(a)+f(b)+sum);
  return integral_1;
}

int main()
{
float a,b,dx;
printf("intial value:\n");
scanf("%f",&a);
printf("final value:\n");
scanf("%f",&b);
printf("difference value:\n");
scanf("%f",&dx);
float trap_ans=trap(a,b,dx);
printf("The value of intregation: %.4f\n",trap_ans);
float simp_ans=simp(a,b,dx);
printf("The value of intregation: %.4f\n",simp_ans);

return 0;
}
