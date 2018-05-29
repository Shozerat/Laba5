#include <math.h>
#include <iostream>

using namespace std;

class Rational {
private:
	int nominator, denominator, x;
public:
	friend Rational operator+(Rational a, Rational b) {
		Rational res;
		int nod = 1, nok;
		int a1 = a.denominator, b1 = b.denominator;
		while (a1 != 0 && b1 != 0) {
			if (a1 > b1) {
				a1 = a1 % b1;
			}
			else {
				b1 = b1 % a1;
			}
		}
		nod = a1 + b1;
		nok = (a.denominator * b.denominator) / nod;
		res.nominator = (nok / a.denominator)*a.nominator + (nok / b.denominator)*b.nominator;
		res.denominator = nok;
		return res;
	}

	friend Rational operator*(Rational a, Rational b) {
		Rational res;
		res.nominator = a.nominator * b.nominator;
		res.denominator = a.denominator * b.denominator;
		return res;
	}

	friend Rational operator/(Rational a, Rational b) {
		Rational res;
		res.nominator = a.nominator * b.denominator;
		res.denominator = a.denominator * b.nominator;
		return res;
	}

	friend ostream &operator<<(ostream &stream, const Rational &x) {
		stream << x.GetNominator() << "/" << x.GetDenominator();
		return stream;
	}

	Rational() {
		nominator = 0;
		denominator = 0;
	};

	Rational(int n, int d) {
		nominator = n;
		denominator = d;
	}

	Rational(double x) {
		int i = 1;
		int a = x;
		while (a != x) {
			x = x * 10;
			a = x;
			i = i * 10;
		};
		nominator = x;
		denominator = i;
	}


	int GetNominator() const { return nominator; };
	int GetDenominator() const { return denominator; };

	void SetNominator(int n) { nominator = n; }
	void SetDenominator(int d) { denominator = d; }

};

Rational y1(const Rational &x) {
	return (x - Rational(13, 10)) / (x + Rational(16, 10));
};


double y2(double x) {
	return (x - 1.3)/(x + 1.6);
};

int main(int argc, const char * argv[]) {
	int n, d;
	double q;
	cout << "nominator = ";
	cin >> n;
	cout << "denominator = ";
	cin >> d;

	cout << "double x = ";
	cin >> q;

	Rational x(n, d);
	Rational y = y1(x);
	cout << y << endl;

	Rational a(q);
	double z = y2(q);
	cout << z;

	cin.get(); cin.get();
	return 0;
}
