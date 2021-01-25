
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print_table(pair<double,double>valuesof_x_y[],pair<double,double>valuesof_x_ysquare[])
{
  cout<<"x"<<" "<<"y"<<endl;
  for(ll i=0;i<5;i++)
  cout<<valuesof_x_y[i].first<<" "<<valuesof_x_y[i].second<<endl;
  cout<<"x"<<" "<<"y^2"<<endl;
  for(ll i=0;i<5;i++)
  cout<<valuesof_x_ysquare[i].first<<" "<<valuesof_x_ysquare[i].second<<endl;
}
void calculate_volume(double sum_of_odd,double sum_of_even,double first_term,double last_term,double h)
{
  double volume=3.1416*(h/3)*(first_term+last_term+(4*(sum_of_odd))+(2*(sum_of_even)));
  cout<<"volume = "<<volume<<endl;
}
int main()
{
   pair<double,double> valuesof_x_y[5],valuesof_x_ysquare[5];
   double a=0,b=1,h=0.00,n=4;
   h=(b-a)/n;
   for(ll i=0;i<5;i++)
   {
     cin>>valuesof_x_y[i].first>>valuesof_x_y[i].second;
   }

   for(ll i=0;i<5;i++)
   {
     valuesof_x_ysquare[i].first=valuesof_x_y[i].first;
     valuesof_x_ysquare[i].second=pow(valuesof_x_y[i].second,2);
   }
   double sum_of_odd=0.00,sum_of_even=0.00;
   for(ll i=1;i<4;i+=2)
   {
     sum_of_odd+=valuesof_x_ysquare[i].second;
   }
   for(ll i=2;i<4;i+=2)
   {
     sum_of_even+=valuesof_x_ysquare[i].second;
   }
   print_table(valuesof_x_y,valuesof_x_ysquare);
   double first_term=valuesof_x_ysquare[0].second,last_term=valuesof_x_ysquare[4].second;
   calculate_volume(sum_of_odd,sum_of_even,first_term,last_term,h);
}
