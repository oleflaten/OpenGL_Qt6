#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include "gameobject.h"

///Simple Light class that has a small mesh and some light parameters
class Light : public GameObject
{
public:
    ///Light class with mesh and light parameters
    Light();
    virtual void init() override;
    virtual void draw() override;

    GLfloat mAmbientStrenght{0.3f};
    glm::vec3 mAmbientColor{0.3f, 0.3f, 0.3f};   //Grey

    GLfloat mLightStrenght{0.7f};
    glm::vec3 mLightColor{0.9f, 0.9f, 0.3f};     //Yellow

    GLfloat mSpecularStrenght{0.9f};
    GLint mSpecularExponent{4};
};

#endif // LIGHT_H
