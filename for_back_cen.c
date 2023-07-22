#include<stdio.h>
#include<math.h>
//Define constant
float k = 1/(4*M_PI);
float q=1;
//////////////////////////////////
float V(float x)
{
return k*(q/x);
}
float forward(float y1,float y2,float h)
{
return (y2-y1)/h;
}
float center(float y1,float y2,float h)
{
return (y2-y1)/(2*h);
}
float backward(float y1,float y2,float h)
{
return (y2-y1)/h;
}
int main() {
    // Generate the values of V(x) in the range 1 <= x <= 5 with step-size h=0.1
    double x[41];
    for (int i = 0; i < 41; i++) {
        x[i] = 1 + i * 0.1;
    }
    double V_values[41];
    for (int i = 0; i < 41; i++) {
        V_values[i] = V(x[i]);
    }

    // Calculate the analytical result for electric field
    double E_analytical[40];
    for (int i = 0; i < 40; i++) {
        E_analytical[i] = - q / (4 *M_PI * pow(x[i+1], 2));
    }

    // Calculate the forward, backward, and centered differences for electric field
    double E_forward[40], E_backward[40], E_centered[39];
    for (int i = 0; i < 40; i++) {
        E_forward[i] = forward(V_values[i], V_values[i+1], 0.1);
        E_backward[i] = backward(V_values[i-1], V_values[i], 0.1);
    }
    for (int i = 0; i < 39; i++) {
        E_centered[i] = center(V_values[i], V_values[i+2], 0.1);
    }
    E_centered[40]=0;

    // Print the results
    printf("x\tE_analytical\tE_forward\tE_backward\tE_centered\n");
    for (int i = 0; i < 40; i++) {
        printf("%.1f\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", x[i], E_analytical[i], E_forward[i], E_backward[i],E_centered[i]);
    }
    ///Store all the values in a dat file
    FILE *fp;
    fp=fopen("q1.dat","w");
    for(int i=1;i<39;i++)
    {
    fprintf(fp,"%.1f\t%.4f\t%.4f\t%.4f\t%.4f\n", x[i], E_analytical[i],E_forward[i], E_backward[i],E_centered[i]);
    }
    fclose(fp);


    return 0;
}

