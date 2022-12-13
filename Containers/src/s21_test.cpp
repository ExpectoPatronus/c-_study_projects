#include <gtest/gtest.h>
#include "s21_vector.cpp"
#include "s21_array.cpp"
#include "s21_stack.cpp"
#include "s21_queue.cpp"
#include "s21_set.cpp"
#include "s21_list.cpp"
#include "s21_multiset.cpp"
#include "s21_map.cpp"

#include <map>
#include <set>
#include <array>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>


/* --------------------------LIST TESTS --------------------------*/

template <class T>
bool equel_list(s21::list<T> s21_list, std::list<T> std_list) {
    bool res = true;
    if ((s21_list.size() != std_list.size()) || (s21_list.empty() != std_list.empty()))
        res = false;
    if (res != false) {
        typename s21::list<T>::iterator s21_it = s21_list.begin();
        typename std::list<T>::iterator std_it = std_list.begin();
        while (std_it != std_list.end() && res == true) {
            if (*s21_it != *std_it)
                res = false;
            ++s21_it;
            ++std_it;
        }
    }
    return res;
}

TEST(list, default_constructor) {
    s21::list<int> s21_list;
    std::list<int> std_list;
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<double> s21_list1;
    std::list<double> std_list1;
    EXPECT_TRUE(equel_list(s21_list1, std_list1));

    s21::list<std::string> s21_list2;
    std::list<std::string> std_list2;
    EXPECT_TRUE(equel_list(s21_list2, std_list2));

    s21::list<char> s21_list3;
    std::list<char> std_list3;
    EXPECT_TRUE(equel_list(s21_list3, std_list3));

    s21::list<std::pair<int, double>> s21_list4;
    std::list<std::pair<int, double>> std_list4;
    EXPECT_TRUE(equel_list(s21_list4, std_list4));

    s21::list<std::set<int>> s21_list5;
    std::list<std::set<int>> std_list5;
    EXPECT_TRUE(equel_list(s21_list5, std_list5));
}

TEST(list, init_constructor) {
    s21::list<int> s21_list(2);
    std::list<int> std_list(2);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<double> s21_list1(0);
    std::list<double> std_list1(0);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<std::string> s21_list2(1);
    std::list<std::string> std_list2(1);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<char> s21_list3(8);
    std::list<char> std_list3(8);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<std::pair<int, double>> s21_list4(16);
    std::list<std::pair<int, double>> std_list4(16);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<std::set<int>> s21_list5(3);
    std::list<std::set<int>> std_list5(3);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<int> s21_list6(2);
    std::list<int> std_list6(3);
    EXPECT_FALSE(equel_list(s21_list6, std_list6));
}

TEST(list, initializer_list_constructor) {
    s21::list<int> s21_list{1, 2, 3};
    std::list<int> std_list{1, 2, 3};
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<double> s21_list1{1.4, 2.0008, 3.122345, 123345};
    std::list<double> std_list1{1.4, 2.0008, 3.122345, 123345};
    EXPECT_TRUE(equel_list(s21_list1, std_list1));

    s21::list<std::string> s21_list2{"Hello", "World!"};
    std::list<std::string> std_list2{"Hello", "World!"};
    EXPECT_TRUE(equel_list(s21_list2, std_list2));

    s21::list<char> s21_list3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    std::list<char> std_list3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    EXPECT_TRUE(equel_list(s21_list3, std_list3));

    s21::list<std::pair<int, double>> s21_list4{{42, 3.1415}, {89, 21}};
    std::list<std::pair<int, double>> std_list4{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_list(s21_list4, std_list4));

    s21::list<std::string> s21_list6{"Hello", "Me!"};
    std::list<std::string> std_list6{"Hello", "World!"};
    EXPECT_FALSE(equel_list(s21_list6, std_list6));
}

TEST(list, copy_constructor) {
    s21::list<char> s21_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::list<char> std_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::list<char> s21_list_copy(s21_list);
    std::list<char> std_list_copy(std_list);
    EXPECT_TRUE(equel_list(s21_list, std_list));
    EXPECT_TRUE(equel_list(s21_list_copy, std_list_copy));

    s21::list<int> s21_list1{1, 2, 3};
    std::list<int> std_list1{1, 2, 3};
    s21::list<int> s21_list1_copy(s21_list1);
    std::list<int> std_list1_copy(std_list1);
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
    EXPECT_TRUE(equel_list(s21_list1_copy, std_list1_copy));
}

TEST(list, move_constructor) {
    s21::list<int> s21_list{1, 2, 3};
    std::list<int> std_list{1, 2, 3};
    s21::list<int> s21_list_move(std::move(s21_list));
    std::list<int> std_list_move(std::move(std_list));
    EXPECT_TRUE(equel_list(s21_list_move, std_list_move));
    ASSERT_EQ(s21_list.size(), std_list.size());
    ASSERT_EQ(s21_list.empty(), std_list.empty());

    s21::list<char> s21_list1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::list<char> std_list1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::list<char> s21_list1_move(std::move(s21_list1));
    std::list<char> std_list1_move(std::move(std_list1));
    EXPECT_TRUE(equel_list(s21_list1_move, std_list1_move));
    ASSERT_EQ(s21_list1.size(), std_list1.size());
    ASSERT_EQ(s21_list1.empty(), std_list1.empty());
}

TEST(list, move_to_less_buffer) {
    s21::list<int> s21_list{123, 34567, 6789634, 34567986, 0, 1, 56};
    std::list<int> std_list{123, 34567, 6789634, 34567986, 0, 1, 56};
    s21::list<int> s21_list_move{1, 2};
    std::list<int> std_list_move{1, 2};
    s21_list_move = std::move(s21_list);
    std_list_move = std::move(std_list);
    EXPECT_TRUE(equel_list(s21_list_move, std_list_move));
    ASSERT_EQ(s21_list.size(), std_list.size());
    ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list, move_to_more_buffer) {
    s21::list<int> s21_list{1, 2};
    std::list<int> std_list{1, 2};
    s21::list<int> s21_list_move{123, 34567, 6789634, 34567986, 0, 1, 56};
    std::list<int> std_list_move{123, 34567, 6789634, 34567986, 0, 1, 56};
    s21_list_move = std::move(s21_list);
    std_list_move = std::move(std_list);
    EXPECT_TRUE(equel_list(s21_list_move, std_list_move));
    ASSERT_EQ(s21_list.size(), std_list.size());
    ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list, front_function) {
    s21::list<char> s21_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::list<char> std_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_list(s21_list, std_list));
    ASSERT_EQ(s21_list.front(), std_list.front());

    s21::list<std::pair<int, double>> s21_list2{{42, 3.1415}, {89, 21}};
    std::list<std::pair<int, double>> std_list2{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_list(s21_list2, std_list2));
    ASSERT_EQ(s21_list2.front(), std_list2.front());

    s21::list<std::string> s21_list3{"Hello", "World!"};
    std::list<std::string> std_list3{"Hello", "World!"};
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
    ASSERT_EQ(s21_list3.front(), std_list3.front());
}


TEST(list, back_function) {
    s21::list<char> s21_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::list<char> std_list{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_list(s21_list, std_list));
    ASSERT_EQ(s21_list.back(), std_list.back());

    s21::list<std::pair<int, double>> s21_list2{{42, 3.1415}, {89, 21}};
    std::list<std::pair<int, double>> std_list2{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_list(s21_list2, std_list2));
    ASSERT_EQ(s21_list2.back(), std_list2.back());

    s21::list<std::string> s21_list3{"Hello", "World!"};
    std::list<std::string> std_list3{"Hello", "World!"};
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
    ASSERT_EQ(s21_list3.back(), std_list3.back());
}

TEST(list, const_iterator_access) {
    s21::list<char> s21_list{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    std::list<char> std_list{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    s21::list<char>::const_iterator s21_it = s21_list.cbegin();
    std::list<char>::const_iterator std_it = std_list.cbegin();
    while (s21_it != s21_list.end()) {
        EXPECT_TRUE(*s21_it == *std_it);
        ++s21_it;
        ++std_it;
    }
    s21::list<char> s21_list1{'f', 'a', 'u', 'l', 't'};
    std::list<char> std_list1{'f', 'a', 'u', 'l', 't'};
    s21::list<char>::const_iterator s21_it1 = s21_list1.cend();
    std::list<char>::const_iterator std_it1 = std_list1.cend();
    --s21_it1;
    --std_it1;
    while (s21_it1 != s21_list1.begin()) {
        EXPECT_TRUE(*s21_it1 == *std_it1);
        --s21_it1;
        --std_it1;
    }
}

TEST(list, citerator_access) {
    s21::list<char> s21_list{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    std::list<char> std_list{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    s21::list<char>::iterator s21_it = s21_list.begin();
    std::list<char>::iterator std_it = std_list.begin();
    while (s21_it != s21_list.end()) {
        EXPECT_TRUE(*s21_it == *std_it);
        ++s21_it;
        ++std_it;
    }
    s21_list.push_back('!');
    std_list.push_back('!');
    ++s21_it;
    ++std_it;
    EXPECT_TRUE(*s21_it == *std_it);
    s21::list<char> s21_list1{'f', 'a', 'u', 'l', 't'};
    std::list<char> std_list1{'f', 'a', 'u', 'l', 't'};
    s21::list<char>::iterator s21_it1 = s21_list1.end();
    std::list<char>::iterator std_it1 = std_list1.end();
    --s21_it1;
    --std_it1;
    while (s21_it1 != s21_list1.begin()) {
        EXPECT_TRUE(*s21_it1 == *std_it1);
        --s21_it1;
        --std_it1;
    }
    s21_list1.push_back('!');
    std_list1.push_back('!');
    --s21_it1;
    --std_it1;
    --s21_it1;
    --std_it1;
    EXPECT_TRUE(*s21_it1 == *std_it1);
}


TEST(list, max_sizef_function) {
    s21::list<int> s21_list;
    std::list<int> std_list;
    ASSERT_EQ(s21_list.max_size(), std_list.max_size());
    s21::list<std::string> s21_list1{"Hello", "World!"};
    std::list<std::string> std_list1{"Hello", "World!"};
    ASSERT_EQ(s21_list1.max_size(), std_list1.max_size());
}

TEST(list, clear_function) {
    s21::list<std::string> s21_list{"Hello", "World!"};
    std::list<std::string> std_list{"Hello", "World!"};
    s21_list.clear();
    std_list.clear();
    ASSERT_EQ(s21_list.size(), std_list.size());
    ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list, insert_function) {
    s21::list<std::string> s21_list{"Hello,", "World!"};
    std::list<std::string> std_list{"Hello,", "World!"};
    s21::list<std::string>::iterator s21_it = s21_list.begin();
    std::list<std::string>::iterator std_it = std_list.begin();
    s21_it = s21_list.insert(s21_it, "Hi or");
    std_it = std_list.insert(std_it, "Hi or");
    ASSERT_EQ(*s21_it, *std_it);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.begin();
    std_it = std_list.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_it = s21_list.insert(s21_it, "my dear");
    std_it = std_list.insert(std_it, "my dear");
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.end();
    std_it = std_list.end();
    s21_it = s21_list.insert(s21_it, "Be happy");
    std_it = std_list.insert(std_it, "Be happy");
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, erase_function) {
    s21::list<int> s21_list{1, 2, 3, 4, 5, 6, 7, 9, 8, 10};
    std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 9, 8, 10};
    s21::list<int>::iterator s21_it = s21_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
    s21_list.erase(s21_it);
    std_list.erase(std_it);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.end();
    std_it = std_list.end();
    --s21_it;
    --std_it;
    s21_list.erase(s21_it);
    std_list.erase(std_it);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.begin();
    std_it = std_list.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_list.erase(s21_it);
    std_list.erase(std_it);
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, pop_back_function) {
    s21::list<std::string> s21_list{"I'm", "glad", "to see", "you"};
    std::list<std::string> std_list{"I'm", "glad", "to see", "you"};
    s21_list.pop_back();
    std_list.pop_back();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_back();
    std_list.pop_back();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_back();
    std_list.pop_back();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_back();
    std_list.pop_back();
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, push_back_function) {
    s21::list<std::string> s21_list;
    std::list<std::string> std_list;
    s21_list.push_back("I'm");
    std_list.push_back("I'm");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_back("glad");
    std_list.push_back("glad");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_back("to see");
    std_list.push_back("to see");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_back("you");
    std_list.push_back("you");
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, pop_front_function) {
    s21::list<std::string> s21_list{"I'm", "glad", "to see", "you"};
    std::list<std::string> std_list{"I'm", "glad", "to see", "you"};
    s21_list.pop_front();
    std_list.pop_front();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_front();
    std_list.pop_front();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_front();
    std_list.pop_front();
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.pop_front();
    std_list.pop_front();
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, push_front_function) {
    s21::list<std::string> s21_list;
    std::list<std::string> std_list;
    s21_list.push_front("I'm");
    std_list.push_front("I'm");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_front("glad");
    std_list.push_front("glad");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_front("to see");
    std_list.push_front("to see");
    EXPECT_TRUE(equel_list(s21_list, std_list));
    s21_list.push_front("you");
    std_list.push_front("you");
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(list, swap_function) {
    s21::list<char> s21_list{'l', 'o', 'v', 'e'};
    std::list<char> std_list{'l', 'o', 'v', 'e'};
    s21::list<char> s21_list_swap{'o'};
    std::list<char> std_list_swap{'o'};
    s21_list.swap(s21_list_swap);
    std_list.swap(std_list_swap);
    EXPECT_TRUE(equel_list(s21_list, std_list));
    EXPECT_TRUE(equel_list(s21_list_swap, std_list_swap));

    s21::list<char> s21_list1{'o'};
    std::list<char> std_list1{'o'};
    s21::list<char> s21_list1_swap{'l', 'o', 'v', 'e'};
    std::list<char> std_list1_swap{'l', 'o', 'v', 'e'};
    s21_list1.swap(s21_list1_swap);
    std_list1.swap(std_list1_swap);
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
    EXPECT_TRUE(equel_list(s21_list1_swap, std_list1_swap));

    s21::list<char> s21_list2{'l', 'o', 'v', 'e'};
    std::list<char> std_list2{'l', 'o', 'v', 'e'};
    s21::list<char> s21_list2_swap;
    std::list<char> std_list2_swap;
    s21_list2.swap(s21_list2_swap);
    std_list2.swap(std_list2_swap);
    EXPECT_TRUE(equel_list(s21_list2, std_list2));
    EXPECT_TRUE(equel_list(s21_list2_swap, std_list2_swap));

    s21::list<char> s21_list3;
    std::list<char> std_list3;
    s21::list<char> s21_list3_swap{'l', 'o', 'v', 'e'};
    std::list<char> std_list3_swap{'l', 'o', 'v', 'e'};
    s21_list3.swap(s21_list3_swap);
    std_list3.swap(std_list3_swap);
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
    EXPECT_TRUE(equel_list(s21_list3_swap, std_list3_swap));
}

TEST(list, sort_function) {
    s21::list<double> s21_list{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21_list.sort();
    std_list.sort();
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<double> s21_list1{8};
    std::list<double> std_list1{8};
    s21_list1.sort();
    std_list1.sort();
    EXPECT_TRUE(equel_list(s21_list1, std_list1));

    s21::list<char> s21_list2{'c', 'a', 'd', 'b'};
    std::list<char> std_list2{'c', 'a', 'd', 'b'};
    s21_list2.sort();
    std_list2.sort();
    EXPECT_TRUE(equel_list(s21_list2, std_list2));

    s21::list<std::string> s21_list3{"to see", "glad", "you", "I'm"};
    std::list<std::string> std_list3{"to see", "glad", "you", "I'm"};
    s21_list3.sort();
    std_list3.sort();
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
}

TEST(list, merge_function) {
    s21::list<double> s21_list{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21::list<double> s21_list_merge{1, 2, 9};
    std::list<double> std_list_merge{1, 2, 9};
    s21_list.merge(s21_list_merge);
    std_list.merge(std_list_merge);
    EXPECT_TRUE(equel_list(s21_list, std_list));
    EXPECT_TRUE(equel_list(s21_list_merge, std_list_merge));
    s21::list<double> s21_list1{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list1{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21::list<double> s21_list1_merge{1, 2, 9};
    std::list<double> std_list1_merge{1, 2, 9};
    s21_list1.sort();
    std_list1.sort();
    s21_list1.merge(s21_list1_merge);
    std_list1.merge(std_list1_merge);
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
    EXPECT_TRUE(equel_list(s21_list1_merge, std_list1_merge));

    s21::list<double> s21_list2{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list2{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21::list<double> s21_list2_merge;
    std::list<double> std_list2_merge;
    s21_list2.sort();
    std_list2.sort();
    s21_list2.merge(s21_list2_merge);
    std_list2.merge(std_list2_merge);
    EXPECT_TRUE(equel_list(s21_list2, std_list2));
    EXPECT_TRUE(equel_list(s21_list2_merge, std_list2_merge));

    s21::list<double> s21_list3;
    std::list<double> std_list3;
    s21::list<double> s21_list3_merge{1, 2, 9};
    std::list<double> std_list3_merge{1, 2, 9};
    s21_list3.merge(s21_list3_merge);
    std_list3.merge(std_list3_merge);
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
    EXPECT_TRUE(equel_list(s21_list3_merge, std_list3_merge));

    s21::list<double> s21_list4{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list4{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21::list<double> s21_list4_merge{8, 9, 9};
    std::list<double> std_list4_merge{8, 9, 9};
    s21_list4.merge(s21_list4_merge);
    std_list4.merge(std_list4_merge);
    EXPECT_TRUE(equel_list(s21_list4, std_list4));
    EXPECT_TRUE(equel_list(s21_list4_merge, std_list4_merge));

    s21::list<double> s21_list5{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    std::list<double> std_list5{ 8, 4.9, 5, 9, 1.2, 1, 3, 2, 6, 4 };
    s21::list<double> s21_list5_merge{1, 1, 1};
    std::list<double> std_list5_merge{1, 1, 1};
    s21_list5.merge(s21_list5_merge);
    std_list5.merge(std_list5_merge);
    EXPECT_TRUE(equel_list(s21_list5, std_list5));
    EXPECT_TRUE(equel_list(s21_list5_merge, std_list5_merge));
}

TEST(list, function_splice) {
    s21::list<std::string> s21_list{"Hello,", "World!"};
    std::list<std::string> std_list{"Hello,", "World!"};
    s21::list<std::string> s21_list_splice{"I'm", "glad", "to see", "you"};
    std::list<std::string> std_list_splice{"I'm", "glad", "to see", "you"};
    s21::list<std::string>::const_iterator s21_it = s21_list.cbegin();
    std::list<std::string>::const_iterator std_it = std_list.cbegin();
    ++s21_it;
    ++std_it;
    s21_list.splice(s21_it, s21_list_splice);
    std_list.splice(std_it, std_list_splice);
    EXPECT_TRUE(equel_list(s21_list, std_list));
    EXPECT_TRUE(equel_list(s21_list_splice, std_list_splice));

    s21::list<std::string> s21_list1{"I'm", "glad", "to see", "you"};
    std::list<std::string> std_list1{"I'm", "glad", "to see", "you"};
    s21::list<std::string> s21_list1_splice;
    std::list<std::string> std_list1_splice;
    s21::list<std::string>::const_iterator s21_it1 = s21_list1_splice.cend();
    std::list<std::string>::const_iterator std_it1 = std_list1_splice.cend();
    s21_list1.splice(s21_it1, s21_list1_splice);
    std_list1.splice(std_it1, std_list1_splice);
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
    EXPECT_TRUE(equel_list(s21_list1_splice, std_list1_splice));
}

TEST(list, reverse_function) {
    s21::list<int> s21_list{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21_list.reverse();
    std_list.reverse();
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<int> s21_list2{2};
    std::list<int> std_list2{2};
    s21_list2.reverse();
    std_list2.reverse();
    EXPECT_TRUE(equel_list(s21_list2, std_list2));

    s21::list<int> s21_list3;
    std::list<int> std_list3;
    s21_list3.reverse();
    std_list3.reverse();
    EXPECT_TRUE(equel_list(s21_list3, std_list3));
}

TEST(list, unique_function) {
    s21::list<double> s21_list{11, 1.1, 1, 3, 4, 3, 3, 5, 21};
    std::list<double> std_list{11, 1.1, 1, 3, 4, 3, 3, 5, 21};
    s21_list.unique();
    std_list.unique();
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21::list<int> s21_list1{1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::list<int> std_list1{1, 1, 1, 1, 1, 1, 1, 1, 1};
    s21_list1.unique();
    std_list1.unique();
    EXPECT_TRUE(equel_list(s21_list1, std_list1));

    s21::list<int> s21_list2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> std_list2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21_list2.unique();
    std_list2.unique();
    EXPECT_TRUE(equel_list(s21_list2, std_list2));

    s21::list<int> s21_list3;
    std::list<int> std_list3;
    s21_list3.unique();
    std_list3.unique();
    EXPECT_TRUE(equel_list(s21_list3, std_list3));

    s21::list<int> s21_list4{2};
    std::list<int> std_list4{2};
    s21_list4.unique();
    std_list4.unique();
    EXPECT_TRUE(equel_list(s21_list4, std_list4));
}

/* --------------------------VECTOR TESTS --------------------------*/
template <class T>
bool equel_vector(s21::vector<T> s21_vector, std::vector<T> std_vector) {
    bool res = true;
    if ((s21_vector.size() != std_vector.size()) || (s21_vector.empty() != std_vector.empty()))
        res = false;
    if (res != false) {
        for (size_t i = 0; i < s21_vector.size(); i++)
            if (std_vector[i] != s21_vector[i])
                            res = false;
    }
    return res;
}

template <class T>
bool equel_vector_full(s21::vector<T> s21_vector, std::vector<T> std_vector) {
    bool res = true;
    if (!equel_vector(s21_vector, std_vector))
        res = false;
    if (s21_vector.capacity() != std_vector.capacity())
        res = false;
    return res;
}

TEST(vector, default_constructor) {
    s21::vector<int> s21_vector;
    std::vector<int> std_vector;
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<double> s21_vector1;
    std::vector<double> std_vector1;
    EXPECT_TRUE(equel_vector_full(s21_vector1, std_vector1));

    s21::vector<std::string> s21_vector2;
    std::vector<std::string> std_vector2;
    EXPECT_TRUE(equel_vector_full(s21_vector2, std_vector2));

    s21::vector<char> s21_vector3;
    std::vector<char> std_vector3;
    EXPECT_TRUE(equel_vector_full(s21_vector3, std_vector3));

    s21::vector<std::pair<int, double>> s21_vector4;
    std::vector<std::pair<int, double>> std_vector4;
    EXPECT_TRUE(equel_vector_full(s21_vector4, std_vector4));

    s21::vector<std::set<int>> s21_vector5;
    std::vector<std::set<int>> std_vector5;
    EXPECT_TRUE(equel_vector_full(s21_vector5, std_vector5));
}

TEST(vector, init_constructor) {
    s21::vector<int> s21_vector(2);
    std::vector<int> std_vector(2);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<double> s21_vector1(0);
    std::vector<double> std_vector1(0);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<std::string> s21_vector2(1);
    std::vector<std::string> std_vector2(1);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<char> s21_vector3(8);
    std::vector<char> std_vector3(8);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<std::pair<int, double>> s21_vector4(16);
    std::vector<std::pair<int, double>> std_vector4(16);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<std::set<int>> s21_vector5(3);
    std::vector<std::set<int>> std_vector5(3);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<int> s21_vector6(2);
    std::vector<int> std_vector6(3);
    EXPECT_FALSE(equel_vector_full(s21_vector6, std_vector6));
}

TEST(vector, initializer_vector_constructor) {
    s21::vector<int> s21_vector{1, 2, 3};
    std::vector<int> std_vector{1, 2, 3};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21::vector<double> s21_vector1{1.4, 2.0008, 3.122345, 123345};
    std::vector<double> std_vector1{1.4, 2.0008, 3.122345, 123345};
    EXPECT_TRUE(equel_vector_full(s21_vector1, std_vector1));

    s21::vector<std::string> s21_vector2{"Hello", "World!"};
    std::vector<std::string> std_vector2{"Hello", "World!"};
    EXPECT_TRUE(equel_vector_full(s21_vector2, std_vector2));

    s21::vector<char> s21_vector3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    std::vector<char> std_vector3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    EXPECT_TRUE(equel_vector_full(s21_vector3, std_vector3));

    s21::vector<std::pair<int, double>> s21_vector4{{42, 3.1415}, {89, 21}};
    std::vector<std::pair<int, double>> std_vector4{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_vector_full(s21_vector4, std_vector4));

    s21::vector<std::string> s21_vector6{"Hello", "Me!"};
    std::vector<std::string> std_vector6{"Hello", "World!"};
    EXPECT_FALSE(equel_vector_full(s21_vector6, std_vector6));
}

TEST(vector, copy_constructor) {
    s21::vector<char> s21_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::vector<char> std_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::vector<char> s21_vector_copy(s21_vector);
    std::vector<char> std_vector_copy(std_vector);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    EXPECT_TRUE(equel_vector_full(s21_vector_copy, std_vector_copy));

    s21::vector<int> s21_vector1{1, 2, 3};
    std::vector<int> std_vector1{1, 2, 3};
    s21::vector<int> s21_vector1_copy(s21_vector1);
    std::vector<int> std_vector1_copy(std_vector1);
    EXPECT_TRUE(equel_vector_full(s21_vector1, std_vector1));
    EXPECT_TRUE(equel_vector_full(s21_vector1_copy, std_vector1_copy));
}

TEST(vector, move_constructor) {
    s21::vector<int> s21_vector{1, 2, 3};
    std::vector<int> std_vector{1, 2, 3};
    s21::vector<int> s21_vector_move(std::move(s21_vector));
    std::vector<int> std_vector_move(std::move(std_vector));
    EXPECT_TRUE(equel_vector_full(s21_vector_move, std_vector_move));
    ASSERT_EQ(s21_vector.size(), std_vector.size());
    ASSERT_EQ(s21_vector.empty(), std_vector.empty());

    s21::vector<char> s21_vector1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::vector<char> std_vector1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::vector<char> s21_vector1_move(std::move(s21_vector1));
    std::vector<char> std_vector1_move(std::move(std_vector1));
    EXPECT_TRUE(equel_vector_full(s21_vector1_move, std_vector1_move));
    ASSERT_EQ(s21_vector1.size(), std_vector1.size());
    ASSERT_EQ(s21_vector1.empty(), std_vector1.empty());
}

TEST(vector, move_to_less_buffer) {
    s21::vector<int> s21_vector{123, 34567, 6789634, 34567986, 0, 1, 56};
    std::vector<int> std_vector{123, 34567, 6789634, 34567986, 0, 1, 56};
    s21::vector<int> s21_vector_move{1, 2};
    std::vector<int> std_vector_move{1, 2};
    s21_vector_move = std::move(s21_vector);
    std_vector_move = std::move(std_vector);
    EXPECT_TRUE(equel_vector_full(s21_vector_move, std_vector_move));
    ASSERT_EQ(s21_vector.size(), std_vector.size());
    ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(vector, move_to_more_buffer) {
    s21::vector<int> s21_vector{1, 2};
    std::vector<int> std_vector{1, 2};
    s21::vector<int> s21_vector_move{123, 34567, 6789634, 34567986, 0, 1, 56};
    std::vector<int> std_vector_move{123, 34567, 6789634, 34567986, 0, 1, 56};
    s21_vector_move = std::move(s21_vector);
    std_vector_move = std::move(std_vector);
    EXPECT_TRUE(equel_vector_full(s21_vector_move, std_vector_move));
    ASSERT_EQ(s21_vector.size(), std_vector.size());
    ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}


TEST(vector, front_function) {
    s21::vector<char> s21_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::vector<char> std_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    ASSERT_EQ(s21_vector.front(), std_vector.front());

    s21::vector<std::pair<int, double>> s21_vector2{{42, 3.1415}, {89, 21}};
    std::vector<std::pair<int, double>> std_vector2{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_vector_full(s21_vector2, std_vector2));
    ASSERT_EQ(s21_vector2.front(), std_vector2.front());

    s21::vector<std::string> s21_vector3{"Hello", "World!"};
    std::vector<std::string> std_vector3{"Hello", "World!"};
    EXPECT_TRUE(equel_vector_full(s21_vector3, std_vector3));
    ASSERT_EQ(s21_vector3.front(), std_vector3.front());
}


TEST(vector, back_function) {
    s21::vector<char> s21_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::vector<char> std_vector{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    ASSERT_EQ(s21_vector.back(), std_vector.back());

    s21::vector<std::pair<int, double>> s21_vector2{{42, 3.1415}, {89, 21}};
    std::vector<std::pair<int, double>> std_vector2{{42, 3.1415}, {89, 21}};
    EXPECT_TRUE(equel_vector_full(s21_vector2, std_vector2));
    ASSERT_EQ(s21_vector2.back(), std_vector2.back());

    s21::vector<std::string> s21_vector3{"Hello", "World!"};
    std::vector<std::string> std_vector3{"Hello", "World!"};
    EXPECT_TRUE(equel_vector_full(s21_vector3, std_vector3));
    ASSERT_EQ(s21_vector3.back(), std_vector3.back());
}

TEST(vector, const_iterator_access) {
    s21::vector<char> s21_vector{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    std::vector<char> std_vector{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    s21::vector<char>::const_iterator s21_it = s21_vector.begin();
    std::vector<char>::const_iterator std_it = std_vector.begin();
    while (s21_it != s21_vector.end()) {
        EXPECT_TRUE(*s21_it == *std_it);
        ++s21_it;
        ++std_it;
    }
    s21::vector<char> s21_vector1{'f', 'a', 'u', 'l', 't'};
    std::vector<char> std_vector1{'f', 'a', 'u', 'l', 't'};
    s21::vector<char>::const_iterator s21_it1 = s21_vector1.end();
    std::vector<char>::const_iterator std_it1 = std_vector1.end();
    --s21_it1;
    --std_it1;
    while (s21_it1 != s21_vector1.begin()) {
        EXPECT_TRUE(*s21_it1 == *std_it1);
        --s21_it1;
        --std_it1;
    }
    EXPECT_TRUE(*s21_it1 == *std_it1);
}

TEST(vector, max_sizef_function) {
    s21::vector<int> s21_vector;
    std::vector<int> std_vector;
    ASSERT_EQ(s21_vector.max_size(), std_vector.max_size());
    s21::vector<std::string> s21_vector1{"Hello", "World!"};
    std::vector<std::string> std_vector1{"Hello", "World!"};
    ASSERT_EQ(s21_vector1.max_size(), std_vector1.max_size());
}

TEST(vector, clear_function) {
    s21::vector<std::string> s21_vector{"Hello", "World!"};
    std::vector<std::string> std_vector{"Hello", "World!"};
    s21_vector.clear();
    std_vector.clear();
    ASSERT_EQ(s21_vector.size(), std_vector.size());
    ASSERT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(vector, insert_function) {
    s21::vector<std::string> s21_vector{"Hello,", "World!"};
    std::vector<std::string> std_vector{"Hello,", "World!"};
    s21::vector<std::string>::iterator s21_it = s21_vector.begin();
    std::vector<std::string>::iterator std_it = std_vector.begin();
    s21_it = s21_vector.insert(s21_it, "Hi or");
    std_it = std_vector.insert(std_it, "Hi or");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21_it = s21_vector.begin();
    std_it = std_vector.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_it = s21_vector.insert(s21_it, "my dear");
    std_it = std_vector.insert(std_it, "my dear");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21_it = s21_vector.end();
    std_it = std_vector.end();
    s21_it = s21_vector.insert(s21_it, "Be happy");
    std_it = std_vector.insert(std_it, "Be happy");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
}

TEST(vector, erase_function) {
    s21::vector<int> s21_vector{1, 2, 3, 4, 5, 6, 7, 9, 8, 10};
    std::vector<int> std_vector{1, 2, 3, 4, 5, 6, 7, 9, 8, 10};
    s21::vector<int>::iterator s21_it = s21_vector.begin();
    std::vector<int>::iterator std_it = std_vector.begin();
    s21_vector.erase(s21_it);
    std_vector.erase(std_it);
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));

    s21_it = s21_vector.end();
    std_it = std_vector.end();
    --s21_it;
    --std_it;
    s21_vector.erase(s21_it);
    std_vector.erase(std_it);
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));

    s21_it = s21_vector.begin();
    std_it = std_vector.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_vector.erase(s21_it);
    std_vector.erase(std_it);
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
}

TEST(vector, pop_back_function) {
    s21::vector<std::string> s21_vector{"I'm", "glad", "to see", "you"};
    std::vector<std::string> std_vector{"I'm", "glad", "to see", "you"};
    s21_vector.pop_back();
    std_vector.pop_back();
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.pop_back();
    std_vector.pop_back();
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.pop_back();
    std_vector.pop_back();
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.pop_back();
    std_vector.pop_back();
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
}

TEST(vector, push_back_function) {
    s21::vector<std::string> s21_vector;
    std::vector<std::string> std_vector;
    s21_vector.push_back("I'm");
    std_vector.push_back("I'm");
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.push_back("glad");
    std_vector.push_back("glad");
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.push_back("to see");
    std_vector.push_back("to see");
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
    s21_vector.push_back("you");
    std_vector.push_back("you");
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
}

TEST(vector, swap_function) {
    s21::vector<char> s21_vector{'l', 'o', 'v', 'e'};
    std::vector<char> std_vector{'l', 'o', 'v', 'e'};
    s21::vector<char> s21_vector_swap{'o'};
    std::vector<char> std_vector_swap{'o'};
    s21_vector.swap(s21_vector_swap);
    std_vector.swap(std_vector_swap);
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    EXPECT_TRUE(equel_vector_full(s21_vector_swap, std_vector_swap));

    s21::vector<char> s21_vector1{'o'};
    std::vector<char> std_vector1{'o'};
    s21::vector<char> s21_vector1_swap{'l', 'o', 'v', 'e'};
    std::vector<char> std_vector1_swap{'l', 'o', 'v', 'e'};
    s21_vector1.swap(s21_vector1_swap);
    std_vector1.swap(std_vector1_swap);
    EXPECT_TRUE(equel_vector_full(s21_vector1, std_vector1));
    EXPECT_TRUE(equel_vector_full(s21_vector1_swap, std_vector1_swap));

    s21::vector<char> s21_vector2{'l', 'o', 'v', 'e'};
    std::vector<char> std_vector2{'l', 'o', 'v', 'e'};
    s21::vector<char> s21_vector2_swap;
    std::vector<char> std_vector2_swap;
    s21_vector2.swap(s21_vector2_swap);
    std_vector2.swap(std_vector2_swap);
    EXPECT_TRUE(equel_vector_full(s21_vector2, std_vector2));
    EXPECT_TRUE(equel_vector_full(s21_vector2_swap, std_vector2_swap));

    s21::vector<char> s21_vector3;
    std::vector<char> std_vector3;
    s21::vector<char> s21_vector3_swap{'l', 'o', 'v', 'e'};
    std::vector<char> std_vector3_swap{'l', 'o', 'v', 'e'};
    s21_vector3.swap(s21_vector3_swap);
    std_vector3.swap(std_vector3_swap);
    EXPECT_TRUE(equel_vector_full(s21_vector3, std_vector3));
    EXPECT_TRUE(equel_vector_full(s21_vector3_swap, std_vector3_swap));
}

TEST(vector, reserve_function) {
    s21::vector<char> s21_vector_default;
    std::vector<char> std_vector_default;
    s21_vector_default.reserve(130);
    std_vector_default.reserve(130);
    ASSERT_EQ(s21_vector_default.capacity(), std_vector_default.capacity());
    EXPECT_TRUE(equel_vector(s21_vector_default, std_vector_default));

    s21::vector<int> s21_vector{'h', 'i', '!'};
    std::vector<int> std_vector{'h', 'i', '!'};
    s21_vector.reserve(50);
    std_vector.reserve(50);
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));
}

TEST(vector, shrink_to_fit_function) {
    s21::vector<int> s21_vector{1, 2, 3};
    std::vector<int> std_vector{1, 2, 3};
    s21_vector.reserve(50);
    std_vector.reserve(50);
    s21_vector.shrink_to_fit();
    std_vector.shrink_to_fit();
    ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));

    s21::vector<int> s21_vector1;
    std::vector<int> std_vector1;
    s21_vector1.resize(100);
    std_vector1.resize(100);
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    s21_vector1.resize(50);
    std_vector1.resize(50);
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    s21_vector1.shrink_to_fit();
    std_vector1.shrink_to_fit();
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    s21_vector1.clear();
    std_vector1.clear();
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    s21_vector1.shrink_to_fit();
    std_vector1.shrink_to_fit();
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    for (int i = 1000; i < 1300; ++i) {
        s21_vector1.push_back(i);
        std_vector1.push_back(i);
    }
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
    s21_vector1.shrink_to_fit();
    std_vector1.shrink_to_fit();
    ASSERT_EQ(s21_vector1.capacity(), std_vector1.capacity());
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
}

TEST(vector, iterators) {
    s21::vector<int> s21_vector{1, 2, 3};
    std::vector<int> std_vector{1, 2, 3};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    s21::vector<int>::const_iterator s21_it = s21_vector.begin();
    s21::vector<int>::const_iterator s21_it_2 = s21_vector.begin();
    std::vector<int>::const_iterator std_it = std_vector.begin();
    ASSERT_EQ(*s21_it, *std_it);
    EXPECT_TRUE(*s21_it == *std_it);
    EXPECT_TRUE(s21_it == s21_it_2);
    ++s21_it;
    ++std_it;
    ASSERT_EQ(*s21_it, *std_it);
    s21_it = s21_vector.end();
    std_it = std_vector.end();
    ASSERT_EQ(*s21_it, *std_it);
    --s21_it;
    --std_it;
    ASSERT_EQ(*s21_it, *std_it);
    EXPECT_TRUE(s21_it != s21_it_2);
}

TEST(vector, function_at) {
    s21::vector<std::string> s21_vector{"access", "specified", "element", "with", "bounds", "checking"};
    std::vector<std::string> std_vector{"access", "specified", "element", "with", "bounds", "checking"};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
    ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
    ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
    ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
    ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
    ASSERT_EQ(s21_vector.at(5), std_vector.at(5));
}

TEST(vector, operator_square_brackets) {
    s21::vector<std::string> s21_vector{"access", "specified", "element"};
    std::vector<std::string> std_vector{"access", "specified", "element"};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    ASSERT_EQ(s21_vector[0], std_vector[0]);
    ASSERT_EQ(s21_vector[1], std_vector[1]);
    ASSERT_EQ(s21_vector[2], std_vector[2]);
}

TEST(vector, function_data) {
    s21::vector<int> s21_vector_empty;
    std::vector<int> std_vector_empty;
    ASSERT_EQ(s21_vector_empty.data(), nullptr);
    ASSERT_EQ(std_vector_empty.data(), nullptr);
    EXPECT_TRUE(equel_vector_full(s21_vector_empty, std_vector_empty));
    s21::vector<int> s21_vector{1, 2234567, 21, 9874567};
    std::vector<int> std_vector{1, 2234567, 21, 9874567};
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
    ASSERT_NE(s21_vector.data(), nullptr);
    ASSERT_NE(std_vector.data(), nullptr);
}

/* --------------------------ARRAY TESTS --------------------------*/


template <class T, std::size_t N>
bool equel_array(s21::array<T, N> s21_array, std::array<T, N> std_array) {
    bool res = true;
    if ((s21_array.size() != std_array.size()) || (s21_array.empty() != std_array.empty()))
        res = false;
    if (res != false) {
        for (size_t i = 0; i < s21_array.size(); i++)
            if (std_array[i] != s21_array[i])
                            res = false;
    }
    return res;
}


TEST(array, default_constructor) {
    s21::array<int, 3> s21_array;
    std::array<int, 3> std_array;
    ASSERT_EQ(s21_array.size(), std_array.size());
    ASSERT_EQ(s21_array.empty(), std_array.empty());

    s21::array<double, 0> s21_array1;
    std::array<double, 0> std_array1;
    ASSERT_EQ(s21_array1.size(), std_array1.size());
    ASSERT_EQ(s21_array1.empty(), std_array1.empty());

    s21::array<std::string, 10> s21_array2;
    std::array<std::string, 10> std_array2;
    ASSERT_EQ(s21_array2.size(), std_array2.size());
    ASSERT_EQ(s21_array2.empty(), std_array2.empty());

    s21::array<char, 0> s21_array3;
    std::array<char, 0> std_array3;
    ASSERT_EQ(s21_array3.size(), std_array3.size());
    ASSERT_EQ(s21_array3.empty(), std_array3.empty());

    s21::array<std::pair<int, double>, 1> s21_array4;
    std::array<std::pair<int, double>, 1> std_array4;
    ASSERT_EQ(s21_array4.size(), std_array4.size());
    ASSERT_EQ(s21_array4.empty(), std_array4.empty());

    s21::array<std::set<int>, 24> s21_array5;
    std::array<std::set<int>, 24> std_array5;
    ASSERT_EQ(s21_array5.size(), std_array5.size());
    ASSERT_EQ(s21_array5.empty(), std_array5.empty());
}

TEST(array, initializer_array_constructor) {
    s21::array<int, 3> s21_array{1, 2, 3};
    std::array<int, 3> std_array{1, 2, 3};
    EXPECT_TRUE(equel_array(s21_array, std_array));

    s21::array<double, 4> s21_array1{1.4, 2.0008, 3.122345, 123345};
    std::array<double, 4> std_array1{1.4, 2.0008, 3.122345, 123345};
    EXPECT_TRUE(equel_array(s21_array1, std_array1));

    s21::array<std::string, 2> s21_array2{"Hello", "World!"};
    std::array<std::string, 2> std_array2{"Hello", "World!"};
    EXPECT_TRUE(equel_array(s21_array2, std_array2));

    s21::array<char, 12> s21_array3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    std::array<char, 12> std_array3{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'd', 'e', '!'};
    EXPECT_TRUE(equel_array(s21_array3, std_array3));

    s21::array<std::string, 2> s21_array6{"Hello", "Me!"};
    std::array<std::string, 2> std_array6{"Hello", "World!"};
    EXPECT_FALSE(equel_array(s21_array6, std_array6));
}

TEST(array, copy_constructor) {
    s21::array<char, 14> s21_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::array<char, 14> std_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::array<char, 14> s21_array_copy(s21_array);
    std::array<char, 14> std_array_copy(std_array);
    EXPECT_TRUE(equel_array(s21_array, std_array));
    EXPECT_TRUE(equel_array(s21_array_copy, std_array_copy));

    s21::array<int, 3> s21_array1{1, 2, 3};
    std::array<int, 3> std_array1{1, 2, 3};
    s21::array<int, 3> s21_array1_copy(s21_array1);
    std::array<int, 3> std_array1_copy(std_array1);
    EXPECT_TRUE(equel_array(s21_array1, std_array1));
    EXPECT_TRUE(equel_array(s21_array1_copy, std_array1_copy));
}

TEST(array, move_constructor) {
    s21::array<int, 3> s21_array{1, 2, 3};
    std::array<int, 3> std_array{1, 2, 3};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    s21::array<int, 3> s21_array_move(std::move(s21_array));
    std::array<int, 3> std_array_move(std::move(std_array));
    EXPECT_TRUE(equel_array(s21_array_move, std_array_move));
    EXPECT_TRUE(equel_array(s21_array, std_array));

    s21::array<char, 14> s21_array1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::array<char, 14> std_array1{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    s21::array<char, 14> s21_array1_move(std::move(s21_array1));
    std::array<char, 14> std_array1_move(std::move(std_array1));
    EXPECT_TRUE(equel_array(s21_array1, std_array1));
    EXPECT_TRUE(equel_array(s21_array1_move, std_array1_move));

    s21::array<int, 7> s21_array2{123, 34567, 6789634, 34567986, 0, 1, 56};
    std::array<int, 7> std_array2{123, 34567, 6789634, 34567986, 0, 1, 56};
    s21::array<int, 7> s21_array2_move{1, 2};
    std::array<int, 7> std_array2_move{1, 2};
    s21_array2_move = std::move(s21_array2_move);
    s21_array2_move = std::move(s21_array2);
    s21_array2_move = s21_array2_move;
    std_array2_move = std::move(std_array2);
    EXPECT_TRUE(equel_array(s21_array2_move, std_array2_move));
    ASSERT_EQ(s21_array2.size(), std_array2.size());
    ASSERT_EQ(s21_array2.empty(), std_array2.empty());
}

TEST(array, front_function) {
    s21::array<char, 14> s21_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::array<char, 14> std_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    ASSERT_EQ(s21_array.front(), std_array.front());

    s21::array<std::string, 2> s21_array3{"Hello", "World!"};
    std::array<std::string, 2> std_array3{"Hello", "World!"};
    EXPECT_TRUE(equel_array(s21_array3, std_array3));
    ASSERT_EQ(s21_array3.front(), std_array3.front());
}


TEST(array, back_function) {
    s21::array<char, 14> s21_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    std::array<char, 14> std_array{'I', ' ', 'a', 'm', ' ', 'y', 'o', 'u', 'r', ' ', 'h', 'e', 'r', 'o'};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    ASSERT_EQ(s21_array.back(), std_array.back());

    s21::array<std::string, 2> s21_array3{"Hello", "World!"};
    std::array<std::string, 2> std_array3{"Hello", "World!"};
    EXPECT_TRUE(equel_array(s21_array3, std_array3));
    ASSERT_EQ(s21_array3.back(), std_array3.back());
}

TEST(array, const_iterator_access) {
    s21::array<char, 12> s21_array{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    std::array<char, 12> std_array{'S', 'e', 'g', 'm', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n'};
    s21::array<char, 12>::const_iterator s21_it = s21_array.begin();
    std::array<char, 12>::const_iterator std_it = std_array.begin();
    while (s21_it != s21_array.end()) {
        EXPECT_TRUE(*s21_it == *std_it);
        ++s21_it;
        ++std_it;
    }

    s21::array<char, 5> s21_array1{'f', 'a', 'u', 'l', 't'};
    std::array<char, 5> std_array1{'f', 'a', 'u', 'l', 't'};
    s21::array<char, 5>::const_iterator s21_it1 = s21_array1.end();
    std::array<char, 5>::const_iterator std_it1 = std_array1.end();
    --s21_it1;
    --std_it1;
    while (s21_it1 != s21_array1.begin()) {
        EXPECT_TRUE(*s21_it1 == *std_it1);
        --s21_it1;
        --std_it1;
    }
    EXPECT_TRUE(*s21_it1 == *std_it1);
}


TEST(array, max_sizef_function) {
    s21::array<int, 0> s21_array;
    std::array<int, 0> std_array;
    ASSERT_EQ(s21_array.max_size(), std_array.max_size());

    s21::array<std::string, 2> s21_array1{"Hello", "World!"};
    std::array<std::string, 2> std_array1{"Hello", "World!"};
    ASSERT_EQ(s21_array1.max_size(), std_array1.max_size());

    s21::array<int, 4> s21_array2;
    std::array<int, 4> std_array2;
    ASSERT_EQ(s21_array2.max_size(), std_array2.max_size());
}

TEST(array, swap_function) {
    s21::array<char, 4> s21_array{'l', 'o', 'v', 'e'};
    std::array<char, 4> std_array{'l', 'o', 'v', 'e'};
    s21::array<char, 4> s21_array_swap{'o'};
    std::array<char, 4> std_array_swap{'o'};
    s21_array.swap(s21_array_swap);
    std_array.swap(std_array_swap);
    EXPECT_TRUE(equel_array(s21_array, std_array));
    EXPECT_TRUE(equel_array(s21_array_swap, std_array_swap));

    s21::array<char, 4> s21_array1{'o'};
    std::array<char, 4> std_array1{'o'};
    s21::array<char, 4> s21_array1_swap{'l', 'o', 'v', 'e'};
    std::array<char, 4> std_array1_swap{'l', 'o', 'v', 'e'};
    s21_array1.swap(s21_array1_swap);
    std_array1.swap(std_array1_swap);
    EXPECT_TRUE(equel_array(s21_array1, std_array1));
    EXPECT_TRUE(equel_array(s21_array1_swap, std_array1_swap));

    s21::array<char, 4> s21_array2{'l', 'o', 'v', 'e'};
    std::array<char, 4> std_array2{'l', 'o', 'v', 'e'};
    s21::array<char, 4> s21_array2_swap;
    std::array<char, 4> std_array2_swap;
    s21_array2.swap(s21_array2_swap);
    std_array2.swap(std_array2_swap);
    EXPECT_TRUE(equel_array(s21_array2, std_array2));
    EXPECT_TRUE(equel_array(s21_array2_swap, std_array2_swap));

    s21::array<char, 4> s21_array3;
    std::array<char, 4> std_array3;
    s21::array<char, 4> s21_array3_swap{'l', 'o', 'v', 'e'};
    std::array<char, 4> std_array3_swap{'l', 'o', 'v', 'e'};
    s21_array3.swap(s21_array3_swap);
    std_array3.swap(std_array3_swap);
    EXPECT_TRUE(equel_array(s21_array3, std_array3));
    EXPECT_TRUE(equel_array(s21_array3_swap, std_array3_swap));
}


TEST(array, function_at) {
    s21::array<std::string, 6> s21_array{"access", "specified", "element", "with", "bounds", "checking"};
    std::array<std::string, 6> std_array{"access", "specified", "element", "with", "bounds", "checking"};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    ASSERT_EQ(s21_array.at(0), std_array.at(0));
    ASSERT_EQ(s21_array.at(1), std_array.at(1));
    ASSERT_EQ(s21_array.at(2), std_array.at(2));
    ASSERT_EQ(s21_array.at(3), std_array.at(3));
    ASSERT_EQ(s21_array.at(4), std_array.at(4));
    ASSERT_EQ(s21_array.at(5), std_array.at(5));
}

TEST(array, operator_square_brackets) {
    s21::array<std::string, 3> s21_array{"access", "specified", "element"};
    std::array<std::string, 3> std_array{"access", "specified", "element"};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    ASSERT_EQ(s21_array[0], std_array[0]);
    ASSERT_EQ(s21_array[1], std_array[1]);
    ASSERT_EQ(s21_array[2], std_array[2]);
}

TEST(array, function_data) {
    s21::array<int, 0> s21_array_empty;
    std::array<int, 0> std_array_empty;
    ASSERT_EQ(s21_array_empty.data(), nullptr);
    ASSERT_EQ(std_array_empty.data(), nullptr);
    EXPECT_TRUE(equel_array(s21_array_empty, std_array_empty));
    s21::array<int, 4> s21_array{1, 2234567, 21, 9874567};
    std::array<int, 4> std_array{1, 2234567, 21, 9874567};
    EXPECT_TRUE(equel_array(s21_array, std_array));
    ASSERT_NE(s21_array.data(), nullptr);
    ASSERT_NE(std_array.data(), nullptr);
}

TEST(array_test_suit, fill_test) {
    std::array<double, 4> std_array;
    s21::array<double, 4> s21_array;
    std_array.fill(555);
    s21_array.fill(555);
    for (size_t i = 0; i < std_array.size(); i++)
        ASSERT_EQ(std_array[i], s21_array[i]);
    ASSERT_EQ(std_array.size(), s21_array.size());;
}

/* --------------------------STACK TESTS --------------------------*/

template <class T>
bool equel_stack(s21::stack<T> s21_stack, std::stack<T> std_stack) {
    bool res = true;
    if ((s21_stack.size() != std_stack.size()) || (s21_stack.empty() != std_stack.empty()))
        res = false;
    if (res != false) {
        for (size_t i = 0; i < s21_stack.size(); i++) {
            if (std_stack.top() != s21_stack.top() )
                            res = false;
            std_stack.pop();
            s21_stack.pop();
        }
    }
    return res;
}


TEST(stack, default_constructor) {
    s21::stack<int> s21_stack;
    std::stack<int> std_stack;
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));

    s21::stack<double> s21_stack1;
    std::stack<double> std_stack1;
    EXPECT_TRUE(equel_stack(s21_stack1, std_stack1));

    s21::stack<std::string> s21_stack2;
    std::stack<std::string> std_stack2;
    EXPECT_TRUE(equel_stack(s21_stack2, std_stack2));

    s21::stack<char> s21_stack3;
    std::stack<char> std_stack3;
    EXPECT_TRUE(equel_stack(s21_stack3, std_stack3));

    s21::stack<std::pair<int, double>> s21_stack4;
    std::stack<std::pair<int, double>> std_stack4;
    EXPECT_TRUE(equel_stack(s21_stack4, std_stack4));

    s21::stack<std::set<int>> s21_stack5;
    std::stack<std::set<int>> std_stack5;
    EXPECT_TRUE(equel_stack(s21_stack5, std_stack5));
}


TEST(stack, initializer_stack_constructor) {
    s21::stack<int> s21_stack{1, 2, 3};
    std::stack<int> std_stack;
    std_stack.push(1);
    std_stack.push(2);
    std_stack.push(3);
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));

    s21::stack<char> s21_stack1{'l', 'o', 'v', 'e'};
    std::stack<char> std_stack1;
    std_stack1.push('l');
    std_stack1.push('o');
    std_stack1.push('v');
    std_stack1.push('e');
    EXPECT_TRUE(equel_stack(s21_stack1, std_stack1));

    s21::stack<std::pair<int, double>> s21_stack2{{42, 3.1415}, {89, 21}};
    std::stack<std::pair<int, double>> std_stack2;
    std_stack2.push({42, 3.1415});
    std_stack2.push({89, 21});
    EXPECT_TRUE(equel_stack(s21_stack2, std_stack2));

    s21::stack<std::string> s21_stack6{"Hello", "Me!"};
    std::stack<std::string> std_stack6;
    EXPECT_FALSE(equel_stack(s21_stack6, std_stack6));
}


TEST(stack, copy_constructor) {
    s21::stack<char> s21_stack{'l', 'o', 'v', 'e'};
    std::stack<char> std_stack;
    std_stack.push('l');
    std_stack.push('o');
    std_stack.push('v');
    std_stack.push('e');
    s21::stack<char> s21_stack_copy(s21_stack);
    std::stack<char> std_stack_copy(std_stack);
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    EXPECT_TRUE(equel_stack(s21_stack_copy, std_stack_copy));

    s21::stack<int> s21_stack1{1, 2, 3};
    std::stack<int> std_stack1;
    std_stack1.push(1);
    std_stack1.push(2);
    std_stack1.push(3);
    s21::stack<int> s21_stack1_copy(s21_stack1);
    std::stack<int> std_stack1_copy(std_stack1);
    EXPECT_TRUE(equel_stack(s21_stack1, std_stack1));
    EXPECT_TRUE(equel_stack(s21_stack1_copy, std_stack1_copy));
}

TEST(stack, move_constructor) {
    s21::stack<char> s21_stack{'l', 'o', 'v', 'e'};
    std::stack<char> std_stack;
    std_stack.push('l');
    std_stack.push('o');
    std_stack.push('v');
    std_stack.push('e');
    s21::stack<char> s21_stack_move(std::move(s21_stack));
    std::stack<char> std_stack_move(std::move(std_stack));
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    EXPECT_TRUE(equel_stack(s21_stack_move, std_stack_move));

    s21::stack<int> s21_stack1{1, 2, 3};
    std::stack<int> std_stack1;
    std_stack1.push(1);
    std_stack1.push(2);
    std_stack1.push(3);
    s21::stack<int> s21_stack1_move(std::move(s21_stack1));
    std::stack<int> std_stack1_move(std::move(std_stack1));
    EXPECT_TRUE(equel_stack(s21_stack1, std_stack1));
    EXPECT_TRUE(equel_stack(s21_stack1_move, std_stack1_move));
}

TEST(stack, move_to_less_buffer) {
    s21::stack<int> s21_stack{1, 2, 3};
    std::stack<int> std_stack;
    std_stack.push(1);
    std_stack.push(2);
    std_stack.push(3);
    s21::stack<int> s21_stack_move{1, 2};
    std::stack<int> std_stack_move;
    std_stack_move.push(1);
    std_stack_move.push(2);
    s21_stack_move = std::move(s21_stack);
    std_stack_move = std::move(std_stack);
    EXPECT_TRUE(equel_stack(s21_stack_move, std_stack_move));
    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, move_to_more_buffer) {
    s21::stack<int> s21_stack{1, 2};
    std::stack<int> std_stack;
    std_stack.push(1);
    std_stack.push(2);
    s21::stack<int> s21_stack_move{1, 2, 3, 4};
    std::stack<int> std_stack_move;
    std_stack_move.push(1);
    std_stack_move.push(2);
    std_stack_move.push(3);
    std_stack_move.push(4);
    s21_stack_move = std::move(s21_stack);
    std_stack_move = std::move(std_stack);
    EXPECT_TRUE(equel_stack(s21_stack_move, std_stack_move));
    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, pop_function) {
    s21::stack<char> s21_stack{'l', 'o', 'v', 'e'};
    std::stack<char> std_stack;
    std_stack.push('l');
    std_stack.push('o');
    std_stack.push('v');
    std_stack.push('e');
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.pop();
    std_stack.pop();
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.pop();
    std_stack.pop();
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.pop();
    std_stack.pop();
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.pop();
    std_stack.pop();
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
}

TEST(stack, push_function) {
    s21::stack<char> s21_stack;
    std::stack<char> std_stack;
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.push('l');
    std_stack.push('l');
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.push('o');
    std_stack.push('o');
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.push('v');
    std_stack.push('v');
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
    s21_stack.push('e');
    std_stack.push('e');
    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
}

TEST(stack, swap_function) {
    std::stack<char> std_stack1;
    std_stack1.push('b');
    std_stack1.push('e');
    std_stack1.push(' ');
    std_stack1.push('m');
    std_stack1.push('y');
    std_stack1.push(' ');
    std_stack1.push('g');
    std_stack1.push('i');
    std_stack1.push('r');
    std_stack1.push('l');
    std::stack<char> std_stack2;
    std_stack2.push('N');
    std_stack2.push('O');
    std_stack2.push('O');
    s21::stack<char> s21_stack1;
    s21_stack1.push('b');
    s21_stack1.push('e');
    s21_stack1.push(' ');
    s21_stack1.push('m');
    s21_stack1.push('y');
    s21_stack1.push(' ');
    s21_stack1.push('g');
    s21_stack1.push('i');
    s21_stack1.push('r');
    s21_stack1.push('l');
    s21::stack<char> s21_stack2;
    s21_stack2.push('N');
    s21_stack2.push('O');
    s21_stack2.push('O');
    std_stack1.swap(std_stack2);
    s21_stack1.swap(s21_stack2);
    EXPECT_TRUE(equel_stack(s21_stack1, std_stack1));
    EXPECT_TRUE(equel_stack(s21_stack2, std_stack2));
}

TEST(stack, top_function) {
    s21::stack<char> s21_stack1{'B', 'a', 'g'};
    std::stack<char> std_stack1;
    std_stack1.push('B');
    std_stack1.push('a');
    std_stack1.push('g');
    ASSERT_EQ(s21_stack1.top(), 'g');
    ASSERT_EQ(std_stack1.top(), s21_stack1.top());
    s21_stack1.pop();
    std_stack1.pop();
    ASSERT_EQ(s21_stack1.top(), 'a');
    ASSERT_EQ(std_stack1.top(), s21_stack1.top());
    s21_stack1.pop();
    std_stack1.pop();
    ASSERT_EQ(s21_stack1.top(), 'B');
    ASSERT_EQ(std_stack1.top(), s21_stack1.top());
}

/* --------------------------QUEUE TESTS --------------------------*/


template <class T>
bool equel_queue(s21::queue<T> s21_queue, std::queue<T> std_queue) {
    bool res = true;
    if ((s21_queue.size() != std_queue.size()) || (s21_queue.empty() != std_queue.empty()))
        res = false;
    if (res != false) {
        for (size_t i = 0; i < s21_queue.size(); i++) {
            if (std_queue.front() != s21_queue.front() )
                            res = false;
            std_queue.pop();
            s21_queue.pop();
        }
    }
    return res;
}

TEST(queue, default_constructor) {
    s21::queue<int> s21_queue;
    std::queue<int> std_queue;
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));

    s21::queue<double> s21_queue1;
    std::queue<double> std_queue1;
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));

    s21::queue<std::string> s21_queue2;
    std::queue<std::string> std_queue2;
    EXPECT_TRUE(equel_queue(s21_queue2, std_queue2));

    s21::queue<char> s21_queue3;
    std::queue<char> std_queue3;
    EXPECT_TRUE(equel_queue(s21_queue3, std_queue3));

    s21::queue<std::pair<int, double>> s21_queue4;
    std::queue<std::pair<int, double>> std_queue4;
    EXPECT_TRUE(equel_queue(s21_queue4, std_queue4));

    s21::queue<std::set<int>> s21_queue5;
    std::queue<std::set<int>> std_queue5;
    EXPECT_TRUE(equel_queue(s21_queue5, std_queue5));
}


TEST(queue, initializer_queue_constructor) {
    s21::queue<int> s21_queue{1, 2, 3};
    std::queue<int> std_queue;
    std_queue.push(1);
    std_queue.push(2);
    std_queue.push(3);
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));

    s21::queue<char> s21_queue1{'l', 'o', 'v', 'e'};
    std::queue<char> std_queue1;
    std_queue1.push('l');
    std_queue1.push('o');
    std_queue1.push('v');
    std_queue1.push('e');
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));

    s21::queue<std::pair<int, double>> s21_queue2{{42, 3.1415}, {89, 21}};
    std::queue<std::pair<int, double>> std_queue2;
    std_queue2.push({42, 3.1415});
    std_queue2.push({89, 21});
    EXPECT_TRUE(equel_queue(s21_queue2, std_queue2));

    s21::queue<std::string> s21_queue6{"Hello", "Me!"};
    std::queue<std::string> std_queue6;
    EXPECT_FALSE(equel_queue(s21_queue6, std_queue6));
}


TEST(queue, copy_constructor) {
    s21::queue<char> s21_queue{'l', 'o', 'v', 'e'};
    std::queue<char> std_queue;
    std_queue.push('l');
    std_queue.push('o');
    std_queue.push('v');
    std_queue.push('e');
    s21::queue<char> s21_queue_copy(s21_queue);
    std::queue<char> std_queue_copy(std_queue);
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    EXPECT_TRUE(equel_queue(s21_queue_copy, std_queue_copy));

    s21::queue<int> s21_queue1{1, 2, 3};
    std::queue<int> std_queue1;
    std_queue1.push(1);
    std_queue1.push(2);
    std_queue1.push(3);
    s21::queue<int> s21_queue1_copy(s21_queue1);
    std::queue<int> std_queue1_copy(std_queue1);
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));
    EXPECT_TRUE(equel_queue(s21_queue1_copy, std_queue1_copy));
}

TEST(queue, move_constructor) {
    s21::queue<char> s21_queue{'l', 'o', 'v', 'e'};
    std::queue<char> std_queue;
    std_queue.push('l');
    std_queue.push('o');
    std_queue.push('v');
    std_queue.push('e');
    s21::queue<char> s21_queue_move(std::move(s21_queue));
    std::queue<char> std_queue_move(std::move(std_queue));
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    EXPECT_TRUE(equel_queue(s21_queue_move, std_queue_move));

    s21::queue<int> s21_queue1{1, 2, 3};
    std::queue<int> std_queue1;
    std_queue1.push(1);
    std_queue1.push(2);
    std_queue1.push(3);
    s21::queue<int> s21_queue1_move(std::move(s21_queue1));
    std::queue<int> std_queue1_move(std::move(std_queue1));
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));
    EXPECT_TRUE(equel_queue(s21_queue1_move, std_queue1_move));
}

TEST(queue, move_to_less_buffer) {
    s21::queue<int> s21_queue{1, 2, 3};
    std::queue<int> std_queue;
    std_queue.push(1);
    std_queue.push(2);
    std_queue.push(3);
    s21::queue<int> s21_queue_move{1, 2};
    std::queue<int> std_queue_move;
    std_queue_move.push(1);
    std_queue_move.push(2);
    s21_queue_move = std::move(s21_queue);
    std_queue_move = std::move(std_queue);
    EXPECT_TRUE(equel_queue(s21_queue_move, std_queue_move));
    ASSERT_EQ(s21_queue.size(), std_queue.size());
    ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue, move_to_more_buffer) {
    s21::queue<int> s21_queue{1, 2};
    std::queue<int> std_queue;
    std_queue.push(1);
    std_queue.push(2);
    s21::queue<int> s21_queue_move{1, 2, 3, 4};
    std::queue<int> std_queue_move;
    std_queue_move.push(1);
    std_queue_move.push(2);
    std_queue_move.push(3);
    std_queue_move.push(4);
    s21_queue_move = std::move(s21_queue);
    std_queue_move = std::move(std_queue);
    EXPECT_TRUE(equel_queue(s21_queue_move, std_queue_move));
    ASSERT_EQ(s21_queue.size(), std_queue.size());
    ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue, pop_function) {
    s21::queue<char> s21_queue{'l', 'o', 'v', 'e'};
    std::queue<char> std_queue;
    std_queue.push('l');
    std_queue.push('o');
    std_queue.push('v');
    std_queue.push('e');
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.pop();
    std_queue.pop();
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.pop();
    std_queue.pop();
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.pop();
    std_queue.pop();
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.pop();
    std_queue.pop();
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
}

TEST(queue, push_function) {
    s21::queue<char> s21_queue;
    std::queue<char> std_queue;
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.push('l');
    std_queue.push('l');
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.push('o');
    std_queue.push('o');
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.push('v');
    std_queue.push('v');
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
    s21_queue.push('e');
    std_queue.push('e');
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));
}

TEST(queue, swap_function) {
    std::queue<char> std_queue1;
    std_queue1.push('b');
    std_queue1.push('e');
    std_queue1.push(' ');
    std_queue1.push('m');
    std_queue1.push('y');
    std_queue1.push(' ');
    std_queue1.push('g');
    std_queue1.push('i');
    std_queue1.push('r');
    std_queue1.push('l');
    std::queue<char> std_queue2;
    std_queue2.push('N');
    std_queue2.push('O');
    std_queue2.push('O');
    s21::queue<char> s21_queue1;
    s21_queue1.push('b');
    s21_queue1.push('e');
    s21_queue1.push(' ');
    s21_queue1.push('m');
    s21_queue1.push('y');
    s21_queue1.push(' ');
    s21_queue1.push('g');
    s21_queue1.push('i');
    s21_queue1.push('r');
    s21_queue1.push('l');
    s21::queue<char> s21_queue2;
    s21_queue2.push('N');
    s21_queue2.push('O');
    s21_queue2.push('O');
    std_queue1.swap(std_queue2);
    s21_queue1.swap(s21_queue2);
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));
    EXPECT_TRUE(equel_queue(s21_queue2, std_queue2));
}

TEST(queue, back_function) {
    s21::queue<char> s21_queue1;
    s21_queue1.push('B');
    s21_queue1.push('a');
    s21_queue1.push('g');
    std::queue<char> std_queue1;
    std_queue1.push('B');
    std_queue1.push('a');
    std_queue1.push('g');
    ASSERT_EQ(s21_queue1.front(), 'B');
    ASSERT_EQ(std_queue1.front(), s21_queue1.front());
    s21_queue1.pop();
    std_queue1.pop();
    ASSERT_EQ(s21_queue1.front(), 'a');
    ASSERT_EQ(std_queue1.front(), s21_queue1.front());
    s21_queue1.pop();
    std_queue1.pop();
    ASSERT_EQ(s21_queue1.front(), 'g');
    ASSERT_EQ(std_queue1.front(), s21_queue1.front());
}

TEST(queue, front_function) {
    s21::queue<char> s21_queue1{'B', 'a', 'g'};
    std::queue<char> std_queue1;
    std_queue1.push('B');
    std_queue1.push('a');
    std_queue1.push('g');
    ASSERT_EQ(s21_queue1.back(), 'g');
    ASSERT_EQ(std_queue1.back(), s21_queue1.back());
    s21_queue1.pop();
    std_queue1.pop();
    ASSERT_EQ(std_queue1.back(), s21_queue1.back());
    s21_queue1.pop();
    std_queue1.pop();
    ASSERT_EQ(std_queue1.back(), s21_queue1.back());
}

std::pair<const int, const char*> q0(0, "q0");
std::pair<const int, const char*> q1(1, "q1");
std::pair<const int, const char*> q2(2, "q2");
std::pair<const int, const char*> q3(3, "q3");
std::pair<const int, const char*> q4(4, "q4");
std::pair<const int, const char*> q01(0, "q01");
std::pair<const int, const char*> q111(1, "q111");
std::pair<const int, const char*> q21(2, "q21");
std::pair<const int, const char*> q31(3, "q31");
std::pair<const int, const char*> q41(4, "q41");

std::pair<const int, const char*> q5(5, "q5");
std::pair<const int, const char*> q555(5, "q555");

std::initializer_list<std::pair<const int, const char*>> list = {
    q2, q2, q2, q2, q0, q3, q1, q4, q21, q01, q31, q111, q41 };
std::initializer_list<std::pair<const int, const char*>> list2 = {
    q4, q3, q1, q0, q2, q2, q2, q2, q41, q31, q111, q01, q21 };

/* --ТЕСТЫ MAP И SET-- */
TEST(map_and_set, constructors) {
    s21::map<const int, const char*> map1_s21;
    s21::map<const int, const char*> map2_s21(list);
    s21::map<const int, const char*> map3_s21(map2_s21);
    s21::map<const int, const char*> map4_s21(std::move(map3_s21));

    std::map<const int, const char*> map1_std;
    std::map<const int, const char*> map2_std(list2);
    std::map<const int, const char*> map3_std(map2_std);
    std::map<const int, const char*> map4_std(std::move(map3_std));

    map2_s21.print("Test print");
    EXPECT_EQ(map1_s21.size(), map1_std.size());
    EXPECT_EQ(map2_s21.size(), map2_std.size());
    EXPECT_EQ(map3_s21.size(), map3_std.size());
    EXPECT_EQ(map4_s21.size(), map4_std.size());

    map1_s21 = std::move(map4_s21);
    map1_std = std::move(map4_std);

    EXPECT_EQ(map1_s21.size(), map1_std.size());
}

TEST(map_and_set, iterators) {
    s21::map<const int, const char*> map_s21(list);
    std::map<const int, const char*> map_std(list2);

    // общее тестирвоание
    auto iter_s21 = map_s21.begin();
    auto iter_std = map_std.begin();

    EXPECT_FALSE(iter_s21 != iter_s21);

    size_t x = 0;
    while (x < map_s21.size() && x < map_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }

    iter_s21 = map_s21.end();
    iter_std = map_std.end();
    x = 0;
    while (x < map_s21.size() && x < map_std.size()) {
        --iter_s21;
        --iter_std;
        EXPECT_EQ(*iter_s21, *iter_std);
        x += 1;
    }
}

TEST(map_and_set, filling) {
    s21::map<const int, const char*> map1_s21;
    std::map<const int, const char*> map1_std;
    s21::map<const int, const char*> map2_s21(list);
    std::map<const int, const char*> map2_std(list);

    EXPECT_EQ(map1_s21.empty(), map1_std.empty());
    EXPECT_EQ(map2_s21.empty(), map2_std.empty());

    EXPECT_EQ(map1_s21.size(), map1_std.size());
    EXPECT_EQ(map2_s21.size(), map2_std.size());

    EXPECT_EQ(map1_s21.max_size(), 461168601842738790);
    EXPECT_EQ(map2_s21.max_size(), 461168601842738790);
}

TEST(map_and_set, editing) {
    std::pair<const int, const char*> q6(6, "q6");
    std::pair<const int, const char*> q7(7, "q7");
    std::pair<const int, const char*> q8(8, "q8");
    std::pair<const int, const char*> q9(9, "q9");
    std::pair<const int, const char*> q10(10, "q10");
    std::pair<const int, const char*> q11(11, "q11");

    s21::map<const int, const char*> map1_s21(list);
    std::map<const int, const char*> map1_std(list2);
    s21::map<const int, const char*> map2_s21(list);
    std::map<const int, const char*> map2_std(list2);
    s21::map<const int, const char*> map3_s21;
    std::map<const int, const char*> map3_std;

    // проверка функции clear()
    map1_s21.clear();
    map1_std.clear();
    EXPECT_EQ(map1_s21.size(), map1_std.size());

    // првоерка функции insert() с учётом возравта пары <итератор, bool вставки>
    auto result_i5_s21 = map1_s21.insert(q5);
    auto result_i10_s21 = map1_s21.insert(q10);
    auto result_i6_s21 = map1_s21.insert(q6);
    auto result_i9_s21 = map1_s21.insert(q9);
    auto result_i7_s21 = map1_s21.insert(q7);
    auto result_i8_s21 = map1_s21.insert(q8);
    auto result_i11_s21 = map1_s21.insert(q11);

    auto result_i11_std = map1_std.insert(q11);
    auto result_i10_std = map1_std.insert(q10);
    auto result_i9_std = map1_std.insert(q9);
    auto result_i8_std = map1_std.insert(q8);
    auto result_i7_std = map1_std.insert(q7);
    auto result_i6_std = map1_std.insert(q6);
    auto result_i5_std = map1_std.insert(q5);

    // проверка неудачной вставки
    auto result_i55_s21 = map1_s21.insert(q5);
    auto result_i55_std = map1_std.insert(q5);
    EXPECT_EQ(*(result_i55_std.first), *(result_i55_s21.first));
    EXPECT_EQ(result_i55_std.second, result_i55_s21.second);

    EXPECT_EQ(*(result_i5_std.first), *(result_i5_s21.first));
    EXPECT_EQ(result_i5_std.second, result_i5_s21.second);
    EXPECT_EQ(*(result_i6_std.first), *(result_i6_s21.first));
    EXPECT_EQ(result_i6_std.second, result_i6_s21.second);
    EXPECT_EQ(*(result_i7_std.first), *(result_i7_s21.first));
    EXPECT_EQ(result_i7_std.second, result_i7_s21.second);
    EXPECT_EQ(*(result_i8_std.first), *(result_i8_s21.first));
    EXPECT_EQ(result_i8_std.second, result_i8_s21.second);
    EXPECT_EQ(*(result_i9_std.first), *(result_i9_s21.first));
    EXPECT_EQ(result_i9_std.second, result_i9_s21.second);
    EXPECT_EQ(*(result_i10_std.first), *(result_i10_s21.first));
    EXPECT_EQ(result_i10_std.second, result_i10_s21.second);
    EXPECT_EQ(*(result_i11_std.first), *(result_i11_s21.first));
    EXPECT_EQ(result_i11_std.second, result_i11_s21.second);

    auto iter_s21 = map1_s21.begin();
    auto iter_std = map1_std.begin();
    size_t x = 0;
    while (x < map1_s21.size() || x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map1_std.size());

    // проверка функции erase()
    // покрытие ветвлений erase()  и emplace()
    map3_s21.emplace(q3, q4, q5);

    map3_std.insert(q5);
    map3_std.insert(q4);
    map3_std.insert(q3);
    map3_s21.erase(--map3_s21.end());
    map3_std.erase(--map3_std.end());
    EXPECT_EQ(map3_s21.size(), map3_std.size());
    map3_s21.erase(map3_s21.begin());
    map3_std.erase(map3_std.begin());
    EXPECT_EQ(map3_s21.size(), map3_std.size());
    map3_s21.erase(map3_s21.begin());
    map3_std.erase(map3_std.begin());
    EXPECT_EQ(map3_s21.size(), map3_std.size());

    // общее тестирование
    map1_s21.erase(--(--(--iter_s21)));
    map1_std.erase(--(--(--iter_std)));

    iter_s21 = map1_s21.begin();
    iter_std = map1_std.begin();
    x = 0;
    while (x < map1_s21.size() || x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map1_std.size());

    // проверка функции swap
    map1_s21.swap(map2_s21);

    iter_s21 = map2_s21.begin();
    iter_std = map1_std.begin();
    x = 0;
    while (x < map2_s21.size() || x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map2_s21.size(), map1_std.size());

    iter_s21 = map1_s21.begin();
    iter_std = map2_std.begin();
    x = 0;
    while (x < map1_s21.size() || x < map2_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map2_std.size());

    // проверка функции merge()
    map1_s21.merge(map2_s21);
    map1_std.merge(map2_std);

    iter_s21 = map1_s21.begin();
    iter_std = map1_std.begin();
    x = 0;
    while (x < map1_s21.size() || x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map1_std.size());
    EXPECT_EQ(map2_s21.size(), map2_std.size());
}

TEST(map_and_set, view) {
    s21::map<const int, const char*> map1_s21(list);
    std::map<const int, const char*> map1_std(list);

    // проверка функции contains()
    int x = -100;
    while (x < 100) {
        EXPECT_EQ(map1_s21.contains(x), map1_std.contains(x));
        x += 1;
    }
}
/* ----------------------------------------------- */

/* --ТЕСТЫ SET-- */
TEST(set, editing) {
    // проверка возврата функции insert() и emplace()
    std::initializer_list<int> set_list = { -1, 0, 2, -100, 700, 300, -30, -29 };
    s21::set<int> set_s21;
    set_s21.emplace(-1, 0, 2, -100, 700, 300, -30, -29);
    std::set<int> set_std(set_list);

    EXPECT_EQ(*(set_s21.insert(0).first), *(set_std.insert(0).first));
    EXPECT_EQ((set_s21.insert(0).second), (set_std.insert(0).second));

    // проверка возврата функции merge()
    std::initializer_list<int> set_list2 = { -10, 0, 2, -1050, 7050, 300, -3000, -29 };
    s21::set<int> set2_s21(set_list2);
    std::set<int> set2_std(set_list2);
    set_s21.merge(set2_s21);
    set_std.merge(set2_std);

    EXPECT_EQ(set_s21.size(), set_std.size());
    EXPECT_EQ(set2_s21.size(), set2_std.size());
}

TEST(set, view) {
    // проверка функции find()
    std::initializer_list<int> set_list = { -1, 0, 2, -100, 700, 300, -30, -29 };
    s21::set<int> set_s21(set_list);
    std::set<int> set_std(set_list);

    auto x = set_list.begin();
    while (x < set_list.end()) {
        EXPECT_EQ(*set_s21.find(*x), *set_std.find(*x));
        x += 1;
    }
    // проверка поиска несуществующего элемента
    EXPECT_EQ(*(--set_s21.find(5)), *(--set_std.find(5)));
}
/* ----------------------------------------------- */

/* --ТЕСТЫ MAP-- */
TEST(map, view) {
    s21::map<const int, const char*> map1_s21(list);
    std::map<const int, const char*> map1_std(list);

    // проверка функции at
    map1_s21.at(1) = "qqaz";
    map1_std.at(1) = "qqaz";
    auto x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(map1_s21.at((*x).first), map1_std.at((*x).first));
        x += 1;
    }
    // проверка оператора []
    x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(map1_s21[(*x).first], map1_std[(*x).first]);
        x += 1;
    }

    map1_s21[0] = "q00111";
    map1_std[0] = "q00111";
    x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(map1_s21[(*x).first], map1_std[(*x).first]);
        x += 1;
    }
//    EXPECT_ANY_THROW(map1_s21[600]);
}

TEST(map, editing) {
    // проверка функции insert(const K& key, const M& obj)
    s21::map<int, const char*> map1_s21;
    std::map<int, const char*> map1_std;
    map1_s21.insert(0, "q0");
    map1_s21.insert(1, "q1");
    map1_s21.insert(2, "q2");
    map1_s21.insert(3, "q3");
    map1_s21.insert(4, "q4");
    map1_s21.insert(5, "q5");

    map1_std.insert_or_assign(5, "q5");
    map1_std.insert_or_assign(4, "q4");
    map1_std.insert_or_assign(3, "q3");
    map1_std.insert_or_assign(2, "q2");
    map1_std.insert_or_assign(1, "q1");
    map1_std.insert_or_assign(0, "q0");

    size_t x = 0;
    auto iter_s21 = map1_s21.begin();
    auto iter_std = map1_std.begin();
    while (x < map1_s21.size() && x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map1_std.size());

    // проверка функции insert_or_assign(const K& key, const M& obj)

    map1_s21.insert_or_assign(6, "q6");
    map1_s21.insert_or_assign(7, "q7");
    map1_s21.insert_or_assign(8, "q8");
    map1_s21.insert_or_assign(1, "q11");

    map1_std.insert_or_assign(6, "q6");
    map1_std.insert_or_assign(7, "q7");
    map1_std.insert_or_assign(8, "q8");
    map1_std.insert_or_assign(1, "q11");

    x = 0;
    iter_s21 = map1_s21.begin();
    iter_std = map1_std.begin();
    while (x < map1_s21.size() && x < map1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(map1_s21.size(), map1_std.size());
}
/* ----------------------------------------------- */

/* --ТЕСТЫ MULTISET-- */
TEST(multiset, constructors) {
    s21::multiset<std::pair<const int, const char*>> mset1_s21;
    s21::multiset<std::pair<const int, const char*>> mset2_s21(list);
    s21::multiset<std::pair<const int, const char*>> mset3_s21(mset2_s21);
    s21::multiset<std::pair<const int, const char*>> mset4_s21(std::move(mset3_s21));

    std::multiset<std::pair<const int, const char*>> mset1_std;
    std::multiset<std::pair<const int, const char*>> mset2_std(list2);
    std::multiset<std::pair<const int, const char*>> mset3_std(mset2_std);
    std::multiset<std::pair<const int, const char*>> mset4_std(std::move(mset3_std));

    EXPECT_EQ(mset1_s21.size(), mset1_std.size());
    EXPECT_EQ(mset2_s21.size(), mset2_std.size());
    EXPECT_EQ(mset3_s21.size(), mset3_std.size());
    EXPECT_EQ(mset4_s21.size(), mset4_std.size());

    mset1_s21 = std::move(mset4_s21);
    mset1_std = std::move(mset4_std);

    EXPECT_EQ(mset1_s21.size(), mset1_std.size());
}

TEST(multiset, iterators) {
    s21::multiset<std::pair<const int, const char*>> mset_s21(list);
    std::multiset<std::pair<const int, const char*>> mset_std(list2);

    // общее тестирвоание
    auto iter_s21 = mset_s21.begin();
    auto iter_std = mset_std.begin();

    EXPECT_FALSE(iter_s21 != iter_s21);

    size_t x = 0;
    while (x < mset_s21.size() && x < mset_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }

    iter_s21 = mset_s21.end();
    iter_std = mset_std.end();
    x = 0;
    while (x < mset_s21.size() && x < mset_std.size()) {
        --iter_s21;
        --iter_std;
        EXPECT_EQ(*iter_s21, *iter_std);
        x += 1;
    }
}

TEST(multiset, filling) {
    s21::multiset<std::pair<const int, const char*>> mset1_s21;
    std::multiset<std::pair<const int, const char*>> mset1_std;
    s21::multiset<std::pair<const int, const char*>> mset2_s21(list);
    std::multiset<std::pair<const int, const char*>> mset2_std(list);

    EXPECT_EQ(mset1_s21.empty(), mset1_std.empty());
    EXPECT_EQ(mset2_s21.empty(), mset2_std.empty());

    EXPECT_EQ(mset1_s21.size(), mset1_std.size());
    EXPECT_EQ(mset2_s21.size(), mset2_std.size());

    EXPECT_EQ(mset1_s21.max_size(), 461168601842738790);
    EXPECT_EQ(mset2_s21.max_size(), 461168601842738790);
}

TEST(multiset, editing) {
    std::pair<const int, const char*> q6(6, "q6");
    std::pair<const int, const char*> q7(7, "q7");
    std::pair<const int, const char*> q8(8, "q8");
    std::pair<const int, const char*> q9(9, "q9");
    std::pair<const int, const char*> q10(10, "q10");
    std::pair<const int, const char*> q11(11, "q11");

    s21::multiset<std::pair<const int, const char*>> mset1_s21(list);
    std::multiset<std::pair<const int, const char*>> mset1_std(list2);
    s21::multiset<std::pair<const int, const char*>> mset2_s21(list);
    std::multiset<std::pair<const int, const char*>> mset2_std(list2);
    s21::multiset<std::pair<const int, const char*>> mset3_s21;
    std::multiset<std::pair<const int, const char*>> mset3_std;

    // проверка функции clear()
    mset1_s21.clear();
    mset1_std.clear();
    EXPECT_EQ(mset1_s21.size(), mset1_std.size());

    // првоерка функции insert() с учётом возравта пары <итератор, bool вставки>
    auto result_i5_s21 = mset1_s21.insert(q5);
    auto result_i10_s21 = mset1_s21.insert(q10);
    auto result_i6_s21 = mset1_s21.insert(q6);
    auto result_i9_s21 = mset1_s21.insert(q9);
    auto result_i7_s21 = mset1_s21.insert(q7);
    auto result_i8_s21 = mset1_s21.insert(q8);
    auto result_i11_s21 = mset1_s21.insert(q11);

    auto result_i11_std = mset1_std.insert(q11);
    auto result_i10_std = mset1_std.insert(q10);
    auto result_i9_std = mset1_std.insert(q9);
    auto result_i8_std = mset1_std.insert(q8);
    auto result_i7_std = mset1_std.insert(q7);
    auto result_i6_std = mset1_std.insert(q6);
    auto result_i5_std = mset1_std.insert(q5);

    EXPECT_EQ(*result_i5_std, *result_i5_s21);
    EXPECT_EQ(*result_i6_std, *result_i6_s21);
    EXPECT_EQ(*result_i7_std, *result_i7_s21);
    EXPECT_EQ(*result_i8_std, *result_i8_s21);
    EXPECT_EQ(*result_i9_std, *result_i9_s21);
    EXPECT_EQ(*result_i10_std, *result_i10_s21);
    EXPECT_EQ(*result_i11_std, *result_i11_s21);

    auto iter_s21 = mset1_s21.begin();
    auto iter_std = mset1_std.begin();

    size_t x = 0;
    while (x < mset1_s21.size() && x < mset1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(mset1_s21.size(), mset1_std.size());

    // проверка функции erase()
    // покрытие ветвлений erase() + emplace()
    mset3_s21.emplace(q3, q4, q5);
    mset3_std.insert(q5);
    mset3_std.insert(q4);
    mset3_std.insert(q3);
    mset3_s21.erase(--mset3_s21.end());
    mset3_std.erase(--mset3_std.end());
    EXPECT_EQ(mset3_s21.size(), mset3_std.size());
    mset3_s21.erase(mset3_s21.begin());
    mset3_std.erase(mset3_std.begin());
    EXPECT_EQ(mset3_s21.size(), mset3_std.size());
    mset3_s21.erase(mset3_s21.begin());
    mset3_std.erase(mset3_std.begin());
    EXPECT_EQ(mset3_s21.size(), mset3_std.size());

    // общее тестирование
    mset1_s21.erase(--(--(--iter_s21)));
    mset1_std.erase(--(--(--iter_std)));
    iter_s21 = mset1_s21.begin();
    iter_std = mset1_std.begin();

    x = 0;
    while (x < mset1_s21.size() && x < mset1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(mset1_s21.size(), mset1_std.size());

    // проверка функции swap
    mset1_s21.swap(mset2_s21);

    iter_s21 = mset2_s21.begin();
    iter_std = mset1_std.begin();
    x = 0;
    while (x < mset2_s21.size() && x < mset1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(mset2_s21.size(), mset1_std.size());

    iter_s21 = mset1_s21.begin();
    iter_std = mset2_std.begin();
    x = 0;
    while (x < mset1_s21.size() && x < mset2_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(mset1_s21.size(), mset2_std.size());

    // проверка функции merge()
    mset2_s21.insert(q555);
    mset2_std.insert(q555);

    mset1_s21.merge(mset2_s21);
    mset1_std.merge(mset2_std);

    mset2_s21.insert(q555);
    mset2_std.insert(q555);

    mset1_s21.merge(mset2_s21);
    mset1_std.merge(mset2_std);

    iter_s21 = mset1_s21.begin();
    iter_std = mset1_std.begin();
    while (x < mset1_s21.size() && x < mset1_std.size()) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
        x += 1;
    }
    EXPECT_EQ(mset1_s21.size(), mset1_std.size());
    EXPECT_EQ(mset2_s21.size(), mset2_std.size());
}

TEST(multiset, view) {
    s21::multiset<std::pair<const int, const char*>> mset1_s21(list);
    std::multiset<std::pair<const int, const char*>> mset1_std(list);

    // проверка функции count()
    auto x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(mset1_s21.count(*x), mset1_std.count(*x));
        x += 1;
    }
    EXPECT_EQ(mset1_s21.count(q5), mset1_std.count(q5));

    // проверка функции find()
    x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(*mset1_s21.find(*x), *mset1_s21.find(*x));
        x += 1;
    }
    EXPECT_EQ(*(--mset1_s21.find(q5)), *(--mset1_std.find(q5)));

    // проверка функции contains()
    x = list.begin();
    while (x < list.end()) {
        EXPECT_EQ(mset1_s21.contains(*x), mset1_s21.contains(*x));
        x += 1;
    }
    EXPECT_EQ(mset1_s21.contains(q5), mset1_std.contains(q5));

    // проверка функции lower_bound()
    // в середине диапазон
    auto iter_std = mset1_std.lower_bound(q2);
    auto iter_s21 = mset1_s21.lower_bound(q2);

    EXPECT_EQ(*iter_s21, *iter_std);
    EXPECT_EQ(*(--iter_s21), *(--iter_std));
    EXPECT_EQ(*(++(++iter_s21)), *(++(++iter_std)));

    // несуществующее значение
    iter_std = mset1_std.lower_bound(q5);
    iter_s21 = mset1_s21.lower_bound(q5);

    EXPECT_EQ(*(--iter_s21), *(--iter_std));

    // крайнее правое значение
    iter_std = mset1_std.lower_bound(q41);
    iter_s21 = mset1_s21.lower_bound(q41);

    EXPECT_EQ(*iter_s21, *iter_std);
    EXPECT_EQ(*(--iter_s21), *(--iter_std));
//    EXPECT_ANY_THROW((*(++(++iter_s21))));

    // проверка функции upper_bound()
    // в середине диапазон
    iter_std = mset1_std.upper_bound(q2);
    iter_s21 = mset1_s21.upper_bound(q2);

    EXPECT_EQ(*iter_s21, *iter_std);
    EXPECT_EQ(*(--iter_s21), *(--iter_std));
    EXPECT_EQ(*(++(++iter_s21)), *(++(++iter_std)));

    // несуществующее значение
    iter_std = mset1_std.upper_bound(q5);
    iter_s21 = mset1_s21.upper_bound(q5);

//    EXPECT_ANY_THROW(*iter_s21);
    EXPECT_EQ(*(--iter_s21), *(--iter_std));

    // крайнее правое значение
    iter_std = mset1_std.upper_bound(q4);
    iter_s21 = mset1_s21.upper_bound(q4);

    EXPECT_EQ(*iter_s21, *iter_std);
    EXPECT_EQ(*(--iter_s21), *(--iter_std));
//    EXPECT_ANY_THROW((*(++(++iter_s21))));

    // проверка функции equal_range()
    // в середине диапазон
    auto y_s21 = mset1_s21.equal_range(q2);
    auto y_std = mset1_std.equal_range(q2);
    iter_s21 = y_s21.first;
    iter_std = y_std.first;
    while (iter_std != y_std.second) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
    }
    EXPECT_EQ(*(++iter_s21), *(++iter_std));

    // крайнее правое значение
    y_s21 = mset1_s21.equal_range(q41);
    y_std = mset1_std.equal_range(q41);
    iter_s21 = y_s21.first;
    iter_std = y_std.first;
    while (iter_std != y_std.second) {
        EXPECT_EQ(*iter_s21, *iter_std);
        ++iter_s21;
        ++iter_std;
    }
//    EXPECT_ANY_THROW(*iter_s21);
}

TEST(stack, emplace) {
    std::stack<int> std_stack;
    std_stack.push(1);
    std_stack.push(2);
    std_stack.push(3);
    std_stack.push(4);
    std_stack.emplace(567);
    std_stack.emplace(111);
    std_stack.emplace(98765);
    s21::stack<int> s21_stack;
    s21_stack.push(1);
    s21_stack.push(2);
    s21_stack.push(3);
    s21_stack.push(4);
    s21_stack.emplace_front(567, 111, 98765);

    EXPECT_TRUE(equel_stack(s21_stack, std_stack));
}

TEST(queue, emplace) {
    std::queue<double> std_queue;
    std_queue.push(1.3);
    std_queue.push(2.008);
    std_queue.push(3);
    std_queue.push(4);
    std_queue.emplace(567.0);
    std_queue.emplace(111.12345);
    std_queue.emplace(98765.90987);
    s21::queue<double> s21_queue;
    s21_queue.push(1.3);
    s21_queue.push(2.008);
    s21_queue.push(3);
    s21_queue.push(4);
    s21_queue.emplace_back(567.0, 111.12345, 98765.90987);
    EXPECT_TRUE(equel_queue(s21_queue, std_queue));

    std::queue<const char*> std_queue1;
    std_queue1.push("gg");
    std_queue1.emplace("hello");
    s21::queue<const char*> s21_queue1;
    s21_queue1.push("gg");
    s21_queue1.emplace_back("hello");
    EXPECT_TRUE(equel_queue(s21_queue1, std_queue1));
}

TEST(list, emplace_back) {
    std::list<double> std_list;
    std_list.push_back(1.3);
    std_list.push_back(2.008);
    std_list.push_back(3);
    std_list.push_back(4);
    std_list.emplace_back(567.0);
    std_list.emplace_back(111.12345);
    std_list.emplace_back(98765.90987);
    s21::list<double> s21_list;
    s21_list.push_back(1.3);
    s21_list.push_back(2.008);
    s21_list.push_back(3);
    s21_list.push_back(4);
    s21_list.emplace_back(567.0, 111.12345, 98765.90987);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    std::list<const char*> std_list1;
    std_list1.push_back("gg");
    std_list1.emplace_back("hello");
    s21::list<const char*> s21_list1;
    s21_list1.push_back("gg");
    s21_list1.emplace_back("hello");
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
}

TEST(list, emplace_front) {
    std::list<double> std_list;
    std_list.push_back(1.3);
    std_list.push_back(2.008);
    std_list.push_back(3);
    std_list.push_back(4);
    std_list.emplace_front(567.0);
    std_list.emplace_front(111.12345);
    std_list.emplace_front(98765.90987);
    s21::list<double> s21_list;
    s21_list.push_back(1.3);
    s21_list.push_back(2.008);
    s21_list.push_back(3);
    s21_list.push_back(4);
    s21_list.emplace_front(567.0, 111.12345, 98765.90987);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    std::list<const char*> std_list1;
    std_list1.push_back("gg");
    std_list1.emplace_front("hello");
    s21::list<const char*> s21_list1;
    s21_list1.push_back("gg");
    s21_list1.emplace_front("hello");
    EXPECT_TRUE(equel_list(s21_list1, std_list1));
}

TEST(list, emplace_function) {
    s21::list<std::string> s21_list{"Hello,", "World!"};
    std::list<std::string> std_list{"Hello,", "World!"};
    s21::list<std::string>::const_iterator s21_it = s21_list.cbegin();
    std::list<std::string>::const_iterator std_it = std_list.cbegin();
    s21_it = s21_list.emplace(s21_it, "Hi or");
    std_it = std_list.emplace(std_it, "Hi or");
    ASSERT_EQ(*s21_it, *std_it);
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.begin();
    std_it = std_list.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_it = s21_list.emplace(s21_it, "my dear");
    std_it = std_list.emplace(std_it, "my dear");
    EXPECT_TRUE(equel_list(s21_list, std_list));

    s21_it = s21_list.end();
    std_it = std_list.end();
    s21_it = s21_list.emplace(s21_it, "Be happy");
    std_it = std_list.emplace(std_it, "Be happy");
    EXPECT_TRUE(equel_list(s21_list, std_list));
}

TEST(vector, emplace_function) {
    s21::vector<std::string> s21_vector{"Hello,", "World!"};
    std::vector<std::string> std_vector{"Hello,", "World!"};
    s21::vector<std::string>::iterator s21_it = s21_vector.begin();
    std::vector<std::string>::iterator std_it = std_vector.begin();
    s21_it = s21_vector.emplace(s21_it, "Hi or");
    std_it = std_vector.emplace(std_it, "Hi or");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21_it = s21_vector.begin();
    std_it = std_vector.begin();
    ++s21_it;
    ++std_it;
    ++s21_it;
    ++std_it;
    s21_it = s21_vector.emplace(s21_it, "my dear");
    std_it = std_vector.emplace(std_it, "my dear");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));

    s21_it = s21_vector.end();
    std_it = std_vector.end();
    s21_it = s21_vector.emplace(s21_it, "Be happy");
    std_it = std_vector.emplace(std_it, "Be happy");
    EXPECT_TRUE(equel_vector_full(s21_vector, std_vector));
}

TEST(vector, emplace_back) {
    std::vector<double> std_vector;
    std_vector.push_back(1.3);
    std_vector.push_back(2.008);
    std_vector.push_back(3);
    std_vector.push_back(4);
    std_vector.emplace_back(567.0);
    std_vector.emplace_back(111.12345);
    std_vector.emplace_back(98765.90987);
    s21::vector<double> s21_vector;
    s21_vector.push_back(1.3);
    s21_vector.push_back(2.008);
    s21_vector.push_back(3);
    s21_vector.push_back(4);
    s21_vector.emplace_back(567.0, 111.12345, 98765.90987);
    EXPECT_TRUE(equel_vector(s21_vector, std_vector));

    std::vector<const char*> std_vector1;
    std_vector1.push_back("gg");
    std_vector1.emplace_back("hello");
    s21::vector<const char*> s21_vector1;
    s21_vector1.push_back("gg");
    s21_vector1.emplace_back("hello");
    EXPECT_TRUE(equel_vector(s21_vector1, std_vector1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
