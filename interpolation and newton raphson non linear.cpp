#include<iostream>
#include<math.h>
using namespace std;
void forward_interpolation()
{
    int n;
    double del1[1000],del2[1000],del3[1000],del4[1000],del5[1000],x[1000],y[1000];
    double p,h,xr,yr;
    cout<<"How many points?"<<endl;
    cin>>n;
    cout<<"Enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
     cout<<"Enter the desired value of x:"<<endl;
    cin>>xr;
    h=x[1]-x[0];
    p=(xr-x[0])/h;
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
        del4[i]=del3[i+1]-del3[i];
        cout<<"Del4 :"<<del4[i]<<endl;
    }
    yr=y[0]+p*del1[0]+(p*(p-1)del2[0])/2+(p(p-1)(p-2)*del3[0])/6+(p(p-1)(p-2)(p-3)*del4[0])/24;
    cout<<"The root is:"<<yr<<endl;
}
void backward_interpolation()
{
     int n;
    double del1[1000],del2[1000],del3[1000],del4[1000],del5[1000],x[100],y[100];
    double p,h,xr,yr;
    cout<<"How many points?"<<endl;
    cin>>n;
    cout<<"Enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }cout<<"Enter the desired value of x:"<<endl;
    cin>>xr;
    h=x[1]-x[0];
    p=(xr-x[n-1])/h;
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
        del4[i]=del3[i+1]-del3[i];
        cout<<"Del4 :"<<del4[i]<<endl;
    }
    yr=y[n-1]+p*del1[n-2]+(p*(p+1)del2[n-3])/2+(p(p+1)(p+2)*del3[n-4])/6+(p(p+1)(p+2)(p+3)*del4[n-5])/24;
    cout<<"The root is:"<<yr<<endl;

}
int main()
{
    cout<<"1.Forward_interpolation 2.Backward_interpolation 0.Exit."<<endl;
    while(1)
    {
        int choice;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            forward_interpolation();
        }
        else if(choice==2)
        {
            backward_interpolation();
        }
        else
        {
            break;
        }
    }

    return 0;
}
