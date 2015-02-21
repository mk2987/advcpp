#include <iostream>
#include <vector>
#include <iterator>
#include <ext/functional>
using namespace std;
using namespace __gnu_cxx;

int main(void) {
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator new_end = 
        remove_if(v.begin(), v.end(), 
                compose1(bind2nd(equal_to<int>(), 0), bind2nd(modulus<int>(), 2)));

    copy(v.begin(), new_end, ostream_iterator<int>(cout, " "));
    cout << endl;
}
