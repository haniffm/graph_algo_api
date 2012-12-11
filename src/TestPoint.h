/*
 * TestPoint.h
 *
 *  Created on: Dec 10, 2012
 *      Author: hfm
 */

#ifndef TESTPOINT_H_
#define TESTPOINT_H_

#include "Point.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;
namespace graph_algo{

class TestPoint{
public:

	typedef double T;

	void TestPointDefConst(){
		cout << "DefConst...";
		Point<T> p;
		assert(p.getX() == T());
		assert(p.getY() == T());
		assert(p.getEpsilon() == DEFAULT_EPSILON);
		cout << "Done!" << endl;
	}

	void TestPointConst2arg(){
		cout << "Const2Arg...";
		Point<T> p(2.2,3.1);
		assert(p.getX() == 2.2);
		assert(p.getY() == 3.1);
		assert(p.getEpsilon() == DEFAULT_EPSILON);
		cout << "Done!" << endl;
	}

	void TestPointCopyConst(){
		cout << "CopyConst...";

		Point<T> p1(2.2,3.1);
		Point<T> p2 = p1;
		assert(p1.getX() == 2.2);
		assert(p1.getY() == 3.1);

		assert(p2.getX() == 2.2);
		assert(p2.getY() == 3.1);

		cout << "Done!" << endl;
	}

	void TestPointAssignment(){
		cout << "Assignment...";

		Point<T> p1(2.2,3.1);
		Point<T> p2;
		p2 = p1;
		assert(p1.getX() == 2.2);
		assert(p1.getY() == 3.1);

		assert(p2.getX() == 2.2);
		assert(p2.getY() == 3.1);


		cout << "Done!" << endl;
	}

	void TestPointDestructor(){
		cout << "Destructor...";
		Point<T>* p1 = new Point<T>();

		assert(p1->getX() == T());
		assert(p1->getY() == T());

		delete p1;

		cout << "Done!" << endl;
	}

	void TestPointLessThan_GreaterThan_Equals(){
		cout << "LessThan_GreaterThan_Equals...";

		Point<T> p0;
		Point<T> p1(2.2, 3.1);
		Point<T> p2(2.22, 3.1);
		Point<T> p3(2.23, 3.2);
		Point<T> p4(2.0, 3.3);
		Point<T> p5(2.3, 2.2);

//		assert(p0 < );
		assert(p1.getY() == 3.1);

		cout << "Done!" << endl;
	}

	void TestPointAddition(){
		cout << "Addition...";
		cout << "Done!" << endl;

	}

	void TestPointSubtraction(){
		cout << "Subtraction...";
		cout << "Done!" << endl;

	}

	void TestPointScalarMult(){
		cout << "ScalarMult...";
		cout << "Done!" << endl;

	}

	void TestPointScalarDiv(){
		cout << "ScalarDiv...";
		cout << "Done!" << endl;

	}

	void TestPointDistanceToPoint(){
		cout << "DistanceToPoint...";
		cout << "Done!" << endl;

	}

	void TestPointDotProduct(){
		cout << "DotProduct...";
		cout << "Done!" << endl;

	}

	void TestPointCrossProduct(){
		cout << "CrossProduct...";
		cout << "Done!" << endl;

	}

	void TestPointLength(){
		cout << "Length...";
		cout << "Done!" << endl;

	}

	void TestPointAngle(){
		cout << "Angle...";
		cout << "Done!" << endl;

	}

	void TestPointAngleToCoordinate(){
		cout << "AngleToCoordinate...";
		cout << "Done!" << endl;

	}

	void TestPointAngleToPoint(){
		cout << "AngleToPoint...";
		cout << "Done!" << endl;

	}

	void TestPointSetGetXY_Epsilon(){
		cout << "SetGetXY_Epsilon...";
		cout << "Done!" << endl;
	}

	void TestAll(){
		TestPointDefConst();
		TestPointConst2arg();
		TestPointCopyConst();
		TestPointAssignment();
		TestPointDestructor();
		TestPointLessThan_GreaterThan_Equals();
		TestPointAddition();
		TestPointSubtraction();
		TestPointScalarMult();
		TestPointScalarDiv();
		TestPointDistanceToPoint();
		TestPointDotProduct();
		TestPointCrossProduct();
		TestPointLength();
		TestPointAngle();
		TestPointAngleToCoordinate();
		TestPointAngleToPoint();
		TestPointSetGetXY_Epsilon();
	}


};//class TestPoint

};//namespace graph_algo




#endif /* TESTPOINT_H_ */
