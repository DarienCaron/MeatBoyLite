#include "GamePCH.h"


// Credit goes to James Lord for providing this spritesheet in last semesters exam
SpriteSheet::SpriteSheet()
{
    m_TextureHandle = 0;
    m_TextureSize.Set(0, 0);
}

SpriteSheet::~SpriteSheet()
{
    if (m_TextureHandle != 0)
        glDeleteTextures(1, &m_TextureHandle);
}

void SpriteSheet::LoadFromJSONFile(std::string path, std::string filename)
{
    char* Buffer = LoadCompleteFile((path + filename).c_str(), 0); // Load the file 
    cJSON* Jfile = cJSON_Parse(Buffer); // Parse the file 
    {
        cJSON* JTextureFilename = cJSON_GetObjectItem(Jfile, "file"); // Get the start of the file
        m_TextureHandle = LoadTexture((path + JTextureFilename->valuestring).c_str()); // set our texture handle to the json sprite file

        cJSON* jTexWidth = cJSON_GetObjectItem(Jfile, "width"); // Get the width of the file
        cJSON* jTexHeight = cJSON_GetObjectItem(Jfile, "height"); // Get the height of the file

        m_TextureSize = vec2((float)jTexWidth->valueint, (float)jTexHeight->valueint); // Store that in our texture size

        cJSON* jFiles = cJSON_GetObjectItem(Jfile, "Files"); // Get the individual files from our Json

        int numFiles = cJSON_GetArraySize(jFiles); // Get the size

        for (int i = 0; i < numFiles; i++)
        {

            // Loop through each image and store it 
            cJSON* jSprite = cJSON_GetArrayItem(jFiles, i);
            assert(jSprite);


            SpriteInformation Sprite;

            cJSON* jFileName = cJSON_GetObjectItem(jSprite, "filename"); // Store all the sprites values
            cJSON* jPosX = cJSON_GetObjectItem(jSprite, "posx");
            cJSON* jPosY = cJSON_GetObjectItem(jSprite, "posy");
            cJSON* jWidth = cJSON_GetObjectItem(jSprite, "origw");
            cJSON* jHeight = cJSON_GetObjectItem(jSprite, "origh");

            Sprite.Setup(jFileName->valuestring, vec2((float)jWidth->valueint, (float)jHeight->valueint), vec2((float)jPosX->valueint, (float)jPosY->valueint)); // Setup our locally declared sprite information object

            
            m_Sprites.push_back(Sprite); // Push each sprite into the vector



        }

    }

    cJSON_Delete(Jfile);
    delete Buffer;
}

SpriteInformation* SpriteSheet::GetSpriteInfoByFileName(std::string filename)
{
    for (unsigned int i = 0; i < m_Sprites.size(); i++) // Loop through our sprites vector
    {
        if (m_Sprites[i].filename == filename) // Check if the name lines up
        {
            return &m_Sprites[i]; // return it.
        }
    }
    return 0;
}
