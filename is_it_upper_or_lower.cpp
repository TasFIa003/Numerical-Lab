#include<bits/stdc++.h>
using namespace std;


int is_it_lower(int a[100][100],int n)
{

    int flag=1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i][j]!=0)
            {
                flag=0;

            }
            else
            {
                flag=1;
            }

        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            break;
        }
        else
        {
            cout<<"No"<<endl;
            break;
        }
        // cout << endl;
    }

}

int is_it_upper(int a[100][100],int n)
{

    int flag=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i][j]!=0)
            {
                flag=0;

            }
            else
            {
                flag=1;
            }

        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            break;
        }
        else
        {
            cout<<"No"<<endl;
            break;
        }
        // cout << endl;
    }

}

int triangular(int a[100][100],int n){

 int lower=1,upper=1;

 //for lower case identify
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i][j]!=0)
            {
                lower=0;

            }
            else
            {
                lower=1;
            }

        }

    }

    //for upper case identify
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i][j]!=0)
            {
                upper=0;

            }
            else
            {
                upper=1;
            }

        }

    }

        if(upper==1 || lower==1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }



}


/*int norm_euclidean(int a[100][100],int n){

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
*/
int main()
{

  int n;
  int a[100][100];


    ifstream f;
    f.open("matrix1.txt");

    while(!f.eof()){

        f>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            f>>a[i][j];
    }
     cout<<"**************************************************"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
       cout<<"a"<<i<<j<<":"<<a[i][j]<<"\t";
            }
            cout<<endl;
    }


    cout<<endl;
    cout<<"Is it Lower_triangular matrix ? : ";
    is_it_lower(a,n);

    cout<<endl;
    cout<<"Is it Upper_triangular matrix ? : ";
    is_it_upper(a,n);

    cout<<endl;
    cout<<"Is this matrix triangular ? :";
    triangular(a,n);

   /* cout<<endl;
    cout<<"the Euclidean norm of the matrix:";
    norm_euclidean(a,n);

     cout<<endl;
    cout<<"the Column norm of the matrix:";
    norm_column(a,n);

    cout<<endl;
    cout<<"the Column norm of the matrix:";
    norm_row(a,n);
    cout<<endl;
    }*/


}

}




