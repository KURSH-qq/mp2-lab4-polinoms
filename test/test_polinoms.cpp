#include <gtest.h>
#include <polinoms.h>
#include "list.h"


TEST(Polinom, can_create_polinom) {
	ASSERT_NO_THROW(polinom p("2 123"));
}

TEST(Polinom, throw_when_wrong_degree) {
	ASSERT_ANY_THROW(polinom p("3 444"));
	ASSERT_ANY_THROW(polinom p("2 123+3 444"));
}

TEST(Polinom, can_do_arithmetic_op) {
	polinom p1("1 101+2 131");
	polinom p2("-1 111+4.5 201");
	ASSERT_NO_THROW(p1 + p2);
	ASSERT_NO_THROW(p1 - p2);
	ASSERT_NO_THROW(p1 * 2);
	ASSERT_NO_THROW(p1 * p2);
}

TEST(Polinom, throw_when_wrong_degree_after_mult) {
	polinom p1("1 123+2 234");
	polinom p2("10.4 333+2 222");
	ASSERT_ANY_THROW(p1 * p2);
}

TEST(Polinom, a) {
	polinom p1("1 123+2 234");
	ASSERT_NO_THROW(polinom p2(p1));
}