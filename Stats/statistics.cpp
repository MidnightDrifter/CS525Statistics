#include "statistics.h"
#include <numeric> //accumulate
#include <cmath> //sqrt
#include <iterator> //ostream_iterator, back_inserter
#include <iomanip> //setfill setw
#include <iostream> //cout

Statistics::Statistics() : data() {}

std::ostream& operator<<( std::ostream& out, Statistics const& stat ) {
    std::copy( stat.data.begin(),  stat.data.end(),
               std::ostream_iterator<int>( out, " " ) );
    return out;
}

std::istream& operator>>( std::istream& in, Statistics & stat ) {
    std::copy( std::istream_iterator<int>(in),
               std::istream_iterator<int>(),
               std::back_inserter( stat.data ) );
    return in; 
}

