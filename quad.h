#ifndef QUAD_H
#define QUAD_H

#include <QOpenGLFunctions_4_1_Core>
#include <vector>
#include "gameobject.h"

class Quad : public GameObject
{
public:
    Quad(bool smooth);
    ~Quad() override;

    void init() override;
    void draw() override;
};

#endif // QUAD_H
