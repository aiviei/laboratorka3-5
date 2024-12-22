#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Element {
	Type element;
	Element<Type>* NextEl;
	Element(Type el) :element(el), NextEl(nullptr) {}
};

template<typename Type>
class OneList {
	Element<Type>* FirstEl;
	Element<Type>* LastEL;
	int count_elements;
public:
	OneList() :FirstEl(nullptr), LastEL(nullptr) {}

	OneList(OneList& p) {
		FirstEl = p.FirstEl;
		LastEL = p.LastEL;
		count_elements = 0;
	}

	void push_back(Type el) {
		Element<Type>* Pointer = new Element<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			LastEL->NextEl = Pointer;
			LastEL = Pointer;
		}
		count_elements++;
	}

	void push_front(Type el) {
		Element<Type>* Pointer = new Element<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			Pointer->NextEl = FirstEl;
			FirstEl = Pointer;
		}
		count_elements++;
	}

	Element<Type>* back() {
		return LastEL;
	}

	Element<Type>* front() {
		return FirstEl;
	}

	int size() {
		return count_elements;
	}

	bool empty() {
		if (FirstEl == nullptr) {
			return 1;
		}
		else return 0;
	}

	void insert(int position, Type el) {
		if (position == 0) {
			push_front(el);
		}
		else {
			if (position == size()) {
				push_back(el);
			}
			else {
				Element<Type>* newEl = new Element<Type>(el);
				Element<Type>* point = FirstEl;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
			}
		}
		count_elements++;
	}

	void pop_back() {
		if (LastEL == nullptr) throw "Error";
		Element<Type>* point = FirstEl;
		if (point->NextEl != nullptr) {
			while (point->NextEl->NextEl != nullptr) {
				point = point->NextEl;
			}
		}
		point->NextEl = nullptr;
		delete LastEL;
		LastEL = point;
		count_elements--;
	}

	void pop_front() {
		if (FirstEl == nullptr) throw "Error";
		Element<Type>* point = FirstEl->NextEl;
		delete FirstEl;
		FirstEl = point;
		count_elements--;
	}

	void remove(Type DeleteEL) {
		if (LastEL == nullptr) throw "Error";
		Element<Type>* point = FirstEl;
		Element<Type>* lastPoint = FirstEl;
		while (point->NextEl != nullptr) {
			if (point->element == DeleteEL) {
				if (point == FirstEl) {
					pop_front();
					point = FirstEl;
					lastPoint = FirstEl;
				}
				else {
					lastPoint->NextEl = point->NextEl;
					Element<Type>* TimePoint = point;
					point = point->NextEl;
					delete TimePoint;
				}
				count_elements--;
			}
			else
			{
				lastPoint = point;
				point = point->NextEl;
			}

		}
		if (DeleteEL == LastEL->element) pop_back();
	}

	Type& operator [] (int id) {
		if (FirstEl == nullptr) {
			throw "Error";
		}
		else
		{
			Element<Type>* point = FirstEl;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) throw "Error";
			}
			return point->element;
		}
	}
};