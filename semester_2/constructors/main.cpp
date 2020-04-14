#include <iostream>
#include <string>

using namespace std;  // don't do this in header files!

class CloneableObject {
  int a_;
  string b_;

 public:
  CloneableObject(int a, const string& b) : a_(a), b_(b) {
    cout << "Constructor was called" << endl;
  }

  CloneableObject(const CloneableObject& co) : a_(co.a_), b_(co.b_) {
    cout << "Copy Constructor was called" << endl;
  }

  CloneableObject(CloneableObject&& co) noexcept : a_(exchange(co.a_, 0)), b_(move(co.b_)) {
    cout << "Move constructor was called" << endl;
  }

  void Print() const {
    cout << "Print CloneableObject(a=" << a_ << ", b_=" << b_ << ")" << endl;
  }

  void Increment() {
    cout << "Do increment" << endl;
    a_ += 1;
  }

  ~CloneableObject() {
    cout << "~Destructor was called" << endl;
  }

  int GetA() const {
    return a_;
  }
  string GetB() const {
    return b_;
  }
};

void giveMeCopy(CloneableObject co) {
  cout << "We get a copy of CloneableObject" << endl;
  co.Print();
  co.Increment();
  co.Print();
}

void giveMePtr(CloneableObject* co) {
  cout << "We get a pointer to CloneableObject" << endl;
  co->Print();
  co->Increment();
  co->Print();
}

void giveMeRef(CloneableObject& co) {
  cout << "We get a reference to CloneableObject" << endl;
  co.Print();
  co.Increment();
  co.Print();
}

void giveMeConstRef(const CloneableObject& co) {
  cout << "We get a const reference to CloneableObject" << endl;
  co.Print();
  //  co.Increment(); // cannot call, because co is constant reference, but
  //  Increment cannot be applied on a non-const object
}

int main() {
  {  // anonymous block
    cout << "Example 1 - stack" << endl;
    CloneableObject co(42, "Hello!");
    co.Print();
    assert(co.GetA() == 42);
    giveMeCopy(co);
    assert(co.GetA() == 42);  // but we do increment. Hmmm
    giveMeRef(co);
    assert(co.GetA() == 43);  // hm, we pass it by reference!
    giveMeConstRef(co);
    assert(co.GetA() == 43);  // we cannot change it by const ref
    giveMeCopy(*&co);
    assert(co.GetA() == 43);  // again, it still a copy
    giveMePtr(&co);
    assert(co.GetA() == 44);  // we can change object by ptr
  }
  {
    cout << "Example 2 - heap" << endl;
    auto co = new CloneableObject(42, "Hello!");
    co->Print();
    assert(co->GetA() == 42);
    giveMeCopy(*co);
    assert(co->GetA() == 42);
    giveMeRef(*co);
    assert(co->GetA() == 43);
    giveMeConstRef(*co);
    assert(co->GetA() == 43);
    giveMePtr(co);
    assert(co->GetA() == 44);
    delete co;  // we have to call destructor, because we use new to create a
                // object in the heap
  }
  {
    cout << "Example 3" << endl;
    // giveMeRef(CloneableObject(42, "Hello!")); // cannot call because argument
    // is rvalue but we expected something with an address in memory
    giveMeConstRef(
        CloneableObject(42, "Hello!"));  // it works, because const ref can work
                                         // with temporal objects
    giveMeCopy(CloneableObject(
        42, "Hello!"));  // hmmm, no copy constructor was called.. interesting!
    //    giveMePtr(&CloneableObject(42, "Hello!")) // cannot get address of a
    //    temporal object
  }
  {
    // We use move to say compiler that object data was moved to another object
    // We usually use it
    // - to pass unique_ptr to a new owner,
    // - to pass sockets, file handlers, etc.. to a new owner
    cout << "Example 4 - moving" << endl;
    CloneableObject co(42, "Hello!");
    assert(co.GetA() == 42);
    assert(co.GetB() == "Hello!");
    CloneableObject co2 = move(co);
    co.Print(); // dangerous!
    assert(co.GetA() == 0);
    assert(co.GetB().empty());
    assert(co2.GetA() == 42);
    assert(co2.GetB() == "Hello!");
    // destructor of both co and co2 will be called!
  }
  return 0;
}
