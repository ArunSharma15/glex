#include <glm/glm.hpp>
#include "BBox.h"

Bbox::Bbox(					glm::vec3 x_y_z_pos,
							glm::vec3 translate, 
                            glm::vec3 animate, 
                            glm::vec3 rotate,
                            glm::vec3 scale)
{
	Bbox::translate(glm::vec3 translate){
		
		scale = scale +  glm::vec3(0.5f,0.5f,0.1f);
	}
	
	Bbox::scale(glm::vec3 scale){
	
	scale = scale +  glm::vec3(0.5f,0.5f,0.1f);
		
	}	
	
	Bboxx::pos(glm::vec3 x_y_z_pos){
	
	x_y_z_pos = x_y_z_pos +  glm::vec3(0.5f,0.5f,0.1f);
		
	}
	
	
	
	
}



