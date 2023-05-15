/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<complex.h>
#include<math.h>

void ifft(double complex *x,int N)
{
    for(int i=0;i<N;i++)
    {
        x[i]=conj(x[i]);
    }
    fft(x, N);
    for(int i=0;i<N;i++)
    {
        x[i]= conj(x[i])/N;
    }
    
}
void fft(double complex *x,int N)
{
    if(N<=1)
    {
        return;
    }
    double complex*even=malloc(N/2*sizeof(double complex));
    double complex*odd=malloc(N/2*sizeof(double complex));
    for(int i=0;i<N/2;i++)
    {
        even[i]=x[2*i];
        odd[i]=x[2*i+1];
    }
    fft(even,N/2);
    fft(odd,N/2);
    for(int k=0;k<N/2;k++)
    {
        double complex t =cexp(-I*2*M_PI*k/N)*odd[k];
        x[k]=even[k]+t;
        x[k+N/2]=even[k]-t;
    }
}
int main()
{
    int N=4;
    double complex x[]={0,2,0,2};
    ifft(x,N);
    for(int i=0;i<N;i++)
    {
        printf("x[%d]=%.2f+%.2fi\n",i,creal(x[i]),cimag(x[i]));
    }

    return 0;
}
