#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
    while (distance(first, last) > 0) {
        last--;
        swap(*first, *last);
        first++;
    }
}

void test(int size) {
    vector<int> v(size);
    cout << "\nSize: " << size << endl;
    for (int i = 0; i < size; i++) {
        v[i] = 1 + rand() % size;
    }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    my_reverse(v.begin(), v.end());
    cout << "\nReversed: " << endl;

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << endl;
}

int main(void) {
    test(20);
    test(17);
    test(0);
    test(1);
    return 0;
}
