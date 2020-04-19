#include <iostream>
using namespace std;

int main()	{
	freopen("in.txt", "r", stdin);

	int i;
	double l[8], r[8], D[8], squareDiff[4], sqDifAvg, R;
	
	cout << "按实验中的测量顺序，即从小到大，在in.txt中输入十字叉丝从左到右移动测得的16个数据";
	for (i = 0; i < 8; i++)	{
		cin >> l[i];
		l[i] /= 1000;
	}
	for (i = 0; i < 8; i++)	{
		cin >> r[i];
		r[i] /= 1000;
		D[i] = r[i] - l[7-i];
		cout << "D[" << i << "](m) = " << D[i] << endl;
	}
	cout << endl;
	for (i = 0, sqDifAvg = 0; i < 4; i++)	{
		squareDiff[i] = D[i+4]*D[i+4] - D[i]*D[i];
		sqDifAvg += squareDiff[i];
	}
	sqDifAvg /= 4;
	R = sqDifAvg / (80 * 589 * 1e-9);
	cout << "R(m) = " << R << endl;

	getchar();
	return 0;
}