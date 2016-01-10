#include <Camera.h>
#include <GameWorld.h>
#include <CubeAsset.h>
#include <GameAssetManager.h>
#include <glm/ext.hpp>
//An attempt based on the tutorial www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/


Camera::Camera(){
	
	
}

void Camera::CameraKeys(char press){
	/**List of if conditons that will modify camera position if certain key presses are sent to it. */
	/**Pretty much empty */

}

glm::mat4 Camera::CameraMov(char press, int mX, int mY){
	
	mX = -mX;
	mY = -mY;
	
	Horiz_Cam_angle += 1 * mY;
	Vert_Cam_angle += 1 * mX;
	
	/*! Switch case statement is better than using lots of IF Statements.*/
	switch(press){
	
	case 'w':
	//Camera_Pos += glm::vec3(cos(Vert_Cam_angle) * sin(Horiz_Cam_angle), 0,cos(Vert_Cam_angle) * cos(Horiz_Cam_angle)) * Player_Speed;
	std::cout << "W Cam Class" << std::endl;
	break;
	
	case 'a':
	//Camera_Pos -= right * Player_Speed;
	break;
	
	case 's':
	//Camera_Pos += right * Player_Speed;
	break;
	
	case 'd':
	//Camera_Pos -= glm::vec3(cos(Vert_Cam_angle) * sin(Horiz_Cam_angle), 0,cos(Vert_Cam_angle) * cos(Horiz_Cam_angle)) * Player_Speed;
	break;
	
	default:
	
	break;
	
	
	}

	


}
