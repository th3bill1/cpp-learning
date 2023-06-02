#pragma once

class CollectionUtilities {
public:
    template<typename Iterator, typename T>
    static Iterator find(Iterator begin, Iterator end, T element);

    template<typename Iterator, typename Predicate>
    static bool all_of(Iterator begin, Iterator end, Predicate p);

    template<typename Iterator, typename Predicate>
    static Iterator order_if(Iterator begin, Iterator end, Predicate p);
};

template<typename Iterator, typename T>
Iterator CollectionUtilities::find(Iterator begin, Iterator end, T element) {
    while (begin != end) {
        if (*begin == element) {
            return begin;
        }
        begin++;
    }
    return end;
}

template<typename Iterator, typename Predicate>
static bool CollectionUtilities::all_of(Iterator begin, Iterator end, Predicate p)
{
    while (begin != end) {
        if (!p(*begin)) return false;
        begin++;
    }
    return true;
}
