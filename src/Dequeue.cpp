#include "data_structures/Dequeue.hpp"
#include <stdexcept>

template <typename T> Dequeue<T>::Dequeue() {
    _capacity = 1;
    _size = 0;
    array = new T[_capacity];
}

template <typename T> Dequeue<T>::Dequeue(int capacity) {
    _capacity = capacity;
    _size = 0;
    array = new T[capacity];
}

template <typename T> void Dequeue<T>::push_back(T value) {
    if (_size == _capacity) {
        grow();
    }

    array[_size++] = value;
}

template <typename T> void Dequeue<T>::push_front(T value) {
    if (_size == _capacity) {
        grow();
    }

    for (int i = _size; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = value;
    _size++;
}

template <typename T> T Dequeue<T>::pop_back() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot pop from an empty dequeue");
    }

    T value = array[_size--];

    if (_size <= (_capacity / 2)) {
        shrink();
    }

    return value;
}

template <typename T> T Dequeue<T>::pop_front() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot pop from an empty dequeue");
    }

    T value = array[0];

    for (int i = 0; i < _size - 1; i++) {
        array[i] = array[i + 1];
    }

    _size--;

    if (_size <= (_capacity / 2)) {
        shrink();
    }

    return value;
}

template <typename T> T Dequeue<T>::get_back() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot get from an empty dequeue");
    }

    return array[_size - 1];
}

template <typename T> T Dequeue<T>::get_front() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot get from an empty dequeue");
    }

    return array[0];
}

template <typename T> bool Dequeue<T>::is_empty() { return _size <= 0; }

template <typename T> int Dequeue<T>::size() { return _size; }

template <typename T> void Dequeue<T>::grow() {
    _capacity *= 2;

    T *temp = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template <typename T> void Dequeue<T>::shrink() {
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

template class Dequeue<int>;
template class Dequeue<char>;
template class Dequeue<bool>;
template class Dequeue<float>;
template class Dequeue<double>;
template class Dequeue<wchar_t>;
template class Dequeue<std::string>;
