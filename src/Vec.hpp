class Vec3_32 {
public:
    i32 x;
    i32 y;
    i32 z;

    void sub(Vec3_32 *b);

    //Vec3();
    virtual inline ~Vec3_32();
};
Vec3_32::~Vec3_32() {}

class Vec2_32 {
public:
    i32 x;
    i32 y;

    //Vec3();
    virtual inline ~Vec2_32();
};
Vec2_32::~Vec2_32() {}

class Vec3_16 {
public:
    i16 x;
    i16 y;
    i16 z;

    //Vec3s();
    virtual inline ~Vec3_16();
};
Vec3_16::~Vec3_16() {}