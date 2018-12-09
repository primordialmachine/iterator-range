#include "primordialmachine/ranges/include.hpp"
#include <gtest/gtest.h>
#include <unordered_set>

TEST(ranges_tests, unordered_set_test)
{
  using namespace std;
  using namespace primordialmachine;
  using collection_type = std::unordered_set<std::string>;
  auto collection = collection_type{ "x", "y", "z" };
  auto range = iterator_range<collection_type::const_iterator>(
    collection.cbegin(), collection.cend());
  for (auto iterator = range.begin(); iterator != range.end(); ++iterator) {
    std::cout << *iterator << std::endl;
  }
  for (const auto& element : range) {
    std::cout << element << std::endl;
  }
}
