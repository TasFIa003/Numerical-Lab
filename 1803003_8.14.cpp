#include<bits/stdc++.h>
using namespace std;

double f(double x,double y){

        return (1+((2*x*y)/(1+pow(x,2))));

}

void RK4(double x0,double y0){

double  xn, yn, k1, k2, k3, k4, k,h;

    cout<<endl<<"Enter last point of xn= ";
    cin>>xn;
    h=(xn-x0);
    cout<<endl<<"value of h = "<<h<<endl;

  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
    y0 = yn;
  x0 = x0+h;
    cout<<"\nValue of y at x = "<< x0<< " is " << yn;
    cout<<endl;


}

int main(){
    double x0, y0, h;
    cout<<"Enter Initial Condition"<< endl;
    cout<<"x0 = ";
    cin>> x0;
    cout<<"y0 = ";
    cin >> y0;


    while(1){
        int choice ;
        cout<<endl<<"1.Runge-Kutta Fourth order method\n2.Exit(press any key to exit)\t"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        if(choice==1){
        RK4(x0, y0);
        cout<<endl;
        }else{
                cout<<"Exit";
                break;
        }
    }

}


