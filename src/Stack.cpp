#include "data_structures/Stack.hpp"
#include <stdexcept>

template <typename T> Stack<T>::Stack() {
    _capacity = 1;
    array = new T[_capacity];
    _size = 0;
}

template <typename T> Stack<T>::Stack(int capicity) {
    _capacity = capicity;
    array = new T[capicity];
    _size = 0;
}

template <typename T> void Stack<T>::push(T value) {
    if (_size == _capacity) {
        // grow array if reached capacity
        grow();
    }

    array[_size++] = value;
}

template <typename T> T Stack<T>::pop() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot pop from an empty stack");
    }

    T value = array[--_size];

    // Reduce if the container half element of its capacity
    if (_size == (_capacity / 2)) {
        shrink();
    }

    return value;
}

template <typename T> T Stack<T>::peek() {
    if (_size <= 0) {
        throw std::out_of_range("Cannot peek from an empty stack");
    }

    return array[_size - 1];
}

template <typename T> bool Stack<T>::is_empty() { return _size <= 0; }

template <typename T> int Stack<T>::size() { return _size; }

template <typename T> void Stack<T>::grow() {
    _capacity *= 2;

    T *temp = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template <typename T> void Stack<T>::shrink() {
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

template class Stack<int>;
template class Stack<char>;
template class Stack<bool>;
template class Stack<float>;
template class Stack<double>;
template class Stack<wchar_t>;
template class Stack<std::string>;
