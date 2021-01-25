#include<bits/stdc++.h>
using namespace std;

void gauss_jordan(double a[3][4],int n){

    double r,final_res[1000];

    //for gauss elimination
    for(int i=0;i<n;i++){
            if(a[i][i]==0.0){
                cout<<"math error"<<endl;
                break;
            }
        for(int j=0;j<n;j++){
                if(i!=j){
                    r=a[j][i]/a[i][i];
                        for(int k=0;k<n+1;k++){
                            a[j][k]-=(r*a[i][k]);
                        }
                }

        }
    }


     for(int i=0;i<n;i++)
    {
        final_res[i]=a[i][n]/a[i][i];
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
    gauss_jordan(a,n);


}
