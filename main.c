/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

float psi2( float x, float y)
{ 
    float z;
    z = (x*x - 1)*y;
    return z;
}
float psi1(float y)
{ 
    return y;
}
float ff(float x)
{ 
    float z;
    z = exp(-x*x/2)/pow(3.141,0.25);
    return z;
}


void main()
{ 
    float x[21]={0}, y1[21]={0}, y2[21]={0},h =0.25, k1, k2, k3, k4, p1, p2, p3, p4;
    int i;
    FILE* f;
    f = fopen("QHO.txt","w");
    y1[0]=0.03300;
    y2[0]=0.08250;
    x[0]= -2.5;
    for (i=0;i<21;i++)
    {
        k1 = psi2(x[i], y1[i]);
        p1 = psi1(y2[i]);
        k2 = psi2(x[i] + h/2 , y1[i] + (p1*h)/2);
        p2 = psi1(y2[i] + (k1*h)/2);
        k3 = psi2(x[i] + h/2 , y1[i] + (p2*h)/2);
        p3 = psi1(y2[i] + (k2*h)/2);
        k4 = psi2(x[i] + h , y1[i] + p3*h);
        p4 = psi1(y2[i] +  k3*h);
        y2[i+1] = y2[i] + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
        x[i+1] = x[i] + h; 
        y1[i+1] = y1[i] + (h/6)*(p1 + 2*p2 + 2*p3 + p4);
        fprintf(f,"%f\t%f\t%f\n",x[i],ff(x[i]),y1[i]);
        
    }
}
