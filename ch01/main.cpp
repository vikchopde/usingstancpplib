#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>
#include <iomanip>
#include <unordered_map>

/// Excsercise : 2.1
void exercise2_1()
{
    std::array<std::uint64_t ,50> fib_numbers{0LL, 1LL};

    auto f = fib_numbers[0];
    auto s = fib_numbers[1];
    std::generate(std::begin(fib_numbers), std::end(fib_numbers), [f, s]() mutable{
        std::uint64_t next_element = f + s;
        f = s;
        s = next_element;
        return next_element;
    });

    std::copy(std::begin(fib_numbers), std::end(fib_numbers), std::ostream_iterator<uint64_t>(std::cout, " "));
}


void exercise2_2()
{
    std::unordered_multimap<char, std::string> group;

    std::vector<std::string> dup_vec {"one", "two", "three", "four"};
    std::vector<std::string> words{std::make_move_iterator(dup_vec.begin()),
                                   std::make_move_iterator(dup_vec.end())};

    std::sort(std::begin(words), std::end(words));

    auto max_size =  std::max_element(std::begin(words), std::end(words), [](auto f, auto s){
        return f.length() < s.length();
    })->length();

    std::cout << std::setw(max_size);

    for(const auto& ele : words) {
        group.emplace(ele.front(),ele);
    }

    char ch{};
    for(const auto& ele : group) {
        if(ele.first != ch)
            std::cout << std::endl;
        ch = ele.first;
        std::cout << ele.second<< std::endl;
    }
}

int main()
{

    return 0;
}