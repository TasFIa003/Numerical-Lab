#include<bits/stdc++.h>
using namespace std;

double f(double x,double y){

        return (pow(x,2)+y);

}

int main(){

double x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int  n;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Enter calculation point h= ";
 cin>>h;
 cout<<"Enter number of steps: ";
 cin>> n;


  cout<<"\nx0\ty0\tyn\n";
 for(int i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  cout<<setprecision(5)<< x0<<"\t"<< y0<<"\t"<< yn<< endl;
  y0 = yn;
  x0 = x0+h;
 }

     cout<<"\nValue of y at x = "<< x0<< " is " << yn;


}
