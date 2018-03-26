/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 8-11 Coins
*
******************************************************************************************************/
#include <iostream>

using namespace std;
int count = 0;

void findLessThan5Comb(int val) {
	count++; return;
}

void findLessThan10Comb(int val) {
	if (val == 0) { count++; return; }
	int maxNumOf5 = val / 5;
	for (int i = 0; i <= maxNumOf5; i++) {
		findLessThan5Comb(val - i * 5);
	}
}

void findLessThan25Comb(int val) {
	if (val == 0) { count++; return; }
	int maxNumOf10 = val / 10;
	for (int i = 0; i <= maxNumOf10; i++) {
		findLessThan10Comb(val - i * 10);
	}
}

void findCoinsCombinations(int val) {
	if (val == 0) { count++; return; }
	int maxNumOf25 = val / 25;
	for (int i = 0; i <= maxNumOf25; i++) {
		findLessThan25Comb(val - i * 25);
	}
}

int main() {
  int val;
  cin >> val;
  findCoinsCombinations(val);
  cout << "Number of ways of giving out "<< val << " cents using 25/10/5/1 is "<< count << endl;
}