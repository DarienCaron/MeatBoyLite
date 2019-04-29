#include "GamePCH.h"


Material::Material(ShaderProgram * a_Shader, GLuint a_Texture)
{
    init(a_Shader, a_Texture);
}
Material::Material(ShaderProgram * a_Shader, GLuint a_Texture, GLuint CubeTexture)
{
    init(a_Shader, a_Texture, CubeTexture);
}

Material::~Material()
{
}

void Material::init(ShaderProgram * a_Shader, GLuint a_Texture)
{
    m_Shader = a_Shader;
    m_Texture = a_Texture;
}
void Material::init(ShaderProgram * a_Shader, GLuint a_Texture, GLuint CubeTexture)
{
    m_Shader = a_Shader;
    m_Texture = a_Texture;
    m_CubeMapTexture = CubeTexture;
}
ShaderProgram* Material::GetShader()
{
    return m_Shader;
}

GLuint Material::GetTexture()
{
    return m_Texture;
}

GLuint Material::GetCubeMapTexture()
{
    return m_CubeMapTexture;
}
