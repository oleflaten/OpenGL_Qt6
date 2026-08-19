#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>
#include <iostream>
#include <fstream>

#include "gltypes.h"

class Vertex {
public:
    Vertex();
    Vertex(float x, float y, float z, float r, float g, float b, float s = 0.f, float t = 0.f);
    Vertex(glm::vec3 a, glm::vec3 b, glm::vec2 c);
    ~Vertex();

     //! Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::ostream& operator<< (std::ostream&, const Vertex&);

     //! Overloaded ostream operator which reads all vertex data from an open textfile stream
    friend std::istream& operator>> (std::istream&, Vertex&);

    void set_xyz(GLfloat *xyz);
    void set_xyz(GLfloat x, GLfloat y, GLfloat z);
    void set_xyz(glm::vec3 xyz_in);
    void set_rgb(GLfloat *rgb);
    void set_rgb(GLfloat r, GLfloat g, GLfloat b);
    void set_normal(GLfloat *normal);
    void set_normal(GLfloat x, GLfloat y, GLfloat z);
    void set_normal(glm::vec3 normal_in);
    void set_st(GLfloat *st);
    void set_st(GLfloat s, GLfloat t);
    void set_uv(GLfloat u, GLfloat v);

private:
    glm::vec3 mXYZ;
    glm::vec3 mNormal;
    glm::vec2 mST;
};

#endif // VERTEX_H
