#include <iostream>
#include <string>
#include <deque>
#include <list>

#include <vector>
#include "vector.hpp"
#include "__service.ipp"
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs)
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}

// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

// int main(){
// 	ft::vector<std::string>				vector_str;
// 	ft::vector<std::string>::iterator	it;
// 	std::vector<std::string>			vector_std;
// 	std::vector<std::string>::iterator	std;

// 	vector_str.push_back("abc");
// 	vector_str.push_back("def");
// 	vector_str.push_back("ghi");
// 	vector_str.push_back("jkl");
// 	vector_str.push_back("123");

// 	vector_std.push_back("abc");
// 	vector_std.push_back("def");
// 	vector_std.pop_back();


// 	it = ft::vector<std::string>::iterator();
// 	it = ++(vector_str.begin());
// 	vector_str.erase(it, ++(++it));

// 	vector_str.pop_back();

// 	std::cout << (std::string) *vector_str.data() << (std::string) *(vector_std.data() + 2) << std::endl;
// 	std::cout << sizeof(vector_str) << std::endl;
// 	std::cout << vector_str.size() << std::endl;
// }

#define TESTED_TYPE foo<int>
#define TESTED_NAMESPACE std

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "capacity: " << vct.capacity() << " size: " << vct.size() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << "		first: " << *first << "		second: " << *second << std::endl;
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

	class B {
	public:
	    char *l;
	    int i;
	    B():l(nullptr), i(1) {};
	    B(const int &ex) {
	        this->i = ex;
	        this->l = new char('a');
	    };
	    virtual ~B() {
	        delete this->l;
	        this->l = nullptr;
	    };
	};

	class A : public B {
	public:
	    A():B(){};
	    A(const B* ex){
	        this->l = new char(*(ex->l));
	        this->i = ex->i;
	        if (ex->i == -1) throw "n";
	    }
	    ~A() {
	        delete this->l;
	        this->l = nullptr;
	    };
	};

int		main(void)
{
	std::vector<int> vector1;
    std::vector<int> v1;
    vector1.assign(9900 * _ratio, 1);
    g_start1 = timer();
    vector1.resize(5000 * _ratio);
    vector1.reserve(5000 * _ratio);
    v1.push_back(vector1.size());
    v1.push_back(vector1.capacity());
    vector1.resize(7000 * _ratio);
    v1.push_back(vector1.size());
    v1.push_back(vector1.capacity());
    vector1.resize(15300 * _ratio, int());
    v1.push_back(vector1.size());
    v1.push_back(vector1.capacity());
    v1.push_back(vector1[65]);
    g_end1 = timer();

	ft::vector<int> vector;
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start2 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, int());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    g_end2 = timer();

    std::vector<int> diff;
    //no need to sort since it's already sorted
    //but you can sort with:
    //std::sort(std::begin(v1), std::end(v1))

    std::set_difference(v.begin(), v.end(), v1.begin(), v1.end(),
        std::inserter(diff, diff.begin()));

    for (auto i : v1) std::cout << i << ' ';
    std::cout << "\nminus\n";
    for (auto i : v) std::cout << i << ' ';
    std::cout << "\nis: ";

    for (auto i : diff) std::cout << i << ' ';
    std::cout << '\n';

	// if (v < v1)
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// printSize(v1, true);
	// printSize(v, true);
	return 0;
}

