#include <iostream>
#include "polinoms.h"
#include "list.h"
#include <string>



polinom::monom::monom(const monom& m) {
	degree = m.degree;
	coef = m.coef;
}

int polinom::monom::calculateDegree(int num) {
	return num / 100 + (num / 10) % 10 + num % 10;
}

bool polinom::monom::operator<(const monom& m) {
	if (calculateDegree(degree) < calculateDegree(m.degree)) {
		return true;
	}
	return false;
}

bool polinom::monom::operator<=(const monom& m) { 
	if (calculateDegree(degree) == calculateDegree(m.degree)) { 
		return true;
	}
	else if (*this < m) {
		return true;
	}
	else if (degree == m.degree && coef < m.coef) {
		return true;
	}
	return false;
}

polinom::monom& polinom::monom::operator=(const monom& m) {
	coef = m.coef;
	degree = m.degree;
	return *this;
}

polinom::monom polinom::monom::operator+(const monom& m) { 
	monom result(*this);
	if (degree == m.degree) {
		result.coef = result.coef + m.coef;
	}
	else {
		throw exception("wrong degree");
	}
	return result;
}

polinom::monom polinom::monom::operator*(const monom& m) { 
	monom result(*this);
	
	if ( result.degree+m.degree>= 1000 || calculateDegree(result.degree+m.degree)>9 ) { 
		throw exception("wrong degree");
	}
	result.coef *= m.coef;
	result.degree += m.degree;
	return result;
}

polinom::monom polinom::monom::operator*(double d) {
	monom result(*this);
	result.coef *= d;
	return result;
}

polinom::monom polinom::monom::operator-(monom& m) {
	monom result(*this);
	if (degree == m.degree) {
		result = result + m*(-1);
		return *this;
	}
	else {
		throw exception("wrong degree");
	}
}

void polinom::add(const monom& m) {
	data.push(m);
}


polinom::polinom() {
	size = 0;
}

polinom::polinom(const polinom& p) {
	size = p.size;
	data = p.data;
}

polinom& polinom::operator=(const polinom& p) {  
	polinom result(p);
	return result;
}

polinom::polinom(string s) {
	int sz = s.size();
	int space_index = 0;
	int plus_index = -1;
	std::string cur_coef;
	std::string cur_degree;
	int j = 0;
	for (int i = 0; i< sz; i++) {
		if (s[i] == ' ') {
			space_index = i;
			j = plus_index+1;
			while (j != space_index) {
				cur_coef += s[j];
				j += 1;
			}
			if (i + 4 == sz) {
				j = i + 1;
				while (j != sz) {
					cur_degree += s[j];
					j += 1;
				}
				data.push(monom(std::stod(cur_coef), std::stod(cur_degree)));
				cur_coef.clear();
				cur_degree.clear();
			}		
		}
		else if (s[i] == '+') {  
			plus_index = i;
			j = space_index+1;
			while (j != plus_index) {
				cur_degree += s[j];
				j += 1;
			}
			data.push(monom(std::stod(cur_coef), std::stod(cur_degree)));
			cur_coef.clear();
			cur_degree.clear();
		}
	}

	merge();

	size = data.getSize();
}

void polinom::merge() {
	for (int i = 0; i < data.getSize(); i++) {
		for (int j = i + 1; j < data.getSize(); j++) {
			if (data[i] == data[j]) {
				data[i] = data[i]+ data[j];
				data.pop(j);
			}
		}
	}
}

bool polinom::monom::operator==(const monom& m) {
	if (degree == m.degree) {
		return true;
	}
	return false;
}

bool polinom::monom::operator!=(const monom& m) {
	if (*this == m) {
		return false;
	}
	return true;
}


int polinom::getSize() const{
	return size;
}

polinom polinom::operator+(const polinom& p) {
	polinom result(*this);
	for (auto itr = p.data.begin(); itr != p.data.end();itr++) {
		result.add(*itr);
	}
	result.merge();
	return result;
}

polinom polinom::operator*(double d) {
	polinom result(*this);
	for (auto itr = result.data.begin(); itr != result.data.end(); itr++) {
		*itr = *itr * d;
	}
	return result;
}

polinom polinom::operator-(polinom& p) {
	polinom result(*this);
	return result + p * (-1);
}

polinom polinom::operator*(polinom& p) {
	polinom result;
	for (auto itr1 = data.begin(); itr1 != data.end(); itr1++) {
		for (auto itr2 = p.data.begin(); itr2 != p.data.end(); itr2++) {
			result.add(*itr1*(*itr2));
		}
	}
	result.merge();
	return result;
}