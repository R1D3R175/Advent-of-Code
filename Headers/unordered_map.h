#ifndef _UNORDERED_MAP_
#include <unordered_map>
#endif

template <typename T, typename K>
void print_umap(std::unordered_map<T, K> const &um)
{
    std::cout << "\n<--------------- [DEBUG] print_umap --------------->\n";
    for (auto const &p : um)
    {
        std::cout << p.first << " - " << p.second << std::endl;
    }
    std::cout << "<--------------- [DEBUG] print_umap --------------->\n\n";
}