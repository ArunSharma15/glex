#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#ifdef _APPLE_
#include <OpenGL/gl.h>
#else

#include <GL/gl.h>
#endif

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"
/**
 * Cube Asset Class - Resonsible for storing structure of Cube class
 * and drawing.
 */
class CubeAsset : public GameAsset { 
 public:
  CubeAsset(GLfloat x,GLfloat y, GLfloat z,GLfloat r, GLfloat g, GLfloat b);
  ~CubeAsset(); /*!< Constructor - Intialise vertices of cube.*/
  virtual void Draw(GLuint);/*!< Resonsible for drawing and transferring information about Cube. */
 void rotateX(float);
 private:
  GLuint element_buffer_length; /*!< Create triangles for each face of the cube, 3 vertex points create a triangle, 2 triangles for a cube face. */	
  GLuint colour_buffer_length;  /*!< Create a uniformly coloured cube, which means fill in all the triangles with the same RGB value.*/ 
  GLuint element_buffer_token;
  GLuint vertex_buffer_token; /*!< Resonsible for storing vertices of the cube.*/
    glm::mat4 ani;
  GLuint colour_buffer_token;
  glm::mat4 model_matrix;
};

#endif // CUBEASSET_H
