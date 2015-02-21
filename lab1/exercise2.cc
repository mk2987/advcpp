#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Generator {
    int min;
    int max;
public:
    Generator(int min, int max):min(min), max(max) {}

    string operator()() {
        string s;
        int length = min + rand() % (max+1);
        for (int i = 0; i < length; i++) {
            s += 'a' + rand() % 26;
        }
        return s;
    }
};

bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}

int main(void) {
    vector<string> v(100);
    Generator f(5, 15);
    generate(v.begin(), v.end(), f);
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    cout << "====\n";
    sort(v.begin(), v.end(), cmp);
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}

