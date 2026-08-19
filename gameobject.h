#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "vertex.h"
#include "shader.h"

class Renderer;

class GameObject : public QOpenGLFunctions_4_1_Core {
public:
    GameObject();
    virtual ~GameObject();
    virtual void init();
    virtual void draw()= 0;

    glm::mat4 mMatrix{glm::mat4(1.0f)};

    std::string mName;

    Renderer *mRenderWindow{nullptr}; //Just to be able to call checkForGLerrors()

protected:
    std::vector<Vertex> mVertices;
    std::vector<GLuint> mIndices;

    GLuint mVAO{0};
    GLuint mVBO{0};
    GLuint mEAB{0}; //holds the indices (Element Array Buffer - EAB)

};
#endif // GAMEOBJECT_H

