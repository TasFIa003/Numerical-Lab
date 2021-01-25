#include<bits/stdc++.h>
using namespace std;

void least_square(double x[10000],double y[10000],int n){

        cout<<"the table of values is given below:"<<endl;
       cout<<"x\ty\tx^2\tx^3\tx*4\txy\tx^2y"<<endl;
       for(int i=0;i<n;i++){
        cout<<x[i]<<"\t"<<y[i]<<"\t"<<pow(x[i],2)<<"\t"<<pow(x[i],3)<<"\t"<<pow(x[i],4)<<"\t"<<x[i]*y[i]<<"\t"<<pow(x[i],2)*y[i];
         cout<<endl;
       }

        double a1,a0,a2,det,x_sum=0,x2_sum=0,y_sum=0,xy_sum=0,x3_sum=0,x4_sum=0,x2y_sum=0,Y[10000];

       for(int i=0;i<n;i++)
        {
        x_sum=x_sum+x[i];
        y_sum=y_sum+y[i];
        x2_sum=x2_sum+pow(x[i],2);
        x3_sum=x3_sum+pow(x[i],3);
        x4_sum=x4_sum+pow(x[i],4);
        xy_sum=xy_sum+x[i]*y[i];
        x2y_sum=x2y_sum+pow(x[i],2)*y[i];

        }

    cout<<"\nthe equations are:"<<endl;
    cout<<n<<"a0 + "<<x_sum<<"a1 + "<<x2_sum<<"a2 = "<<y_sum<<endl;
     cout<<x_sum<<"a0 + "<<x2_sum<<"a1 + "<<x3_sum<<"a2 = "<<xy_sum<<endl;
      cout<<x2_sum<<"a0 + "<<x3_sum<<"a1 + "<<x4_sum<<"a2 = "<<x2y_sum<<endl;

    det = (n*x2_sum*x4_sum+x_sum*x2_sum*x3_sum+x2_sum*x_sum*x3_sum)-(n*x3_sum*x3_sum+x_sum*x_sum*x4_sum+x2_sum*x2_sum*x2_sum);
    a0 = ((x_sum*x4_sum*(-xy_sum)+x2_sum*x2_sum*(-x2y_sum)+(-y_sum)*x3_sum*x3_sum)-(x_sum*x3_sum*(-x2y_sum)+x2_sum*x3_sum*(-xy_sum)+(-y_sum)*x2_sum*x4_sum))/det;
    a1 = ((n*x3_sum*(-x2y_sum)+x2_sum*x2_sum*(-xy_sum)+(-y_sum)*x_sum*x4_sum)-(n*x4_sum*(-xy_sum)+x2_sum*x_sum*(-x2y_sum)+(-y_sum)*x3_sum*x2_sum))/det;
    a2= ((n*x3_sum*(-xy_sum)+x_sum*x_sum*(-x2y_sum)+(-y_sum)*x2_sum*x2_sum)-(n*x2_sum*(-x2y_sum)+x_sum*x2_sum*(-xy_sum)+(-y_sum)*x_sum*x3_sum))/det;

    cout<<"\nThe solution of the above system is:\n\n"<<"a0 : "<<a0<<" a1: "<<a1<<" a2: "<<a2<<endl;
    cout<<"\nThe Polynomial equation is :\n\n"<<"Y = "<<a0<<" + "<<a1<<"x + "<<a2<<"x^2"<<endl;
}

int main()
{
    int n;
    double x[10000],y[10000];

    ifstream f;
    f.open("curve2.txt");

    while(!f.eof()){

        f>>n;

        for(int i=0;i<n;i++){
            f>>x[i]>>y[i];
        }

     /* for(int i=0;i<n;i++){
            cout<<x[i]<<" "<<y[i]<<" "<<z[i];
            cout<<endl;
        }*/


        least_square(x,y,n);
        cout<<"\n\n*************************************************************************\n"<<endl;

        }

}


