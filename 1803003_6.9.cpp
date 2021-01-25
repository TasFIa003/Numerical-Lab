#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=4,m=5;
    double x[5],y[5],a[5];


    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
    }
   /* for(int i=0;i<n;i++){
        cout<<x[i]<<y[i];
    }*/

    for(int i=0;i<m;i++){
        a[i]=pow(y[i],2);
        //cout<<a;
    }

    cout<<"Table:"<<endl;
    for(int i=0;i<m;i++){
        cout<<x[i]<<"\t\t"<<a[i]<<endl;
    }
    cout<<endl;
    double volume,h;

    h=x[1]-x[0];
    double sum_odd=0.0;
    double sum_even=0.0;

    for (int i = 1; i < n; i += 2)
    {
        sum_odd +=a[i] ;
    }
    double sum_evens = 0.0;
    for (int i = 2; i < n; i += 2)
    {
        sum_even +=a[i];
    }

    double fist_num=a[0], last_num=a[m-1];
    //cout<<fist_num<<endl<<last_num<<endl;
    volume=3.1416*(h/3)*(fist_num+last_num+(2*sum_even)+(4*sum_odd));

    cout<<"Volume: ";
    cout<<setprecision(5)<<volume<<endl;




}




