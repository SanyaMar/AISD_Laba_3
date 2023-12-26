#include "function.cpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using namespace sorts;


TEST(sort_test, sort_choice1) {
	vector<int> v1 = { 3, 1, 5, 2, 6, 4, 7, 9, 8, 0 };
	vector<int> res = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	stats stat = sort_choice(v1);
	EXPECT_EQ(v1, res);
}

TEST(sort_test, shaker_sort1) {
	vector<int> v1 = { 3, 1, 5, 2, 6, 4, 7, 9, 8, 0 };
	vector<int> res = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	stats stat = shaker_sort(v1);
	EXPECT_EQ(v1, res);
}

TEST(sort_test, comb_sort1) {
	vector<int> v1 = { 3, 1, 5, 2, 6, 4, 7, 9, 8, 0 };
	vector<int> res = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	stats stat = comb_sort(v1);
	EXPECT_EQ(v1, res);
}

TEST(sort_test, stat_random_comb1) {
	stat_random_comb();
	EXPECT_EQ(1,1);
}
TEST(sort_test, order_comb1) {
	stat_order_comb();
	EXPECT_EQ(1, 1);
}
TEST(sort_test, revers_comb1) {
	stat_revers_comb();
	EXPECT_EQ(1, 1);
}