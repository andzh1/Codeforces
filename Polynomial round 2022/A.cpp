#include <algorithm>
#include <iostream>
using namespace std;

int distance_to_d_point(int x, int d) {
  int closest_on_left = ((x - d + 1) / d) * d;
  return min(x - closest_on_left, closest_on_left + d - x);
}

int main() {
  long long int a, b, d;
  cin >> a >> b >> d;

  int first_option = (a + b) / 2;
  int second_option = (a + b + 1) / 2;

  int first_dist = distance_to_d_point(first_option, d);
  int second_dist = distance_to_d_point(second_option, d);
  if (first_dist < second_dist) {
    cout << first_option << ' ' << first_dist << '\n';
  } else {
    cout << second_option << ' ' << second_dist << '\n';
  }
}