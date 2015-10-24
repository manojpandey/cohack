/*
	Minimum number of checks required from N-floor with 2 eggs
	Ref: https://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle

	///
	n = number of test eggs available, n = 0, 1, 2, 3, ..., N − 1.
	k = number of (consecutive) floors yet to be tested, k = 0, 1, 2, ..., H − 1.

	W(n,k) = minimum number of checks required to identify the value of the critical floor under the worst-case scenario given that the process is in state s = (n,k).
	
	Then it can be shown that:
		W(n,k) = 1 + min{max(W(n − 1, x − 1), W(n,k − x)): x = 1, 2, ..., k }
		
		,with W(n,1) = 1 for all n > 0 and W(1,k) = k for all k. It is easy to solve this equation iteratively by systematically increasing the values of n and k.

	///

	Author: teamJSON
	Date: 10/24/2015 GMT+5.30

	Co-Hack Hackathon

	The MIT License (MIT)

	Copyright (c) 2015 Manoj Pandey

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

*/

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int minimChecks(int n, int k) {
 
    // Base case, if there is one egg
    // problem reduces to 1-egg problem, where
    // the result will always be n floors
	// as, W(1,k) = k for all k.
    if (n == 1)
        return k;
    
    // If there are no floors, then no checks needed. OR if there is
    // one floor, one trial needed.
    // as, W(n,1) = 1 for all n > 0
    if (k == 0 || k == 1)
        return k;
 
    int minim = INT_MAX, x, res;
 
    // Consider all droppings from 1st floor to kth floor and
    // return the minimimum of these values plus 1.
    for (x = 1; x <= k; x++) {
        res = max(minimChecks(n-1, x-1), minimChecks(n, k-x));
        if (res < minim)
            minim = res;
    }
 
    return minim + 1;
}
 
int main() {
    int n, k;
    cout << "Enter number of eggs and floors: ";
    cin >> n >> k;
    printf ("\nMinimum number of checks in worst case with %d eggs and "
             "%d floors is %d \n", n, k, minimChecks(n, k));
    return 0;
}