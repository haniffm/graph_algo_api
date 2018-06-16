#include <iostream>
#include <typeinfo>
#include <gtest/gtest.h>
#include "../main/Point.h"

using namespace graph_algo;

typedef double T;

TEST(PointTest, defaultConstructor) {
    Point<T> p;
    ASSERT_EQ(T(), p.getX());
    ASSERT_EQ(T(), p.getY());
    ASSERT_EQ(DEFAULT_EPSILON, p.getEpsilon());
}

TEST(PointTest, construct2Arg) {
    Point<T> p(2.2, 3.1);
    ASSERT_EQ(p.getX(), 2.2);
    ASSERT_EQ(p.getY(), 3.1);
    ASSERT_EQ(p.getEpsilon(), DEFAULT_EPSILON);
}

TEST(PointTest, copyConstructor) {
    Point<T> p1(2.2, 3.1);
    Point<T> p2 = p1;
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);

    ASSERT_EQ(p2.getX(), 2.2);
    ASSERT_EQ(p2.getY(), 3.1);
}

TEST(PointTest, assignment) {
    Point<T> p1(2.2, 3.1);
    Point<T> p2;
    p2 = p1;
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);

    ASSERT_EQ(p2.getX(), 2.2);
    ASSERT_EQ(p2.getY(), 3.1);
}

TEST(PointTest, destructor) {
    auto *p1 = new Point<T>();

    ASSERT_EQ(p1->getY(), T());
    ASSERT_EQ(p1->getX(), T());
    //TODO: how to check if the point is deleted?
    delete p1;
}

TEST(PointTest, lessThan) {
    Point<T> p0;
    Point<T> p1(2.2, 3.1);
    Point<T> p2(2.22, 3.1);
    Point<T> p3(2.23, 3.2);
    Point<T> p4(2.2, 3.3);
    Point<T> p5(2.3, 2.2);

    ASSERT_TRUE(p0 < p1);
    ASSERT_TRUE(p1 < p2);
    ASSERT_TRUE(p2 < p3);
    ASSERT_TRUE(p3 < p4);
    ASSERT_FALSE(p4 < p5);

    ASSERT_FALSE(p0 < p0);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, greaterThan) {
    Point<T> p0;
    Point<T> p1(2.2, 3.1);
    Point<T> p2(2.22, 3.1);
    Point<T> p3(2.23, 3.2);
    Point<T> p4(2.2, 3.3);
    Point<T> p5(2.3, 2.2);

    ASSERT_FALSE(p0 > p1);
    ASSERT_TRUE(p1 > p0);
    ASSERT_FALSE(p1 > p2);
    ASSERT_FALSE(p2 > p3);
    ASSERT_FALSE(p3 > p4);
    ASSERT_TRUE(p4 > p5);

    ASSERT_FALSE(p0 < p0);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, equalsTo) {
    Point<T> p0;
    Point<T> p00(0.0, 0.0);
    Point<T> p11(1.1, 1.1);
    Point<T> p11_2(1.1, 1.1);
    Point<T> p11_m1(1.1, -1.1);
    Point<T> p11_m2(-1.1, 1.1);
    Point<T> p11_m3(-1.1, -1.1);

    ASSERT_TRUE(p0 == p00);
    ASSERT_TRUE(p11 == p11_2);
    ASSERT_FALSE(p11 == p11_m1);
    ASSERT_FALSE(p11 == p11_m2);
    ASSERT_FALSE(p11 == p11_m3);
    ASSERT_FALSE(p0 == p11);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, lessThanOrEqualsTo) {
    Point<T> p0;
    Point<T> p00(0.0, 0.0);
    Point<T> p11(1.1, 1.1);
    Point<T> p11_2(1.1, 1.1);
    Point<T> p1(0.2, 1.1);
    Point<T> p2(-2.22, -3.1);

    ASSERT_TRUE(p0 <= p00);
    ASSERT_TRUE(p00 <= p0);
    ASSERT_TRUE(p11 <= p11_2);
    ASSERT_TRUE(p0 <= p11);
    ASSERT_FALSE(p11 <= p0);

    ASSERT_TRUE(p1 <= p11);
    ASSERT_TRUE(p11 <= p2);
    ASSERT_FALSE(p2 <= p11);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, greaterThanOrEqualsTo) {
    Point<T> p0;
    Point<T> p00(0.0, 0.0);
    Point<T> p11(1.1, 1.1);
    Point<T> p11_2(1.1, 1.1);
    Point<T> p1(0.2, 1.1);
    Point<T> p2(-2.22, -3.1);

    ASSERT_TRUE(p0 >= p00);
    ASSERT_TRUE(p00 >= p0);
    ASSERT_TRUE(p11 >= p11_2);
    ASSERT_FALSE(p0 >= p11);
    ASSERT_TRUE(p11 >= p0);

    ASSERT_FALSE(p1 >= p11);
    ASSERT_FALSE(p11 >= p2);
    ASSERT_TRUE(p2 >= p11);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, addition) {
    Point<T> p0;
    Point<T> p1(2.2, 3.1);
    Point<T> p2(2.22, 3.1);
    Point<T> p2_m1(2.22, -3.1);
    Point<T> p2_m2(-2.22, 3.1);
    Point<T> p2_m3(-2.22, -3.1);

    Point<T> c1 = p0 + p1;
    ASSERT_EQ(c1.getX(), 2.2);
    ASSERT_EQ(c1.getY(), 3.1);

    Point<T> c2 = p1 + p2;
    ASSERT_EQ(c2.getX(), 4.42);
    ASSERT_EQ(c2.getY(), 6.2);

    Point<T> c3 = p2 + p2_m1;
    ASSERT_EQ(c3.getX(), 4.44);
    ASSERT_EQ(c3.getY(), 0);

    Point<T> c4 = p2 + p2_m2;
    ASSERT_EQ(c4.getX(), 0);
    ASSERT_EQ(c4.getY(), 6.2);

    Point<T> c5 = p2 + p2_m3;
    ASSERT_EQ(c5.getX(), 0);
    ASSERT_EQ(c5.getY(), 0);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, subtraction) {
    Point<T> p0;
    Point<T> p1(2.2, 3.1);
    Point<T> p2(2.22, 3.1);
    Point<T> p2_m1(2.22, -3.1);
    Point<T> p2_m2(-2.22, 3.1);
    Point<T> p2_m3(-2.22, -3.1);

    Point<T> c1 = p0 - p1;
    ASSERT_EQ(c1.getX(), -2.2);
    ASSERT_EQ(c1.getY(), -3.1);

    Point<T> c2 = p1 - p2;
    ASSERT_NEAR(c2.getX(), -0.02, p1.getEpsilon());
    ASSERT_EQ(c2.getY(), 0);

    Point<T> c3 = p2 - p2_m1;
    ASSERT_EQ(c3.getX(), 0);
    ASSERT_EQ(c3.getY(), 6.2);

    Point<T> c4 = p2 - p2_m2;
    ASSERT_EQ(c4.getX(), 4.44);
    ASSERT_EQ(c4.getY(), 0);

    Point<T> c5 = p2 - p2_m3;
    ASSERT_EQ(c5.getX(), 4.44);
    ASSERT_EQ(c5.getY(), 6.2);

    //Untouched
    ASSERT_EQ(p0.getX(), 0.0);
    ASSERT_EQ(p0.getY(), 0.0);
}

TEST(PointTest, multiplicationWithScalar) {
    Point<T> p1(2.2, 3.1);
    Point<T> ps1 = p1 * 3;
    Point<T> ps2 = p1 * -2;

    ASSERT_NEAR(ps1.getX(), 6.6, ps1.getEpsilon());
    ASSERT_NEAR(ps1.getY(), 9.3, ps1.getEpsilon());

    ASSERT_NEAR(ps2.getX(), -4.4, ps2.getEpsilon());
    ASSERT_NEAR(ps2.getY(), -6.2, ps2.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
}

TEST(PointTest, divisionWithScalar) {
    Point<T> p1(12.6, 6.6);
    Point<T> ps1 = p1 / 3;
    Point<T> ps2 = p1 / -2;

    ASSERT_NEAR(ps1.getX(), 4.2, ps1.getEpsilon());
    ASSERT_NEAR(ps1.getY(), 2.2, ps1.getEpsilon());

    ASSERT_NEAR(ps2.getX(), -6.3, ps2.getEpsilon());
    ASSERT_NEAR(ps2.getY(), -3.3, ps2.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 12.6);
    ASSERT_EQ(p1.getY(), 6.6);
}

TEST(PointTest, distanceToPoint) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(2.2, 3.1);
    Point<T> p2(1.2, 3.1);
    Point<T> p2_m1(-1.2, 3.1);
    Point<T> p2_m2(1.2, -3.1);
    Point<T> p2_m3(-1.2, -3.1);
    double p0_p1 = p0 | p1;
    double p1_p2 = p1 | p2;
    double p2_p2_m1 = p2 | p2_m1;
    double p2_p2_m2 = p2 | p2_m2;
    double p2_p2_m3 = p2 | p2_m3;

    ASSERT_NEAR(p0_p1, 3.8013, p0.getEpsilon());
    ASSERT_NEAR(p1_p2, 1.0, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m1, 2.4, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m2, 6.2, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m3, 6.6483, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
}

TEST(PointTest, dotProduct) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(2.2, 3.1);
    Point<T> p2(1.2, 3.1);
    Point<T> p2_m1(-1.2, 3.1);
    Point<T> p2_m2(1.2, -3.1);
    Point<T> p2_m3(-1.2, -3.1);
    double p0_p1 = p0 ^p1;
    double p1_p2 = p1 ^p2;
    double p2_p2_m1 = p2 ^p2_m1;
    double p2_p2_m2 = p2 ^p2_m2;
    double p2_p2_m3 = p2 ^p2_m3;

    ASSERT_NEAR(p0_p1, 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1_p2, 12.25, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m1, 8.17, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m2, -8.17, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m3, -11.05, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
}

TEST(PointTest, crossProduct) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(2.2, 3.1);
    Point<T> p2(1.2, 3.1);
    Point<T> p2_m1(-1.2, 3.1);
    Point<T> p2_m2(1.2, -3.1);
    Point<T> p2_m3(-1.2, -3.1);
    double p0_p1 = p0 & p1;
    double p1_p2 = p1 & p2;
    double p2_p2_m1 = p2 & p2_m1;
    double p2_p2_m2 = p2 & p2_m2;
    double p2_p2_m3 = p2 & p2_m3;

    ASSERT_NEAR(p0_p1, 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1_p2, 3.1, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m1, 7.44, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m2, -7.44, p0.getEpsilon());
    ASSERT_NEAR(p2_p2_m3, 0, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
}

TEST(PointTest, lengthFromOrigin) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(2.2, 3.1);
    Point<T> p2(1.2, 3.1);
    Point<T> p3(4.1, 2.1);
    Point<T> p2_m1(-1.2, 3.1);
    Point<T> p2_m2(1.2, -3.1);
    Point<T> p2_m3(-1.2, -3.1);

    ASSERT_NEAR(p0.length(), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1.length(), 3.8013, p0.getEpsilon());
    ASSERT_NEAR(p2.length(), 3.3241, p0.getEpsilon());
    ASSERT_NEAR(p3.length(), 4.6065, p0.getEpsilon());
    ASSERT_NEAR(p2_m1.length(), 3.3241, p0.getEpsilon());
    ASSERT_NEAR(p2_m2.length(), 3.3241, p0.getEpsilon());
    ASSERT_NEAR(p2_m3.length(), 3.3241, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
}

TEST(PointTest, angleToOrigin) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(1, 1);
    Point<T> p2(2.2, 3.1);
    Point<T> p3(-2.2, 3.1);
    Point<T> p4(2.2, -3.1);
    Point<T> p5(-2.2, -3.1);

    ASSERT_NEAR(p0.angle(), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1.angle(), 0.7853, p0.getEpsilon());
    ASSERT_NEAR(p2.angle(), 0.9536, p0.getEpsilon());
    ASSERT_NEAR(p3.angle(), 2.1879, p0.getEpsilon());
    ASSERT_NEAR(p4.angle(), -0.9536, p0.getEpsilon());
    ASSERT_NEAR(p5.angle(), -2.1879, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 1);
    ASSERT_EQ(p1.getY(), 1);
}

TEST(PointTest, angleToCoordinates) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(1, 1);
    Point<T> p2(2.2, 3.1);
    Point<T> p3(-2.2, 3.1);
    Point<T> p4(2.2, -3.1);
    Point<T> p5(-2.2, -3.1);

    ASSERT_NEAR(p0.angle(0.0, 0.0), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1.angle(1.0, 1.0), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p2.angle(1.0, 1.0), 1.0516, p0.getEpsilon());
    ASSERT_NEAR(p3.angle(1.0, 1.0), 2.5608, p0.getEpsilon());
    ASSERT_NEAR(p4.angle(1.0, 1.0), -1.2860, p0.getEpsilon());
    ASSERT_NEAR(p5.angle(1.0, 1.0), -2.2335, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 1);
    ASSERT_EQ(p1.getY(), 1);
}

TEST(PointTest, angleToPoint) {
    Point<T> p0(0, 0, 0.0001);
    Point<T> p1(1, 1);
    Point<T> p2(2.2, 3.1);
    Point<T> p3(-2.2, 3.1);
    Point<T> p4(2.2, -3.1);
    Point<T> p5(-2.2, -3.1);

    ASSERT_NEAR(p0.angle(p0), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p1.angle(p1), 0.0, p0.getEpsilon());
    ASSERT_NEAR(p2.angle(p1), 1.0516, p0.getEpsilon());
    ASSERT_NEAR(p3.angle(p1), 2.5608, p0.getEpsilon());
    ASSERT_NEAR(p4.angle(p1), -1.2860, p0.getEpsilon());
    ASSERT_NEAR(p5.angle(p1), -2.2335, p0.getEpsilon());

    //Untouched
    ASSERT_EQ(p1.getX(), 1);
    ASSERT_EQ(p1.getY(), 1);
}

TEST(PointTest, setXY_epsilon) {
    Point<T> p1(2.2, 3.1);
    ASSERT_EQ(p1.getX(), 2.2);
    ASSERT_EQ(p1.getY(), 3.1);
    ASSERT_EQ(p1.getEpsilon(), DEFAULT_EPSILON);

    p1.setX(11.2);
    p1.setY(23.2);
    p1.setEpsilon(0.001);

    ASSERT_EQ(p1.getX(), 11.2);
    ASSERT_EQ(p1.getY(), 23.2);
    ASSERT_EQ(p1.getEpsilon(), 0.001);

    ASSERT_NE(p1.getX(), 2.2);
    ASSERT_NE(p1.getY(), 3.1);
}