#include<bits/stdc++.h>
using namespace std;


int  n=4;
double x[4];
double y[4][4];



void input(){

    ifstream f1;
    f1.open("newton1.txt");

     for(int i=0;i<n;i++)
    {
        f1>>x[i]>>y[i][0];
    }



}

void difference_table(){

for(int j=1;j<n;j++){
    for(int i=0;i<n-j;i++){
        y[i][j]=y[i+1][j-1]-y[i][j-1];
    }
}
}
void draw_table(){

    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
        for(int j = 0; j < n-i ; j++)
    {
            cout << "\t" << y[i][j];
    }
        cout << endl;
    }

}

int factorial(int n){
    if(n==1){
        return 1;
    }else{
        return (n*factorial(n-1));
    }

}

double p_val_forward(int n,double p)
{
    double p_original=p;
    for(int i=1;i<n;i++){
        p_original*=(p-i);
    }

    return p_original;

}
double p_val_backward(int n,double p)
{
    double p_original=p;

    for(int i=1;i<n;i++){
        p_original*=(p+i);
    }

    return p_original;

}

double interpolation_for_forward(double val){

    double result = y[0][0];
    double h=x[1]-x[0];
    double p=(val-x[0])/h;
    //cout<<result<<endl;
    //cout<<p<<endl;
    for(int i=1;i<n;i++){

        result+=(( p_val_forward(i,p))*(y[0][i]))/factorial(i);

    }

    return result;


}



double interpolation_for_backward(double val){

        double result = y[n-1][0];
     double  h=x[1]-x[0];
         double  p=(val-x[n-1])/h;

    for(int i=1;i<n;i++){
        result+= ( (p_val_backward(i,p))*(y[n-i-1][i]))/factorial(i);
    }

    return result;


}


int main(){


    input();

    difference_table();
    cout<<"Difference table:"<<endl;
    draw_table();

    double val;
    int i=0;
    while(1){

        cout<<"Choose option:"<<endl<<"1.forward interpolation   2.backword interpolation  3.press any number to exit"<<endl;
        int choice;
        cout<<"option number:";
        cin>>choice;
        if(choice==1){

        while(true){
        cout<<"Enter an interpolating value:"<<endl;
        cin>>val;

        if(val==0){
            break;
        }
         cout<<"missing value for forward interpolation:";
        cout<<interpolation_for_forward(val)<<endl;
    }

    }
    else if(choice==2){
        while(true){
        cout<<"Enter an interpolating value:"<<endl;
        cin>>val;

        if(val==0){
            break;
        }

        cout<<"missing value for backward interpolation:";
        cout<<interpolation_for_backward(val)<<endl;
        }
    }
    else{
        cout<<"exit"<<endl;
        break;
    }
}


}

