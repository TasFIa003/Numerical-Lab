#include<bits/stdc++.h>
using namespace std;

void PrintA(double a[3][3],int n){

     for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
                }cout<<endl;
            }

}

void PrintB(double b[3],int n){

     for(int i=0;i<n;i++){

                cout<<b[i]<<endl;
            }


}


void solution(double a[3][3],double b[3],int n){

    double l[3][3],u[3][3],s=0.0;

    for(int i=0;i<n;i++){
        l[i][i]=0.0;
        for(int m=0;m<n;m++){
            //upper triangular
            for(int j=m;j<n;j++)
            {
                for(int k=0;k<m;k++){
                    s+=u[k][j]*l[m][k];
                    u[m][j]=a[m][j]-s;
                    }
                }
            if(m<(n-1)){
                    for(int i=m+1;i<n;i++)
                        {

                        for(int k=0;k<=m-1;k++){
                            s+=u[k][m]*l[i][k];
                            l[i][m]=(a[i][m]-s)/u[m][m];
                        }
                        }
            }
        }
    }



cout << "L Decomposition is as follows..."<<endl;
   for (int i = 0; i < n; i++) {
      for ( int j = 0; j < n; j++) {
         cout<<l[i][j]<<" ";
      }
      cout << endl;
   }
   cout << "U Decomposition is as follows..."<<endl;
 for (int i = 0; i < n; i++) {
      for ( int j = 0; j < n; j++) {
         cout<<u[i][j]<<" ";
      }
      cout << endl;
   }

}

int main(){

    int n=3;
    double a[3][3],b[3];

    ifstream f1;
    f1.open("lu.txt");

        while(!f1.eof()){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    f1>>a[i][j];
                }
            }


            for(int i=0;i<n;i++){
                f1>>b[i];
            }


    cout<<"print the value of A matrix:"<<endl;
    PrintA(a,n);
    cout<<"print the value of B matrix:"<<endl;
    PrintB(b,n);
    solution(a,b,n);


    }


}
