#include <stdio.h>
#include <math.h>
// Name : Mahdi Hasan Shuvo
// GitHub: Mahdi-Hasan-Shuvo
// ID: 251-115-030 
int main() {
	double theta, lamda,d;
	int m;
	printf("Enter Wavelength Lambda (NM): ");
    scanf("%lf", &lamda);
    if (lamda < 380 || lamda > 750) {
        printf("Out of the range. Please enter a valid number.\n");
       // main();
    }
    printf("Enter angle θ in degrees : ");
    scanf("%lf", &theta);

    printf("Enter slit separation : ");
    scanf("%lf", &d);
    double lamda_m = lamda * 1e-9;      // nm to meter
    double d_m = d * 1e-6;                // µm to meter
    double theta_radious = theta * (3.1416 / 180); // degrees to radians
    double calculation = (d_m * sin(theta_radious)) / lamda_m;
    m =(int)(calculation + 0.5);
    printf("%d-th order maxima\n", m);

    return 0;

}
