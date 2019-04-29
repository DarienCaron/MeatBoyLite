
Test Mode: 5/5

Game Programming Requirements (30%):

 7% - Game rules/Physics     - 7/7
 3% - Audio                  - 3/3
 3% - Saved game             - 3/3
 4% - Scene management       - 4/4
 3% - Tweening               - 2/4
10% - Polish                 - 7/10

Graphics Requirements (30%):

10% - Lighting               - 7/10
 5% - Rendering to a texture - 5/5
 5% - Cubemaps               - 3/5
10% - Polish                 - 7/10




Team members:
    - Stefano Pinto
    - Darien Caron

Game Description:
    - A mockup of "Super Meat Boy" 

Controls: 
Left/Right = Movement
Spacebar   = Jump
Enter      = Select

Debug Keys:
Camera Rotation - 'R'
Meat Boy Manipulation - 'M'
Pause - 'P'


Completed:
- Bloodtrail gets placed once, working out some techincal bugs. They also aren't rendering in front of the ground block.
- Player can properly jump when they press up
- The saw will change to a bloody saw on contact.
- Scene Manager added
- Preloaded scene implemented.

Week 2 Goals:
- Get Audio working
- Get Turrets and missiles working
- Get State Machine in place
- Get player to reset when they die

Completed:
- Audio is in place for certain elements.
- Turrets have a state machine and will either follow the player or remain idle.
- Missiles are launched from the front of the turret and go towards the player
- Player resets when they are struck by missile and saw blade.

Week 3 Goals:
- Add multiple scenes
- Add tweening
- Add more physics to Meat Boy's movement
- Add lighting

Completed:
- Added scene management with a title screen, level select screen and and our actual levels.
- Added our light shaders, helper files, and began implementing light to Meat Boy.
- Tweening on level select screen.
- Wall jumping physics.

Week 4 goals:
- Add sound cues
- Add Rendering to a texture
- Add Cubemap/skybox
- Add a second map

Completed:
- SoundCue class in place
- Rendering to a texture works 
- Cubemap/Skybox 
- Second map in place just need to work out some physics problems.



Game Programming Requirements (30%):

 7% - Game rules/Physics
    - Collision filtering is implemented.
    - An object pooling class has been implemented.
    - A raycast has been implemented. The turret object uses it and a missle fires when Meat Boy crosses it. 
    - Revolute joints are working. We have one as an example with the sawblade.	 
    - Added wall jump physics. We may fine tune them if we have enough time for the sake of polish.
    - Turrets follow Meat Boy when he hits the raycast by way of a state machine. 
    - A "lerp" camera now follows Meat Boy.
    - Added an ImGui debugger.
	- In Level 2 a sawblade launcher shoots miniature sawblades downward as another obstacle. 
  
 3% - Audio
    - Some sounds like jump, death, and the missile shoot, play. Audio cue has also been implemented.

 3% - Saved game
    - Game can be saved and loaded, a json file is generated and can be read.


 4% - Scene management
    - Added a Scene Manager with a pre-loaded scene. 
    - There is a title screen, level select screen and then the actual level which can all be accessed in this build.
    - At the moment, no matter what level you select, it just brings you to level 1 because level 2 isn't implemented. 
 
 3% - Tweening
    - On the level select screen you can press left and right to have Meat Boy's sprite move in between 
      the icons for level 1 and 2. Currently there is an issue where if you press one direction while Meat Boy
      is moving in the opposite direction the tweening gets stuck. 

10% - Polish
    - Level icons the on the level select screen change colour when the level is complete.
	- When a bandage is collected an icon displaying that also appears on the level select screen
	- A state machine for our turret. It only tries tracking Meat Boy when he is within the radius.

 5% - Debugging
	- Debugging options for Meat Boy's jump strength, and the ability to kill him for the sake of resetting him.
	- Debugging option for rotating the camera on the x and y axis. This is mostly for the purpose of looking at the cubemap. 
	- Debugging option for skipping to the end of a level. After clicking 'Skip to end of Level' you must unclick the box to regain control. 
       
Graphics Requirements (30%):

10% - Lighting
    - Three separate point lights have been added in Level 1.  
  
 5% - Rendering to a texture
    - The textures of Level 1 and 2 are rendered to a plane in the level select screen. Depending on what level the player hovers over
	said level will be rendered as a preview before actually entering it. 
  
 5% - Cubemaps
    - A cubemap is being rendered to the scenes of both levels. You can use the camera rotation debug
  
10% - Polish
    - Sawblade texture changes to a bloody texture when Meat Boy collides with it. 
    - The title screen has a quick graphical change for comedic effect after pressing start. 
    - Added a revolute joint sawblade to the title screen for extra JUICE.
	- Meat Boy has a bloody trail behind when he moves in a straight line for a second or two.
	To see this in action walk along the lower platform in Level 1.







