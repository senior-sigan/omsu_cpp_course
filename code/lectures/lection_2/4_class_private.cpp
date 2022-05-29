#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int CalculateDistance(const string& source, const string& destination) {
  // THIS IS REALLY SOPHISTICATED FUNCTION
  // IT MIGHT BE A CALL TO THE ~police~ DB.
  cout << "!!! CalculateDistance " << source << " " << destination << endl;
  int l = source.length() - destination.length();
  return abs(l);
}

class Route {
 private:
  string source;
  string destination;
  int length = 0;
  vector<string> log{};

 public:
  string GetSource() const {
    return source;
  }

  string GetDestination() const {
    return destination;
  }

  int GetLength() const {
    return length;
  }

  void SetSource(const string& source) {
    this->source = source;
    length = CalculateDistance(source, destination);
    log.push_back(ToString());
  }

  void SetDestination(const string& dest) {
    destination = dest;
    length = CalculateDistance(source, destination);
    log.push_back(ToString());
  }

  // Route() {
  //   destination = "St Petersburg";
  //   source = "Omsk";
  //   length = CalculateDistance(source, destination);
  // }

  Route(const string& src = "St Petersburg", const string& dst = "Omsk")
      : source(src), destination(dst), length(0) {
    length = CalculateDistance(source, destination);
    log.push_back(ToString());
  }

  void PrintLog() {
    cout << "Log" << endl;
    for (auto& entry : log) {
      cout << "\t" << entry << endl;
    }
  }

  ~Route() {
    PrintLog();
  }

  string ToString() const {
    stringstream ss;
    ss << "Source: " << GetSource() << ", Destination: " << GetDestination()
       << ", Length: " << GetLength();

    return ss.str();
  }
};

void PrintRoute(const Route& r) {
  cout << r.ToString() << endl;
}

void CopyRoute(Route r) {
  cout << "COPY" << endl;
  r.GetLength();  // nothing to do here
}

int main() {
  {
    Route r;
    r.SetDestination("AAAAAAA");
    r.SetSource("?");

    r.SetDestination("CCCP");
    r.SetSource("K-POP");

    // r.PrintLog();
    cout << "DIE!" << endl;
  }
  cout << "DEAD LOL" << endl;

  {
    Route* r = new Route();
    r->SetDestination("AAAAAAA");
    r->SetSource("?");

    r->SetDestination("CCCP");
    r->SetSource("K-POP");

    // r.PrintLog();
    cout << "DIE!" << endl;
    delete r;
  }

  {
    Route r("A", "BB");
    Route r2(r);  // copy example
  }
}
