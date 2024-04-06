#pragma once
#include <functional>
#include<string>
   

using std::string;
class VectorDinamicError {
private:
    string mesaj;
public:
    VectorDinamicError(string mesaj) : mesaj{ mesaj } {}
    string getMesaj() {
        return mesaj;
    }
};

/*
template <typename ElementT>
class IteratorVectorT;

template <typename ElementT>
class VectDinNewDeleteT
*/
template <typename TElem>
class Iterator;

template <typename TElem>
class VectorDinamic {
    friend class Iterator<TElem>;

private:
    TElem* elemente;
    int capacity;   
    int current_size;   //numarul de elemente, lungimea
    void redim();      //functia pentru resize

public:
    VectorDinamic();    //constructor default
    VectorDinamic(const VectorDinamic<TElem>& other);   //constructor de copiere, rule of 3

    //Move constructor, Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return), Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
    //VectDinNewDeleteT(VectDinNewDeleteT&& ot); //rule of 5 

    void operator=(const VectorDinamic<TElem>& other);  //Operator assignment, elibereaza ce era in obiectul curent (this), aloca spatiu pentru elemente, copieaza elementele din ot in this, rule of 3

    //Move assgnment, Similar cu move constructor, Folosit la assignment
    //VectDinNewDeleteT& operator=(VectDinNewDeleteT&& ot); //rule of 5 

    ~VectorDinamic();   //eliberam memoria, rule of 3, destructor

    int size() const;
    void adauga(const TElem& e);
    TElem sterge(int poz);
    TElem element(int poz) const;
    TElem& operator[](int poz) const;
    void sort(std::function<bool(const TElem&, const TElem&)>Compara);
    bool empty() const;
    //void set(int poz, const TElem& e);

    //functii care creaza iteratori
    Iterator<TElem> begin() const;
    Iterator<TElem> end() const;
};



//Constructor default
template <typename TElem>
VectorDinamic<TElem>::VectorDinamic() : capacity{ 2 }, current_size{ 0 } {
    elemente = new TElem[capacity];
}

//constructorul de copiere, se creeaza un nou vector dinamic pe baza unuia existent, Obiectul current (this) acum se creaza, aloca spatiu pentru elemente, copieaza elementele din other in this
template <typename TElem>
VectorDinamic<TElem>::VectorDinamic(const VectorDinamic<TElem>& other) : capacity{ other.capacity }, current_size{ other.current_size } //am setat lungimea si capacitatea{
    this->elemente = new TElem[other.capacity]  //fiindca se creeaza un nou vector dinamic, trebuie sa alocam spatiu
    //copiez elementele
    for (int i = 0; i < other.current_size; i++) {
        elemente[i] = other[i];     //assignment din Oferta, copiem elementele
    }
}

//Operator assgnment, elibereaza ce era in obiectul curent (this), aloca spatiu pentru elemente, copieaza elementele din ot in this
/*VectDinNewDeleteT<ElementT>& VectDinNewDeleteT<ElementT>::operator=(const VectDinNewDeleteT<ElementT>& ot) {
    if (this == &ot) {
        return *this;//s-a facut l=l;
    }
    delete[] elems;
    elems = new ElementT[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elems[i] = ot.elems[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
    return *this;
}
*/
template <typename TElem>
void VectorDinamic<TElem>::operator=(const VectorDinamic<TElem>& other) {
    if (elemente != nullptr) {
        delete[] elemente;
    }
    capacity = other.capacity;
    current_size = other.current_size;
    this->elemente = new TElem[other.capacity];
    //copiez elementele
    for (int i = 0; i < other.current_size; i++) {
        elemente[i] = other[i];
    }
}

template <typename TElem>
void VectorDinamic<TElem>::redim() {
    if (current_size < capacity) {
        return; //mai avem loc
    }
    auto* new_elemente = new TElem[capacity * 2];
    for (int i = 0; i < current_size; i++) {
        new_elemente[i] = elemente[i];
    }
    delete[] elemente;
    elemente = new_elemente;
    capacity *= 2;
}

template <typename TElem>
void VectorDinamic<TElem>::adauga(const TElem& element) {
    if (capacity == current_size) {
        redim();    //daca e nevoie mai alocam memorie
    }
    elemente[current_size] = element;
    current_size++;
}

template <typename TElem>
TElem VectorDinamic<TElem>::sterge(int poz) {
    if (current_size == 0) {
        throw VectorDinamicError("MyVector<TElem>::sterge Nu sunt elemente in vector");
    }
    for (int i = poz; i < current_size; i++) {
        elemente[i + 1] = elemente[i];
    }
    current_size--;
    return elemente[current_size];
}

/*void VectDinNewDeleteT<ElementT>::set(int poz, const ElementT& el) {
    elems[poz] = el;
}
ElementT& VectDinNewDeleteT<ElementT>::get(int poz) const {
    return elems[poz];
}
*/
template <typename TElem>
TElem VectorDinamic<TElem>::element(int poz) const {
    if (poz < 0 || poz >= current_size) {
        throw VectorDinamicError("MyVector<TElem>::element(): Index out of range!");
    }
    return elemente[poz];
}

template <typename TElem>
TElem& VectorDinamic<TElem>::operator[](int poz) const {
    if (poz < 0 || poz >= current_size) {
        throw VectorDinamicError("MyVector<TElem>::operator[](): Index out of range!");
    }
    return elemente[poz];
}

template <typename TElem>
int VectorDinamic<TElem>::size() const /*noexcept*/ {
    return current_size;
}

template <typename TElem>
Iterator<TElem> VectorDinamic<TElem>::begin() const {
    return Iterator<TElem>(*this, false);
}

template <typename TElem>
Iterator<TElem> VectorDinamic<TElem>::end() const {
    return Iterator<TElem>(*this, true);    //    return IteratorVectorT<ElementT>(*this, lg);
}

template <typename TElem>
bool VectorDinamic<TElem>::empty() const {
    return current_size == 0;
}

template <typename TElem>
void VectorDinamic<TElem>::sort(std::function<bool(const TElem&, const TElem&)>Compara) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < current_size - 1; i++) {
            if (!compareFct(elemente[i], elemente[i + 1])) {
                std::swap(elemente[i], elemente[i + 1]);
                sorted = false;
            }
        }
    }
}

//Eliberam memoria, destructorul
template <typename TElem>
VectorDinamic<TElem>::~VectorDinamic() {
    delete[] elemente;
}
