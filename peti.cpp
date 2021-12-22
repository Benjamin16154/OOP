#include <math.h>
#include <iostream>
using namespace std;
struct Tacka {
  int x;
  int y;
};
struct Trokut {
  Tacka jedan;  // x=1 y=2
  Tacka dva;    // x=1 y=9
  Tacka tri;    // x=4 y=4

  void transliraj(int a, int b) {
    jedan.x += a;
    jedan.y += b;
    dva.x += a;
    dva.y += b;
    tri.x += a;
    tri.y += b;
  }
  void skaliraj(int a = 1, int b = 1) {
    jedan.x *= a;
    jedan.y *= b;
    dva.x *= a;
    dva.y *= b;
    tri.x *= a;
    tri.y *= b;
  }
  void vrhovi() {
    cout << "A(" << jedan.x << "," << jedan.y << ") ";
    cout << "B(" << dva.x << "," << dva.y << ") ";
    cout << "C(" << tri.x << "," << tri.y << ") " << endl;
  }

  double obimTrougla();
};

double Trokut::obimTrougla() {
  int x1 = jedan.x;
  int y1 = jedan.y;
  int x2 = dva.x;
  int y2 = dva.y;
  int x3 = tri.x;
  int y3 = tri.y;
  double dAB = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
  double dAC = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
  double dBC = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
  double obim = dAB + dAC + dBC;
  return obim;
}

int main() {
  Tacka A{1, 2};
  Tacka B{1, 9};
  Tacka C;
  C.x = C.y = 4;
  Trokut t{A, B, C};
  t.transliraj(3, -3).skaliraj(2).skaliraj(-1, -1);
  cout << t.obimTrougla() << endl;
  return 0;
}
