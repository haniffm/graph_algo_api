//============================================================================
// Name        : graph_algo_api.cpp
// Author      : HFM
// Version     :
// Copyright   : GPLv3
// Description : graph_algo api in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Point.h"
#include "RingIndex.h"
#include "TestPoint.h"

using namespace std;
using namespace graph_algo;

int main() {
	cout << "######## Testing Point ########\n" << endl; // prints
	TestPoint tp;
	tp.TestAll();
	cout << "\n######## Done testing Point ########" << endl;

	RingIndex i(42, 100);

	Point<double> p(1.0,1.0);


	return 0;
}
