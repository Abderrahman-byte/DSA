#ifndef DSA_QUEUE_HPP
#define DSA_QUEUE_HPP

#include <string>
template <typename T> class Queue {
  private:
    int _capacity = 1;
    int _size = 0;
    T *array = nullptr;

  public:
    Queue();
    Queue(int capacity);
    void enqueue(T value);
    T dequeue();
    T peek();
    bool is_empty();

  private:
    void grow();
    void shrink();
};

extern template class Queue<int>;
extern template class Queue<char>;
extern template class Queue<bool>;
extern template class Queue<float>;
extern template class Queue<double>;
extern template class Queue<wchar_t>;
extern template class Queue<std::string>;
#endif
