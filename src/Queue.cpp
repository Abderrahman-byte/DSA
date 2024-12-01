#include "data_structures/Queue.hpp"
#include <stdexcept>

template <typename T> Queue<T>::Queue() {
    _capacity = 1;
    _size = 0;
    array = new T[_capacity];
}

template <typename T> Queue<T>::Queue(int capacity) {
    _capacity = capacity;
    _size = 0;
    array = new T[capacity];
}

template <typename T> void Queue<T>::enqueue(T value) {
    if (_capacity == _size) {
        grow();
    }

    array[_size++] = value;
}

template <typename T> T Queue<T>::dequeue() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot peek from an empty queue");
    }

    T value = array[0];

    for (int i = 0; i < _size; i++) {
        array[i] = array[i + 1];
    }

    _size--;

    if (_size == (_capacity / 2)) {
        shrink();
    }

    return value;
}

template <typename T> T Queue<T>::peek() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot peek from an empty queue");
    }

    return array[0];
}

template <typename T> bool Queue<T>::is_empty() { return _size <= 0; }

template <typename T> void Queue<T>::grow() {
    _capacity = _capacity * 2;

    T *temp = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template <typename T> void Queue<T>::shrink() {
    if (_capacity <= 1)
        return;

    _capacity = _size > 0 ? _size : 1;

    T *temp = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template class Queue<int>;
template class Queue<char>;
template class Queue<bool>;
template class Queue<float>;
template class Queue<double>;
template class Queue<wchar_t>;
template class Queue<std::string>;
