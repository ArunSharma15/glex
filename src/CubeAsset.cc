#include "CubeAsset.h"


CubeAsset::CubeAsset(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b){ /*!Send vertice maniplation and RGB colour values for the cube.*/
   GLfloat vertex_buffer [] {
    
   -0.5f+x,-0.5f+y,-0.5f+z, //Vertex 0
   -0.5f+x, 0.5f+y,-0.5f+z, //Vertex 1
     
    0.5f+x,-0.5f+y,-0.5f+z, //Vertex 2
    0.5f+x, 0.5f+y,-0.5f+z, //Vertex 3
   
   -0.5f+x, 0.5f+y, 0.5f+z, //Vertex 4
    0.5f+x, 0.5f+y, 0.5f+z, //Vertex 5
   
    0.5f+x,-0.5f+y, 0.5f+z, //Vertex 6
   -0.5f+x,-0.5f+y, 0.5f+z  //Vertex 7
    

  };
	
	GLfloat vertex_buffer_length = sizeof(vertex_buffer);//Size of vertex buffer
	
  	GLfloat g_colour_buffer_data[]= 
	{
	//Red-Green-Blue (RGB) Colour Values - Sent from constructor.
	r,g,b, //Side 1 - Colour Triangle
	r,g,b, //Side 1 - Colour Triangle
	
	r,g,b, //Side 2 - Colour Triangle
	r,g,b, //Side 2 - Colour Triangle
	
	r,g,b, //Side 3 - Colour Triangle
	r,g,b, //Side 3 - Colour Triangle
	
	r,g,b, //Side 4 - Colour Triangle
	r,g,b, //Side 4 - Colour Triangle
	
	r,g,b,  //Side 5 - Colour Triangle
	r,g,b   //Side 5 - Colour Triangle
		
	};
	colour_buffer_length = sizeof(g_colour_buffer_data);

  //element_buffer_length = 36;
  GLuint element_buffer []  { 
    
    0,1,2 //Side 1
   ,1,3,2 //Side 1
   
   ,1,4,3 //Side 2
   ,4,3,5 //Side 2

   ,3,2,6 //Side 3
   ,3,5,6 //Side 3
   
   ,0,1,4 //Side 4
   ,0,7,4 //Side 4

   ,0,7,2 //Side 5
   ,2,6,7 //Side 5
   
   ,4,7,6 //Side 6
   ,4,6,5 //Side 6

  };
  

	element_buffer_length = sizeof(element_buffer);
	

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

  // create buffer
  glGenBuffers(1, &colour_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, g_colour_buffer_data, GL_STATIC_DRAW);
  
  // create buffer
  glGenBuffers(1,&element_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,element_buffer_length,element_buffer,GL_STATIC_DRAW);
  
  rotateX(0.0f);
}

CubeAsset::~CubeAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void CubeAsset::Draw(GLuint program_token) {
  if(GL_TRUE != glIsProgram(program_token)) {
    std::cerr << "Drawing Cube with invalid program : " << program_token << std::endl;
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

  //Possibly remove
  GLuint model_uniform =  glGetUniformLocation(program_token, "model");
  

  //glUseProgram(program_token);
  checkGLError();
  
    //glm::vec3 unit_x_axis(1.0,0.0,0.0);
    //possible remove 3
    //glm::mat4 id(1.0);
   //glm::mat4 model_matrix = glm::rotate(id,45.0f,unit_x_axis);
	//possible remove 2
   glUniformMatrix4fv(model_uniform, 1, false, glm::value_ptr(model_matrix));

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
  //glEnableVertexAttribArray(position_attrib);
	glEnableVertexAttribArray(1);
  checkGLError();

  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
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

void CubeAsset::rotateX(float angle){
	
    glm::vec3 unit_x_axis(1.0,0.0,0.0);
   model_matrix = glm::rotate(this->model_matrix,angle,unit_x_axis);
   
	
}
