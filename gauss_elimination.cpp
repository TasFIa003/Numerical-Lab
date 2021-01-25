#include<bits/stdc++.h>
using namespace std;

void gauss_elimination(double a[3][4],int n){

    double r;

    //for gauss elimination
    for(int i=0;i<n;i++){
            if(a[i][i]==0.0){
                cout<<"math error"<<endl;
                break;
            }
        for(int j=i+1;j<n+1;j++){
            r=a[j][i]/a[i][i];
            for(int k=0;k<n+1;k++){
                a[j][k]-=(r*a[i][k]);
            }

        }
    }
    //back substitution apply to find out unknown
    double final_res[1000];
    for(int i=n-1;i>=0;i--){
        final_res[i]=a[i][n];
        for(int j=i+1;j<n;j++){
                if(i!=j){
                final_res[i]-=(a[i][j]*final_res[j]);
                }
        }
        final_res[i]/=a[i][i];
    }

     for(int i=0;i<n;i++)
    {
      cout<<final_res[i]<<endl;
    }




}
int main(){

    int n=3;
    double a[3][4];


    ifstream f;
    f.open("gauss_elimination.txt");

    for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++)
        f>>a[i][j];
    }

    cout<<"the augmented matrix of system:\n"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
       cout<<"a"<<i<<j<<" :"<<a[i][j]<<"  ";
            }
            cout<<"\n";
    }
    cout<<"the solution of the system:"<<endl;
    gauss_elimination(a,n);


}
