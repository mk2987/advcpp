#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

class Generator {
    int max;
public:
    Generator(int max): max(max) {}

    int operator()(void) {
        return rand() % max;
    }
};

int main(void) {
    vector<int> v(100);
    Generator f(100);

    generate(v.begin(), v.end(), f);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}
