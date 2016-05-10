#include "GameWorld.h"

/*! GameWorld class - responsible for holding information about the world and applying draw commands
 * 
 * 
 *
 * 
 * */
 
 int i = 0;
 
GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);

  
   
  /*!3D Array to store block world configuration*/
  int map[7][7][7] = { 
  //Note that actual map is turned on it's side.
  //<- Front | Back->
  // Y = 0				Y = 1			Y=2				Y=3					Y=4				Y=5				Y=6
  /*x=0*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,4,0,0,0,4,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}},
  /*x=1*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}}, 
  /*x=2*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,4,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}},
  /*x=3*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}},
  /*x=4*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,4,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}},
  /*x=5*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,4,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}},
  /*x=6*/{{ 1,1,1,5,5,5,5},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 6,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0}}  
};
   
  // 1 = Sand/Yellow Blocks
  // 2 = Wood/Brown Blocks
  // 4 = Clouds/White Blocks
  // 5 = Water/Blue Blocks
  // 6 = Animated Block
  
  // Shapes will also be passed RGB Colour values, so that they can be set from here
  // As opposed to making new shapes.
 
  
  for(int countX = 0; countX<7; countX++){
  for(int countY = 0; countY<7; countY++){
  for(int countZ = 0; countZ<7; countZ++){
  
  if(map[countX][countY][countZ] == 1){
  //Sand
  //Format as follows(X Pos   , Y Pos   , Z Pos      ,R , G , B )
  asset_manager->AddAsset(std::make_shared<CubeAsset>(countX,countY+6,countZ,1.0,1.0,0.0));
  
  }
  	if(map[countX][countY][countZ] == 2){	//Tree
	 asset_manager->AddAsset(std::make_shared<CubeAsset>(countX,countY+6,countZ,0.5,0.35,0.05));
	}
	
		if(map[countX][countY][countZ] == 4){ //Clouds
		 
		  asset_manager->AddAsset(std::make_shared<PyramidAsset>(countX,countY+6,countZ,1.0,1.0,1.0));
		}

		if(map[countX][countY][countZ] == 5){ //Water
		 asset_manager->AddAsset(std::make_shared<CubeAsset>(countX,countY+6,countZ,0.0,0.0,1.0));
		}
	
		if(map[countX][countY][countZ] == 6){//Test Animation
		
			asset_manager->AddAsset(std::make_shared<CubeAsset>(countX,countY+i,countZ,0.4,0.0,1.0));

	}

}
}
}
}


void GameWorld::counter(){
	
	i += 10;
	cout << "counter" + i<< endl;
}

void GameWorld::bindtest(){
	cout << "Method 'bindtest' succesfully called" << endl;
}

void GameWorld::bindtesttwo(){
	cout << "Method 'bindtest2' succesfully called" << endl;
}

void GameWorld::Draw() {
  
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
	
asset_manager->UpdateCameraPosition(input_direction, mouseX, mouseY);	
	
}
