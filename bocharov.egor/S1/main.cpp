#include <iostream>
#include "actions.hpp"

int main()
{
  bocharov::pairs_list_t pairs_list;
  std::string list_name = "";

  while (std::cin >> list_name)
  {
    bocharov::list_t list;
    unsigned long long num = 0;
    while (std::cin >> num)
    {
      list.push_back(num);
    }
    pairs_list.push_back(std::make_pair(list_name, list));
    std::cin.clear();
  }

  if (pairs_list.empty())
  {
    std::cout << 0 << '\n';
    return 0;
  }
  std::cout << pairs_list.cbegin()->first;
  for (auto i = ++pairs_list.cbegin(); i != pairs_list.cend(); ++i)
  {
    std::cout << ' ' << i->first;
  }
  std::cout << '\n';
  try
  {
    bocharov::print_lists_info(std::cout, pairs_list);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Memory allocation error\n";
    return 1;
  }
  catch (const std::overflow_error &)
  {
    std::cerr << "Overflow error\n";
    return 1;
  }
  std::cout << '\n';
}
