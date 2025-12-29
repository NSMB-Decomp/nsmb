#include "Collider.hpp"

//PTMF data_ov000_020cac0c_00(func_ov000_020ac7bc, 0);
//PTMF data_ov000_020cac0c_01(func_ov000_020acc78, 0);
//PTMF data_ov000_020cac0c_02(func_ov000_020acc78, 0);
//PTMF data_ov000_020cac0c_10(func_ov000_020ac288, 0);
//PTMF data_ov000_020cac0c_11(func_ov000_020ac750, 0);
//PTMF data_ov000_020cac0c_12(func_ov000_020ac750, 0);
//PTMF data_ov000_020cac0c_20(func_ov000_020abcfc, 0);
//PTMF data_ov000_020cac0c_21(func_ov000_020ac21c, 0);
//PTMF data_ov000_020cac0c_22(func_ov000_020ac21c, 0);
//PTMF data_ov000_020cac0c_30(func_ov000_020aba68, 0);
//PTMF data_ov000_020cac0c_31(func_ov000_020abc90, 0);
//PTMF data_ov000_020cac0c_32(func_ov000_020abc90, 0);

//PTMF data_ov000_020cac0c[3] = {
//    PTMF(func_ov000_020ac7bc, 0),
//    PTMF(func_ov000_020acc78, 0),
//    PTMF(func_ov000_020acc78, 0),
//};
//PTMF __2[3] = {
//    PTMF(func_ov000_020ac288, 0),
//    PTMF(func_ov000_020ac750, 0),
//    PTMF(func_ov000_020ac750, 0),
//};
//PTMF __3[3] = {
//    PTMF(func_ov000_020abcfc, 0),
//    PTMF(func_ov000_020ac21c, 0),
//    PTMF(func_ov000_020ac21c, 0),
//};
//PTMF __4[3] = {
//    PTMF(func_ov000_020aba68, 0),
//    PTMF(func_ov000_020abc90, 0),
//    PTMF(func_ov000_020abc90, 0),
//};


Collider::Collider() {
    this->Reset();
}
Collider::~Collider() {
    this->unlink();
}
void Collider::func_ov000_020ab18c() {

}