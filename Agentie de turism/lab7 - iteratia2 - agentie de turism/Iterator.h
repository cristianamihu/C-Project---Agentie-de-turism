#pragma once
#include "VectorDinamic.h"


template <typename TElem>
class Iterator {
	friend class VectorDinamic<TElem>;

private:
	const VectorDinamic<TElem>& vector;
	TElem* current_elem;	//	int poz = 0;

public:
	Iterator(const VectorDinamic<TElem>& vector, const bool& end);
	//IteratorVectorT(const VectDinNewDeleteT<ElementT>& v) noexcept;
	//IteratorVectorT(const VectDinNewDeleteT<ElementT>& v, int poz)noexcept;
	void begin();
	TElem operator*() const;
	void operator++();
	void operator++(int);
	void end();
	bool operator==(const Iterator& other) noexcept;
	bool operator!=(const Iterator& other) const /*sau doar noexcept*/;
	/*
	bool valid() const;
	ElementT& element() const;
	void next();
	IteratorVectorT& operator++();
	*/
};

template<typename TElem>
Iterator<TElem>::Iterator(const VectorDinamic<TElem>& vector, const bool& end) : vector{ vector } {
	if (!end) begin();
	else this->end();
}

template<typename TElem>
void Iterator<TElem>::begin() {
	current_elem = vector.elemente;
}

template<typename TElem>
TElem Iterator<TElem>::operator*() const {
	return *current_elem;
}
//ElementT& IteratorVectorT<ElementT>::operator*() {
//	return element();
//}

template<typename TElem>
void Iterator<TElem>::operator ++() {
	current_elem++;
}

template<typename TElem>
void Iterator<TElem>::operator++(int) {
	current_elem++;
}

template<typename TElem>
void Iterator<TElem>::end() {
	current_elem = vector.elemente + vector.current_size;
}

template<typename TElem>
bool Iterator<TElem>::operator!=(const Iterator& other) const {
	return current_elem != other.current_elem;
}
//bool IteratorVectorT<ElementT>::operator!=(const IteratorVectorT<ElementT>& ot)noexcept {
//	return !(*this == ot);
//}
