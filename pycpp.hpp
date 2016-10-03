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
    return ret;
}

template <class From>
std::string oct(From from) {
    std::string ret;
    std::stringstream ss;
    ss << std::oct << from;
    ss >> ret;
    return ret;
}

} // end of pycpp namespace

#endif
