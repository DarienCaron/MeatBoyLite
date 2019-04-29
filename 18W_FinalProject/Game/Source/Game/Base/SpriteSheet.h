#ifndef __SpriteSheet_H__
#define __SpriteSheet_H__

struct SpriteInformation // Serves as the spritesheet template
{
    std::string filename;
    vec2 Size;
    vec2 Offset;
    void Setup(std::string file, vec2 size, vec2 offset)
    {
        filename = file;
        Size = size;
        Offset = offset;

    }

};


class SpriteSheet
{
public:
    SpriteSheet();
    ~SpriteSheet();

    GLuint GetTextureHandle() { return m_TextureHandle; }
    vec2 GetTextureSize() { return m_TextureSize; }

    void LoadFromJSONFile(std::string path, std::string filename);

    SpriteInformation* GetSpriteInfoByFileName(std::string filename);


protected:
    vector<SpriteInformation> m_Sprites;
    GLuint m_TextureHandle;
    vec2 m_TextureSize;


};









#endif //__SpriteSheet_H__