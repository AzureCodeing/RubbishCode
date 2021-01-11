#include <iostream>
#include <type_traits>
#include <vector>

#define DEFINE_TYPE_TRAIT(name, func)                     \
  template <typename T>                                   \
  struct name {                                           \
    template <typename Class>                             \
	static constexpr bool Test(decltype(&Class::func)*) { \
	  return true;                                        \
	}                                                     \
	template <typename>                                   \
	static constexpr bool Test(...) {                     \
	  return false;                                       \
	}                                                     \
														  \
	static constexpr bool value = Test<T>(nullptr);       \
  };                                                      \
 														  \
  template <typename T>                                   \
  constexpr bool name<T>::value;


DEFINE_TYPE_TRAIT(HasLess, operator<)  // NOLINT

template <class Value, class End>
typename std::enable_if<HasLess<Value>::value && HasLess<End>::value,
						bool>::type
	LessThan(const Value& val, const End& end) {
		return val < end;
}

template <class Value, class End>
typename std::enable_if<!HasLess<Value>::value || !HasLess<End>::value,
		 				bool>::type
	LessThan(const Value& val, const End& end) {
		return val != end;
}


#define FOR_EACH(i, begin, end)				\
	for (auto i = (true ? (begin) : (end)); \
		LessThan(i, (end)); ++i)


int main(int argc, char *argv[])
{
	std::vector<int> vec;
	FOR_EACH(i, 0, 100) { vec.push_back(i); }

	int index = 0;
	FOR_EACH(it, vec.begin(), vec.end()) { std::cout << *it << "\t"; }

	std::cout << std::endl;

	FOR_EACH(i, 0, 's') { std::cout << char(i) << "\t"; }

	std::cout << std::endl;
	
	return 0;
}
