#include "map.hpp"
#include "vector.hpp"
#include "utilities.hpp"

#include <map>
#include <vector>

#include <iostream>


#define NAS ft

int main(void)
{
	NAS::pair<std::string, std::string>		arr_str_std[32];

	NAS::pair<int, int>						arr_int_std[32];

	std::string x[32] = { "RxWAUMME3GtF9Zbv3a4M", "WC96vs7Z6I6TfdGxObUg", "2beuhrfBZvjdkmfqV9yn",
						  "AuIhF3lUgwT0OMy8DuUx", "dVW2KAL06gB4s7rEf508", "jnsp7MGfl5wZNZVfQSvp",
						  "p26Kfhz0Iof6rJDy27vc", "bnWXfp2eexq7MPpcmRSI", "tMEU0L6RNvqDAaV6HN0e",
						  "POcbaPteUMFfltrwdu7r", "epDGhJZoKoL4i1HO67XS", "o83N1RTIeOafqBfqeAYh",
						  "aYRtwuDT8k7k7iIfTrtU", "fEPXIREoFGKXqnNKySG5", "QrqmIbVVIQzf8WKBxiga",
						  "k5NSg0Dq0b9ewfrhYdy7", "Tf9dsqBADfMeWVQGG3Zk", "dS2LouElpUXsXNCClr4B",
						  "tsvf3JaWNg5JlSDZs1Dm", "oWurB8fBAIBQq1ZnlFiR", "8YllXP80XunEXhqnjkZc",
						  "Spt36tVcEkIFjwogWli0", "c25H1u6DF9RVdagn81DA", "AjWfT7TlXgzSKOywpoTH",
						  "ZwTg8WNnmXOJKdW6ZeJv", "E9aYpoCXd1kbSWhdLOnf", "QN1iAuoSNQ5WvHeSeSSL",
						  "7g5wfNllowIaqMUVjywr", "b38gJrosdk9xEQ2K8Gbu", "KdVdRVLHJg9Bazc4cpM7",
						  "COJeGmQEzjXwqKCAnd6J", "2k6XCpXEkP7QoST6uYoy" };

	std::string y[32] = { "TZ3QuE3ZNUbFrEpQhgcY", "BX2lyPzOWRIznb34T5OT", "v7lPrSeDokdBIUXR9QGh",
						  "nAQxkuEYL5k1Er7FspKu", "r8T4oZaWBI1m7sPBEDz3", "pdxM9tJrYZskZla7L7yM",
						  "dIIx6eKTfygu24SNKa32", "tw04BOo705mdWxuDciNO", "q94icFprhKrrFXLvjEN3",
						  "uM25BWUl14NTlTwFsNIv", "2oTV9fXUESLQqzvsPFmd", "W6ASLRzrlOggx5b7CtYN",
						  "bz4BQ7rLU203RNwwmbMK", "jfWgRPiuy1P3NGDPWmbe", "PgtdYLdGuneYEUgMA8SB",
						  "eaaFugCSOOU5my4y4SkG", "gGd4FiUEJwgvhOCSHu9g", "9K0ZhqlbyDCJXYXHoEIN",
						  "VTmk8m7rbEGl8ntGpTCQ", "eRJ98PUF2tSMX6zpDOi4", "wFMJIDAbjYnJkxMxkAtL",
						  "JCOXV4iPcIt72DcNnbuY", "LsnOUrHHD2FNFH5DMvbc", "YVPp2jPqK3jmif7yY14r",
						  "JBMhRRtLY3QX3x1ZVDCs", "Uwo5PD2RLMx5ByW9Rscq", "O4Q6DPBJHOelMtBKc9GQ",
						  "Bq0H2eqnuCYqyj9F5Lkn", "P2fJf0TYN92iUXkwELjG", "f656ltXlumpc7YyPVjan",
						  "YQfr76LAA1xKokfq8HpL", "6utvLeZ9t0IM4OkdfAQ2" };

	int n[32] = { 94649484, 564998919, 89788321,
						  23121832, 655, 4,
						  897933216, 6511651, 656161,
						  5891320, 661651, 66616,
						  21351, 656615613, 66112131,
						  113213, 64984491, 4412316,
						  87133212, 6561, 11254,
						  56465651, 232112354, 55998132,
						  65165165, 65548, 213132,
						  656516516, 1132, 121112,
						  561655165, 2121112 };

	for (std::size_t i = 0; i < 32; ++i) {
		arr_str_std[i] = NAS::make_pair(x[i], y[i]);

		arr_int_std[i] = NAS::make_pair(n[i], i);
	}

	{
		NAS::map<std::string, std::string> 	map;
		std::cout << 	"\n\n__________STRING__________\n" << std::endl;

														map.insert(map.begin(), NAS::make_pair("Hello", "World"));
		std::cout << 	"\nCapacity: " <<				map.max_size()
		<< 				"\nSize    : " <<				map.size()
		<< 				"\nBegin   : " << "k: " <<		map.begin()->first << " v: " << map.begin()->second
		<< 				"End     : " << "k: " <<		(--map.end())->first << " v: " << (--map.end())->second 			<< std::endl;

														map.insert(arr_str_std, arr_str_std + 30);
		std::cout << 	"ALL: " << std::endl;
		NAS::map<std::string, std::string>::iterator	map_iter = map.begin();
		while (map_iter != map.end()){
		std::cout << "Entry   : " << "k: " <<			map_iter->first << " v: " << map_iter->second							<< std::endl;
														++map_iter;
		}
		map_iter =										map.find("Hello");
		std::cout << "Find Hello: " <<					map_iter->second														<< std::endl;

		try {
		std::cout << "At Fail:" <<						map.at("Sdasdasd")													<< std::endl;
		} catch (std::exception e) { std::cout << "Catch : " << e.what() << std::endl; };
		std::cout << "At Hello:" <<						map.at("Hello")														<< std::endl;

														map.erase("Hello");
		try {
		std::cout << "At Fail:" <<						map.at("Hello")														<< std::endl;
		} catch (std::exception e) { std::cout << "Catch : " << e.what() << std::endl; };

		NAS::map<std::string, std::string>::const_iterator maptd_cit = map.begin();
														map_iter = map.begin();
		std::cout << "Comp Iter:" <<					(map_iter == maptd_cit)												<< std::endl;

		NAS::map<std::string, std::string>				map_copy(map);
		std::cout << "Comp :" <<						(map == map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map != map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map <= map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map >= map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map < map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map > map_copy)													<< std::endl;
														map_iter = map_copy.begin();
														map_iter++;
														map_iter++;
														map_copy.erase(map_copy.begin(), map_iter);
		std::cout << "Comp :" <<						(map == map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map != map_copy)													<< std::endl;

														map.get_allocator();
														map.key_comp();
														map.value_comp();
		std::cout << "Empty :" <<						map.empty()															<< std::endl;
														map.clear();
		std::cout << "Empty :" <<						map.empty()															<< std::endl;

		std::cout << "Insert :" <<						map.insert(map.begin(), NAS::make_pair("Hello", "Wrdssds"))->second	<< std::endl;
		std::cout << "Insert :" <<						map.insert(NAS::make_pair("Hello", "World")).first->second			<< std::endl;

		std::cout << 	"Swap Before: " <<				map.size() << " " << map_copy.size()								<< std::endl;
														swap(map_copy, map);
		std::cout << 	"Swap After: " <<				map.size() << " " << map_copy.size()								<< std::endl;

		std::cout << 	"Index Op: " <<					map_copy["Hello"]														<< std::endl;
		std::cout << "Insert :" <<						map_copy.insert(NAS::make_pair("XHello", "XWorld")).first->second			<< std::endl;
		std::cout << "Insert :" <<						map_copy.insert(NAS::make_pair("AHello", "AWorld")).first->second			<< std::endl;

		std::cout << 	"Equal Range: " <<				map_copy.equal_range("Hello").first->first							<< std::endl;
		std::cout << 	"Lower Bounds: " <<				map_copy.lower_bound("Hello")->first									<< std::endl;
		std::cout << 	"Equal Range: " <<				map_copy.equal_range("Hello").second->first							<< std::endl;
		std::cout << 	"Upper Bounds: " <<				map_copy.upper_bound("Hello")->first									<< std::endl;
	}

	{
		std::cout << 	"\n\n__________INT__________\n" << std::endl;
		NAS::map<int, int> 	map;


														map.insert(map.begin(), NAS::make_pair(15, 155));
		std::cout << 	"\nCapacity: " <<				map.max_size()
		<< 				"\nSize    : " <<				map.size()
		<< 				"\nBegin   : " << "k: " <<		map.begin()->first << " v: " << map.begin()->second
		<< 				"End     : " << "k: " <<		(--map.end())->first << " v: " << (--map.end())->second 			<< std::endl;

														map.insert(arr_int_std, arr_int_std + 30);
		std::cout << 	"ALL: " << std::endl;
		NAS::map<int, int>::iterator					map_iter = map.begin();

		while (map_iter != map.end()){
		std::cout << "Entry   : " << "k: " <<			map_iter->first << " v: " << map_iter->second							<< std::endl;
														++map_iter;
		}
		map_iter =										map.find(15);
		std::cout << "Find Hello: " <<					map_iter->second														<< std::endl;

		try {
		std::cout << "At Fail:" <<						map.at(516165)													<< std::endl;
		} catch (std::exception e) { std::cout << "Catch : " << e.what() << std::endl; };
		std::cout << "At Hello:" <<						map.at(15)														<< std::endl;

														map.erase(15);
		try {
		std::cout << "At Fail:" <<						map.at(15)														<< std::endl;
		} catch (std::exception e) { std::cout << "Catch : " << e.what() << std::endl; };

		NAS::map<int, int>::const_iterator maptd_cit = map.begin();
														map_iter = map.begin();
		std::cout << "Comp Iter:" <<					(map_iter == maptd_cit)												<< std::endl;

		NAS::map<int, int>								map_copy(map);
		std::cout << "Comp :" <<						(map == map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map != map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map <= map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map >= map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map < map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map > map_copy)													<< std::endl;
														map_iter = map_copy.begin();
														map_iter++;
														map_iter++;
														map_copy.erase(map_copy.begin(), map_iter);
		std::cout << "Comp :" <<						(map == map_copy)													<< std::endl;
		std::cout << "Comp :" <<						(map != map_copy)													<< std::endl;

														map.get_allocator();
														map.key_comp();
														map.value_comp();
		std::cout << "Empty :" <<						map.empty()															<< std::endl;
														map.clear();
		std::cout << "Empty :" <<						map.empty()															<< std::endl;

		std::cout << "Insert :" <<						map.insert(map.begin(), NAS::make_pair(15,155))->second	<< std::endl;
		std::cout << "Insert :" <<						map.insert(NAS::make_pair(15, 155)).first->second			<< std::endl;

		std::cout << 	"Swap Before: " <<				map.size() << " " << map_copy.size()								<< std::endl;
														swap(map_copy, map);
		std::cout << 	"Swap After: " <<				map.size() << " " << map_copy.size()								<< std::endl;

		std::cout << 	"Index Op: " <<					map_copy[15]														<< std::endl;
		std::cout << "Insert :" <<						map_copy.insert(NAS::make_pair(20, 200)).first->second			<< std::endl;
		std::cout << "Insert :" <<						map_copy.insert(NAS::make_pair(10, 100)).first->second			<< std::endl;

		std::cout << 	"Equal Range: " <<				map_copy.equal_range(15).first->first							<< std::endl;
		std::cout << 	"Lower Bounds: " <<				map_copy.lower_bound(15)->first									<< std::endl;
		std::cout << 	"Equal Range: " <<				map_copy.equal_range(15).second->first							<< std::endl;
		std::cout << 	"Upper Bounds: " <<				map_copy.upper_bound(15)->first									<< std::endl;
	}


	{
		NAS::vector<std::string> 	vector;
		std::cout << 	"\n\n__________VECTOR__________\n" << std::endl;

														vector.insert(vector.begin(), "Hello");
		std::cout << 	"\nCapacity: " <<				vector.max_size()
		<< 				"\nSize    : " <<				vector.size()
		<< 				"\nBegin   : " <<				*vector.begin()
		<< 				"End     : " <<					*(--vector.end())														<< std::endl;
														vector.push_back("333");
														vector.push_back("555");
														vector.pop_back();

														vector.insert(vector.begin(), y, y + 30);
		std::cout << 	"ALL: " << std::endl;
		NAS::vector<std::string>::iterator	vector_iter = vector.begin();


		while (vector_iter != vector.end()){
		std::cout << "Entry   : "			 <<			*vector_iter															<< std::endl;
														++vector_iter;
		}

														vector.erase(vector.begin() + 5);
		try {
		std::cout << "At Fail:" <<						vector[324]																<< std::endl;
		} catch (std::exception e)																								 { std::cout << "Catch : " << e.what() << std::endl; };

		NAS::vector<std::string>::const_iterator		vectortd_cit = vector.begin();
														vector_iter = vector.begin();
		std::cout << "Comp Iter:" <<					(vector_iter == vectortd_cit)											<< std::endl;
		std::cout << 	"Size: " <<						vector.size()															<< std::endl;
		std::cout << 	"Back: " <<						vector.back()															<< std::endl;
		NAS::vector<std::string>						vector_copy(vector);
		std::cout << 	"Back: " <<						vector_copy.back()															<< std::endl;
		std::cout << 	"Size: " <<						vector_copy.size()															<< std::endl;
		std::cout << "Comp :" <<						(vector == vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector != vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector <= vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector >= vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector < vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector > vector_copy)													<< std::endl;
														vector_iter = vector_copy.begin();
														vector_iter++;
														vector_iter++;
														vector_copy.erase(vector_copy.begin(), vector_iter);
		std::cout << "Comp :" <<						(vector == vector_copy)													<< std::endl;
		std::cout << "Comp :" <<						(vector != vector_copy)													<< std::endl;

														vector.clear();

														vector.insert(vector.begin(),  y, y + 30);
														vector.insert(vector.begin(), 5, "300");
		std::cout << "Insert :" <<						*vector.insert(vector.begin() + 3, "666")								<< std::endl;

		std::cout << 	"Swap Before: " <<				vector.size() << " " << vector_copy.size()								<< std::endl;
														swap(vector_copy, vector);
		std::cout << 	"Swap After: " <<				vector.size() << " " << vector_copy.size()								<< std::endl;

														vector.insert(vector.begin(),  y, y + 30);

														vector_iter = vector.begin();
		while (vector_iter != 							vector.end()){
		std::cout << "Entry   : "			 <<			*vector_iter															<< std::endl;
														++vector_iter;
		}

														vector.reserve(400);


		std::cout << 	"Size: " <<						vector.size()															<< std::endl;
		std::cout << 	"Capacity: " <<					vector.capacity()								<< "\nresize"			<< std::endl;





														vector.resize(5);
		std::cout << 	"Size: " <<						vector.size()															<< std::endl;
		std::cout << 	"Capacity: " <<					vector.capacity()								<< "\nreserve"			<< std::endl;
														vector.reserve(5000);
		std::cout << 	"Size: " <<						vector.size()															<< std::endl;
		std::cout << 	"Capacity: " <<					vector.capacity()														<< std::endl;

		std::cout << 	"At: " <<						vector.at(3)															<< std::endl;
		std::cout << 	"At: " <<						vector[3]																<< std::endl;

		NAS::vector<std::string>::reverse_iterator		rit = vector.rbegin();
		std::cout << 	"ALL reverse: " << std::endl;
		while (rit != vector.rend()){
		std::cout << "Entry   : "			 <<			*rit																<< std::endl;
														++rit;
		}
		std::cout << 	"ALL: " << std::endl;
														vector_iter = vector.begin();
		while (vector_iter != vector.end()){
		std::cout << "Entry   : "			 <<			*vector_iter															<< std::endl;
														++vector_iter;
		}
														vector.clear();
		std::cout << 	"ALL afer clear: " << std::endl;
														vector_iter = vector.begin();
		while (vector_iter != vector.end()){
		std::cout << "Entry   : "			 <<			*vector_iter															<< std::endl;
														++vector_iter;
		}

	}

	return (0);
}
