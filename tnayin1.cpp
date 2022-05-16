#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

template<typename Iter>
void do_advance(Iter& it, int n, std::input_iterator_tag) {
    while(n > 0) {
        --n;
        ++it;
    }
}

template<typename Iter>
void do_advance(Iter& it, int n, std::bidirectional_iterator_tag) {
    while(n > 0) {
        --n;
        ++it;
    }

    while(n < 0) {
        ++n;
        --it;
    }
}

template<typename Iter>
void do_advance(Iter& it, int n, std::random_access_iterator_tag) {
    it += n;
}

template<typename InputIterator>
void advance(InputIterator& it, int distance) {
    do_advance(it, distance, typename std::iterator_traits<InputIterator>::iterator_category());
}


template<typename InputIterator, typename T>
InputIterator find(InputIterator begin, InputIterator end, T value) {
    while(begin != end) {
        if(*begin == value) {
            return begin;
        }
        ++begin;
    }
    return end;
}


int main() {
    // advance and find for vector
    std::vector<int> v{ 3, 1, 4 };

    auto vi = v.begin();
    advance(vi, 2);
    std::cout << *vi << ' ';
 
    vi = v.end();
    advance(vi, -2);
    std::cout << *vi << std::endl;

    std::cout << *(find(v.begin(), v.end(), 4)) << std::endl;
    std::cout << *(find(v.begin(), v.end(), 5)) << std::endl;

    // advance and find fo list
    std::list<int> a{ 3, 1, 4 };

    auto ai = a.begin();
    advance(ai, 2);
    std::cout << *ai << ' ';
 
    ai = a.end();
    advance(ai, -2);
    std::cout << *ai << std::endl;

    std::cout << *(find(a.begin(), a.end(), 4)) << std::endl;
    std::cout << *(find(a.begin(), a.end(), 5)) << std::endl;

    // advance for forward_list
    std::forward_list<int> s{ 3, 1, 4 };

    auto si = s.begin();
    advance(si, 2);
    std::cout << *si << ' ';
 
    si = s.end();
    advance(si, -2);
    std::cout << *si << std::endl;

    std::cout << *(find(s.begin(), s.end(), 4)) << std::endl;
    std::cout << *(find(s.begin(), s.end(), 5)) << std::endl;
}