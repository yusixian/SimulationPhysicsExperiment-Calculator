#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()	{
	// 采用文件重定向stdin
	freopen("in.txt", "r", stdin);
	double U[8], U_avg, t[8], t_avg, e_std, e_computed, RE, q;
	U_avg = t_avg = 0.0;
	e_std = 1.602;
	for ( int i = 0; i < 8; i++ )	{
		cin >> U[i];
		U_avg += U[i];
	}
	for ( int i = 0; i < 8; i++ )	{
		cin >> t[i];
		t_avg += t[i];
	}
	U_avg /= 8;
	t_avg /= 8;
	q = 1.43 / ( pow(t_avg*(1+0.02*sqrt(t_avg)),1.5) * U_avg) * 1e5;
	e_computed = q / round(q/e_std);
	RE = fabs(e_std-e_computed)/e_std;

	cout << "U_avg = " << setiosflags(ios::fixed) << setprecision(10) << U_avg << endl;
	cout << "t_avg = " << t_avg << endl;
	cout << "q = " << q << endl;
	cout << "e_computed = " << e_computed << endl;
	cout << "RE% = " << RE*100 << endl;
    getchar();
        
    return 0;
}