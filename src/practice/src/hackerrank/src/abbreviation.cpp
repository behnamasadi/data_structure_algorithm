#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

bool recursiveAbbreviation(string a, string b) {
  if (a.at(0) == b.at(0))
    // return recursiveAbbreviation(a.substr(1), b);
    return true;
  return false;
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) { return std::string(""); }

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    string result = abbreviation(a, b);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}
