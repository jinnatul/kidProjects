#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int back();

float root()
{
    double num, root;

    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any number to find square root : ");
    scanf("%lf", &num);

    /* Calculate square root of num */
    root = sqrt(num);

    /* Print the resultant value */
    printf("\nSquare root of %.2lf = %.2lf\n", num, root);
    fprintf(m, "%.2lf\n", root);
    fclose(m);

    return 0;
}


float square()
{
    float n,sqr=0;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nENTER THE NO : ");
    scanf("%f",&n);
    sqr=n*n;
    printf("\nSQUARE OF %f is %f\n",n,sqr);

    fprintf(m, "%.2f\n", sqr);
    fclose(m);
}


float cube()
{
    float n,cube=0;
     FILE *m;
    m = fopen("a.txt","a");

    printf("\nENTER THE NO.: ");
    scanf("%f",&n);
    cube=n*n*n;
    printf("\nCUBE OF %f is %f\n",n,cube);

     fprintf(m, "%.2f\n", cube);
    fclose(m);
}


float cubic_root()
{
    float num, ans;

     FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any number : ");
    scanf("%f",&num);
    ans=pow(num, 1/3);
    printf("\nCube root of %f is: %f\n",num,ans);

    fprintf(m, "%.2f\n", ans);
    fclose(m);
}


float any_root()
{
    float num, ans,pow_nu;

     FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any number : ");
    scanf("%f",&num);
    printf("\nEnter power of the number : ");
    scanf("%f",&pow_nu);
    ans=pow(num, pow_nu);
    printf("\nCube root of %f is: %f\n",num,ans);

    fprintf(m, "%.2f\n", ans);
    fclose(m);
}


float power()
{

    float num,power;

    FILE *m;
    m = fopen("a.txt","a");

    double ans;
    printf("\nEnter any number : ");
    scanf("%f",&num);
    printf("\nEnter any its power : ");
    scanf("%f",&power);
    ans=pow(num,power);
    printf("\nAnswer of %f is: %lf\n",num,ans);

    fprintf(m, "%.2lf\n", ans);
    fclose(m);

}


int factorial()
{
    int n,i;
    FILE *m;
    m = fopen("a.txt","a");

    long fact=1;
    printf("\nWrite a number : ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        fact=fact*i;
    }
    printf("\nFactorial is : %ld\n",fact);

    fprintf(m, "%.ld\n", fact);
    fclose(m);
}


float sine()
{
    int i;
    float aa;

    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);

    aa= sin(i*M_PI/180);
    printf("\nsin(%d) = %.2f\n",i,aa);

    fprintf(m, "%.2f\n", aa);
    fclose(m);
}


float cosine()
{
    int i;
    float ab;

    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);

    ab = cos(i*M_PI/180);
    printf("\ncos(%d) = %.2f\n",i,ab);

    fprintf(m, "%.2f\n", ab);
    fclose(m);
    
}


float tangent()
{
    int i;
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);
    ab = tan(i*M_PI/180);

    printf("\ntan(%d) = %.2f\n",i,ab);

    fprintf(m, "%.2f\n", ab);
    fclose(m);
     
}


float cot()
{
    int i;
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);

    ab = 1/tan(i*M_PI/180);

    printf("\ncot(%d) = %.2f\n",i,ab);

    fprintf(m, "%.2f\n", ab);
    fclose(m);
     

}


float sec()
{
    int i;
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);
    ab = 1/cos(i*M_PI/180);

    printf("\nsec(%d) = %.2f\n",i,ab);
    
     fprintf(m, "%.2f\n", ab);
    fclose(m);
}


float cosec()
{
    int i;
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%d",&i);

    ab = 1/sin(i*M_PI/180);

    printf("\ncosec(%d) = %.2f\n",i,ab);
   
   fprintf(m, "%.2f\n", ab);
    fclose(m);
}


float sin_inverse()
{
    float i;

    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%f",&i);

    ab = asin(i*180/M_PI);
    printf("\nsin inverse(%.2f) = %.2f\n",i,ab);
   
   fprintf(m, "%.2f\n", ab);
    fclose(m);
}


float cos_inverse()
{
    float i;
    
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%f",&i);

    ab = acos(i*180/M_PI);
    printf("\ncos inverse(%.2f) = %.2f\n",i,ab);
   
    fprintf(m, "%.2f\n", ab);
    fclose(m);
}


float tan_inverse()
{
    float i;
    float ab;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any angle : ");
    scanf("%f",&i);

    ab = atan(i*180/M_PI);
    printf("\ntan inverse(%.2f) = %.2f\n",i,ab);
    
    fprintf(m, "%.2f\n", ab);
    fclose(m);
}

float add()
{
    int b,i;

    FILE *m;
    m = fopen("a.txt","a");

    float s=0,c[1000];
    printf("\nHow many number : ");
    scanf("%d",&b);
    printf("\nEnter numbers : ");
    for(i=0; i<b; i++)
    {
        scanf("%f",&c[i]);
        s=s+c[i];
    }


    printf("\nAddition: %.2f\n",s);

    fprintf(m, "%.2f\n", s);
    fclose(m);
}


float sub()
{
    int b,i;

    FILE *m;
    m = fopen("a.txt","a");

    float s=0,ss,ck,c[1000];
    printf("\nHow many number : ");
    scanf("%d",&b);
    printf("\nEnter numbers : ");
    for(i=0; i<b; i++)
    {
        scanf("%f",&c[i]);
        ck = c[0];
        s+=c[i];
    }
   ss = (2*ck) - s;

    printf("\nSubtraction : %.2f\n",ss);

    fprintf(m, "%.2f\n", ss);
    fclose(m);
}


float mul()
{
    int b,i;

    FILE *m;
    m = fopen("a.txt","a");

    float s=1,c[1000];
    printf("\nHow many number : ");
    scanf("%d",&b);
    printf("\nEnter numbers : ");
    for(i=0; i<b; i++)
    {
        scanf("%f",&c[i]);
        s=s*c[i];
    }

    printf("\nMultiplication: %.2f\n",s);

    fprintf(m, "%.2f\n", s);
    fclose(m);
}


float div()
{
    int b,i;
   
    FILE *m;
    m = fopen("a.txt","a");

    float s=1,c[1000];
    printf("\nHow many number : ");
    scanf("%d",&b);
    printf("\nEnter numbers : ");
    for(i=0; i<b; i++)
    {
        scanf("%f",&c[i]);
        s/=c[i];
    }

    printf("\nDivision : %.2f\n",s);

    fprintf(m, "%.2f\n", s);
    fclose(m);
}


float logarithm()
{
    double a,b;
    FILE *m;
    m = fopen("a.txt","a");

    printf("\nEnter any number to find the logarithm value : ");
    scanf("%lf",&a);
    b= log(a);
    printf("\nlog(%lf) = %.2lf\n", a,b);

   fprintf(m, "%.2lf\n", b);
    fclose(m);
}


int main()
{
    char a,b[10];
    int i=0;
    printf("\nWhat type of operation do you need?\n\n");
   
    printf("\n\tNormal Mode : \n");
    printf("\t\t1--> Addition to press (+)\n");
    printf("\t\t2--> Subtraction to pree (-)\n");
    printf("\t\t3--> Multiplication to pree (*)\n");
    printf("\t\t4--> Division to pree (/)\n");
   
    printf("\n\tOther Mode : \n");
    printf("\t\t5--> Root\n \t\t6--> Square\n \t\t7--> Cube\n \t\t8--> Cubic_root\n \t\t9--> Power\n \t\t10--> Factorial\n");
    printf("\t\t11-> sin\n \t\t12--> tan\n \t\t13--> cos\n \t\t14--> cot\n \t\t15--> sec\n \t\t16--> cosec\n");
    printf("\t\t17--> sin_inverse\n \t\t18--> tan_inverse\n \t\t19--> cos_inverse\n \t\t20--> Any_root\n \t\t21--> Logarithm\n\n ");
    
    printf("Exit this system to pree Any keyword.......\n\n");
    printf("\nChoose your operation : ");

    back();
}

back()
{
   int a;
   scanf("%d",&a);
   
   switch(a){

    case 1:

        add();
        break;
    
    case 2:
        sub();
        break;
   
    case 3:
        mul();
        break;

    case 4:
        div();
        break;
    
    case 5:
        root();
        break;
    
    case 6:
        square();
        break;
    case 7:
        cube();
        break;
    
    case 8:
        cubic_root();
        break;
 
    case 9:
        power();
        break;
    
    case 10:
        factorial();
        break;
       
    case 11:
      sine();
      break;
    
    case 12:
        tangent();
         break;
    
    case 13:
        cosine();
        break;
    
    case 14:
        cot();
        break;
    
    case 15:
        sec();
        break;

    case 16:
        cosec();
        break;
    
    case 17:
        cos_inverse();
        break;
    
    case 18:
        sin_inverse();
        break;
    
    case 19:
        tan_inverse();
        break;
    
    case 20:
        any_root();
        break;
    
    case 21:
        logarithm();
        break;
    }

    printf("\n\nIf back to main function  to pree (1) : ");
    int as;
    scanf("%d",&as);

    if(as==1){

        system("cls");
        main();
    }
 
}