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
		int newcapacity = currentcapacity * 2; //�뷮�� �� ��� Ȯ��
		T* newdata = new T[newcapacity];
		copy(data, data + currentsize, newdata);
		delete[] data;	// ���� �迭 ����

		data = newdata; // ������ �� �뷮 ����
		currentcapacity = newcapacity;
	}

public:
	SimpleVector() : currentcapacity(10), currentsize(0) {
		data = new T[currentcapacity];
	} // �뷮�� 10���� �ʱ�ȭ


	SimpleVector(int capacity) : currentcapacity(capacity), currentsize(0) {
		if (currentcapacity <= 0) {
			currentcapacity = 10; // �⺻�뷮
		}
		data = new T[currentcapacity];
	} // Ư�� �뷮�� �޴� ������

	~SimpleVector() {
		delete[] data;
	} // �Ҹ���

	void push_back(const T& value) {
		if (currentsize < currentcapacity) {
			data[currentsize++] = value;
		}
	} // �뷮�� ���� �� ��� �ƹ��͵� ���� ����

	void pop_back() {
		if (currentsize > 0) {
			currentsize--;
			//���������� �Ҹ���	ȣ��
			// data[currentsize].~T();
		}
	}
	// ������ ���Ҹ� ����

	int size() const {
		return currentsize;
	} // ���� ������ ���� ��ȯ

	int capacity() const {
		return currentcapacity;
	} // ���� �뷮 ��ȯ

	typedef T* iterator;
	typedef const T* const_iterator;
	// �ݺ��� ����

	iterator begin() {
		return data;
	} // begin �ݺ���

	iterator end() {
		return data + currentsize;
	} // end �ݺ���

	const_iterator begin() const {
		return data;
	} // const begin �ݺ���

	const_iterator end() const {
		return data + currentsize;
	} // const end �ݺ���

};
