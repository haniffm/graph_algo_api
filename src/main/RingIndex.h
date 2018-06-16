/*
 * RingIndex.h
 *
 *  Created on: Dec 8, 2012
 *      Author: hfm
 */

#ifndef RINGINDEX_H_
#define RINGINDEX_H_

#include <assert.h>
#include <exception>
#include <cmath>
#include <iostream>

namespace graph_algo {

    struct RingIndexOutOfBoundException : public std::exception {
        const char *what() const throw() {
            return "The index of the ring must be [0, n-1] where n is the size of the ring. I.e. between 0 and size of the ring minus 1.";
        }

    };

/**
 * A special list index, defined in such that it raps around instead of going out of bounds
 */
    template<class T = int>
    class RingIndex {
    public:
        RingIndex() : mIndex(0), mSize(1) {}

        RingIndex(const T v) : mIndex(v), mSize(v + 1) {}

        RingIndex(const T v, const T ringSize) : mIndex(v), mSize(ringSize) {
            if (ringSize <= v) throw RingIndexOutOfBoundException();
        }

        RingIndex &operator=(const T v) {
            if (v >= mSize) {
                mIndex = v % mSize;
            } else if (v >= 0) {
                mIndex = v;
            } else {
                mIndex = (mSize + (v % mSize));
            }
            return *this;
        }

        RingIndex &operator=(const RingIndex &ref) {
            mIndex = ref.mIndex;
            mSize = ref.mSize;
            return *this;
        }

        T operator+(T v) const {
            T t = mIndex + v;
            if (t >= mSize)
                t = t % mSize;
            return t;
        }

        T operator-(const T v) const {
            if (mIndex - v < 0) {
                return mSize - (std::abs(mIndex - v) % mSize);
            }
            return mIndex - v;
        }

        operator T() const { return mIndex; }

        friend inline bool operator<(const T &lhs, const RingIndex &rhs) {
            return lhs < rhs.mIndex;
        }

        friend inline bool operator<(const RingIndex &lhs, const T &rhs) {
            return lhs.mIndex < rhs;
        }

        inline bool operator<(const RingIndex &other) const {
            return mIndex < other.mIndex;
        }

        friend inline bool operator>(const T &lhs, const RingIndex &rhs) {
            return lhs > rhs.mIndex;
        }

        friend inline bool operator>(const RingIndex &lhs, const T &rhs) {
            return lhs.mIndex > rhs;
        }

        inline bool operator>(const RingIndex &other) const {
            return mIndex > other.mIndex;
        }

        friend inline bool operator==(const T &lhs, const RingIndex &rhs) {
            return lhs == rhs.mIndex;
        }

        friend inline bool operator==(const RingIndex &lhs, const T &rhs) {
            return rhs == lhs.mIndex;
        }

        inline bool operator==(const RingIndex &other) const {
            return other.mIndex == mIndex;
        }

        const T operator++(T) { /* Suffix */
            T tmp = mIndex;
            this->operator++();
            return tmp;
        }

        const T operator++() { /* prefix */
            if (mIndex >= mSize - 1) { mIndex = 0; }
            else { ++mIndex; }
            return mIndex;
        }

        const T operator--(T) { /* Suffix */
            T tmp = mIndex;
            this->operator--();
            return tmp;
        }

        const T operator--() { /* prefix */
            if (mIndex == 0) { mIndex = mSize - 1; }
            else { --mIndex; }
            return mIndex;
        }

        void setSize(T ringSize) {
            if (mIndex >= ringSize) {
                mIndex %= ringSize;
            }
            mSize = ringSize;
        }

        const T size() const {
            return mSize;
        }

    private:
        T mIndex;
        T mSize;

    };

}; //namespace graph_algo


#endif /* RINGINDEX_H_ */
