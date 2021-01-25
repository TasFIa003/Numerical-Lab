/// Ensure that you have the corresponding
/// .txt file in the same directory.
/// For any query contact: faruk@cse.ruet.ac.bd


#include<bits/stdc++.h>
using namespace std;

int n=4;
double x[4];
double y[4][4];

double buffer;
vector<double>tmp;

void Input()
{
    ifstream f1;
    f1.open("newton.txt");

    while(! f1.eof() )
    {
        f1>>buffer;
        tmp.push_back(buffer);
        ///buffer.clear();
    }


///tmp = 1 24 3 120 5 336 7 720
///input x values.
for(int i=0,j=0;i<tmp.size();i+=2,j++)
x[j] = tmp.at(i);


///input y values to y[][]...
for(int i=1,j=0;i<tmp.size();i+=2,j++)
y[j][0] = tmp.at(i);

}

void Forward_difference_table()
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
}

void Draw_difference_table()
{
    for(int i=0;i<n;i++){

        cout<<x[i]<<"\t";

        for(int j=0;j<n-i;j++)
        cout<<y[i][j]<<"\t";

        cout<<endl;

    }
}


int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);

}

double p_val(int n, double p)
{
    double p_original = p;

    for(int i=1; i<n;i++)
        p_original = p_original*(p-i);

    return p_original;  /// p, p(p-1), p(p-1)(p-2).....

}

double Interpolation(double val)
{
    double result = y[0][0];
    double h = x[1]-x[0];
    double p = (val-x[0])/h;


    for(int i=1;i<n;i++)
    {
        result = result + ( p_val(i,p)*y[0][i] )/factorial(i);
    }

    return result;
}


int main()
{
   /// Step-I: Input...
   Input();

   /// Step-II: Forward difference table...
   Forward_difference_table();

   /// Draw the difference table...
   Draw_difference_table();

   double val;

   while(true)
   {
       cout<<"Enter an interpolating value: "<<endl;
       cin>>val;

       if(val==0)
           break;

       double missing_value = Interpolation(val);
       cout<<"Missing value for "<<val<<" is "<<missing_value<<endl;

   }


}
