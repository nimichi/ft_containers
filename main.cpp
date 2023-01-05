#include "map.hpp"
#include "pair.hpp"
#include <map>
#include <vector>
#include <list>
#include "vector.hpp"
#include <iostream>

// #include "vector_prelude.hpp"
#include "map_prelude.hpp"

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
#define _ratio 10

// int		main(void)
// {
// 	ft::map<int, int> test = ft::map<int, int>();
// 	test.insert(ft::pair<int, int>(1, 10));
// 	test.insert(ft::pair<int, int>(15, 10));
// 	test.insert(ft::pair<int, int>(6, 10));
// 	test.insert(ft::pair<int, int>(27, 10));
// 	test.insert(ft::pair<int, int>(11, 10));
// 	test.insert(ft::pair<int, int>(17, 10));
// 	test.insert(ft::pair<int, int>(13, 10));
// 	test.insert(ft::pair<int, int>(8, 10));
// 	test.insert(ft::pair<int, int>(22, 10));
// 	test.insert(ft::pair<int, int>(25, 10));
// 	ft::map<int, int>::iterator start_iter;
// 	ft::map<int, int>::iterator end_iter;
// 	start_iter = test.begin();
// 	end_iter = start_iter;
// 	std::advance(start_iter, 5);
// 	std::advance(end_iter, 6);
// 	test.erase(start_iter, end_iter);

// 	start_iter = test.begin();
// 	end_iter = test.end();

// 	std::cout << "\n" << std::endl;
// 	while(start_iter != end_iter)
// 	{
// 		std::cout << (*start_iter).first << "\n" << std::endl;
// 		start_iter++;
// 	}
// }

int main(void)
{
    SETUP_ARRAYS();

    {
		std::map<int ,int> blc;
		blc.max_size()
        strmap m(strstr_arr, strstr_arr + 16);

        strmap::iterator it = m.find("Hello");

        m.insert(strstr_arr, strstr_arr + strstr_size);


        m.erase(m.begin());


        it = m.begin();
        std::advance(it, 10);

        m.erase(it, m.end());

		std::cout << m.size() << std::endl;

        PRINT_ALL(m);
    }

    // {
    //     NAMESPACE::map<int, int, std::less<int>, track_allocator<NAMESPACE::pair<const int, int> > >
    //         m;

    //     for (int i = 0; i < 50000; ++i) {
    //         m.insert(NAMESPACE::make_pair(rand(), rand()));
    //     }

    //     PRINT_ALL(m);

    //     m.erase(m.begin(), m.end());

    //     PRINT_ALL(m);
    // }
}
