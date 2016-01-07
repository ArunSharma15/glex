#include <Camera.h>
#include <GameWorld.h>
#include <CubeAsset.h>
#include <GameAssetManager.h>



void Camera::CameraKeys(char press){
	
	if(press == 'w') {
	Camera_Position += Movement_Z * Player_Speed;	
	std::cout << "W key pressed" << std::endl;
}
	if(press == 'a') {
	Camera_Position -= Movement_X * Player_Speed;	
	std::cout << "A key pressed" << std::endl;
}	
	if(press == 's') {
	Camera_Position -= Movement_Z * Player_Speed;	
	std::cout << "S key pressed" << std::endl;
}	
	if(press == 'd') {
	Camera_Position += Movement_X * Player_Speed;	
	std::cout << "D key pressed" << std::endl;
	
	}

}

void Camera::CameraMov(){

glm::vec3 direction(
cos(Camera_Vertical) * sin(Camera_Horizontal),
sin(Camera_Vertical),
cos(Camera_Vertical) * cos(Camera_Horizontal)
);	

glm::vec3 Movement_Direction(
cos(Camera_Vertical) * sin(Camera_Horizontal),
0,
cos(Camera_Vertical) * cos(Camera_Horizontal)
);

Movement_Z=Movement_Direction;

Movement_X = glm::vec3(
sin(Camera_Horizontal - 3.14f/2.0f),
0,
cos(Camera_Horizontal - 3.14f/2.0f)

);

glm::vec3 vup = glm::cross(Movement_X, Movement_Direction);
glm::mat4 C_Projection = glm::perspective(45.0f,16.0f/9.0f,0.1f,1000.0f);
glm::mat4 C_View = glm::lookAt(
		  Camera_Position,
		  Camera_Position + direction,
		  vup
);
glm::mat4 C_Model(1.0f);

glUniformMatrix4fv(0,1,GL_FALSE, &C_Projection[0][0]);
glUniformMatrix4fv(1,1,GL_FALSE, &C_View[0][0]);
glUniformMatrix4fv(2,1,GL_FALSE, &C_Model[0][0]);



}
