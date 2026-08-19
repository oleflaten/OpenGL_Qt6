#include "vertex.h"
#include <iostream>

Vertex::Vertex() { }

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float s, float t)
{
    mXYZ = glm::vec3(x, y, z);
    mNormal = glm::vec3(r, g, b);
    mST = glm::vec2(s, t);
}

Vertex::Vertex(glm::vec3 a, glm::vec3 b , glm::vec2 c)
{
    mXYZ = a;
    mNormal = b;
    mST = c;
}

Vertex::~Vertex() { }

void Vertex::set_xyz(GLfloat *xyz)
{
    mXYZ = glm::vec3(xyz[0], xyz[1], xyz[2]);
}

void Vertex::set_xyz(GLfloat x, GLfloat y, GLfloat z)
{
    mXYZ = glm::vec3(x, y, z);
}

void Vertex::set_xyz(glm::vec3 xyz_in)
{
    mXYZ = xyz_in;
}

void Vertex::set_rgb(GLfloat *rgb)
{
    mNormal = glm::vec3(rgb[0], rgb[1], rgb[2]);
}

void Vertex::set_rgb(GLfloat r, GLfloat g, GLfloat b)
{
    mNormal = glm::vec3(r, g, b);
}

void Vertex::set_normal(GLfloat *normal)
{
    mNormal = glm::vec3(normal[0], normal[1], normal[2]);
}

void Vertex::set_normal(GLfloat x, GLfloat y, GLfloat z)
{
    mNormal = glm::vec3(x, y, z);
}

void Vertex::set_normal(glm::vec3 normal_in)
{
    mNormal = normal_in;
}

void Vertex::set_st(GLfloat *st)
{
    mST = glm::vec2(st[0], st[1]);
}

void Vertex::set_st(GLfloat s, GLfloat t)
{
    mST = glm::vec2(s, t);
}

void Vertex::set_uv(GLfloat u, GLfloat v)
{
    mST = glm::vec2(u, v);
}

std::ostream& operator<< (std::ostream& os, const Vertex& v) {
    os << std::fixed;
    os << "(" << v.mXYZ.x << ", " << v.mXYZ.y << ", " << v.mXYZ.z << ") ";
    os << "(" << v.mNormal.x << ", " << v.mNormal.y << ", " << v.mNormal.z << ") ";
    os << "(" << v.mST.x << ", " << v.mST.y << ") ";
    return os;
}

std::istream& operator>> (std::istream& is, Vertex& v) {
     // needs 4 temps to get commas and parenthesis
    char temp, temp2, temp3, temp4;
    is >> temp >> v.mXYZ.x >> temp2 >> v.mXYZ.y >> temp3 >> v.mXYZ.z >> temp4;
    is >> temp >> v.mNormal.x >> temp2 >> v.mNormal.y >> temp3 >> v.mNormal.z >> temp4;
    is >> temp >> v.mST.x >> temp2 >> v.mST.y >> temp3;
    return is;
}
