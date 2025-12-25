#include "Collider.hpp"

Collider a = Collider();

Collider::Collider() {
    this->Reset();
}
Collider::~Collider() {
    this->unlink();
}
void Collider::func_ov000_020ab18c() {

}