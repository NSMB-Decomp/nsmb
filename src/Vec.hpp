class Vec3_32 {
public:
    i32 x;
    i32 y;
    i32 z;

    void sub(Vec3_32 a, Vec3_32 b);

    //Vec3();
    virtual ~Vec3_32();
};

class Vec3_16 {
public:
    i16 x;
    i16 y;
    i16 z;

    //Vec3s();
    virtual ~Vec3_16();
};