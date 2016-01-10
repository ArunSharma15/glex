#ifndef CAMERA_H
#define CAMERA_H



#include "common.h" /*!< include the common.h file.*/
#include "GameAssetManager.h" /*!< include the GameAssetManager.h file.*/
#include "CubeAsset.h" /*!< include the CubeAsset.h file.*/
/**
 * A reasonable attempt at implementing a camera interface.
 * Purpose is to change camera position using uniform variables and
 * acceptance of keyboard input.
 * An attempt based on the tutorial www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/
 */
class Camera {

public:
	Camera(); /*! Constructor for the camera class */
	
	void CameraKeys(char press);/*!<Old method to modify camera - obselete remove.*/
	glm::mat4 CameraMov(char press, int mX, int mY);/*!<Method to modify camera position based on keyboard input and possibly mouse.*/
	
	
	GLfloat camPosX; /*!< X position of the camera.*/
	GLfloat camPosY; /*!< Y position of the camera.*/
	GLfloat camPosZ; /*!< Z position of the camera */
	GLfloat Mouse_Sensitivity;/*!< Float to hold sensitivity of mouse.*/
	GLfloat Player_Speed = 1.0;/*!< Float to hold information about how fast player moves.*/
	
	GLfloat Horiz_Cam_angle = 0;/*!< Float to hold information about horizontal camera angle.*/
	GLfloat Vert_Cam_angle = 0;/*!< Float to hold information about vertical camera angle.*/
	
	glm::vec3 Camera_Pos = glm::vec3(1,2,-1); /*!< 3D Floating point vector for camera position.*/

	
	GLfloat mouseDX = 1;/*!< Difference in x axis mouse movement*/
	
	GLfloat mouseDy = 1;/*!< Difference in y axis mouse movement*/
	

	
	
};
#endif //CAMERA_H
