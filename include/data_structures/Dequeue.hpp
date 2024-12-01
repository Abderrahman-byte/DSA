#ifndef DSA_DEQUEUE_HPP
#define DSA_DEQUEUE_HPP

#include <string>

template <typename T> class Dequeue {
  private:
    int _capacity = 1;
    int _size = 0;
    T *array = nullptr;

  public:
    Dequeue();
    Dequeue(int capacity);
    void push_back(T value);
    void push_front(T value);
    T pop_back();
    T pop_front();
    T get_back();
    T get_front();
    bool is_empty();
    int size();

  private:
    void grow();
    void shrink();
};

extern template class Dequeue<int>;
extern template class Dequeue<char>;
extern template class Dequeue<bool>;
extern template class Dequeue<float>;
extern template class Dequeue<double>;
extern template class Dequeue<wchar_t>;
extern template class Dequeue<std::string>;
#endif
