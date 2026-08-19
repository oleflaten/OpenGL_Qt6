#ifndef XYZ_H
#define XYZ_H

#include <QOpenGLFunctions_4_1_Core>
#include "gameobject.h"

class XYZ : public GameObject
{
public:
   XYZ();
   ~XYZ() override;

   void init() override;
   void draw() override;
};

#endif // XYZ_H
