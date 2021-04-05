//Operator Overloading
// sample input
// 3+i4
// 5+i6
#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex operator +(Complex operand1, Complex operand2){
    Complex r;
    r.a= operand1.a +operand2.a;
    r.b = operand1.b +operand2.b;
    return r;
}

// cin and cout is objs of istream and ostream respectively
ostream& operator <<(ostream& operand1, Complex operand2){
    operand1 << operand2.a;
    operand1 << "+i"<<operand2.b;
    return operand1;
}
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
    cout << z.a<<z.b<<endl;
}
