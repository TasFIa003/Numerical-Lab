#include<bits/stdc++.h>
using namespace std;

int lower_triangular (int a[3][3],int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                cout<<"0"<<" ";
            }else{
                cout<<a[i][j]<<" ";
            }

            }
            cout << endl;
        }
}

int upper_triangular (int a[3][3],int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                cout<<"0"<<" ";
            }else{
                cout<<a[i][j]<<" ";
            }

            }
            cout << endl;
        }
}







int main(){

    int n=3;
    int a[3][3];

    ifstream f;
    f.open("matrix.txt");

    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
        f>>a[i][j];
    }
    /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
       cout<<"a"<<i<<j<<":"<<a[i][j]<<" "<<endl;
    }*/
    cout<<"lower_triangular:"<<endl;
    lower_triangular(a,n);
      cout<<"Upper_triangular:"<<endl;
    upper_triangular(a,n);

}



