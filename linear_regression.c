#include<stdio.h>
#include<math.h>
void main()
{
float ep[]={5.0, 6.0, 8.0, 9.0, 10.0};
float ek[]={0.37, 1.13, 3.22, 4.27, 5.31};
int n=sizeof(ep)/sizeof(ep[0]);
float sum_ep=0.0,sum_ek=0.0,sum_epek=0.0,x,sum_ep_2;
printf("x=");
scanf("%f",&x);
for(int i=0;i<n;i++)
{
sum_ep=sum_ep+ep[i];
sum_ek=sum_ek+ek[i];
sum_epek=sum_epek+ep[i]*ek[i];
sum_ep_2=sum_ep_2+ep[i]*ep[i];
}
float m_ep=sum_ep/n;
float m_ek=sum_ek/n;
float m=(sum_epek-(n*m_ep*m_ek))/(sum_ep_2-n*pow(m_ep,2));
float c=m_ek-(m*m_ep);

printf("slope = %.3f.........Constant=%.3f.......Ans: %.4f",m,c,m*x+c);
}
