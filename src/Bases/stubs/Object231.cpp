#include "Object231.hpp"

void *Object231::create()
{
	return new Object231();
}

void (Object231::*data_ov097_02188bc0[4])() = {
    &Object231::func_ov097_02185b74,
    &Object231::func_ov097_02185b24,
    &Object231::func_ov097_02185a08,
    &Object231::func_ov097_021859b8,
};
void (Object231::*data_ov097_02188be0[4])() = {
    &Object231::func_ov097_02185b28,
    &Object231::func_ov097_02185a0c,
    &Object231::func_ov097_021859bc,
    &Object231::func_ov097_0218585c,
};

// 0x02188830
ActorProfile Object231_Profile = { Object231::create, 231, 194, NULL /* TODO: 0x02185790 */ };
