
#include<stdio.h>
#include<math.h>
#define pi 3.1416
// Name : Mahdi Hasan Shuvo
// GitHub: Mahdi-Hasan-Shuvo
// ID: 251-115-030 
int main()
{
    double lemda_nm,lemda_m,m,a1,a2,a3,t1,t2,t3,sint;
    printf("Enter wavelength in nm : ");
    scanf("%lf",&lemda_nm);
    if(lemda_nm < 380 || lemda_nm >750)
    {
        printf("Out of Range\n",lemda_nm);
    }
    printf("Enter the value of m : ");
    scanf("%lf",&m);

    printf("Enter the first slit width a1 : ");
    scanf("%lf",&a1);
    printf("Enter the second slit width a2 : ");
    scanf("%lf",&a2);
    printf("Enter the third slit width a3 : ");
    scanf("%lf",&a3);


    lemda_m = lemda_nm * 1e-9;

    sint = (m * lemda_m) / (a1 * 1e-6);
    t1 = asin(sint) * (180 / pi);

    sint = (m * lemda_m) / (a2 * 1e-6);
    t2 = asin(sint) * (180 / pi);

    sint = (m * lemda_m) / (a3 * 1e-6);
    t1 = asin(sint) * (180 / pi);

    printf("The angle for slit a1 :%.2f degrees\n",t1);
    printf("The angle for slit a2 :%.2f degrees\n",t2);
    printf("The angle for slit a3 :%.2f degrees\n",t3);


    if(t1>t2&&t1>t3)
    {
        printf("slit a1 light bend the most\n");
    }
    else if(t2 > 1 && t2 > t3)
    {
        printf("slit a2 light bend the most\n");
    }
    else if(t3 > t1 && t3 > t2)
    {
        printf("slit a3 light bend the most\n");
    }

    printf("color of light : ");
    if(lemda_nm >=380 && lemda_nm < 450)
    {
        printf("Violet\n");
    }
    else if(lemda_nm >= 450 && lemda_nm < 485)
    {
        printf("Blue\n");
    }
    else if(lemda_nm >=485 && lemda_nm < 500)
    {
        printf("Cyan\n");
    }
    else if(lemda_nm >=500 && lemda_nm < 565)
    {
        printf("Green\n");
    }
    else if(lemda_nm >=565 && lemda_nm < 590)
    {
        printf("Yellow\n");
    }
    else if(lemda_nm >=590 && lemda_nm < 625)
    {
        printf("Orange\n");
    }
    else if(lemda_nm >=625 && lemda_nm < 750)
    {
        printf("Red\n");
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}
