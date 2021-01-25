#include<iostream>
#include<math.h>

using namespace std;

void lagrange()
{
    int n;
    double x[1000],y[1000],xr,yp=0;
    cout<<"number of points:";
    cin>>n;
    cout<<"enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<"desired x:";
    cin>>xr;
    for(int i=0;i<n;i++)
    {
        double s=1;
        double t=1;
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                s*=(xr-x[j]);
                t*=(x[i]-x[j]);
            }
        }
        yp+=((s/t)*y[i]);
    }

    cout<<"y(301):"<<yp<<endl;
    double error=(fabs(log10(301)-yp)/log10(301))*100;
    cout<<"percentage of error:"<<error<<"%"<<endl;
}

void least_curvefitting()
{
    int n;
    double x[1000],y[1000],sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,a0,a1,yp;
     cout<<"number of points:";
    cin>>n;
    cout<<"enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++)
    {
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=(x[i]*y[i]);
        sum_x2+=(x[i]*x[i]);
    }

    a0=((sum_xy*sum_x)-(sum_y*sum_x2))/((sum_x*sum_x)-(n*sum_x2));
    a1=((sum_y*sum_x)-(n*sum_xy))/((sum_x*sum_x)-(n*sum_x2));

    cout<<"a0:"<<a0<<"\na1:"<<a1<<endl;
    cout<<"the equation of the curve: Y="<<a0<<"+"<<a1<<"x"<<endl;
}

int main()
{
    cout<<"1.lagrange"<<endl<<"2.curve fitting"<<endl<<"3.exit"<<endl;

    while(1)
    {
        int choice;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            lagrange();
        }
        else if(choice==2)
        {
            least_curvefitting();
        }
        else
        {
            cout<<"exit";
            break;
        }
    }

    return 0;
}

