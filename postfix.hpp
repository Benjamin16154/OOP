#pragma once
#include <iostream>

class PostfixCal {
  public:
  PostfixCal()
      : size_{0}, capacity_{10}, arr_{new int[capacity_]}, line_{" "} {}

  PostfixCal(std::string a) {
    line_ = a;
  }
  int calculate(){
    int num = 0;
    for (int i = 0; i < size_; i++) {
      if (line_[i] >= '0' && line_[i] <= '9') {
        do {
          num = num * 10;
          num += (line_[i] - '0');
          i++;
        } while (line_[i] != ' ');
        push(num);
        num = 0;
      } else {
        if (line_[i] == '+' || line_[i] == '-' || line_[i] == '*' || line_[i] == '/') {
          int op2 = top();
          pop();
          int op1 = top();
          pop();
          int res;

          switch (line_[i]) {
            case '+':
              res = op1 + op2;
              break;
            case '-':
              res = op1 - op2;
              break;
            case '*':
              res = op1 * op2;
              break;
            case '/':
              res = op1 / op2;
          }

          push(res);
        }
      }
    }
    int result = pop();
    return result;


  }

  PostfixCal(const PostfixCal& other)
      : size_{other.size_},
        capacity_{other.capacity_},
        arr_{new int[capacity_]} {
    std::copy(other.arr_, other.arr_ + size_, arr_);
  }

  PostfixCal(PostfixCal&& other)
      : size_{other.size_}, capacity_{other.capacity_}, arr_{other.arr_} {
    other.arr_ = nullptr;
  }

  ~PostfixCal() {
    delete[] arr_;
    size_ = capacity_ = 0;
  }

  PostfixCal& operator=(const PostfixCal& other) {
    if (this == &other) return *this;
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = new int[capacity_];
    line_ = other.line_;
    std::copy(other.arr_, other.arr_ + size_, arr_);
    return *this;
  }

  PostfixCal& operator=(PostfixCal&& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = other.arr_;
    line_ = other.line_;
    other.arr_ = nullptr;
  }

  bool operator==(const PostfixCal& other) {
    return size_ == other.size_ && capacity_ == other.capacity_ &&
           arr_ == other.arr_ && line_ == other.line_;
  }

  bool operator!=(const PostfixCal& other) {
    return size_ != other.size_ && capacity_ != other.capacity_ &&
           arr_ != other.arr_ && line_ != other.line_;
  }

  size_t size2() const { return size_; }
  size_t capacity() const { return capacity_; }

  PostfixCal& push(int element) {
    if (size_ == capacity_) {
      int* temp = new int[size_];
      std::copy(arr_, arr_ + size_, temp);
      delete[] arr_;
      capacity_ *= 2;
      arr_ = new int[capacity_];
      std::copy(temp, temp + size_, arr_);
      delete[] temp;
    }
    arr_[size_++] = std::forward<int>(element);
    return *this;
  }

  int pop() {
    if (size_ == 0) throw std::out_of_range{"Empty stack"};
    int element = arr_[--size_];
    return element;
  }

  int& top() const {
    if (size_ == 0) throw std::out_of_range{"Empty stack"};
    return arr_[size_ - 1];
  }

  private:
  size_t size_{0};
  size_t capacity_{10};
  int* arr_{nullptr};
  std::string line_{" "};
};
