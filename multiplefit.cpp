#include<bits/stdc++.h>
using namespace std;

void least_square(double x[10000],double y[10000],double z[10000],int n){

        cout<<"the table of values is given below:"<<endl;
       cout<<"x\ty\tz\tx^2\txy\tzx\ty^2\tyz"<<endl;
       for(int i=0;i<n;i++){
        cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<"\t"<<pow(x[i],2)<<"\t"<<x[i]*y[i]<<"\t"<<z[i]*x[i]<<"\t"<<pow(y[i],2)<<"\t"<<y[i]*z[i];
         cout<<endl;
       }

        double a1,a0,a2,det,x_sum=0,x2_sum=0,y_sum=0,xy_sum=0,z_sum=0,zx_sum=0,yz_sum=0,y2_sum=0,Y[10000];

        for(int i=0;i<n;i++)
        {
        x_sum=x_sum+x[i];
        y_sum=y_sum+y[i];
        z_sum=z_sum+z[i];
        x2_sum=x2_sum+pow(x[i],2);
         y2_sum=y2_sum+pow(y[i],2);
        xy_sum=xy_sum+x[i]*y[i];
         zx_sum=zx_sum+z[i]*x[i];
          yz_sum=yz_sum+y[i]*z[i];
        }

    cout<<"\nthe equations are:"<<endl;
    cout<<n<<"a0 + "<<x_sum<<"a1 + "<<y_sum<<"a2 = "<<z_sum<<endl;
     cout<<x_sum<<"a0 + "<<x2_sum<<"a1 + "<<xy_sum<<"a2 = "<<zx_sum<<endl;
      cout<<y_sum<<"a0 + "<<xy_sum<<"a1 + "<<y2_sum<<"a2 = "<<yz_sum<<endl;

    det=(n*x2_sum*y2_sum+x_sum*y_sum*xy_sum+y_sum*x_sum*xy_sum)-(n*xy_sum*xy_sum+x_sum*x_sum*y2_sum+y_sum*x2_sum*y_sum);
    a0=((x_sum*y2_sum*(-zx_sum)+y_sum*x2_sum*(-yz_sum)+(-z_sum)*xy_sum*xy_sum)-(x_sum*xy_sum*(-yz_sum)+y_sum*xy_sum*(-zx_sum)+(-z_sum)*x2_sum*y2_sum))/det;
    a1=((n*xy_sum*(-yz_sum)+y_sum*y_sum*(-zx_sum)+(-z_sum)*x_sum*y2_sum)-(n*y2_sum*(-zx_sum)+y_sum*x_sum*(-yz_sum)+(-z_sum)*xy_sum*y_sum))/det;
    a2=((n*xy_sum*(-zx_sum)+x_sum*x_sum*(-yz_sum)+(-z_sum)*x2_sum*y_sum)-(n*x2_sum*(-yz_sum)+x_sum*y_sum*(-zx_sum)+(-z_sum)*x_sum*xy_sum))/det;

    cout<<"\nThe solution of the above system is:\n\n"<<"a0 : "<<a0<<" a1: "<<a1<<" a2: "<<a2<<endl;

    double Z[10000];

    for(int i=0;i<n;i++){
        Z[i]=a0+(a1*x[i])+(a2*y[i]);
    }

    cout<<"\nThe linear fit line is of the form:\n\n"<<"Z = "<<a0<<" + "<<a1<<"x + "<<a2<<"y"<<endl;
}

int main()
{
    int n;
    double x[10000],y[10000],z[10000];

    ifstream f;
    f.open("curve1.txt");

    while(!f.eof()){

        f>>n;

        for(int i=0;i<n;i++){
            f>>x[i]>>y[i]>>z[i];
        }

     /* for(int i=0;i<n;i++){
            cout<<x[i]<<" "<<y[i]<<" "<<z[i];
            cout<<endl;
        }*/


        least_square(x,y,z,n);

        }

}

