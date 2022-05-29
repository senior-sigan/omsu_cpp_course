#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LectureTitle {
  string Specialization;
  string Course;
  string Name;
};

struct Lecture {
  LectureTitle Title;
  int Duration;
};
