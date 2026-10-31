#include "Object112.hpp"

void *Object112::create()
{
	return new Object112();
}

void (Object112::*data_ov046_02148690)() = &Object112::func_ov046_02147a18;
void (Object112::*data_ov046_02148688)() = &Object112::func_ov046_021476a8;
void (Object112::*data_ov046_02148698)() = &Object112::func_ov046_02147278;
void (Object112::*data_ov046_021486a0)() = &Object112::func_ov046_021471dc;
void (Object112::*data_ov046_02148680)() = &Object112::func_ov046_021470c8;

// 0x02148548
ActorProfile Object112_Profile = { Object112::create, 112, 130, NULL /* TODO: 0x0214833c */ };
