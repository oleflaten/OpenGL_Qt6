#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QOpenGLFunctions_4_1_Core>
#include <vector>
#include "gameobject.h"

class Triangle : public GameObject
{
public:
    Triangle();
    ~Triangle() override;

    void init() override;
    void draw() override;
};

#endif // TRIANGLE_H
