#include <iostream>
#include <string>

class Array {
 private:
  int* memory_;
  int capacity_;
  int length_;

 public:
  // default constructor
  Array(int capacity = 2) {
    std::cout << "Construct" << std::endl;
    length_ = 0;
    capacity_ = capacity;
    memory_ = new int[capacity];
  }

  ~Array() {
    std::cout << "Destroy" << std::endl;
    delete[] memory_;
  }

  void Push(int value) {}
  int Length() const {
    return length_;
  }
  int Capacity() const {
    return capacity_;
  }
};

class Student {
 private:
  int age;
  std::string name;

 public:
  void Print() {
    std::cout << this->name << " " << this->age << "\n";
  }
};

int main() {
  {
    Array arr(42);
    // arr.length = 42;
    std::cout << arr.Capacity() << "\n";
    arr.Push(1);
  }
  {
    Array* arr = new Array(13);
    std::cout << arr->Capacity() << "\n";
    arr->Push(1);
    delete arr;
  }

  std::cout << "Exit" << std::endl;

  return 0;
}
