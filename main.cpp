#include <iostream>

#include "gilded_rose.h"

int main() {
  Gilded_rose gr{Item_vector{{"Aged Brie", 10, 50}}};
  gr.update_quality();
  for (const auto &item : gr.get_items()) {
    std::cout << item.name << ": " << item.quality << "\n";
  }
}
