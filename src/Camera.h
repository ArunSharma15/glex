#ifndef CAMERA_H
#define CAMERA_H



#include "common.h"
#include "GameAssetManager.h"
#include "CubeAsset.h"

class Camera {

public:

	
	void CameraKeys(char press);
	void CameraMov();
	
	GLfloat Mouse_Sensitivity = 0.05f;
	GLfloat Player_Speed = 1.0;
	
	GLfloat Camera_Horizontal = 0.0;
	GLfloat Camera_Vertical   = 0.0;
	
	glm::vec3 Camera_Position = glm::vec3(1,2,-1);
	glm::vec3 Movement_Z;
	glm::vec3 Movement_X;
	
	
	

	
	
};
#endif //CAMERA_H
