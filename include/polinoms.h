#pragma once
#include "list.h"

class polinom
{
private:

	struct monom
	{
		int degree;
		double coef;

		monom(double _coef, int _degree): coef(_coef), degree(_degree){
			if (degree>999 || calculateDegree(degree) > 27 || calculateDegree(degree) < 0  ) {
				throw exception("wrond degree");
			}
		}
		
		monom(const monom& m);
 
		bool operator <(const monom& m);
		bool operator <=(const monom& m);
		bool operator ==(const monom& m);
		bool operator !=(const monom& m);

		monom operator+(const monom& m);
		monom operator*(const monom& m);
		monom operator-(monom& m);
		monom operator*(double d);

		monom& operator=(const monom& m);

		inline int calculateDegree(int num);

		friend ostream& operator<<(ostream& ostr, const monom& m) {
			ostr << m.coef << "*" << "x^" << m.degree / 100 << " y^" << (m.degree / 10) % 10 << " z^" << m.degree % 10;
			return ostr;
		}
	};

	TList<monom> data;
	int size;

	inline void add( const monom& m);
	void merge();
	void parse(string s);

public:
	polinom();
	polinom(string s);
	polinom(const polinom& p);


	polinom& operator=(const polinom& p);
	polinom operator+(const polinom& p);
	polinom operator-(polinom& p);
	polinom operator*(polinom& p);
	polinom operator*(double d);

	inline int getSize() const;

	friend ostream& operator<<(ostream& ostr, const polinom& p) {
		for (auto itr = p.data.begin(); itr != p.data.end(); itr++) {
			if (itr + 1 != p.data.end()) {
				ostr << *itr << " + ";
			}
			else {
				ostr << *itr;
			}
		}
		ostr << endl;
		return ostr;
	}
	friend istream& operator>>(istream& istr, polinom& p) {
		string input;
		istr >> input;
		p.parse(input);
		p.merge();
		return istr;
	}

	~polinom() = default;

};

