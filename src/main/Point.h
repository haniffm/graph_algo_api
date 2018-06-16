#ifndef POINT_H_
#define POINT_H_

#include <cmath>

/**
 * This Point class can be used to for geometrical calculation.
 * You can do the following operations:
 * - addition
 * - subtraction
 * - scalar multiplication and division
 * - scalar product
 * - cross product
 * - get length of the vector (from origo)
 * - get distance to another point
 * - the angle of this point/vector
 *
 * Created on: Dec 10, 2012
 *
 * @version 0.9
 * @author Hanif Farahmand Mokarremi
 *
 */

namespace graph_algo{

static const double DEFAULT_EPSILON = 0.00000000001;

template<class T = double>
class Point{
	public:

		/**
		 * Default constructor
		 * Sets all values to 0.0.
		 */
		Point():mX(T()),mY(T()),mEPSILON(DEFAULT_EPSILON){}

		/**
		 * Constructor, sets x and y position
		 */
		Point(const T x, const T y):mX(x),mY(y),mEPSILON(DEFAULT_EPSILON){}

		/**
		 * Constructor, sets x, y positions and epsilon
		 */
		Point(const T x, const T y, const T epsilon):mX(x),mY(y),mEPSILON(epsilon){}

		/**
		 * Copy constructor
		 */
		Point(const Point& other){
			mX = other.mX;
			mY = other.mY;
			mEPSILON = other.mEPSILON;
		}

		/**
		 * Assignment operator
		 */
		virtual Point& operator=(const Point& other){
			if(&mX == &other.mX)
				return *this;

			this->~Point();
			new (this) Point(other);

			return *this;
		}

		/**
		 * Destructor
		 */
		virtual ~Point(){}

		/**
		 * Compare (less than) operator
		 * Checks if this points distance from origin is less than other points distance from origin
		 * 		if so returns true,
		 * 		otherwise false
		 */
		virtual bool operator<(const Point &p) const {
			return length() < p.length() && (fabs(length() - p.length()) > std::max(mEPSILON, p.mEPSILON));
		}

		virtual bool operator>(const Point &p) const {
			return length() > p.length() && (fabs(length() - p.length()) > std::max(mEPSILON, p.mEPSILON));
		}

		virtual bool operator==(const Point&p) const {
			return(fabs(mX - p.mX) < mEPSILON  && fabs(mY - p.mY) < mEPSILON);
		}

		virtual bool operator<=(const Point &p) const {
			return (operator==(p) || operator<(p));
		}

		virtual bool operator>=(const Point &p) const {
			return (operator==(p) || operator>(p));
		}

		/**
		 * Point-wise addition
		 * @param p The other point which we want to add to
		 * @return Returns a new Point which is the sum of the two points
		 */
		virtual Point operator+(const Point &p) const {
			return Point(mX+p.mX, mY+p.mY);
		}

		/**
		 * Point-wise subtraction
		 * @param p The other point which we want this point to be subtracted from.
		 * @return Returns a new Point which the result of this point minus the other point
		 */
		virtual Point operator-(const Point &p) const {
			return Point(mX-p.mX, mY-p.mY);
		}

		/**
		 * Multiplication with a scalar
		 * @param scalar The scalar whom we want to multiply this point with.
		 * @return Returns a new Point which is this point multiplicated by the scalar.
		 */
		virtual Point operator*(T scalar) const {
			return Point(mX*scalar, mY*scalar);
		}

		/**
		 * Division with a scalar
		 * @param scalar The scalar whom we want to divide this point with.
		 * @return Returns a new Point which is this point divided by the scalar.
		 */
		virtual Point operator/(T scalar) const {
			return Point(mX/scalar, mY/scalar);
		}

		/**
		 * Distance of p and this point.
		 * @param p The other point.
		 * @return Returns the distance between this point and the other point.
		 */
		virtual T operator|(const Point& p) const {
			return hypot(p.mX-mX, p.mY-mY);
		}

		/**
		 * Calculates the scalar product (= dot product) of two points.
		 * @param p The other point which we want to do scalar product with.
		 * @return Returns the scalar product of this point and the other point p.
		 */
		virtual T operator^(const Point& p) const {
			return 	mX * p.mX + mY * p.mY;
		}

		/**
		 * Calculates the cross product of two points/vectors.
		 * @param p The other point which we want to do cross product with.
		 * @return Returns the cross product of this point and the other point p.
		 */
		virtual T operator&(const Point& p) const {
			return (mX * p.mY) - (p.mX * mY);
		}

		/**
		 * Length of the vector
		 * @return Returns the length of the vector (or this point from origin).
		 */
		virtual double length() const {
			return hypot(mX, mY);
		}

		/**
		 * The angle of this point in relation to the origin.
		 * @return Returns the angle of this point in relation to the origin.
		 */
		virtual double angle() const {
			return angle(T(), T());
		}

		/**
		 * The angle of this point in relation to another points coordinates
		 * @param cX The x-coordinate for the center-point
		 * @param cY The y-coordinate for the center-point
		 * @return Returns the angle between this point in relation to the given coordinates.
		 */
		virtual double angle(T cX, T cY) const{
			return atan2(mY-cY, mX-cX);
		}

		/**
		 * The angle of this point in relation to another point.
		 * @param p The point that we want to calculate the angle from. (This is usually the origin)
		 * @return Returns the angle between this point and the given point.
		 */
		virtual double angle(const Point& p) const {
			return angle(p.mX, p.mY);
		}

		virtual void setX(double x) {mX = x;}
		virtual void setY(double y) {mY = y;}
		virtual void setEpsilon(double epsilon) {mEPSILON = epsilon;}

		virtual T getX() const {return mX;}
		virtual T getY() const {return mY;}
		virtual T getEpsilon() const { return mEPSILON;}

	private:
		T mX, mY, mEPSILON;


}; // Point class
};// namespace graph_algo



#endif /* POINT_H_ */
