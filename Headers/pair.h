#ifndef _UTILITY_
#include <utility>
#endif

template <typename T, typename K>
void print_pair(std::pair<T, K> const &p)
{
    std::cout << "\n[DEBUG] print_pair " << p.first << " - " << p.second << std::endl
              << std::endl;
}