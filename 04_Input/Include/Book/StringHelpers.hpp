#ifndef BOOK_STRINGHELPERS_HPP
#define BOOK_STRINGHELPERS_HPP

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

#include <Book/StringHelpers.inl>
#endif // BOOK_STRINGHELPERS_HPP
