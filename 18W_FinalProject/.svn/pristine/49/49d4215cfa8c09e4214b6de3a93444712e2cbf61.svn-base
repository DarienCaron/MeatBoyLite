#ifndef __Mesh_H__
#define __Mesh_H__
class Material;
class ScoreDisplay;

struct ScoreSpriteFormat
{
    float m_Position[2];
    float m_UV[2];
    
};


class Mesh
{
protected:
    GLuint m_VBO;
    GLuint m_IBO;

    unsigned int m_NumVerts;
    unsigned int m_NumIndices;

    GLenum m_PrimitiveType;

public:
    Mesh();
    virtual ~Mesh();

    virtual void Init(VertexFormat* verts, int numverts, unsigned int* indices, int numindices, GLenum usage);
    virtual void Init(const void* verts, int numverts, int vertexbytesize, GLenum usage);

    virtual void SetupAttributes(ShaderProgram* pShaderProgram);
    virtual void SetupUniforms(mat4* pMatWorld, mat4* pMatView, mat4* pMatProj, vec3 campos,Material* a_Material, int digit, unsigned int Lightcount, vec3 Lightpos[], vec4 LightColor[], mat4* Rotationmat);
    virtual void Draw(ShaderProgram* pShaderProgram);
    void GenerateScoreDisplay(float width, float height);

    // The following functions are defined in MeshShapes.cpp
    static Mesh* CreateBox(vec3 size);
	
    static Mesh* CreateCube(vec3 size);
    static Mesh* CreatePlane(vec2 origin, vec2 worldsize,ivec2 numofverts);
    static Mesh* CreateFromObjFile(const char* objfilename);
    static Mesh* CreateInverseCube(vec3 size);
};

#endif //__Game_H__
