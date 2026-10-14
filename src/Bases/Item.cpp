#include "Item.hpp"

s32 Item::onCreate() {

}
s32 Item::onDestroy() {
}

Item *Item::create()
{
	return new Item();
}

ToadItem *ToadItem::create()
{
	return new ToadItem();
}
