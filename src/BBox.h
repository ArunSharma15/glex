#ifndef BBox_H
#define BBox_H


class BBox
{
	
private:
	
public:	



BBox(						glm::vec3 x_y_z_pos, 
							glm::vec3 translate, 
                            glm::vec3 animate, 
                            glm::vec3 rotate,
                            glm::vec3 scale);
virtual ~ BBox();

void translate(glm::vec3);
	
	
};


#endif
