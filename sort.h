#ifndef SORT_H
#define SORT_H

namespace my {

template <typename Iterator, typename Comparator>
void sort(Iterator begin, Iterator end, Comparator comp)
{
    for (auto it1 = begin; it1 != end; ++it1) {
        for (auto it2 = begin; it2 != it1; ++it2) {
            if (comp(*it1, *it2)) {
                std::swap(*it1, *it2);
            }
        }
    }
}

template <typename Iterator>
void sort(Iterator begin, Iterator end)
{
    for (auto it1 = begin; it1 != end; ++it1) {
        for (auto it2 = begin; it2 != it1; ++it2) {
            if (*it1 < *it2) {
                std::swap(*it1, *it2);
            }
        }
    }
}

}

#endif // SORT_H
