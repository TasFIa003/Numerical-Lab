#include<bits/stdc++.h>
#define ll long long
using namespace std;
double calculate_y(double x,double y){

        return ((3*x+y)/(x+2*y));

}

int main()
{
    double x0,y0;
     cout<<"Enter Initial Condition"<< endl;
     cout<<"x0 = ";
     cin>> x0;
     cout<<"y0 = ";
     cin >> y0;
     ll i=0;

  while(1)
  {
    double xn,h,y,d1,d2,d3,d4,d;
    ll n;
     cout<<"Enter calculation point h = ";
     cin>>h;
     if(h==0)
     break;
     //cout<<"Enter number of decimal places: ";
     //cin>>n;


      cout<<"x"<<"\t"<<"y"<<endl;

        d1 = h*(calculate_y(x0, y0));
        d2 = h * (calculate_y((x0+h/2),(y0+d1/2)));
        d3 = h * (calculate_y((x0+h/2),(y0+d2/2)));
        d4 = h * (calculate_y((x0+h),(y0+d3)));
        d  = (d1+2*d2+2*d3+d4)/6;
        y = y0+d;
        cout<<setprecision(5)<<x0+h<<"\t"<<y<< endl;

       cout<<endl<<"Value of y at x = "<<x0+h<<" is "<<y<<endl;
  }


}
