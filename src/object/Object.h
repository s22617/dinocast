#ifndef DINOCAUST_OBJECT_H
#define DINOCAUST_OBJECT_H

#endif //DINOCAUST_OBJECT_H

class Object {

public:
    virtual void draw()=0;
    virtual void update(float dt)=0;
    virtual void clean()=0;
};