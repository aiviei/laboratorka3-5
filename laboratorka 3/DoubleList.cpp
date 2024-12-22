#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Element2 {
	Type element;
	Element2<Type>* NextEl;
	Element2<Type>* PreviosEl;
	Element2(Type el) :element(el), NextEl(nullptr), PreviosEl(nullptr) {}
};

template<typename Type>
class DoubleList {
	Element2<Type>* FirstEl;
	Element2<Type>* LastEL;
	int count_elements = 0;
public:
	DoubleList() :FirstEl(nullptr), LastEL(nullptr) {}

	void push_back(Type el) {
		Element2<Type>* Pointer = new Element2<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
			count_elements++;
		}
		else {
			LastEL->NextEl = Pointer;
			Pointer->PreviosEl = LastEL;
			LastEL = Pointer;
			count_elements++;
		}
	}

	void push_front(Type el) {
		Element2<Type>* Pointer = new Element2<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
			count_elements++;
		}
		else {
			Pointer->NextEl = FirstEl;
			FirstEl = Pointer;
			count_elements++;
		}

	}

	Element2<Type>* back() {
		return LastEL;
	}

	Element2<Type>* front() {
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
		if (position < count_elements) {
			if (position == 0) {
				push_front(el);
			}
			else
			{
				Element2<Type>* newEl = new Element2<Type>(el);
				Element2<Type>* point = FirstEl;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
				count_elements++;
			}
		}
		else
		{
			if (position == size()) {
				push_back(el);
			}
			else
			{
				Element2<Type>* newEl = new Element2<Type>(el);
				Element2<Type>* point = LastEL;
				int countElements = size();
				while (countElements != position) {
					countElements--;
					point = point->PreviosEl;
				}
				newEl->PreviosEl = point->PreviosEl;
				point->PreviosEl = newEl;
				count_elements++;
			}
		}
	}

	void pop_back() {
		Element2<Type>* DelEl = LastEL;
		LastEL->PreviosEl->NextEl = nullptr;
		LastEL = LastEL->PreviosEl;
		delete DelEl;
		count_elements--;
	}

	void pop_front() {
		Element2<Type>* DelEl = FirstEl;
		FirstEl->NextEl->PreviosEl = nullptr;
		FirstEl = FirstEl->NextEl;
		count_elements--;
		delete DelEl;
	}

	Type& operator [] (int id) {
		if (FirstEl == nullptr) {
			std::cout << "MissingEl";
		}
		else
		{
			Element2<Type>* point = FirstEl;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) {
					std::cout << "MissingEl";
				}
			}
			return point->element;
		}
	}

	void remove(Type data) {
		if (LastEL != nullptr) {

			int current_element_index = 0;
			Element2<Type>* element_ = new Element2<Type>(data);
			Element2<Type>* current_element = FirstEl;

			if (current_element->element == data) {
				pop_front();
			}
			else {
				for (int i = 0; i < count_elements; i++) {
					while (current_element->NextEl != nullptr) {
						if (current_element->NextEl->element == element_->element) {
							if (current_element_index + 2 == count_elements) {
								pop_back();
								break;
							}
							Element2<Type>* elemDel = current_element->NextEl;
							current_element->NextEl = elemDel->NextEl;
							delete elemDel;
							count_elements--;
							break;

						}

						current_element = current_element->NextEl;
						current_element_index++;
					}
				}
			}
		}
		else {
			throw "List size Error";
		}
	}
};