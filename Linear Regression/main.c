#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intake(void);
void mean_of_data(void);
void calc_eqn(void);
void calc_rsqr(void);
void calc_std_er_est(void);

int n;
float xm,ym,xbar2m,ybar2m,m,c,yact2,yest2,rsqr,ystd2,std_er;
float x[1000],y[1000],xbar[1000],ybar[1000],xbar2[1000],ybar2[1000];
float yact[1000],yest[1000],ystd[1000];

int main()
{
    intake();

    mean_of_data();

    calc_eqn();

    calc_rsqr();

    calc_std_er_est();

    return 0;
}

void intake(){
    xm=ym=xbar2m=ybar2m=yact2=yest2=ystd2=0;
    printf("Enter the number of samples (<1000) : \n");
    scanf("%d",&n);
    printf("\n\nEnter the Independent variables : \n");
    for(int i=0;i<n;i++)
        scanf("%f", &x[i]);
    printf("\n\nEnter the Dependent variables : \n");
    for(int i=0;i<n;i++)
        scanf("%f", &y[i]);
    printf("\n________________________________________________________________\n");
}

void mean_of_data(){
    for(int i=0;i<n;i++)
        xm=xm+x[i];
    xm=xm/n;
    for(int i=0;i<n;i++)
        ym=ym+y[i];
    ym=ym/n;

    printf("Mean of Independent Variable is : %f \n",xm);
    printf("Mean of Dependent Variable is : %f \n",ym);
    printf("\n________________________________________________________________\n");
}

void calc_eqn(){
    for(int i=0;i<n;i++)
        xbar[i]=x[i]-xm;
    for(int i=0;i<n;i++)
        ybar[i]=y[i]-ym;
    for (int i=0;i<n;i++){
        xbar2[i]=xbar[i]*xbar[i];
        xbar2m=xbar2m+xbar2[i];
    }
    for (int i=0;i<n;i++){
        ybar2[i]=xbar[i]*ybar[i];
        ybar2m=ybar2m+ybar2[i];
    }

    m=ybar2m/xbar2m;
    c=ym - (m*xm);

    printf("Linear Regression Equation OP : \n");
    printf("Y = M x X + C\n");
    printf("M = %f and C = %f \n",m,c);
    printf("\n________________________________________________________________\n");
}

void calc_rsqr(){
    for(int i=0; i<n;i++){
        yact[i]=ybar[i]*ybar[i];
        yact2 = yact2 + yact[i];
    }
    for(int i=0;i<n;i++){
        yest[i]=(((x[i]*m)+c)-ym) * (((x[i]*m)+c)-ym);
        yest2=yest2+yest[i];
    }
    rsqr=yest2/yact2;

    printf("The R Squared Value of the Given Regressed Data is : %f \n",rsqr);

    printf("\n________________________________________________________________\n");
}

void calc_std_er_est(){
    for(int i=0;i<n;i++){
        ystd[i]=(((x[i]*m)+c)-y[i])*(((x[i]*m)+c)-y[i]);
        ystd2=ystd2+ystd[i];
    }
    std_er=sqrt(ystd2/(n-2));

    printf("The Standard Error Estimate of the Given Regressed Data is : %f \n",std_er);

    printf("\n________________________________________________________________\n");
}
