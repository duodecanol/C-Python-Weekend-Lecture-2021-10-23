#include <iostream>
#include <bitset>
#include <climits>

template<typename T>
struct BinaryForm {
    BinaryForm(const T& v) : _bs(v) {}
    const std::bitset<sizeof(T)* CHAR_BIT> _bs;
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const BinaryForm<T>& bf) {
    return os << bf._bs;
}
