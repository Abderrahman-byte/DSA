#include <stdexcept>

#include "data_structures/Array.hpp"

template <typename T> Array<T>::Array() {
    _capacity = 1;
    array = new T[_capacity];
    _size = 0;
}

template <typename T> Array<T>::Array(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Capacity must be at least 1.");
    }

    this->_capacity = capacity;
    array = new T[capacity];
    _size = 0;
}

template <typename T> void Array<T>::push_back(T value) {
    if (_size == _capacity) {
        // grow array by double if reached capacity
        grow();
    }

    array[_size++] = value;
}

template <typename T> T Array<T>::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from an empty array");
    }

    T value = array[--_size];

    // Reduce if the container half element of its capacity
    if (_size == (_capacity / 2)) {
        shrink();
    }

    return value;
}

template <typename T> void Array<T>::grow() {
    _capacity *= 2;

    T *temp = new T[_capacity * 2];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template <typename T> void Array<T>::shrink() {
    if (_capacity <= 1) {
        return;
    }

    _capacity = _size > 0 ? _size : 1;

    T *temp = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;

    array = temp;
}

template <typename T> void Array<T>::insert(int index, T value) {
    if (index > _size || index < 0) {
        throw std::out_of_range("Index out of range");
    }

    if (_size == _capacity) {
        grow();
    }

    for (int i = _size; i > index; --i) {
        array[i] = array[i - 1];
    }

    array[index] = value;
    _size++;
}

template <typename T> void Array<T>::remove(int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < _size; i++) {
        array[i] = array[i + 1];
    }

    _size--;

    if (_size == (_capacity / 2)) {
        shrink();
    }
}

template <typename T> const T &Array<T>::operator[](int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    return array[index];
}

template <typename T> int Array<T>::size() { return _size; }

template class Array<int>;
template class Array<float>;
template class Array<std::string>;
