#include<stdio.h>
#include<math.h>
//#include<stdlib>

float func(float x)
{
float z=exp(-x*x/2)/pow(3.414,0.25);
return z;
}

float psi2(float x, float y)
{
float z=(x*x-1)*y;
return z;
}
float psi1(float y)
{
return y;
}
void main()
{
float x1[21]={0},y1[21]={0},y2[21]={0},f1,f2,f3,f4,p1,p2,p3,p4;
x1[0]=-2.5;
y1[0]=0.033;
y2[0]=0.0825;
float h=0.25;
int i;
FILE* f;
f = fopen("QHO.txt","w");
for(i=0;i<21;i++)
{
f1=psi2(x1[i],y1[i]);

p1=psi1(y2[i]);

f2=psi2((x1[i]+h/2),(y1[i]+(p1*h)/2));

p2=psi1(y2[i]+(f1*h)/2);

f3=psi2((x1[i] + h/2),(y1[i] + (p2*h)/2));

p3=psi1(y2[i] + (f2*h)/2);

f4=psi2((x1[i]+h),(y1[i]+(p3*h)));

p4=psi1(y2[i]+(f3*h));
y2[i+1]=y2[i]+((f1+(2*f2)+(2*f3)+f4)*(h/6));
x1[i+1]=x1[i]+h;
y1[i+1]=y1[i]+((p1+(2*p2)+(2*p3)+p4)*(h/6));
fprintf(f,"%f\t%f\t%f\n",x1[i],func(x1[i]),y1[i]);
}
fclose(f);
}
