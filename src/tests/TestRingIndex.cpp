#include "../main/RingIndex.h"
#include <iostream>
#include <typeinfo>
#include <gtest/gtest.h>

using namespace graph_algo;

TEST(RingIndexTest, DefaultConst) {
    RingIndex<> ringIndex(10);
    ASSERT_EQ(11, ringIndex.size());
    ASSERT_EQ(10, ringIndex);
}

TEST(RingIndexTest, ConstructorAtIndex) {
    RingIndex<> ringIndex;
    ASSERT_EQ(1, ringIndex.size());
    ASSERT_EQ(0, ringIndex);
}

TEST(RingIndexTest, ConstructorAtIndexWithSize) {
    RingIndex<> ringIndex(9, 42);
    ASSERT_EQ(42, ringIndex.size());
    ASSERT_EQ(9, ringIndex);
}

TEST(RingIndexTest, ShouldThrowExceptionOnConstructorWithLowerSizeThanIndex) {
    try {
        RingIndex<> ringIndex(9, 8);
        FAIL() << "throwException() should throw an exception when index is higher than the ring size";
    } catch (RingIndexOutOfBoundException exception) {
        EXPECT_EQ(exception.what(), "The index of the ring must be [0, n-1] where n is the size of the ring. I.e. between 0 and size of the ring minus 1.");
    }
}

TEST(RingIndexTest, ShouldThrowExceptionOnConstructorWithSameSizeAsIndex) {
    try {
        RingIndex<> ringIndex(9, 9);
        FAIL() << "throwException() should throw an exception when index is higher than the ring size";
    } catch (RingIndexOutOfBoundException exception) {
        EXPECT_EQ(exception.what(), "The index of the ring must be [0, n-1] where n is the size of the ring. I.e. between 0 and size of the ring minus 1.");
    }
}

TEST(RingIndexTest, AssignmentIndexValue) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = 2;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(2, ringIndex);
}

TEST(RingIndexTest, AssignmentNegativeValue) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = -3;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(7, ringIndex);
}

TEST(RingIndexTest, AssignmentHighNegativeValue) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = -42;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(8, ringIndex);
}

TEST(RingIndexTest, AssignmentIndexOutOfBoundShouldWrap) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = 10;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);
}

TEST(RingIndexTest, AssignmentIndexLastRingValueShouldNOTWrap) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = 9;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(9, ringIndex);
}

TEST(RingIndexTest, AssignmentIndexWith3TimesTheSizeValueShouldWrap) {
    RingIndex<> ringIndex(0, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = 31;
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(1, ringIndex);
}

TEST(RingIndexTest, AssignmentCopy) {
    RingIndex<> ringIndex(0, 10);
    RingIndex<> ringIndexRef(2, 11);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(0, ringIndex);

    ringIndex = ringIndexRef;
    ASSERT_EQ(11, ringIndex.size());
    ASSERT_EQ(2, ringIndex);
    ASSERT_EQ(11, ringIndexRef.size());
    ASSERT_EQ(2, ringIndexRef);
}

TEST(RingIndexTest, Addition) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_EQ(5, ringIndex + 1);
    ASSERT_EQ(6, ringIndex + 2);
    ASSERT_EQ(7, ringIndex + 3);
    ASSERT_EQ(8, ringIndex + 4);
    ASSERT_EQ(9, ringIndex + 5);
    ASSERT_EQ(0, ringIndex + 6);
    ASSERT_EQ(1, ringIndex + 7);
    ASSERT_EQ(1, ringIndex + 17);
    ASSERT_EQ(2, ringIndex + 28);
    ASSERT_EQ(2, ringIndex + 10000008);

    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, Subtraction) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_EQ(3, ringIndex - 1);
    ASSERT_EQ(2, ringIndex - 2);
    ASSERT_EQ(1, ringIndex - 3);
    ASSERT_EQ(0, ringIndex - 4);
    ASSERT_EQ(9, ringIndex - 5);
    ASSERT_EQ(4, ringIndex - 10);
    ASSERT_EQ(3, ringIndex - 21);
    ASSERT_EQ(3, ringIndex - 100021);

    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, lessThanLeftHandSide) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_FALSE(ringIndex < 1);
    ASSERT_FALSE(ringIndex < 2);
    ASSERT_FALSE(ringIndex < 3);
    ASSERT_FALSE(ringIndex < 4);

    ASSERT_TRUE(ringIndex < 5);
    ASSERT_TRUE(ringIndex < 6);
    ASSERT_TRUE(ringIndex < 7);
    ASSERT_TRUE(ringIndex < 8);
    ASSERT_TRUE(ringIndex < 9);
    ASSERT_TRUE(ringIndex < 10);
    ASSERT_TRUE(ringIndex < 100);

    // untouched
    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, lessThanRightHandSide) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_TRUE(0 < ringIndex);
    ASSERT_TRUE(1 < ringIndex);
    ASSERT_TRUE(2 < ringIndex);
    ASSERT_TRUE(3 < ringIndex);

    ASSERT_FALSE(4 < ringIndex);
    ASSERT_FALSE(5 < ringIndex);
    ASSERT_FALSE(6 < ringIndex);
    ASSERT_FALSE(7 < ringIndex);
    ASSERT_FALSE(8 < ringIndex);
    ASSERT_FALSE(9 < ringIndex);

    ASSERT_FALSE(10   < ringIndex);
    ASSERT_FALSE(100  < ringIndex);
    ASSERT_FALSE(1000 < ringIndex);
    ASSERT_FALSE(1001 < ringIndex);

    // untouched
    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, lessThanRefrence) {
    RingIndex<> ringIndex(4, 10);
    RingIndex<> ringIndexRef_0(0, 10);
    RingIndex<> ringIndexRef_1(1, 10);
    RingIndex<> ringIndexRef_2(2, 10);
    RingIndex<> ringIndexRef_3(3, 10);
    RingIndex<> ringIndexRef_4(4, 10);
    RingIndex<> ringIndexRef_5(5, 10);
    RingIndex<> ringIndexRef_6(6, 10);
    RingIndex<> ringIndexRef_7(7, 10);
    RingIndex<> ringIndexRef_8(8, 10);
    RingIndex<> ringIndexRef_9(9, 10);
    RingIndex<> ringIndexRef_10(10, 20);
    RingIndex<> ringIndexRef_100(100, 110);
    RingIndex<> ringIndexRef_1000(1000, 1020);
    RingIndex<> ringIndexRef_1001(1001, 1020);
    RingIndex<> ringIndexRef_1002(1002, 1020);
    RingIndex<> ringIndexRef_1003(1003, 1020);
    RingIndex<> ringIndexRef_1004(1004, 1020);
    RingIndex<> ringIndexRef_1005(1005, 1020);
    RingIndex<> ringIndexRef_1009(1009, 1020);
    RingIndex<> ringIndexRef_1010(1010, 1020);


    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_FALSE(ringIndex < ringIndexRef_0);
    ASSERT_FALSE(ringIndex < ringIndexRef_1);
    ASSERT_FALSE(ringIndex < ringIndexRef_2);
    ASSERT_FALSE(ringIndex < ringIndexRef_3);
    ASSERT_FALSE(ringIndex < ringIndexRef_4);

    ASSERT_TRUE(ringIndex < ringIndexRef_5);
    ASSERT_TRUE(ringIndex < ringIndexRef_6);
    ASSERT_TRUE(ringIndex < ringIndexRef_7);
    ASSERT_TRUE(ringIndex < ringIndexRef_8);
    ASSERT_TRUE(ringIndex < ringIndexRef_9);

    ASSERT_TRUE(ringIndex < ringIndexRef_10  );
    ASSERT_TRUE(ringIndex < ringIndexRef_100 );
    ASSERT_TRUE(ringIndex < ringIndexRef_1000);
    ASSERT_TRUE(ringIndex < ringIndexRef_1001);

    ASSERT_TRUE(ringIndex < ringIndexRef_1005);
    ASSERT_TRUE(ringIndex < ringIndexRef_1009);

    // untouched
    ASSERT_EQ(4, ringIndex);
    ASSERT_EQ(0, ringIndexRef_0);
    ASSERT_EQ(1010, ringIndexRef_1010);
}

TEST(RingIndexTest, greaterThan) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_TRUE(ringIndex > 1);
    ASSERT_TRUE(ringIndex > 2);
    ASSERT_TRUE(ringIndex > 3);
    ASSERT_FALSE(ringIndex > 4);

    ASSERT_FALSE(ringIndex > 5);
    ASSERT_FALSE(ringIndex > 6);
    ASSERT_FALSE(ringIndex > 7);
    ASSERT_FALSE(ringIndex > 8);
    ASSERT_FALSE(ringIndex > 9);
    ASSERT_FALSE(ringIndex > 10);
    ASSERT_FALSE(ringIndex > 100);
    ASSERT_FALSE(ringIndex > 1000);
    ASSERT_FALSE(ringIndex > 1001);
    ASSERT_FALSE(ringIndex > 1004);

    // untouched
    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, equalsToValue) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    ASSERT_TRUE(4 == ringIndex);
    ASSERT_FALSE(14 == ringIndex);
    ASSERT_TRUE(ringIndex == 4);
    ASSERT_FALSE(ringIndex == 14);
    ASSERT_FALSE(ringIndex == 100004);
    ASSERT_FALSE(5 == ringIndex);
    ASSERT_FALSE(15 == ringIndex);
    ASSERT_FALSE(ringIndex == 5);
    ASSERT_FALSE(ringIndex == 15);
    ASSERT_FALSE(ringIndex == 100005);

    // untouched
    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, equalsToReference) {
    RingIndex<> ringIndex(4, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(4, ringIndex);

    RingIndex<> ringIndexRef_4(4, 10);
    RingIndex<> ringIndexRef_14(14, 20);
    RingIndex<> ringIndexRef_100004(100004, 100010);
    ASSERT_TRUE(ringIndexRef_4 == ringIndex);
    ASSERT_FALSE(ringIndexRef_14 == ringIndex);
    ASSERT_FALSE(ringIndexRef_100004 == ringIndex);
    ASSERT_TRUE(ringIndex == ringIndexRef_4);
    ASSERT_FALSE(ringIndex == ringIndexRef_14);
    ASSERT_FALSE(ringIndex == ringIndexRef_100004);

    RingIndex<> ringIndexRef_5(5, 10);
    RingIndex<> ringIndexRef_15(15, 20);
    RingIndex<> ringIndexRef_100005(100005, 100010);
    ASSERT_FALSE(ringIndexRef_5 == ringIndex);
    ASSERT_FALSE(ringIndexRef_15 == ringIndex);
    ASSERT_FALSE(ringIndexRef_100005 == ringIndex);
    ASSERT_FALSE(ringIndex == ringIndexRef_5);
    ASSERT_FALSE(ringIndex == ringIndexRef_15);
    ASSERT_FALSE(ringIndex == ringIndexRef_100005);

    // untouched
    ASSERT_EQ(4, ringIndex);
}

TEST(RingIndexTest, incrementSuffix) {
    RingIndex<> ringIndex(7, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(7, ringIndex);

    ASSERT_EQ(7, ringIndex++);
    ASSERT_EQ(8, ringIndex);

    ringIndex++;
    ASSERT_EQ(9, ringIndex);
    ringIndex++;
    ASSERT_EQ(0, ringIndex);
    ringIndex++;
    ASSERT_EQ(1, ringIndex);
}

TEST(RingIndexTest, incrementPrefix) {
    RingIndex<> ringIndex(7, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(7, ringIndex);

    ASSERT_EQ(8, ++ringIndex);
    ASSERT_EQ(8, ringIndex);

    ASSERT_EQ(9, ++ringIndex);
    ASSERT_EQ(0, ++ringIndex);
    ASSERT_EQ(1, ++ringIndex);
}

TEST(RingIndexTest, decrementSuffix) {
    RingIndex<> ringIndex(3, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(3, ringIndex);

    ASSERT_EQ(3, ringIndex--);
    ASSERT_EQ(2, ringIndex);

    ringIndex--;
    ASSERT_EQ(1, ringIndex);
    ringIndex--;
    ASSERT_EQ(0, ringIndex);
    ringIndex--;
    ASSERT_EQ(9, ringIndex);
}

TEST(RingIndexTest, decrementPrefix) {
    RingIndex<> ringIndex(3, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(3, ringIndex);

    ASSERT_EQ(2, --ringIndex);
    ASSERT_EQ(2, ringIndex);

    ASSERT_EQ(1, --ringIndex);
    ASSERT_EQ(0, --ringIndex);
    ASSERT_EQ(9, --ringIndex);
}

TEST(RingIndexTest, setLowerSize) {
    RingIndex<> ringIndex(42, 50);
    ASSERT_EQ(50, ringIndex.size());
    ASSERT_EQ(42, ringIndex);

    ringIndex.setSize(30);
    ASSERT_EQ(30, ringIndex.size());
    ASSERT_EQ(12, ringIndex);

    ringIndex.setSize(7);
    ASSERT_EQ(7, ringIndex.size());
    ASSERT_EQ(5, ringIndex);
}

TEST(RingIndexTest, setHigerSize) {
    RingIndex<> ringIndex(7, 10);
    ASSERT_EQ(10, ringIndex.size());
    ASSERT_EQ(7, ringIndex);

    ringIndex.setSize(21);
    ASSERT_EQ(21, ringIndex.size());
    ASSERT_EQ(7, ringIndex);

    ringIndex.setSize(42);
    ASSERT_EQ(42, ringIndex.size());
    ASSERT_EQ(7, ringIndex);
}
