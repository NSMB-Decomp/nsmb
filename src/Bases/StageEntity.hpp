#include "StageActor.hpp"

class StageEntity : StageActor {
public:
    u8 _pad1[0x4c];
    Vec3_32 __1;
    Vec3_32 __2;
    Vec3_32 __3;
    u8 _pad2[0x30];
    Vec2_32 __4;
    Vec2_32 __5;
    Vec2_32 __6;
    Vec2_32 __7;
    Vec2_32 __8;
    Vec2_32 __9;

    StageEntity();
    ~StageEntity();

    bool onUpdate();
    bool preUpdate();
    void postUpdate();
    bool preRender();

    virtual bool __00();
    virtual void __01();
    virtual void __02();
    virtual void __03();
    virtual void __04();
    virtual void __05();
    virtual void __06();
    virtual void __07();
    virtual void __08();
    virtual void __09();
    virtual void __10();
    virtual void __11();
    virtual void __12();
    virtual void __13();
    virtual void __14();
    virtual void __15();
    virtual void __16();
    virtual void __17();
    virtual void __18();
    virtual void __19();
    virtual void __20();
    virtual void __21();
    virtual void __22();
    virtual void __23();
    virtual void __24();
    virtual void __25();
    virtual void __26();
    virtual void __27();
    virtual void __28();
    virtual void __29();
    virtual void __30();
    virtual void __31();
    virtual void __32();
    virtual void __33();
    virtual void __34();
    virtual void __35();
    virtual void __36();
    virtual void __37();
    virtual void __38();
    virtual void __39();
    virtual void __40();
    virtual void __41();
    virtual void __42();
    virtual void __43();
    virtual void __44();
    virtual void __45();
    virtual void __46();
};