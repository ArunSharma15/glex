#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"
using namespace std;
/**
 * Pyramid Asset Class - Resonsible for storing structure of Cube class
 * and drawing.
 */
class PyramidAsset : public GameAsset {
public:
  PyramidAsset(GLfloat x,GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b);
  ~PyramidAsset();/*!< Constructor - Intialise vertices of pyramid.*/
  virtual void Draw(GLuint);/*!< Resonsible for drawing and transferring information about pyramid. */
  glm::mat4 ani;
  GLfloat angle;

private:
  GLuint element_buffer_length;	/*!< Create triangles for each face of the pyramid, 3 vertex points create a triangle, 2 triangles for the pyramid square base + 4 to form apex. */	
  GLuint colour_buffer_length;	/*!< Create a uniformly coloured cube, which means fill in all the triangles with the same RGB value.*/  
  GLuint element_buffer_token;			
  GLuint vertex_buffer_token; /*!< Resonsible for storing vertices of the pyramid.*/
  
  GLuint colour_buffer_token;
  void checkError(std::string file, int line);/*!< Check error */
};

#endif // PYRAMIDASSET_H
	
