#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

#include <GL/gl.h>


/**
 * Abstract class
 */
class GameAsset {
 public:
  virtual void Draw(GLuint) = 0;/*! Draw method */

};

#endif
