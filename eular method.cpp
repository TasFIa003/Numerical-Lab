#include<bits/stdc++.h>
using namespace std;

double f(double x,double y){

        return (-y);

}

int main(){

double x0, y0, xn, h, yn, F;
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


  cout<<"\nx0\ty0\tf(x0,y0)\tyn\n";
 for(int i=0; i < n; i++)
 {
  F = f(x0, y0);
  yn = y0 + h*F ;
  cout<<setprecision(5)<< x0<<"\t"<< y0<<"\t"<< F<<"\t"<< yn<< endl;
  y0 = yn;
  x0 = x0+h;
 }

     cout<<"\nValue of y at x = "<< x0<< " is " << yn;


}
