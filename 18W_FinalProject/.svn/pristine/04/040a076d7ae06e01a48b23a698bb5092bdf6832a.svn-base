#include "GamePCH.h"

Game::Game(Framework* pFramework)
: GameCore( pFramework )
{
    m_WindowWidth = -1;
    m_WindowHeight = -1;
    m_pImGuiManager = 0;
    m_pSceneManager = 0;
    m_pResources = 0;
    m_FBO = 0;
}

Game::~Game()
{
    while (m_EventQueue.size() != 0)
    {
        Event* pEvent = m_EventQueue.front();
        m_EventQueue.pop();
        delete pEvent;
    }

    delete m_pSceneManager;
    delete m_pResources;
    delete m_pImGuiManager;
    delete m_FBO;
    delete m_FBO2;
}

void Game::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    glViewport( 0, 0, width, height );


    m_WindowWidth = width;
    m_WindowHeight = height;
}

void Game::LoadContent()
{
    // Creating FBO
    m_FBO = new FBODefinition();
    m_FBO->Create(1024, 1024, GL_NEAREST, GL_NEAREST, true, 32, true);

    m_FBO2 = new FBODefinition();
    m_FBO2->Create(1024, 1024, GL_NEAREST, GL_NEAREST, true, 32, true);

    // World


    // Seed random.
    srand( (unsigned int)GetSystemTime() );
    
    CheckForGLErrors();

    // Turn on depth buffer testing.
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );


    // Turn on alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    m_pResources = new ResourceManager();

    m_pSceneManager = new SceneManager();
    

    m_pSceneManager->AddScene("PreLoaded", new PreLoadedScene(this, m_pResources, "PreLoaded"));
    m_pSceneManager->AddScene("Sample", new SampleScene(this, m_pResources, "Sample"));
    m_pSceneManager->AddScene("Level Select", new LevelSelectScene(this, m_pResources, "Level Select"));
    m_pSceneManager->AddScene("Title", new TitleScene(this, m_pResources, "Title"));
    m_pSceneManager->AddScene("Second Level", new SecondLevelScene(this, m_pResources, "Second Level"));
    m_pSceneManager->AddScene("Pause", new PauseScene(this, m_pResources, "Pause"));

	((PreLoadedScene*)m_pSceneManager->GetScene("PreLoaded"))->LoadContent();
	((SampleScene*)m_pSceneManager->GetScene("Sample"))->LoadContent();
    ((LevelSelectScene*)m_pSceneManager->GetScene("Level Select"))->LoadContent();
    ((TitleScene*)m_pSceneManager->GetScene("Title"))->LoadContent();
    ((SecondLevelScene*)m_pSceneManager->GetScene("Second Level"))->LoadContent();
    ((PauseScene*)m_pSceneManager->GetScene("Pause"))->LoadContent();

    //m_pSceneManager->LoadContent();

    m_pSceneManager->PushScene("Title");

    CheckForGLErrors();

    m_pImGuiManager = new ImGuiManager();
    m_pImGuiManager->Init();
}

void Game::QueueEvent(Event* pEvent)
{
    m_EventQueue.push( pEvent );
}

void Game::ProcessEvents()
{
    while( m_EventQueue.size() != 0 )
    {
        Event* pEvent = m_EventQueue.front();
        m_EventQueue.pop();

        OnEvent( pEvent );

        delete pEvent;
    }
}

void Game::OnEvent(Event* pEvent)
{
	//((SampleScene*)m_pScenes->GetScene("Sample"))->OnEvent(pEvent);
    //((TitleScene*)m_pScenes->GetScene("Title"))->OnEvent(pEvent);
    m_pSceneManager->OnEvent(pEvent);

    m_pImGuiManager->OnEvent(pEvent);
    
    m_Controllers[0].OnEvent( pEvent );

    
}

void Game::Update(float deltatime)
{
   

    // Process events at the start of the frame before updating anything else in the game.
    ProcessEvents();
    m_pImGuiManager->StartFrame((float)m_WindowWidth, (float)m_WindowHeight, deltatime);

    m_pSceneManager->Update(deltatime);

  

    //m_pSceneManager->GetRenderToTextureScene()->Update(deltatime);
    
}

void Game::Draw()
{
    m_FBO->Bind();

    // Clear the screen to dark blue.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glViewport(0, 0, 1024, 1024);

    //m_pSceneManager->Draw();

    m_pSceneManager->GetRenderToTextureScene(1)->Draw();

    CheckForGLErrors();

    m_FBO->Unbind();

    m_FBO2->Bind();

    // Clear the screen to dark blue.
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, 1024, 1024);

    //m_pSceneManager->Draw();
    m_pSceneManager->GetRenderToTextureScene(2)->Draw();
    

    CheckForGLErrors();


    m_FBO2->Unbind();

    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, m_WindowWidth, m_WindowHeight);
    m_pSceneManager->Draw();
    m_pImGuiManager->EndFrame();
}


//void Game::SaveFile(const char* filename)
//{
//    FILE* filehandle;
//    errno_t error = fopen_s(&filehandle, filename, "wb");
//    if (filehandle)
//    {
//        fwrite(string, 1, strlen(string), filehandle);
//        fclose(filehandle);
//    }
//}

FBODefinition* Game::GetFBO(int selection)
{
    if (selection == 1)
    {
        return m_FBO;
    }
    if (selection == 2)
    {
        return m_FBO2;
    }
    return 0;
}




