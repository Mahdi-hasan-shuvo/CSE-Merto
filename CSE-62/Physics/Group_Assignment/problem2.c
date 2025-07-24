#include <stdio.h>
#include <math.h>

// Name : Mahdi Hasan Shuvo
// GitHub: Mahdi-Hasan-Shuvo
// ID: 251-115-030 
int main() {
    double theta = 45.0;
    double theta_radous = theta * (3.1416 / 180); 
    double ratio = 1 / sin(theta_radous);  
    printf("The ratio a/lambda is: %.2f\n", ratio);

    return 0;
}
