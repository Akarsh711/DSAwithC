#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    // Discriminant Formula
    int d = b*b - (4*a*c);
    double squareroot = sqrt(abs(d));

    if(d == 0){
        double res = -b/(2*a);
        cout<<res<<" "<<res;
    }
    if(d>0){
        double root1 = -(b - squareroot)/(2*a);
        double root2 = -(b + squareroot)/(2*a);
        cout<<root1<<" "<<root2;
    }
    else{
        double root1 = -b/(2*a);
        double root2 = -b/(2*a);
        cout<<root1<<"i"<<squareroot/(2*a)<<" ";
        cout<<root2<<"i"<<squareroot/(2*a);
    }
}