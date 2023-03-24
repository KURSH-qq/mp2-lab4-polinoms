#include "gtest.h"
#include "list.h"

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_push_some_element) {
	TList<int> list;
	ASSERT_NO_THROW(list.push(10));
}

TEST(TList, can_take_item) {
	TList<int> list;
	list.push(1);
	list.push(2);
	EXPECT_EQ(list[1], 1);
}

TEST(TList, error_when_wrong_index) {
	TList<int> list;
	list.push(1);
	ASSERT_ANY_THROW(list.at(1));
}

TEST(TList, throw_when_negative_index) {
	TList<int> list;
	ASSERT_ANY_THROW(list.at(-1));
}

TEST(TList, can_tru_that_list_is_emty) {
	TList<int> list;
	EXPECT_EQ(list.isEmpty(), true);
}


TEST(TList ,can_get_size) {
	TList<int> list;
	list.push(2);
	list.push(3);
	list.push(1);
	ASSERT_NO_THROW(list.getSize());
}


TEST(TList, szie_is_corect) {
	TList<int> list;
	list.push(2);
	list.push(3);
	list.push(1);
	EXPECT_EQ(list.getSize(), 3);
}

TEST(TList, can_create_equale_list) {
	TList<int> list1;
	list1.push(1);
	ASSERT_NO_THROW(TList<int> list2(list1));
}

TEST(TList, can_pop_element) {
	TList<int> l;
	l.push(1);
	ASSERT_NO_THROW(l.pop(0));
}


TEST(TList, list_is_sorted) {
	TList<int> l;
	l.push(1);
	l.push(3);
	l.push(2);
	l.push(1);
	for (int i = 0; i < l.getSize()-1; i++) {
		EXPECT_EQ(l[i] >= l[i + 1], true);
	}
}

TEST(TList, copied_list_is_equal) {
	TList<int> l1;
	l1.push(1);
	l1.push(3);
	l1.push(2);
	TList<int> l2(l1);
	for (int i = 0; i < l1.getSize(); i++) {
		EXPECT_EQ(l1[i], l2[i]);
	}
}

TEST(TList, can_begin_by_iterator) {
	TList<int> l;
	ASSERT_NO_THROW(auto itr = l.begin());
}

TEST(TList, can_get_end_by_iterator) {
	TList<int> l;
	ASSERT_NO_THROW(auto itr = l.end());
}

TEST(TList, can_inc_iterator) {
	TList<int> l;
	l.push(1);
	l.push(2);
	auto itr = l.begin();
	EXPECT_EQ(*itr++, 1);
}