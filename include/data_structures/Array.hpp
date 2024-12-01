#ifndef DSA_ARRAY_HPP
#define DSA_ARRAY_HPP

#include <string>

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

extern template class Array<int>;
extern template class Array<float>;
extern template class Array<std::string>;
#endif
