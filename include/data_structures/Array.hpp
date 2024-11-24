#ifndef DSA_ARRAY_HPP
#define DSA_ARRAY_HPP

#include <stdexcept>

template <typename T> class Array {
  private:
    T *array = nullptr;
    int _capacity = 1;
    int _size = 0;

  public:
    Array();
    Array(int capacity);
    void push_back(T value);
    T pop_back();
    int size();
    void insert(int index, T value);
    void remove(int index);
    const T &operator[](int index) const;

  private:
    void grow();
    void shrink();
};

template <typename T> Array<T>::Array() {
    _capacity = 0;
    array = new T[_capacity];
    _size = 0;
}

template <typename T> Array<T>::Array(int capacity) {
    this->_capacity = capacity;
    array = new T[capacity];
    _size = 0;
}

template <typename T> void Array<T>::push_back(T value) {
    if (_size == _capacity) {
        // grow array by double if reached capacity
        grow();
    }

    array[_size] = value;
    _size++;
}

template <typename T> T Array<T>::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from an empty array");
    }

    T value = array[_size - 1];
    array[_size - 1] = 0;

    _size--;

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

    for (int i = index; i < _size; i++) {
        array[i + 1] = array[i];
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

    array[_size - 1] = 0;
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
#endif
