#include<iostream>
#include<math.h>
using namespace std;
void gauss_forward()
{
    int m=1,n,k;
   double del1[1000],del2[1000],del3[1000],del4[1000],del5[1000],x[1000],y[1000];
    double x0,y0,p,h,xr,yr;
    cout<<"How many points?"<<endl;
    cin>>n;
    cout<<"Enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    x0=x[(n-m)/2];
    cout<<"x0:"<<x0<<endl;
    y0=y[(n-m)/2];
    cout<<"y0:"<<y0<<endl;

    h=x[((n-m)/2)+1]-x0;
    cout<<"h:"<<h<<endl;

     cout<<"Enter the desired value of x:"<<endl;
    cin>>xr;

    p=(xr-x0)/h;
    for(int i=0;i<n-1;i++)
    {
        del1[i]=y[i+1]-y[i];
        cout<<"Del1 :"<<del1[i]<<endl;
    }
    for(int i=0;i<n-2;i++)
    {
        del2[i]=del1[i+1]-del1[i];
        cout<<"Del2 :"<<del2[i]<<endl;
    }
    for(int i=0;i<n-3;i++)
    {
        del3[i]=del2[i+1]-del2[i];
        cout<<"Del3 :"<<del3[i]<<endl;
    }
    for(int i=0;i<n-4;i++)
    {
        if(fabs(del3[i+1]-del3[i])<0.0001)
        {
            continue;
        }
        del4[i]=del3[i+1]-del3[i];
        cout<<"del4:"<<del4[i]<<endl;
    }

    k=(n-m)/2;
    cout<<k<<endl;
    yr=y0+(p*del1[k])+(((p*(p+1))/2)*del2[k-1])+(((p*(p-1)*(p+1))/6)*del3[k-1])+(((p*(p-1)*(p-2)*(p+1))/24)*del4[k-2]);
    cout<<"The root is:"<<yr<<endl;
}
int main()
{
    cout<<"1.Forward_interpolation"<<endl<<"2.Exit."<<endl;
    while(1)
    {
        int choice;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            gauss_forward();
        }

        else
        {
            cout<<"exit";
            break;
        }
    }

    return 0;
}
