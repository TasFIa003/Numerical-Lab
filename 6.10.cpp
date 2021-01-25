#include<bits/stdc++.h>
using namespace std;
#define f(x) (1/(1+x))
void solution(){

    double a,b,h,n,sum1=0.0,x,sum2=0.0;
    cout<<"enter upper bound:";
    cin>>b;
    cout<<"enter lower bound:";
    cin>>a;
    cout<<"enter sub-interval of elements :";
    cin>>n;

    cout<<"enter the value of h:";
    cin>>h;

    sum1=f(a)+f(b);

    for(int i=1;i<=n-1;i++){
        x=a+(i*h);
        sum1+=(2*f(x));

    }
    sum1*=(h/2);
    cout<<"the final result of this problem:"<<setprecision(4)<<sum1<<"  when h is "<<h<<endl;

     sum2=f(a)+f(b);

    for(int i=1;i<=n-1;i++){
        x=a+(i*h);
        if(i%2==0){
            sum2+=2*f(x);
        }
        else{
            sum2+=4*f(x);
        }
    }
    sum2*=(h/3);
    cout<<"the final result of this problem:"<<setprecision(4)<<sum2<<"  when h is "<<h<<endl;
     cout<<endl;
}

int main(){

    int i=0;
    while(1){

            cout<<"1.Trapezoidal Rule  and Simson's 1/3rd Rule  2.Exit(press any key)"<<endl;
            int choice;
            cout<<"enter your option:";
            cin>>choice;
            cout<<endl;
            if(choice==1){
                    cout<<"Trapezoidal Rule and Simsons 1/3rd Rule:"<<endl;
                    solution();
                }
           else{
                cout<<"exit"<<endl;
            break;
           }
            i++;
        }
}
