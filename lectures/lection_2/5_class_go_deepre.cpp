#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

class Duration {
 private:
  int Hours;
  int Minutes;

 public:
  Duration(int h = 0, int m = 0) : Hours(h + m / 60), Minutes(m % 60) {}

  Duration operator+(const Duration& rhs) const {
    return Duration{Hours + rhs.Hours, Minutes + rhs.Minutes};
  }

  int GetHourse() const {
    return Hours;
  }

  int GetMinutes() const {
    return Minutes;
  }

  bool operator>(const Duration& rhs) const {
    // Можно переобернуть поля в tuple для которого определо сравнение
    // return make_tuple(Hours, Minutes) > make_tuple(rhs.Hours, rhs.Minutes);

    return Hours > rhs.Hours || Minutes > rhs.Minutes;
  }

  bool operator<(const Duration& rhs) const {
    return Hours < rhs.Hours || Minutes < rhs.Minutes;
  }

  bool operator==(const Duration& rhs) const {
    return Hours == rhs.Hours && Minutes == rhs.Minutes;
  }

  string ToString() const {
    stringstream ss;
    ss << setfill('0');
    ss << setw(2) << GetHourse() << ':' << setw(2) << GetMinutes();
    return ss.str();
  }
};

ostream& operator<<(ostream& stream, const Duration& duration) {
  return stream << duration.ToString();
}

istream& operator>>(istream& stream, Duration& duration) {
  int h = 0;
  int m = 0;
  stream >> h;
  stream.ignore(1);
  stream >> m;
  duration = Duration{h, m};
  return stream;
}

int main() {
  Duration d = {1, 30};
  cout << d << endl;

  stringstream ss("2:32");
  Duration d2;
  ss >> d2;
  cout << d2 << endl;

  Duration d3;
  cin >> d3;
  cout << d3 << endl;

  cout << d3 + d2 << endl;

  if (d3 > d2) {
    cout << "EPIC" << endl;
  } else {
    cout << "NOT EPIC" << endl;
  }

  return 0;
}
