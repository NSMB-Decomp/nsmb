#include "Object114.hpp"

void *Object114::create()
{
	return new Object114();
}

void (Object114::*data_ov040_02146c00)() = &Object114::func_ov040_02143634;
void (Object114::*data_ov040_02146c08)() = &Object114::func_ov040_02143550;
void (Object114::*data_ov040_02146c38)() = &Object114::func_ov040_02143488;
void (Object114::*data_ov040_02146c30)() = &Object114::func_ov040_021433c8;
void (Object114::*data_ov040_02146c28)() = &Object114::func_ov040_02143190;
void (Object114::*data_ov040_02146c20)() = &Object114::func_ov040_02142f74;
void (Object114::*data_ov040_02146c18)() = &Object114::func_ov040_02142620;
void (Object114::*data_ov040_02146c10)() = &Object114::func_ov040_021421cc;

// 0x02146720
ActorProfile Object114_Profile = { Object114::create, 114, 132, NULL /* TODO: 0x02143b04 */ };
