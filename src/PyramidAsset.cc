#include "PyramidAsset.h"
#include "Camera.h"
#include <glm/ext.hpp>
/**
 * Pyramid Class - Responsible for spawning a pyramid to the block world.
 * X,Y,Z coordinates for each pyramid.
 */
PyramidAsset::PyramidAsset(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b) {
  // model coordinates, origin at centre.
  GLfloat vertex_buffer [] {
    
	-0.5f+x,-0.5f+y,-0.5f+z, //Vertex for Pyramid Square Base
	 0.5f+x,-0.5f+y,-0.5f+z, //Vertex for Pyramid Square Base
	 
	 0.5f+x,-0.5f+y, 0.5f+z, //Vertix for Pyramid Square Base
	-0.5f+x,-0.5f+y, 0.5f+z, //Vertix for Pyramid Square Base
	
	 0.0f+x, 0.0f+y, 0.0f+z //Vertix for Pyramid apex.
    

  };
  GLfloat vertex_buffer_length = sizeof(vertex_buffer);
  
  GLfloat colour_buffer[] = {
	  
	r,g,b, //RGB colour value for square base.
	r,g,b,
	r,g,b,
	
	r,g,b,
	r,g,b,
	r,g,b,
	
	r,g,b,
	r,g,b,
	r,g,b
	  
  };
  
  colour_buffer_length = sizeof(colour_buffer);
  
  

  //element_buffer_length = 18;
  GLuint element_buffer []  {

    0,1,3,//Triangle 1 to form part of Pyramid square base.
    1,3,2,//Triangle 2 to form part of Pyramid square vase,
    
    0,1,4,//Triangle 3 to go from base to apex.
    1,2,4,//Triangle 4 to go from base to apex.
    
    0,4,3,//Triangle 5 to go from base to apex.
    3,4,2 //Triangle 6 to go from base to apex.

  };
  element_buffer_length = sizeof(element_buffer);
  

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);


  glGenBuffers(1,&colour_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer,GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

PyramidAsset::~PyramidAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif


void PyramidAsset::checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void PyramidAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "P: Drawing Cube with invalid program" << std::endl;
    return;
  }
  
  //glm::mat4 model      = glm::mat4(1.0f);
  //model = glm::rotate(model, 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  //glUniformMatrix4fv(0, 1, GL_FALSE, &model[0][0]);
  
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();
  
  /*TEST CODE - Create animation mat to send to translate shader*/
  // Then bung in an angle to rotate the clouds around specific point.
  GLuint animation = glGetUniformLocation(program_token, "animation");
  angle += 0.001f;
  ani = glm::rotate(glm::mat4(1.0f),angle,glm::vec3(0,0.5,0));
  glUniformMatrix4fv(animation,1,GL_FALSE,&ani[0][0]);
  /*END TEST CODE*/

  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(1);
  checkGLError();
  
  glBindBuffer(GL_ARRAY_BUFFER,colour_buffer_token);
  glVertexAttribPointer(
						1,
						3,
						GL_FLOAT,
						GL_FALSE,
						0,
						(void*)0
  						);
  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}

