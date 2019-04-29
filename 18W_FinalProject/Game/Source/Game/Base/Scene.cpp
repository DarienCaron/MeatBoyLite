#include "GamePCH.h"

Scene::Scene(Game* pGame, ResourceManager* pResources, std::string name)
{
    m_pGame = pGame;
    m_pResources = pResources;
    m_pName = name;

}

Scene::~Scene()
{
    for( auto object: m_pGameObjects )
    {
        delete object.second;
    }

}

void Scene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
}

void Scene::LoadContent()
{
   
}

void Scene::OnEvent(Event* pEvent)
{
    if (pEvent->GetEventType() == EventType_Input)
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;

        if (pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard)
        {
            if (pInputEvent->GetInputState() == InputState_Pressed)
            {
                if (pInputEvent->GetID() == 'L') 
                {

                    SaveFiles();
                }
                if (pInputEvent->GetID() == 'O') 
                {
                    LoadFiles();

                }
            }
        }
    }
    
  
}

void Scene::Update(float deltatime)
{
    CheckForGLErrors();

    // Update all of the Scene objects in the list.
    for( auto object: m_pGameObjects )
    {
        object.second->Update( deltatime );
    }

    CheckForGLErrors();


}

void Scene::Draw()
{
    CheckForGLErrors();
    CameraObject* pCamera = (CameraObject*)GetGameObject("Camera");
    vec3 campos = pCamera->GetPosition();
    mat4* pMatView = pCamera->GetViewMatrix();
    mat4* pMatProj = pCamera->GetProjMatrix();

    // Render all of the Scene objects in the list.
    for( int i=0; i<5; i++ )
    {
        //for( std::map<std::string, GameObject*>::iterator iterator = m_pGameObjects.begin(); iterator != m_pGameObjects.end(); iterator++ )
        for( auto object: m_pGameObjects )
        {
            if( object.second->GetRenderOrder() == i )
            {
                object.second->Draw(i, pMatView, pMatProj, campos);
            }
        }
    }

    CheckForGLErrors();
}

void Scene::LoadFiles()
{
    char* jsonstring = LoadCompleteFile("Data/savefile.json",0);
    cJSON* jRoot = cJSON_Parse(jsonstring);
    delete[] jsonstring;

    cJSON* jBandagesArray = cJSON_GetObjectItem(jRoot, "Bandages_Collected");

    cJSON* jBandage1 = cJSON_GetArrayItem(jBandagesArray, 0);

    cJSON* jBandage2 = cJSON_GetArrayItem(jBandagesArray, 1);
    bool Bandage1 = false;

    bool Bandage2 = false;
    if (jBandage1->valueint == 1)
    {
        Bandage1 = true;
    }
    else
    {
        Bandage1 = false;
    }

    if (jBandage2->valueint == 1)
    {
        Bandage2 = true;
    }
    else
    {
        Bandage2 = false;
    }
    cJSON* jLevelsArray = cJSON_GetObjectItem(jRoot, "Levels_Beaten");
    cJSON* jLevel1 = cJSON_GetArrayItem(jLevelsArray, 0);

    cJSON* jLevel2 = cJSON_GetArrayItem(jLevelsArray, 1);
    bool Level1 = false;

    bool Level2 = false;


    if (jLevel1->valueint == 1)
    {
        Level1 = true;
    }
    else
    {
        Level1 = false;
    }

    if (jLevel2->valueint == 1)
    {
        Level2 = true;
    }
    else
    {
        Level2 = false;
    }


    GetGame()->GetSceneManager()->GetScene("Sample")->SetIsBeaten(Level1);
    GetGame()->GetSceneManager()->GetScene("Second Level")->SetIsBeaten(Level2);

    ((SampleScene*)this)->SetBandageIsCollected(Bandage1);
    ((SecondLevelScene*)this)->SetBandageIsCollected(Bandage2);

    cJSON_Delete(jRoot);

}

void Scene::SaveFiles()
{
    cJSON* jRoot = cJSON_CreateObject();

    cJSON* jBeatenLevels = cJSON_CreateArray();
    cJSON_AddItemToObject(jRoot, "Levels_Beaten", jBeatenLevels);


    cJSON* jCollectedBandages = cJSON_CreateArray();
    cJSON_AddItemToObject(jRoot, "Bandages_Collected", jCollectedBandages);

   bool SampleSceneBandage =  ((SampleScene*)this)->GetBandageIsCollected();
   bool SecondLevelBandage = ((SecondLevelScene*)this)->GetBandageIsCollected();

   int Bandage1 = 0;
   int Bandage2 = 0;

   if (SampleSceneBandage == true)
   {
       Bandage1 = 1;
   }
   else
   {
       Bandage1 = 0;
   }

   if (SecondLevelBandage == true)
   {
       Bandage2 = 1;
   }
   else
   {
       Bandage2 = 0;
   }

   cJSON* jBandage1 = cJSON_CreateObject();

   cJSON_AddNumberToObject(jBandage1, "Level1 Bandage", Bandage1);

 

   cJSON* jBandage2 = cJSON_CreateObject();

   cJSON_AddNumberToObject(jBandage2, "Level2 Bandage", Bandage2);

   cJSON_AddItemToArray(jCollectedBandages, jBandage1);

   cJSON_AddItemToArray(jCollectedBandages, jBandage2);

   bool SampleSceneBeaten = GetGame()->GetSceneManager()->GetScene("Sample")->GetIsBeaten();

   bool SecondLevelBeaten = GetGame()->GetSceneManager()->GetScene("Second Level")->GetIsBeaten();


   int Level1 = 0;
   int Level2 = 0;

   if (SampleSceneBeaten == true)
   {
       Level1 = 1;
   }
   else
   {
       Level1 = 0;
   }

   if (SecondLevelBeaten == true)
   {
       Level2 = 1;
   }
   else
   {
       Level2 = 0;
   }





   cJSON* jLevel1 = cJSON_CreateObject();

   cJSON_AddNumberToObject(jLevel1, "Level1 Beaten", Level1);

   cJSON* jLevel2 = cJSON_CreateObject();

   cJSON_AddNumberToObject(jLevel2, "Level2 Beaten", Level2);

   cJSON_AddItemToArray(jBeatenLevels, jLevel1);

   cJSON_AddItemToArray(jBeatenLevels, jLevel2);

   char* jsonstring = cJSON_Print(jRoot);

   std::string file = jsonstring;

   FILE* filehandle;
   errno_t error = fopen_s(&filehandle, "Data/savefile.json", "wb");
   if (filehandle)
   {
       fwrite(jsonstring, 1, file.length(), filehandle);
       fclose(filehandle);
   }
   free(jsonstring);
   cJSON_Delete(jRoot);
}

void Scene::AddToScene(std::string name, GameObject * obj)
{
	m_pGameObjects[name] = obj;
}

void Scene::RemoveFromScene(GameObject * obj)
{
	m_pGameObjects.erase(obj->GetName());
}

void Scene::LoadSceneFile(const char* filename)
{
    const char* filecontents = LoadCompleteFile(filename, 0);

   cJSON* jRoot = cJSON_Parse(filecontents);

   
   cJSON* jGameObjectsArray = cJSON_GetObjectItemCaseSensitive(jRoot, "GameObjects");
 //  cJSON* jComponentsArray = cJSON_GetObjectItemCaseSensitive(jGameObjectsArray, "Components");


   int numGameObjects = cJSON_GetArraySize(jGameObjectsArray);

   for (int i = 0; i < numGameObjects; i++)
   {
       cJSON* jGameObject = cJSON_GetArrayItem(jGameObjectsArray, i);
	   
	   cJSON* jGameObjectComponents = cJSON_GetObjectItemCaseSensitive(jGameObject, "Components");


	   cJSON* jComp = cJSON_GetArrayItem(jGameObjectComponents, 0);
	   cJSON* jComp2 = cJSON_GetArrayItem(jGameObjectComponents, 1);

       cJSON* jName = cJSON_GetObjectItem(jGameObject, "Name");
       
	   cJSON* jFlag = cJSON_GetObjectItem(jGameObject, "Flags");

	   cJSON* jPos = cJSON_GetObjectItem(jGameObject, "Pos");

	   cJSON* jRot = cJSON_GetObjectItem(jGameObject, "Rot");

	   cJSON* jScale = cJSON_GetObjectItem(jGameObject, "Scale");

	   vec3 Position = vec3(float(cJSON_GetArrayItem(jPos, 0)->valuedouble),float (cJSON_GetArrayItem(jPos, 1)->valuedouble),float (cJSON_GetArrayItem(jPos, 2)->valuedouble));

	   vec3 Rotation = vec3(float(cJSON_GetArrayItem(jRot, 0)->valuedouble), float(cJSON_GetArrayItem(jRot, 1)->valuedouble), float(cJSON_GetArrayItem(jRot, 2)->valuedouble));

	   vec3 Scale = vec3(float(cJSON_GetArrayItem(jScale, 0)->valuedouble), float(cJSON_GetArrayItem(jScale, 1)->valuedouble), float(cJSON_GetArrayItem(jScale, 2)->valuedouble));


	   cJSON* jMesh = cJSON_GetObjectItem(jComp, "PrimitiveType");
	   cJSON* jDensity = cJSON_GetObjectItem(jComp, "Density");
	   cJSON* jisSensor = cJSON_GetObjectItem(jComp, "IsSensor");
	   cJSON* jFriction = cJSON_GetObjectItem(jComp, "Friction");
	   cJSON* jRestitiution = cJSON_GetObjectItem(jComp, "Restitution");
	   cJSON* jStatic = cJSON_GetObjectItem(jComp, "Static");
	   cJSON* jMaterial = cJSON_GetObjectItem(jComp2, "Material");

	

	   float32 width = Scale.x;
	   float32 height = Scale.y;

		   m_pGameObjects[jName->valuestring] = new GameObject(this, jName->valuestring, Position, Rotation, Scale,
			   m_pResources->GetMesh("Box"), m_pResources->GetMaterial(jMaterial->valuestring));
	   




	   //(float32 halfWidth, float32 halfHeight, float32 density, bool isSensor, float32 friction, float32 restitution);

	 /*  m_pGameObjects[jName->valuestring]->CreateBody(jStatic->valueint);
	   if (strcmp(jMesh->valuestring ,"Box") == 0)
	   {
		   m_pGameObjects[jName->valuestring]->AddBox(width, height, float32(jDensity->valuedouble), jisSensor->valueint, float32(jFriction->valuedouble), float32(jRestitiution->valuedouble));
	   }
	   else if (strcmp(jMesh->valuestring, "Circle") == 0)
	   {
		   m_pGameObjects[jName->valuestring]->AddCircle(float32(jDensity->valuedouble), jisSensor->valueint, float32(jFriction->valuedouble), float32(jRestitiution->valuedouble), Scale.x);
	   }*/
	   

   }

   cJSON_Delete(jRoot);

    delete[] filecontents;
}

