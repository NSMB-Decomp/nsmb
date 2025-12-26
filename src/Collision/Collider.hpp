#include "../base_types.hpp"
#include "../Vec.hpp"

class Collider {
public:
    u8 _pad[0x23];
    Vec2_32 a;
    Vec2_32 b;
    Vec2_32 c;
    Vec2_32 d;
    Vec2_32 e;

    Collider();
    ~Collider();

    void func_ov000_020ab18c();
    void Reset();
    void unlink();
    void updatePosition();
    void init(Base*, void*, u32, u32, u32);
};