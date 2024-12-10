#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Queue
{
	size_t head;
	size_t tail;
	vector<T> mem;
public:
	Queue() : head(0), tail(0) { }

	bool operator==(const Queue& other) {
		if ((*this).size() != other.size()) {
			return 0;
		}

		for (int i = 0; i < size(); ++i) {
			if (mem[head + i] != other.mem[other.head + i])
				return 0;
		}
		return 1;
	}

	bool operator!=(const Queue& other) {
		if ((*this).size() != other.size()) {
			return 1;
		}

		for (int i = 0; i < size(); ++i) {
			if (mem[head + i] != other.mem[other.head + i])
				return 1;
		}
		return 0;
	}

	size_t size() const { 
		return tail - head; 
	}

	size_t Get_Head() const {
		return head;
	}
	
	size_t Get_Tail() const {
		return tail;
	}

	bool IsEmpty() const { 
		return head == tail; 
	}

	void Push(const T& val) {
		mem.push_back(val);
		tail++;
	}
	
	T Pop() { 
		if (IsEmpty()) throw "Queue is empty!";

		head++;
	}

	T Top() {
		if (IsEmpty()) throw "Queue is empty!";

		return mem[head];
	}

	friend istream& operator>>(istream& istr, const Queue& s) {
		Queue<T> temp = s;
		T current;

		for (int i = 0; i < s.size(); ++i) {
			istr >> temp.Top();
			temp.Pop();
		}

		return istr;
	}

	friend ostream& operator<<(ostream& ostr, const Queue& s) {
		Queue<T> temp = s;
		T current;

		for (int i = 0; i < s.size(); ++i) {
			ostr << temp.Top() << " ";
			temp.Pop();
		}
		std::cout << "\n";

		return ostr;
	}
};