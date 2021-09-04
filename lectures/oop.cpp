
class Point {
 public:
  float x;
  float y;
}

class Fraction {
 private:
  int chisl;
  int znam;

 public:
  const int& Chisl() const {
    return chisl;
  }
  // operator +
};

int main() {
  Fraction f1(1, 4);
  Fraction f2(1, 4);
  Fraction f = f2 + f2;  // 1/2, 2/4
  f2.znam = 0;
}
