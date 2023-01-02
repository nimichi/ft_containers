#include "map.hpp"
#include "pair.hpp"
#include <map>
#include <vector>
#include <list>
#include "vector.hpp"
#include <iostream>

#include "vector_prelude.hpp"

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
#define _ratio 10

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	CHECK_AND_PRINT_ALL(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	CHECK_AND_PRINT_ALL(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	CHECK_AND_PRINT_ALL(vct);
    return 0;
}
