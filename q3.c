#include <stdio.h>
#include <math.h>
int main()
{
    // Define the given data
    float Ep[] = {5.0, 6.0, 8.0, 9.0, 10.0};
    float Ek[] = {0.37, 1.13, 3.22, 4.27, 5.31};
    int n = sizeof(Ep) / sizeof(Ep[0]);  // number of data points

    // Calculate the slope and intercept of the line
    float sum_ep = 0, sum_ek = 0, sum_ep_ek = 0, sum_ep_sq = 0;
    for (int i = 0; i < n; i++) {
        sum_ep += Ep[i];
        sum_ek += Ek[i];
        sum_ep_ek += Ep[i] * Ek[i];
        sum_ep_sq += Ep[i] * Ep[i];
    }
    float mean_ep = sum_ep / n;
    float mean_ek = sum_ek / n;
    float m = (sum_ep_ek - n * mean_ep * mean_ek) / (sum_ep_sq - n * mean_ep * mean_ep);
    float c = mean_ek - m * mean_ep;

    // Estimate the value of Ek for Ep = 7.0 eV
    float ep_new = 7.0;
    float ek_new = m * ep_new + c;
    printf("Slope : %.2f\n",m);
    printf("Estimated value of Ek for Ep = 7.0 eV: %.2f eV\n", ek_new);
    printf("Actual value is: 2.33 , Asoulte relative error :%.2f percent\n",(fabs(2.33-ek_new)/2.33)*100);

    return 0;
}
