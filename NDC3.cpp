#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentsize;
	int currentcapacity;

	void resize() {
		int newcapacity = currentcapacity * 2; //용량을 두 배로 확장
		T* newdata = new T[newcapacity];
		copy(data, data + currentsize, newdata);
		delete[] data;	// 기존 배열 삭제

		data = newdata; // 포인터 및 용량 갱신
		currentcapacity = newcapacity;
	}

public:
	SimpleVector() : currentcapacity(10), currentsize(0) {
		data = new T[currentcapacity];
	} // 용량을 10으로 초기화


	SimpleVector(int capacity) : currentcapacity(capacity), currentsize(0) {
		if (currentcapacity <= 0) {
			currentcapacity = 10; // 기본용량
		}
		data = new T[currentcapacity];
	} // 특정 용량을 받는 생성자

	~SimpleVector() {
		delete[] data;
	} // 소멸자

	void push_back(const T& value) {
		if (currentsize < currentcapacity) {
			data[currentsize++] = value;
		}
	} // 용량이 가득 찬 경우 아무것도 하지 않음

	void pop_back() {
		if (currentsize > 0) {
			currentsize--;
			//선택적으로 소멸자	호출
			// data[currentsize].~T();
		}
	}
	// 마지막 원소를 제거

	int size() const {
		return currentsize;
	} // 현재 원소의 개수 반환

	int capacity() const {
		return currentcapacity;
	} // 현재 용량 반환

	typedef T* iterator;
	typedef const T* const_iterator;
	// 반복자 정의

	iterator begin() {
		return data;
	} // begin 반복자

	iterator end() {
		return data + currentsize;
	} // end 반복자

	const_iterator begin() const {
		return data;
	} // const begin 반복자

	const_iterator end() const {
		return data + currentsize;
	} // const end 반복자

};
