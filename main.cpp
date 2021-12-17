#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100
using namespace std;
void nhap(int a[MAX][MAX],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        if(n==1)
        {
            for(int j=0;j<m;j++)
            {
                cout<<"Nhap P."<<char(65+j)<<": ";
                cin>>a[i][j];
            }
            break;
        }
        for(int j=0;j<m;j++)
        {
            cout<<"Nhap P"<<i<<"."<<char(65+j)<<": ";
            cin>>a[i][j];
        }
    }
}

void xuat(int a[MAX][MAX],int n,int m)
{
    cout<<"\t";
    for(int i=0;i<m;i++)
    {
        cout<<char(65+i)<<"\t";
    }
    cout<<endl;
    if(n==1)
    {
       for(int i=0;i<n;i++)
        {
            cout<<"P\t";
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            cout<<"P"<<i<<"\t";
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
}
void xuat_Ava(int a[MAX][MAX],int n,int m,int b[])
{
    cout<<"\t";
    for(int i=0;i<m;i++)
    {
        cout<<char(65+i)<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<"P"<<"\t";
        }
        else
        {
            cout<<"P"<<b[i-1]<<"\t";
        }
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void kt_an_toan(int Need[MAX][MAX],int Ava[MAX][MAX],int All[MAX][MAX],int n,int m)
{
    int Finish[n];
    for(int i=0;i<n;i++)
    {
        Finish[i]=false;
    }
    int dem=0,dem1=0,dem2;
    int n_end=n-1,n_start=0;
    int mangtt[n];
    for(int i=0;i<n;i++)
    {
        dem2=0;
        if(Finish[i]==false)
        {
           dem=0;
           for(int j=0;j<m;j++)
           {
               if(Need[i][j]<=Ava[dem1][j])
               {
                    dem++;
               }
               else
               {
                   Finish[i]=false;
                   break;
               }
           }
           if(dem==m)
           {
               Finish[i]=true;
               dem2++;
               for(int j=0;j<m;j++)
               {
                    Ava[dem1+1][j]=Ava[dem1][j]+All[i][j];
               }
               mangtt[dem1]=i;
               dem1++;
           }
        }
        if(i==n_end&&dem2==0)
        {
            break;
        }
        if(i==(n_end)&&dem1!=n)
        {
            for(int j=n_end;j>=n_start;j--)
            {
                if(Finish[j]==false)
                {
                    n_end=j;
                    break;
                }
            }
            for(int j=n_start;j<=n_end;j++)
            {
                if(Finish[j]==false)
                {
                    n_start=j;
                    break;
                }
            }

            i=n_start-1;
        }

        if(dem1==n)
            break;
    }
    if(dem2!=0)
    {
        cout<<"\n-----------------Work----------------------\n";
        xuat_Ava(Ava,n+1,m,mangtt);
        cout<<endl<<"He o trang thai an toan do co day an toan.\n==>Day an toan: ";
        for(int i=0;i<dem1;i++)
        {
            cout<<"P"<<mangtt[i]<<" ";
        }
    }
    else
    {
        cout<<endl<<"He khong an toan. "<<endl;
        system("pause");
        exit(0);
    }
    cout<<endl;
}
bool kt_xh(int a[],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        if(m==a[i])
            return true;
    }
    return false;
}
void nhap_P_request(int a[MAX][MAX],int n,int m,int b[],int sl)
{
    int temp=0;
    cout<<endl<<"Nhap data Process request:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(kt_xh(b,sl,i)==true)
        {
            for(int j=0;j<m;j++)
            {
                cout<<"Nhap P"<<i<<"_request."<<char(65+j)<<": ";
                cin>>a[i][j];
            }
            temp++;
            cout<<endl;
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=0;
            }
        }

    }
}
void cong_mang(int kq[MAX][MAX],int a[MAX][MAX],int b[MAX][MAX],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            kq[i][j]=a[i][j]+b[i][j];
        }
    }
}
void tru_mang(int kq[MAX][MAX],int a[MAX][MAX],int b[MAX][MAX],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            kq[i][j]=a[i][j]-b[i][j];
            if(kq[i][j]<0)
            {
                cout<<endl<<"He khong an toan. "<<endl;
                system("pause");
                exit(0);
            }
        }
    }

}
void cong_pt_mang(int kq[MAX][MAX],int a[MAX][MAX],int n,int m)
{

    for(int i=0;i<m;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(j>0)
            {
                kq[0][i]+=(a[j][i]+a[j+1][i]-a[j][i]);
            }
            else
            {
                kq[0][i]+=(a[j][i]+a[j+1][i]);
            }

        }
    }
}
void ket_luan(int a[],int n)
{
    cout<<endl<<"==>Co the phan bo tai nguyen cho cac tien trinh: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<a[i]<<"\t";
    }
}
int main()
{
    int n,m;
    int All[MAX][MAX];
    int Max[MAX][MAX];
    int Ava[MAX][MAX];
    int Need[MAX][MAX];
    cout<<"nhap so luong Process(n): ";
    cin>>n;
    cout<<"nhap so luong kieu tai nguyen(m): ";
    cin>>m;

/*----------------------nhap file---------------------------------------*/
    ifstream FileIn_All,FileIn_Max,FileIn_Ava;
    FileIn_All.open("F:\\Trashs\\solieu.TXT", ios_base::in);
    FileIn_Max.open("F:\\Trashs\\solieu1.TXT", ios_base::in);
    FileIn_Ava.open("F:\\Trashs\\solieu2.TXT", ios_base::in);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            FileIn_All>>All[i][j];
            FileIn_Max>>Max[i][j];
        }
    }
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<m;j++)
            FileIn_Ava>>Ava[i][j];
    }
/*--------------------nhap tay--------------------------------------------*/

//    cout<<"\n--------------Allocation-------------------\n";
//    nhap(All,n,m);
//    cout<<"\n------------------Max----------------------\n";
//    nhap(Max,n,m);
//    cout<<"\n---------------Availbale-------------------\n";
//    nhap(Ava,1,m);

/*--------------------xuat----------------------------------------------*/
    cout<<"\n-----------------BANG----------------------\n";
    cout<<"\n--------------Allocation-------------------\n";
    xuat(All,n,m);
    cout<<"\n------------------Max----------------------\n";
    xuat(Max,n,m);
    cout<<"\n---------------Availbale-------------------\n";
    xuat(Ava,1,m);
    cout<<"\n-----------------BAI LAM-------------------\n";
    cout<<endl<<endl;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            Need[i][j]=Max[i][j]-All[i][j];
//            if(Need[i][j]<0)
//            {
//                cout<<endl<<"He khong an toan. ";
//                return 0;
//            }
//        }
//    }
    tru_mang(Need,Max,All,n,m);

    cout<<"\n-----------------Need----------------------\n";
    xuat(Need,n,m);
    kt_an_toan(Need,Ava,All,n,m);
//    int Finish[n];
//    for(int i=0;i<n;i++)
//    {
//        Finish[i]=false;
//    }
//    int dem=0,dem1=0,dem2;
//    int n_end=n-1,n_start=0;
//    int mangtt[n];
//    for(int i=0;i<n;i++)
//    {
//        dem2=0;
//        if(Finish[i]==false)
//        {
//           dem=0;
//           for(int j=0;j<m;j++)
//           {
//               if(Need[i][j]<=Ava[dem1][j])
//               {
//                    dem++;
//               }
//               else
//               {
//                   Finish[i]=false;
//                   break;
//               }
//           }
//           if(dem==m)
//           {
//               Finish[i]=true;
//               dem2++;
//               for(int j=0;j<m;j++)
//               {
//                    Ava[dem1+1][j]=Ava[dem1][j]+All[i][j];
//               }
//               mangtt[dem1]=i;
//               dem1++;
//           }
//        }
//        if(i==n_end&&dem2==0)
//        {
//            break;
//        }
//        if(i==(n_end)&&dem1!=n)
//        {
//            for(int j=n_end;j>=n_start;j--)
//            {
//                if(Finish[j]==false)
//                {
//                    n_end=j;
//                    break;
//                }
//            }
//            for(int j=n_start;j<=n_end;j++)
//            {
//                if(Finish[j]==false)
//                {
//                    n_start=j;
//                    break;
//                }
//            }
//
//            i=n_start-1;
//        }
//
//        if(dem1==n)
//            break;
//    }
//    if(dem2!=0)
//    {
//        cout<<"\n-----------------Work----------------------\n";
//        xuat(Ava,n,m);
//        cout<<endl<<"He o trang thai an toan do co day an toan.\n==>Day an toan: ";
//        for(int i=0;i<dem1;i++)
//        {
//            cout<<"P"<<mangtt[i]<<" ";
//        }
//    }
//    else
//    {
//        cout<<endl<<"He khong an toan. ";
//        return 0;
//    }
//    cout<<endl;
    /*---------------Process yeu cau tai nguyen----------------*/

    int n_P=n,m_P=m,sl_P;
    int P_request[MAX][MAX];
    int Temp[MAX];
    int New_All[MAX][MAX];
    int New_Need[MAX][MAX];
    int New_P_request[MAX][MAX];
    int New_Ava[MAX][MAX];
    cout<<"Nhap so luong Process yeu cau tai nguyen: ";
    cin>>sl_P;
    cout<<"Nhap Process yeu cau tai nguyen (P"<<"0->"<<n-1<<"): "<<endl;
    for(int i=0;i<sl_P;i++)
    {
        cout<<"Process: ";
        cin>>Temp[i];
    }
    nhap_P_request(P_request,n_P,m_P,Temp,sl_P);

    /*---------------Tinh toan(Process yeu cau tai nguyen)----------------*/

    cong_mang(New_All,All,P_request,n,m);
    tru_mang(New_Need,Need,P_request,n,m);
    cong_pt_mang(New_P_request,P_request,n,m);
    tru_mang(New_Ava,Ava,New_P_request,1,m);
    kt_an_toan(New_Need,New_Ava,New_All,n,m);
    ket_luan(Temp,sl_P);
    system("pause");
    return 0;
}
