#pragma once


class Material
{
public :

    Material(ShaderProgram * a_Shader, GLuint a_Texture);
    Material(ShaderProgram * a_Shader, GLuint a_Texture, GLuint CubeTexture);
    ~Material();
    void init(ShaderProgram * a_Shader, GLuint a_Texture);
    void init(ShaderProgram * a_Shader, GLuint a_Texture, GLuint CubeTexture);
    ShaderProgram* GetShader();
    GLuint GetTexture();
    GLuint GetCubeMapTexture();


    ShaderProgram * m_Shader;
    GLuint m_Texture;
    GLuint m_CubeMapTexture;
    





};