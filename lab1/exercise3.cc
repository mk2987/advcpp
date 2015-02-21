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

class Counter: public unary_function<int, void> {
    int even;
public:
    Counter(): even(0) {}
    void operator() (int num) {
        if (num % 2 == 0) {
            even++;
        }
    }
    int get() const {return even;}
};

int main(void) {
    vector<int> v(100);
    Generator f(100);

    generate(v.begin(), v.end(), f);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));

    Counter c = for_each(v.begin(), v.end(), Counter());

    cout << "\nEven: " << c.get() << endl;
    return 0;
}
