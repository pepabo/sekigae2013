#include <random>
#include <algorithm>
#include <array>
#include <string>
#include <iostream>
#include <iterator>

int main()
{
    using std::begin;
    using std::endl;

    std::array<std::string, 4> freshers = {{"おっくん", "ぐっさん", "たけお", "きたけー"}};

    std::shuffle(begin(freshers), end(freshers), std::default_random_engine{std::random_device{}()});
    std::copy(begin(freshers), end(freshers)-1, std::ostream_iterator<std::string>(std::cout, " | "));
    std::cout << freshers.back() << std::endl;

    return 0;
}
