/*
 * RingIndex.h
 *
 *  Created on: Dec 8, 2012
 *      Author: hfm
 */

#ifndef RINGINDEX_H_
#define RINGINDEX_H_

namespace graph_algo{

/**
 * A special list index, defined in such that it raps around instead of going out of bounds
 */
class RingIndex{
	public:
		RingIndex():mIndex(0),mSize(1){}

		RingIndex(const int v):mIndex(v),mSize(v+1){}

		RingIndex(const int v, const int ringSize):mIndex(v),mSize(ringSize){}

		RingIndex& operator=(const int v){
			mIndex = v;
			return *this;
		}

		RingIndex& operator=(const RingIndex& ref){
			mIndex = ref.mIndex;
			mSize = ref.mSize;
			return *this;
		}

		int operator+(int v) const {
			int t;
			if(mIndex >= mSize-1)
				t = 0;
			else
				t = mIndex+1;
			return t;
		}

		int operator-(const int v) const {
			if(mIndex == 0) return mSize-1; return mIndex-1;
		}

		operator int() const {return mIndex;}

		bool operator<(int v) const {
			return mIndex < v;
		}

		bool operator==(int v) const{
			return v == mIndex;
		}

		bool operator==(const RingIndex &other) const{
			return mIndex == other.mIndex;
		}

		const int operator++(int){ /* Suffix */
			int tmp = mIndex;
			this->operator++();
			return tmp;
		}

		const int operator++(){ /* prefix */
			if(mIndex>= mSize-1){ mIndex=0; }
			else{ ++mIndex;}
			return mIndex;
		}

		const int operator--(int){ /* Suffix */
			int tmp = mIndex;
			this->operator--();
			return tmp;
		}

		const int operator--(){ /* prefix */
			if(mIndex == 0){ mIndex=mSize-1; }
			else{ --mIndex;}
			return mIndex;
		}

		void setRingSize(int ringSize){
			mSize = ringSize;
		}

		const int getRingSize() const {
			return mSize;
		}

	private:
		int mIndex;
		int mSize;

};

}; //namespace graph_algo


#endif /* RINGINDEX_H_ */
