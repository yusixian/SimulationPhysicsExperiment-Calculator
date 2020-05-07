#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double m0 = 0.3585;//下圆盘质量358.5克 即0.3585kg
const double m = 0.3855;//圆环质量385.5克 即0.3855kg
const double m1 = 0.2;//一个圆柱体质量200克 即0.2kg
const double g = 9.8;
const double PI = acos(-1);
double FindR(double a[]) {
    double sum = 0;
    for(int i = 0; i < 3; ++i) {
        sum += a[i];
    }
    return sum / (3*sqrt(3));
}
double FindAver(double a[], int size) {
    double sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum/size;
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double a[4];
    cout << "please input first a1 a2 a3(mm):" << endl;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    double r = FindR(a);
   
    cout << setprecision(4) <<  "r: " << r << "mm"<< endl;
    //化成m
    r /= 1000;
    cout << "please input second a1 a2 a3(mm):" << endl;
    for(int i = 0; i < 3; ++i) 
        cin >> a[i];
    double R = FindR(a);
    cout << setprecision(4) << "R: " << R << "mm" << endl; 
    //化成m
    R /= 1000;

    cout << "please input H1 H2 H3(mm):" << endl;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    double H = FindAver(a,3);
    cout << setprecision(4) <<  "ave H: " << H << "mm"<< endl;
    //化成m
    H /= 1000;

    cout << "please input T1 T2 T3 T4 (s):" << endl;
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    double T0 = FindAver(a,4)/20;//注：这里测得是20个周期的平均值 所以要除以20才是一个周期
    cout << setprecision(4) <<  "ave T0: " << T0  << "s" << endl;

    double I0 = m0*g*R*r*T0*T0/(4*PI*PI*H);
    cout << setprecision(4) << "by calculate, I0 = " << I0 << " kg/m^2" <<endl;

    cout << "please input r1 r2 r3(mm):" << endl;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    double r1 = FindAver(a,3);
    cout << setprecision(4) <<  "ave r1: " << r1 << "mm"<< endl;
    //化成m
    r1 /= 1000;

    cout << "please input R1 R2 R3(mm):" << endl;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    double R1 = FindAver(a,3);
    cout << setprecision(4) <<  "ave R1: " << R1 << "mm"<< endl;
    //化成m
    R1 /= 1000;

    cout << "please input T1 T2 T3 T4 (s):" << endl;
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    double T = FindAver(a,4)/20;//注：这里测得是20个周期的平均值 所以要除以20才是一个周期
    cout << setprecision(4) <<  "ave T: " << T  << "s" << endl;//T为+圆环后的周期

    double I1 = (m0+m)*g*R*r*T*T/(4*PI*PI*H);//下圆盘+圆环的转动惯量
    cout << setprecision(4) << "by calculate, I1 = " << I1 << " kg/m^2" <<endl;
    double I = I1 - I0;
    cout << setprecision(4) << "by calculate, I = " << I << " kg/m^2" <<endl;

    cout << "please input D (mm):" << endl;//两圆柱体间距
    double D;
    cin >> D;
    cout << "please input d1 d2 d3(mm):" << endl;
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    double d = FindAver(a,3);
    cout << setprecision(4) <<  "ave d: " << d  << "mm" << endl;
    
    cout << "please input T1 T2 T3 T4 (s):" << endl;
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    double T1 = FindAver(a,4)/20;//注：这里测得是20个周期的平均值 所以要除以20才是一个周期
    cout << setprecision(4) <<  "ave T1: " << T1  << "s" << endl;//T1为+两圆柱体后周期

    I1 = (m0+2*m1)*g*R*r*T1*T1/(4*PI*PI*H);//下圆盘+两圆柱的转动惯量
    cout << setprecision(4) << "by calculate, I1 = " << I1 << " kg/m^2" <<endl;
    double I2 = (I1 - I0)/2;
    cout << setprecision(4) << "by calculate, I2 = (I1-I0)/2 = " << I2 << " kg/m^2" <<endl;
    return 0;
}