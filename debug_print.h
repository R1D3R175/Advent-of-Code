template <typename T, typename K>
void print_pair(std::pair<T, K> const &p)
{
    std::cout << "[DEBUG] print_pair " << p.first << " - " << p.second << std::endl
              << std::endl;
}

template <typename T>
void print_vec(std::vector<T> const &v)
{
    std::cout << "<--------------- [DEBUG] print_vec --------------->\n";
    for (auto const &a : v)
        std::cout << a << " ";

    std::cout << "<--------------- [DEBUG] print_vec --------------->\n\n";
}

template <typename T>
void print_mat(std::vector<std::vector<T>> const &m)
{
    std::cout << "<--------------- [DEBUG] print_mat --------------->\n";
    for (std::vector<T> const &v : m)
    {
        for (auto const &a : v)
            std::cout << a << " ";

        std::cout << std::endl;
    }

    std::cout << "<--------------- [DEBUG] print_mat --------------->\n\n";
}