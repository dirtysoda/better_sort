/*
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004
 
Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.
 
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.
*/

#pragma once
#include <vector>
#include <random>
namespace bsort {
    template<class random_it, class compare>
    bool is_in_order(random_it first, random_it last, compare fn) {
        auto compare1 = first;
        auto compare2 = std::next(compare1);
        while (compare2 != last) {
            if (!fn(*compare1, *compare2))
                return false;
            compare1 = std::next(compare1);
            compare2 = std::next(compare1);
        }
        return true;
    }
    template<class random_it>
    bool is_in_order(random_it first, random_it last) {
        auto compare1 = first;
        auto compare2 = std::next(compare1);
        while (compare2 != last) {
            if (*compare1 > *compare2)
                return false;
            compare1 = std::next(compare1);
            compare2 = std::next(compare1);
        }
        return true;
    }

    template<class random_it, class compare>
    void bogo_sort(random_it first, random_it last, compare fn) {
        std::random_device rand_dev;
        std::mt19937       generator(rand_dev());
        while (!is_in_order(first, last, fn))
            std::shuffle(first, last, generator);
    }

    template<class random_it>
    void bogo_sort(random_it first, random_it last) {
        std::random_device rand_dev;
        std::mt19937       generator(rand_dev());
        while (!is_in_order(first, last))
            std::shuffle(first, last, generator);
    }
}
