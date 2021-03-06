#include <iostream>
#include<vector>
using namespace std;
#define inc(x) int x;cin>>x;

#define ina(x) char x;cin>>x;

int main()
{

	inc(n);
	vector<int> l, r;
	int arr[n / 2][2];
	for (int i = 0; i < n; i++)
	{

		ina(a);
		if (a == 'L')
			l.push_back(i + 1);

		else
			r.push_back(i + 1);
	}

	int a = l.size(), b = r.size();
	if (a < b)
	{	for (int i = 0; i < a; i++)
		{
			arr[i][0] = l[i];

			arr[i + 1][1] = r[i];
		}
		for (int i = a ; i < n / 2 - 1 ; i++)
		{
			arr[i + 1][1] = r[i];
		}

		arr[0][1] = r[b - 1];


		for (int i = a; i < b; i++)
		{
			arr[i][0] = r[n / 2 - a + i - 1];
		}

	}
	else if (b == a)
	{
		arr[0][1] = r[b - 1];
		for (int i = 0; i < a; i++)
		{
			arr[i][0] = l[i];

			arr[i + 1][1] = r[i];
		}
	}
	else if (b < a)
	{

		for (int i = 0; i < b; i++)
		{
			arr[i][1] = r[i];

			arr[i + 1][0] = l[i];
		}
		for (int i = b ; i < n / 2 - 1 ; i++)
		{
			arr[i + 1][0] = l[i];
		}

		arr[0][0] = l[a - 1];


		for (int i = b; i < a; i++)
		{
			arr[i][1] = l[n / 2 - b + i - 1];
		}

	}
	for (int i = 0; i < n / 2; i++)
		cout << arr[i][0] << " " << arr[i][1] << endl;




	return 0;
}