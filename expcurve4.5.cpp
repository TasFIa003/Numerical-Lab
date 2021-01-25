#include<bits/stdc++.h>
using namespace std;

void solve(double x[10000],double y[10000],int n){

        double X[10000],Y1[10000];
        cout<<"the table of values is given below:"<<endl;
       cout<<"x\t\ty\t\tx^2\t\txy"<<endl;
       for(int i=0;i<n;i++){
            X[i]=1/x[i];
            Y1[i]=1/y[i];
        cout<<setprecision(3)<<X[i]<<"\t\t"<<Y1[i]<<"\t\t"<<pow(X[i],2)<<"\t\t"<<X[i]*Y1[i];
         cout<<endl;
       }

        double a1,a0,x_sum=0,x2_sum=0,y_sum=0,xy_sum=0,Y[10000];

        for(int i=0;i<n;i++)
        {
        x_sum=x_sum+X[i];
        y_sum=y_sum+Y1[i];
        x2_sum=x2_sum+pow(X[i],2);
        xy_sum=xy_sum+X[i]*Y1[i];
        }

    a0=(n*xy_sum-x_sum*y_sum)/(n*x2_sum-x_sum*x_sum);
    a1=(x2_sum*y_sum-x_sum*xy_sum)/(x2_sum*n-x_sum*x_sum);

     for(int i=0;i<n;i++){
        Y[i]=a0+(a1*X[i]);
     }

    cout<<"\nThe linear fit line is of the form:\n\n"<<"Y = x/("<<a0<<" + "<<a1<<"x )"<<endl;

}

int main()
{
    int n;
    double x[10000],y[10000];

    ifstream f;
    f.open("curve3.txt");

    while(!f.eof()){

        f>>n;

        for(int i=0;i<n;i++){
            f>>x[i]>>y[i];
        }

       /* for(int i=0;i<n;i++){
            cout<<x[i]<<" "<<y[i];
        }*/


        solve(x,y,n);

        }

}
