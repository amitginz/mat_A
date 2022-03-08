
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces("@@@@@@@\n"
													"@-----@\n"
													"@-@@@-@\n"
													"@-@-@-@\n"
													"@-@@@-@\n"
													"@-----@\n"
													"@@@@@@@"));
	
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(0, 0, '$', '%'));
    
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@\n"));
	
}


TEST_CASE("Bad input") {
    CHECK_THROWS(mat(8, 3, '$', '%'));
    
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													"$+$\n"
													"$+$\n"
													"$+$\n"
													"$$$\n"));
	

}
TEST_CASE("Good input") {
	CHECK(nospaces(mat(5, 3, '$', '+')) == nospaces("$$$$$\n"
													"$+++$\n"
													"$$$$$\n"));
	
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(5, 3, '+', '$')) == nospaces("+++++\n"
													"+$$$+\n"
													"+++++\n"));
	
}
TEST_CASE("Good input") {
	CHECK(nospaces(mat(13, 5, '$', '+')) == nospaces("$$$$$$$$$$$$$\n"
													 "$+++++++++++$\n"
													 "$+$$$$$$$$$+$\n"
													 "$+++++++++++$\n"
													 "$$$$$$$$$$$$$\n"));
	
}

TEST_CASE("Bad input") {
	CHECK_THROWS(mat(2, 2, '$', '+'));
	
}

TEST_CASE("Bad input") {
	CHECK_THROWS(mat(4, 2, '$', '+'));
	
}

TEST_CASE("Bad output") {
	CHECK(nospaces(mat(5, 5, '$', '+')) != nospaces("$$$$$\n"
													"$+++$\n"
													"$$+$+\n"
													"+++$+\n"
													"+++++\n"));
	
}
TEST_CASE("Bad output") {
	CHECK(nospaces(mat(3, 3, '$', '+')) != nospaces("$$$\n"
													"$++\n"
													"$$+\n"));
	
}

TEST_CASE("assert num") {
	string a = nospaces(mat(3, 5, '$', '+'));
	CHECK(a.length() == 15);
	
}


TEST_CASE("assert num") {
	string a = nospaces(mat(5, 5, '$', '+'));
	CHECK(a.length() == 25);
	
}


TEST_CASE("assert num") {
	string a = nospaces(mat(5, 1, '$', '+'));
	CHECK(a.length() == 5);
	
}

TEST_CASE("assert num not equal") {
	string a = nospaces(mat(5, 1, '$', '+'));
	CHECK(a.length() != 10);
	
}

TEST_CASE("assert num not equal") {
	CHECK_THROWS(mat(5, 4, '$', '+'));
	
}


TEST_CASE("assert num") {
	string a = nospaces(mat(5, 7, '$', '+'));
	CHECK(a.length() == 35);
	
}

TEST_CASE("assert num") {
	string a = nospaces(mat(5, 7, '$', '+'));
	CHECK(a.length() != 34);
	
}

