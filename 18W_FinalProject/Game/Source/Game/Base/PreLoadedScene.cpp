#include "GamePCH.h"

PreLoadedScene::PreLoadedScene(Game * pGame, ResourceManager * pResources, std::string name)
	: Scene(pGame, pResources, name)
{
}

PreLoadedScene::~PreLoadedScene()
{
}

void PreLoadedScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
	Scene::OnSurfaceChanged(width, height);
}

void PreLoadedScene::LoadContent()
{
	Scene::LoadContent();

    // Load our sound and sound players
    {
        m_pResources->AddSoundPlayer("Level1_SoundPlayer", new SoundPlayer());
        m_pResources->AddSoundPlayer("Level1_MusicPlayer", new SoundPlayer());
        m_pResources->AddSoundPlayer("Title_SoundPlayer", new SoundPlayer());
        m_pResources->AddSoundPlayer("Title_MusicPlayer",  new SoundPlayer());
        m_pResources->AddSoundPlayer("Level_Select_Player", new SoundPlayer());

        m_pResources->AddSoundObject("Splat", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_death_01.wav"));
        m_pResources->AddSoundObject("Splat2", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_death_02.wav"));
        m_pResources->AddSoundObject("Splat3", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_death_03.wav"));

        m_pResources->AddSoundObject("Level Select Theme", m_pResources->GetSoundPlayer("Level_Select_Player")->LoadSound("Data/Sounds/level_select_theme.wav"));

        m_pResources->AddSoundObject("Saw Launch1", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/saw_launcher_001.wav"));
        m_pResources->AddSoundObject("Saw Launch2", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/saw_launcher_002.wav"));

        m_pResources->AddSoundObject("Punch", m_pResources->GetSoundPlayer("Title_SoundPlayer")->LoadSound("Data/Sounds/punch_01.wav"));

        m_pResources->AddSoundObject("Bandage Pickup", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/bandage_pickup.wav"));

        m_pResources->AddSoundObject("Jump", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_jump_01.wav"));
        m_pResources->AddSoundObject("Jump2", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_jump_02.wav"));
        m_pResources->AddSoundObject("Jump3", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_jump_03.wav"));
        m_pResources->AddSoundObject("Jump4", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/meat_jump_04.wav"));

        m_pResources->AddSoundObject("Theme", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/salt_factory_theme.wav"));
		m_pResources->AddSoundObject("Shoot", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/bullet_shot_01.wav"));
        m_pResources->AddSoundObject("Main Theme", m_pResources->GetSoundPlayer("Level1_SoundPlayer")->LoadSound("Data/Sounds/main_theme.wav"));
    }

	// Load our shaders.
	{
		m_pResources->AddShader("Texture", new ShaderProgram("Data/Shaders/Texture.vert", "Data/Shaders/Texture.frag", "Data/Shaders/LightHelpers.light"));
		m_pResources->AddShader("Score", new ShaderProgram("Data/Shaders/ScoreDisplay.vert", "Data/Shaders/ScoreDisplay.frag", "Data/Shaders/LightHelpers.light"));
		m_pResources->AddShader("Normal", new ShaderProgram("Data/Shaders/Normal.vert", "Data/Shaders/Normal.frag", "Data/Shaders/LightHelpers.light"));
        m_pResources->AddShader("Light", new ShaderProgram("Data/Shaders/LightTexture.vert", "Data/Shaders/LightTexture.frag", "Data/Shaders/LightHelpers.light"));
        m_pResources->AddShader("CubeMap", new ShaderProgram("Data/Shaders/Cubemap.vert", "Data/Shaders/Cubemap.frag", "Data/Shaders/LightHelpers.light"));
        m_pResources->AddShader("Reflection", new ShaderProgram("Data/Shaders/Reflections.vert", "Data/Shaders/Reflections.frag", "Data/Shaders/LightHelpers.light"));


	}

	// Create meshes.
	{
		m_pResources->AddMesh("Box", Mesh::CreateBox(vec2(1, 1)));
        m_pResources->AddMesh("Platform", Mesh::CreateFromObjFile("Data/Models/Platform.obj"));
        m_pResources->AddMesh("Sawblade", Mesh::CreateFromObjFile("Data/Models/Sawblade.obj"));
		m_pResources->AddMesh("Cube", Mesh::CreateCube(vec2(1.5, 1.5)));
		m_pResources->AddMesh("Plane", Mesh::CreatePlane((1.0f, 1.0f), (30.0f, 15.0f), ivec2(8, 16)));
        m_pResources->AddMesh("SkyBox", Mesh::CreateFromObjFile("Data/Models/SkyBox.obj"));

        m_pResources->AddMesh("Sphere", Mesh::CreateFromObjFile("Data/Models/Sphere.obj"));
	}

	// Load our textures.
	{
        m_pResources->AddTexture("Meat Boy", LoadTexture("Data/Textures/Meat Boy.png"));
        m_pResources->AddTexture("Bandage Girl", LoadTexture("Data/Textures/Bandage Girl.png"));

        m_pResources->AddTexture("Bandage Pickup", LoadTexture("Data/Textures/Bandage.png"));

		m_pResources->AddTexture("Bloody Sawblade", LoadTexture("Data/Textures/Bloody Sawblade.png"));
        m_pResources->AddTexture("Blood Gib", LoadTexture("Data/Textures/BloodGib.png"));
		m_pResources->AddTexture("Clean Sawblade", LoadTexture("Data/Textures/Clean Sawblade.png"));
		m_pResources->AddTexture("Turret", LoadTexture("Data/Textures/Turret.png"));
		m_pResources->AddTexture("Missile", LoadTexture("Data/Textures/Missile.png"));
		m_pResources->AddTexture("Ground", LoadTexture("Data/Textures/Ground.png"));
        m_pResources->AddTexture("Sawblade Launcher", LoadTexture("Data/Textures/Sawblade Launcher.png"));

        m_pResources->AddTexture("Salt Factory BG", LoadTexture("Data/Textures/Salt Factory BG.png"));
		m_pResources->AddTexture("BloodTrail", LoadTexture("Data/Textures/BloodTrail.png"));
        m_pResources->AddTexture("Timer Numbers", LoadTexture("Data/Textures/Timer Numbers.png"));
        m_pResources->AddTexture("Title Screen Sawblade", LoadTexture("Data/Textures/Title Screen Sawblade.png"));
        m_pResources->AddTexture("Title-Default", LoadTexture("Data/Textures/Title-Default.png"));
        m_pResources->AddTexture("Title-Pressed", LoadTexture("Data/Textures/Title-Pressed.png"));



        m_pResources->AddTexture("BloodGib_Animation1", LoadTexture("Data/Textures/BloodGib4.png"));
        m_pResources->AddTexture("BloodGib_Animation2", LoadTexture("Data/Textures/BloodGib3.png"));
        m_pResources->AddTexture("BloodGib_Animation3", LoadTexture("Data/Textures/BloodGib2.png"));


        m_pResources->AddTexture("Frame_Window", LoadTexture("Data/Textures/LevelSelectMenuWindows.png"));


        m_pResources->AddTexture("Level Select Screen", LoadTexture("Data/Textures/Level Select Screen.png"));
        m_pResources->AddTexture("Level Square White", LoadTexture("Data/Textures/Level Square White.png"));
        m_pResources->AddTexture("Level Square Red", LoadTexture("Data/Textures/Level Square Red.png"));
        m_pResources->AddTexture("Level 1 Banner", LoadTexture("Data/Textures/Level 1 Banner.png"));
        m_pResources->AddTexture("Level 2 Banner", LoadTexture("Data/Textures/Level 2 Banner.png"));
        m_pResources->AddTexture("Meat Boy on Map", LoadTexture("Data/Textures/Meat Boy on Map.png"));
        m_pResources->AddTexture("Bandage Icon", LoadTexture("Data/Textures/Bandage Icon.png"));

        m_pResources->AddTexture("Rendered Scene", GetGame()->GetFBO(1)->GetColorTextureHandle());
        m_pResources->AddTexture("Rendered Scene2", GetGame()->GetFBO(2)->GetColorTextureHandle());
        m_pResources->AddTexture("Meat Boy Grill", LoadTexture("Data/Textures/Meat Boy Grill.png"));

       const char* t[6] { "Data/Textures/posx.png","Data/Textures/negx.png", "Data/Textures/posy.png","Data/Textures/negy.png","Data/Textures/posz.png","Data/Textures/negz.png"   };

           
        m_pResources->AddTexture("CubeMap", LoadTextureCubemap(t));
	}

	// Load our materials
	{
		m_pResources->AddMaterial("Meat Boy Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Meat Boy")));  
        m_pResources->AddMaterial("Bandage Girl Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Bandage Girl")));

        m_pResources->AddMaterial("Bandage Pickup Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Bandage Pickup")));

		m_pResources->AddMaterial("Bloody Sawblade Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Bloody Sawblade")));
        m_pResources->AddMaterial("Blood Gib Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Blood Gib")));
		m_pResources->AddMaterial("Clean Sawblade Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Clean Sawblade")));
		m_pResources->AddMaterial("Turret Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Turret")));
		m_pResources->AddMaterial("Missile Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Missile")));
		m_pResources->AddMaterial("Ground Material", new Material(m_pResources->GetShader("Light"), m_pResources->GetTexture("Ground")));
        m_pResources->AddMaterial("Sawblade Launcher Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Sawblade Launcher")));

        m_pResources->AddMaterial("Salt Factory BG Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Salt Factory BG")));
		m_pResources->AddMaterial("BloodTrail Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("BloodTrail")));
        m_pResources->AddMaterial("Title-Default Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Title-Default")));
        m_pResources->AddMaterial("Title-Pressed Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Title-Pressed")));
        m_pResources->AddMaterial("Timer Numbers Material", new Material(m_pResources->GetShader("Score"), m_pResources->GetTexture("Timer Numbers")));
        m_pResources->AddMaterial("Title Screen Sawblade Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Title Screen Sawblade")));
        m_pResources->AddMaterial("Meat Boy on Map Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Meat Boy on Map")));

        m_pResources->AddMaterial("Level Select Screen Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Level Select Screen")));
        m_pResources->AddMaterial("Level Square White Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Level Square White")));
        m_pResources->AddMaterial("Level Square Red Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Level Square Red")));
        m_pResources->AddMaterial("Level 1 Banner Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Level 1 Banner")));
        m_pResources->AddMaterial("Level 2 Banner Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Level 2 Banner")));
        m_pResources->AddMaterial("Bandage Icon Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Bandage Icon")));

        m_pResources->AddMaterial("Rendered Scene Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Rendered Scene")));
        m_pResources->AddMaterial("Rendered Scene Material2", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Rendered Scene2")));
        m_pResources->AddMaterial("Meat Boy Grill Material", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Meat Boy Grill")));

        m_pResources->AddMaterial("BloodGib_Animation1_Mat", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("BloodGib_Animation1")));
        m_pResources->AddMaterial("BloodGib_Animation2_Mat", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("BloodGib_Animation2")));
        m_pResources->AddMaterial("BloodGib_Animation3_Mat", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("BloodGib_Animation3")));

        m_pResources->AddMaterial("Frame_Window_Mat", new Material(m_pResources->GetShader("Texture"), m_pResources->GetTexture("Frame_Window")));

        m_pResources->AddMaterial("CubeMap_Mat", new Material(m_pResources->GetShader("CubeMap"), m_pResources->GetTexture("Meat Boy"),m_pResources->GetTexture("CubeMap")));
        m_pResources->AddMaterial("Reflect_Mat", new Material(m_pResources->GetShader("Reflection"), m_pResources->GetTexture("Meat Boy"),m_pResources->GetTexture("CubeMap")));


	}

	// Sound Cues
	{
		SoundObject* DeathSounds[] =  { m_pResources->GetSoundObject("Splat"),
                                        m_pResources->GetSoundObject("Splat2"),
                                        m_pResources->GetSoundObject("Splat3") };

        SoundObject* JumpSounds[] =   { m_pResources->GetSoundObject("Jump"),
                                       m_pResources->GetSoundObject("Jump2"),
                                       m_pResources->GetSoundObject("Jump3"),
                                       m_pResources->GetSoundObject("Jump4") };

        SoundObject* SawLaunchSounds[] = { m_pResources->GetSoundObject("Saw Launch1"),
                                           m_pResources->GetSoundObject("Saw Launch2") };
                                                                    

        m_pResources->AddSoundCueObject("Death", new SoundCue(DeathSounds, 3));

        m_pResources->AddSoundCueObject("Jumping", new SoundCue(JumpSounds, 4));

        m_pResources->AddSoundCueObject("Saw Launching", new SoundCue(SawLaunchSounds, 2));
	}
}

void PreLoadedScene::Update(float deltatime)
{
	Scene::Update(deltatime);
}

void PreLoadedScene::Draw()
{
	Scene::Draw();
}
