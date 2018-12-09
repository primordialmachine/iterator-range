#include "primordialmachine/ranges/include.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(ranges_tests, vector_test)
{
  using namespace std;
  using namespace primordialmachine;
  using collection_type = std::vector<std::string>;
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
