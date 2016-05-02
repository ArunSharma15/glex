#include "GameWorld.h"

/*! GameWorld class - responsible for holding information about the world and applying draw commands
 * 
 * 
 *
 * 
 * */
GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);

  
   
  /*!3D Array to store block world configuration*/
  int map[7][7][7] = { 
  //Note that actual map is turned on it's side.
  //<- Back | Front->
  { 5,5,5,5,5,5,5},
  { 5,5,5,5,5,5,5}, 
  { 1,1,1,1,1,4,1},
  { 1,1,1,1,1,1,1},
  { 1,2,4,1,1,1,1},
  { 1,1,1,1,1,1,1},
  { 1,1,1,1,1,4,1}  
};
   
  // 1 = Sand/Yellow Blocks
  // 2 = Wood/Brown Blocks
  // 4 = Clouds/White Blocks
  // 5 = Water/Blue Blocks
  
  // Shapes will also be passed RGB Colour values, so that they can be set from here
  // As opposed to making new shapes.
 
  
  for(int countX = 0; countX<7; countX++){
  for(int countY = 0; countY<7; countY++){
  for(int countZ = 0; countZ<7; countZ++){
  
  if(map[countX][countY][countZ] == 1){
  //Demonstrate single file blocks
  //asset_manager->AddAsset(std::make_shared<CubeAsset>(3*countX-3,-3-countY,0.32*countZ,0.0,1.0,0.0));
  
								   //Sand
								  //Format as follows(X Pos   , Y Pos   , Z Pos      ,R , G , B )
  asset_manager->AddAsset(std::make_shared<CubeAsset>(countX-3,-3-countY,0.30*countZ,1.0,1.0,0.0));
  
  }
  	if(map[countX][countY][countZ] == 2){	//Tree
	 asset_manager->AddAsset(std::make_shared<CubeAsset>(countX-3,-4-countY,0.30*countZ,0.5,0.35,0.05));
	}
	
		if(map[countX][countY][countZ] == 4){ //Clouds
		 
		  asset_manager->AddAsset(std::make_shared<PyramidAsset>(countX-3,-0-countY,0.50*countZ,1.0,1.0,1.0));
		}

		if(map[countX][countY][countZ] == 5){ //Water
		 asset_manager->AddAsset(std::make_shared<CubeAsset>(countX-3,-3-countY,0.30*countZ,0.0,0.0,1.0));
		}
}
}
}
}

void GameWorld::Draw() {

  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
	
asset_manager->UpdateCameraPosition(input_direction, mouseX, mouseY);	
	
}
