#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include <string>
#include <vector>

struct Item {
  Item(std::string name, int sell_in, int quality) noexcept
      : name{std::move(name)}, sell_in{sell_in}, quality{quality} {}

  std::string name;
  int sell_in;
  int quality;
};

using Item_vector = std::vector<Item>;

class Gilded_rose {
public:
  Gilded_rose(Item_vector items) noexcept : items{std::move(items)} {};

  const Item_vector &get_items() const noexcept { return items; }

  void update_quality() noexcept {
    for (auto &item : items) {
      if (item.name != "Aged Brie" &&
          item.name != "Backstage passes to a TAFKAL80ETC concert") {
        if (item.quality > 0) {
          if (item.name != "Sulfuras, Hand of Ragnaros") {
            item.quality = item.quality - 1;
          }
        }
      } else {
        if (item.quality < 50) {
          item.quality = item.quality + 1;

          if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            if (item.sell_in < 11) {
              if (item.quality < 50) {
                item.quality = item.quality + 1;
              }
            }

            if (item.sell_in < 6) {
              if (item.quality < 50) {
                item.quality = item.quality + 1;
              }
            }
          }
        }
      }

      if (item.name != "Sulfuras, Hand of Ragnaros") {
        item.sell_in = item.sell_in - 1;
      }

      if (item.sell_in < 0) {
        if (item.name != "Aged Brie") {
          if (item.name != "Backstage passes to a TAFKAL80ETC concert") {
            if (item.quality > 0) {
              if (item.name != "Sulfuras, Hand of Ragnaros") {
                item.quality = item.quality - 1;
              }
            }
          } else {
            item.quality = item.quality - item.quality;
          }
        } else {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }
      }
    }
  }

private:
  Item_vector items;
};

#endif
