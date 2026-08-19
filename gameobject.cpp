#include "gameobject.h"
#include "shader.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}

void GameObject::init()
{
}
