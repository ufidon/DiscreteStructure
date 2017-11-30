// hannoi.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

// s(int n, char from, char via, char to, int& m)
int s(int n, char a, char b, char c, int& m)
{
	if (n==1)
	{
		cout <<n<<' '<< a << "->" << c << endl;
		m++;
	}
	else
	{
		s(n - 1, a, c, b, m);
		
		cout << n << ' ' << a << "->" << c << endl;
		m++;

		s(n - 1, b, a, c, m);
	}

	return m;
}

int convert(double f, int b, int m, int *d)
{
	int I = (int)f;
	double F = f - I;
	int i,q;
	double fb;

	int n =(I>1)?(1+ (int)(log(I) / log(b))):1;

	

	int k = m;
	
	while (q=I/b)
	{
		d[k] = I%b;
		I = q;
		++k;
	}
	d[k] = I%b;

	k = m - 1;
	while (F && (k>=0))
	{
		fb = F*b;
		i = (int)fb;
		d[k] = i;
		F = fb - i;
		--k;
	}

	return (int)d;
}


int main()
{

#ifdef HANNOI

	int m = 0,n=3;
	char c = 'y';

	while (c == 'y')
	{
		cout << "Enter the number of disks in the game of Hannoi tower: ";
		cin >> n;

		m = 0;
		s(n, 'a', 'b', 'c', m);

		cout << "minimum number of steps: " << m <<endl;
		cout << "--------------------------------" << endl;

		cout << "continue the game? y/n: ";
		cin >> c;
	}
#endif

	char c = 'y';
	int m = 0,b=2;
	double f = 0.0;
	


	while (c=='y')
	{
		cout << "Enter the real number:";
		cin >> f;
		cout << "\nEnter the base:";
		cin >> b;
		cout << "\nEnter the number of fractional digits:";
		cin >> m;

		int l = (f>1.0)?1+ log(f) / log(b):1;
		int *d = new int[l + m];

		convert(f, b, m,d);
		
		cout << "\n" << f << " in base " << b << " is:";
		for (int i = l+m; i >=0; i--)
		{
			cout << d[i]<<' ';
		}
		cout << endl;

		if(d)delete d;

		cout << "continue ? y/n: ";
		cin >> c;
	}

	

    return 0;
}

