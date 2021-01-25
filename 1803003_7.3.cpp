#include<bits/stdc++.h>
using namespace std;
int norm_euclidean(int a[100][100],int n){

        double sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=(a[i][j]*a[i][j]);
            }
        }
        double norm=sqrt(sum);
        cout<<norm<<endl;


}

int norm_column(int a[100][100],int n){
    int maximum=INT_MIN;
        for(int i=0;i<n;i++){
                int sum=0;
            for(int j=0;j<n;j++){
                sum+=a[j][i];
                    }

                    if(sum>maximum){
                        maximum=sum;
                    }

                }

        cout<<maximum<<endl;
}

int norm_row(int a[100][100],int n){
    int maximum=INT_MIN;
        for(int i=0;i<n;i++){
                int sum=0;
            for(int j=0;j<n;j++){
                sum+=a[i][j];
                    }

                    if(sum>maximum){
                        maximum=sum;
                    }

                }

        cout<<maximum<<endl;
}

int main()
{
    /*1 2 3
      4 5 6
      7 8 9
      */
  int n;
  int a[100][100];


    ifstream f;
    f.open("norm.txt");

    while(!f.eof()){

        f>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            f>>a[i][j];
    }
    cout<<"The given matrix , A is :"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
       cout<<"a"<<i<<j<<":"<<a[i][j]<<"\t";
            }
            cout<<endl;
    }
    cout<<endl;
    cout<<"the Euclidean norm of the matrix:";
    norm_euclidean(a,n);

     cout<<endl;
    cout<<"the Column norm of the matrix:";
    norm_column(a,n);

    cout<<endl;
    cout<<"the Row norm of the matrix:";
    norm_row(a,n);
    cout<<endl;
    }

    return 0;

}
