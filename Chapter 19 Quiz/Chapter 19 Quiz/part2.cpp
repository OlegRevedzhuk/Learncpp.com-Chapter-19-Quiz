/*
2) Write a Pair class that allows you to specify separate types for each of the two values in the pair.

Note: We’re naming this class differently from the previous one because C++ does not currently allow you to “overload” classes 
that differ only in the number or type of template parameters.

The following main program should work and print:
Pair: 5 6.7
Pair: 2.3 4
*/

#include <iostream>
#include <string>

template<class T, class T1>
class Pair {
private:
	T m_first;
	T1 m_second;

public:
	Pair(const T t, const T1 t1) : m_first{ t }, m_second{ t1 } {}

	T first() const { return m_first; }
	T1 second() const { return m_second; }
};

/*
int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
*/

/*
3) A string-value pair is a special type of pair where the first value is always a string type, and the second value can be any type.
Write a template class named StringValuePair that inherits from a partially specialized Pair class
(using std::string as the first type, and allowing the user to specify the second type).

The following main program should run and print:

Pair: Hello 5
*/

template<class T1>
class StringValuePair : public Pair<std::string, T1> {
public:
	StringValuePair(const std::string &str, const T1 t1) : Pair<std::string, T1>(str, t1) {}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}