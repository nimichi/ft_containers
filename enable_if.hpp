template <typename T>
struct sfinae_true : std::true_type {};

struct is_iterator_tester {
    template <typename T>
    static sfinae_true<typename std::iterator_traits<T>::iterator_category> test(int);

    template <typename>
    static std::false_type test(...);
};

template <typename T>
struct is_iterator : decltype(is_iterator_tester::test<T>(0)) {};