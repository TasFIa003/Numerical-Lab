#include<bits/stdc++.h>
using namespace std;

void least_square(double x[10000],double y[10000],int n){

        cout<<"the table of values is given below:"<<endl;
       cout<<"x\ty\tx^2\txy"<<endl;
       for(int i=0;i<n;i++){
        cout<<x[i]<<"\t"<<y[i]<<"\t"<<pow(x[i],2)<<"\t"<<x[i]*y[i];
         cout<<endl;
       }

        double a1,a0,x_sum=0,x2_sum=0,y_sum=0,xy_sum=0;

        for(int i=0;i<n;i++)
        {
        x_sum=x_sum+x[i];
        y_sum=y_sum+y[i];
        x2_sum=x2_sum+pow(x[i],2);
        xy_sum=xy_sum+x[i]*y[i];
        }

    a1=(n*xy_sum-x_sum*y_sum)/(n*x2_sum-x_sum*x_sum);
    a0=(x2_sum*y_sum-x_sum*xy_sum)/(x2_sum*n-x_sum*x_sum);



    cout<<"\nThe linear fit line is of the form:\n\n"<<"Y = "<<a0<<" + "<<a1<<"x"<<endl;

}

int main()
{
    int n;
    double x[10000],y[10000];

    ifstream f;
    f.open("curve.txt");

    while(!f.eof()){

        f>>n;

        for(int i=0;i<n;i++){
            f>>x[i]>>y[i];
        }

       /* for(int i=0;i<n;i++){
            cout<<x[i]<<" "<<y[i];
        }*/


        least_square(x,y,n);

        }

}
