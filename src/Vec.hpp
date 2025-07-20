class Vec3 {
public:
    u32 fake_vtable; // To keep data sizes correct in Actor.hpp
    i32 x;
    i32 y;
    i32 z;

    void sub(Vec3 a, Vec3 b);

    //virtual ~Vec3();
};

class Vec3s {
public:
    i16 x;
    i16 y;
    i16 z;

    virtual ~Vec3s();
};