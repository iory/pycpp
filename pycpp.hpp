#ifndef PYCPP_HPP
#define PYCPP_HPP

#include <bitset>
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>

namespace pycpp
{

template <class T>
std::string bin_prefix(T& num) {
    std::string ret = "";
    if (num < 0) {
        num = -num;
        ret += "-";
    }
    ret += "0b";
    return ret;
}

std::string bin(int num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<32>(num).to_string();
    return ret;
}

std::string bin(unsigned int num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<32>(num).to_string();
    return ret;
}

std::string bin(char num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<8>(num).to_string();
    return ret;
}

std::string bin(unsigned char num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<8>(num).to_string();
    return ret;
}

std::string bin(long long int num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<64>(num).to_string();
    return ret;
}

std::string bin(unsigned long long int num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<64>(num).to_string();
    return ret;
}

std::string bin(float num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<32>(num).to_string();
    return ret;
}

std::string bin(double num) {
    std::string ret = bin_prefix(num);
    ret += std::bitset<64>(num).to_string();
    return ret;
}

template <class From>
std::string str(From from) {
    return boost::lexical_cast<std::string>(from);
}

template <class From>
std::string hex(From from) {
    std::string ret;
    std::stringstream ss;
    ss << std::hex << from;
    ss >> ret;
    return std::string("0x") + ret;
}

template <class From>
std::string oct(From from) {
    std::string ret;
    std::stringstream ss;
    ss << std::oct << from;
    ss >> ret;
    return std::string("0") + ret;
}

// check is_iterable
// http://ideone.com/ExTsEO
namespace detail
{
// To allow ADL with custom begin/end
using std::begin;
using std::end;

template <typename T>
auto is_iterable_impl(int)
    -> decltype (
                 begin(std::declval<T&>()) != end(std::declval<T&>()), // begin/end and operator !=
                 ++std::declval<decltype(begin(std::declval<T&>()))&>(), // operator ++
                 *begin(std::declval<T&>()), // operator*
                 std::true_type{});

template <typename T>
std::false_type is_iterable_impl(...);

}

template <typename T>
using is_iterable = decltype(detail::is_iterable_impl<T>(0));

template <class From>
bool all(From from) {
    if(is_iterable<From>::value) {
        for(auto value : from) {
            if(!value) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class From>
bool any(From from) {
    if(is_iterable<From>::value) {
        for(auto value : from) {
            if(value) {
                return true;
            }
        }
    }
    return false;
}

} // end of pycpp namespace

#endif
