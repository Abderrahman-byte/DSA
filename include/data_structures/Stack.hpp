#ifndef DSA_STACK_HPP
#define DSA_STACK_HPP

#include <string>

template <typename T> class Stack {
  private:
    T *array = nullptr;
    int _capacity = 1;
    int _size = 0;

  public:
    Stack();
    Stack(int capacity);
    void push(T value);
    T pop();
    T peek();
    bool is_empty();
    int size();

  private:
    void grow();
    void shrink();
};

extern template class Stack<int>;
extern template class Stack<char>;
extern template class Stack<bool>;
extern template class Stack<float>;
extern template class Stack<double>;
extern template class Stack<wchar_t>;
extern template class Stack<std::string>;
#endif
