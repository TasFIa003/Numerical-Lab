#include<iostream>
#include<math.h>
using namespace std;
void Newton_forward()
{
    int n,k=0;
   double y[100][100],x[100],del[100][100];
    double p,h,xr,yr;
    cout<<"How many points?"<<endl;
    cin>>n;
    cout<<"Enter the points:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i][0];
    }
 /*   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            del[i][j]=0;
        }
    }
*/


     cout<<"Enter the desired value of x:"<<endl;
    cin>>xr;



    //for first column

    /*for(int i=0;i<n-1;i++){
        del[i][0]=y[i+1]-y[0];
    }*/

    //for others

    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            y[i][j]=y[i+1][j-1]-y[i][j-1];
        }
    }

    cout << endl << "forward difference table:" << endl;
 for(int i = 0; i < n; i++)
 {
  cout <<"x"<<i<<":" <<x[i];
  for(int j = 0; j < n-i ; j++)
  {
   cout << "\t" << y[i][j];
  }
  cout << endl;
 }

    h=x[1]-x[0];
    cout<<"h:"<<h<<endl;

    while(x[k]<xr){
        k++;
    }
    k--;

    p=(xr-x[k])/h;
    cout<<"p:"<<p<<endl;

    for(int i=1;i<n;i++){
        cout<<"value of p:"<<p*(p-i)<<endl;
    }


    cout<<k<<endl;
    yr=y[1][0]+(p*y[k][0])+(((p*(p+1))/2)*y[k-1][1])+(((p*(p-1)*(p+1))/6)*y[k-1][2])+(((p*(p-1)*(p-2)*(p+1))/24)*y[k-2][3]);
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
           Newton_forward();
        }

        else
        {
            cout<<"exit";
            break;
        }
    }

    return 0;
}

