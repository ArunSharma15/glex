#include "GameWorld.h"
#include <Camera.h>
#include <PyramidAsset.h>

GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);

  
  int map[7][7][7] = {
  //Note that actual map is turned on it's side.
  {1,1,1,2,1,3,3},
  {1,1,1,1,1,1,1}, 
  {1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1},
  {1,1,1,2,1,1,1}
};
    
  
 
  
  for(int countX = 0; countX<7; countX++){
  for(int countY = 0; countY<7; countY++){
  for(int countZ = 0; countZ<7; countZ++){
  
  if(map[countX][countY][countZ] == 1){
  //Demonstrate single file blocks
  //asset_manager->AddAsset(std::make_shared<CubeAsset>(3*countX-3,-3-countY,0.32*countZ));
  
  asset_manager->AddAsset(std::make_shared<CubeAsset>(countX-3,-3-countY,0.32*countZ));
  
  }
  	if(map[countX][countY][countZ] == 2){
	 asset_manager->AddAsset(std::make_shared<CubeAsset>(countX-3,-2-countY,0.32*countZ));
	}
	
	  if(map[countX][countY][countZ] == 3){
		 //asset_manager->AddAsset(std::make_shared<PyramidAsset>(countX-3,-2-countY,0.32*countZ));
		}

}
}
}
}

void GameWorld::Draw() {
  //auto cam = std::shared_ptr<Camera>();
  //cam -> CameraMov();
  asset_manager->Draw();
}
