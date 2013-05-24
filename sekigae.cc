#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    vector<string> freshers;
    freshers.push_back("おっくん");
    freshers.push_back("ぐっさん");
    freshers.push_back("たけお");
    freshers.push_back("きたけー");

    srand(static_cast<size_t>(time(NULL)));
    random_shuffle(freshers.begin(), freshers.end());
    copy(freshers.begin(), freshers.end(), ostream_iterator<string>(cout, " | "));

    return 0;
}
