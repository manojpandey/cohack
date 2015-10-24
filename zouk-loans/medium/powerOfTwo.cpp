#include <iostream>

using namespace std;

int isPowerOfTwo (unsigned int x) {
	return ((x != 0) && ((x & (~x + 1)) == x));
}

int main () {

	int num;
	cin >> num;
	if(isPowerOfTwo(num))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}