#ifndef __ResourceManager_H__
#define __ResourceManager_H__

class ResourceManager;

class ShaderProgram;
class Mesh;
class Material;
class SoundCue;

class ResourceManager
{
protected:
    std::map<std::string, Mesh*> m_pMeshes;
    std::map<std::string, ShaderProgram*> m_pShaders;
    std::map<std::string, GLuint> m_pTextures;
    std::map<std::string, Material*> m_pMaterial;
    std::map<std::string, SoundPlayer*> m_pSoundPlayer;
    std::map<std::string, SoundObject*> m_pSoundObject;
	std::map<std::string, SoundCue*> m_pSoundCues;

public:
    ResourceManager();
    virtual ~ResourceManager();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);

    void AddMesh(const char* name, Mesh* pMesh) { m_pMeshes[name] = pMesh; }

    void AddShader(const char* name, ShaderProgram* pShader)
    {
        assert(m_pShaders[name] == 0);  // safety check
        m_pShaders[name] = pShader; 
    }
    
    void AddTexture(const char* name, GLuint texturehandle)
    {
         assert(m_pTextures[name] == 0);   // safety check
         m_pTextures[name] = texturehandle;  
    }

   
    void AddMaterial(const char* name, Material* a_Material) { m_pMaterial[name] = a_Material; }
    void AddSoundPlayer(const char* name, SoundPlayer* pSoundPlayer) { m_pSoundPlayer[name] = pSoundPlayer; }
    void AddSoundObject(const char* name, SoundObject* pSoundObject) { m_pSoundObject[name] = pSoundObject; }

	void AddSoundCueObject(const char* name, SoundCue* pSoundCueObject) { m_pSoundCues[name] = pSoundCueObject; }


    Mesh* GetMesh(const char* name) { return m_pMeshes[name]; }
    ShaderProgram* GetShader(const char* name) { return m_pShaders[name]; }
    GLuint GetTexture(const char* name) { return m_pTextures[name]; }
    Material* GetMaterial(const char* name) { return m_pMaterial[name]; }
    SoundPlayer* GetSoundPlayer(const char* name) { return m_pSoundPlayer[name]; }
    SoundObject* GetSoundObject(const char* name) { return m_pSoundObject[name]; }

	SoundCue* GetSoundCueObject(const char* name) { return m_pSoundCues[name]; }

    Mesh* GetMesh(std::string name) { return m_pMeshes[name]; }
    ShaderProgram* GetShader(std::string name) { return m_pShaders[name]; }
    GLuint GetTexture(std::string name) { return m_pTextures[name]; }
    Material* GetMaterial(std::string name) { return m_pMaterial[name]; }
    SoundPlayer* GetSoundPlayer(std::string name) { return m_pSoundPlayer[name]; }
    SoundObject* GetSoundObject(std::string name) { return m_pSoundObject[name]; }


	SoundCue* GetSoundCueObject(std::string name) { return m_pSoundCues[name]; }
    

    
};

#endif //__ResourceManager_H__
