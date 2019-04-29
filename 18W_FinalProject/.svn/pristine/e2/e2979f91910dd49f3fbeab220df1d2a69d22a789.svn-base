#include "GamePCH.h"

Mesh::Mesh()
{
    m_VBO = 0;
    m_IBO = 0;
    m_PrimitiveType = GL_TRIANGLES;
}

Mesh::~Mesh()
{
    glDeleteBuffers( 1, &m_VBO );
    glDeleteBuffers( 1, &m_IBO );
}

void Mesh::GenerateScoreDisplay(float width, float height)
{
    CheckForGLErrors();

    {
        // Vertex position info for a quad, pivot point is at bottom center.
       ScoreSpriteFormat vertexattributesSprite[] =
        {
            -width / 2,  height,   0.0f, 1.0f, // TL
            width / 2,  height,   1.0f, 1.0f, // TR
            width / 2,    0.0f,   1.0f, 0.0f, // BL
            -width / 2,    0.0f,   0.0f, 0.0f, // BR
        };

        // Gen and fill buffer with our attributes.
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, vertexattributesSprite, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        m_PrimitiveType = GL_TRIANGLE_FAN;
        m_NumVerts = 4;
    }

    CheckForGLErrors();
}

void Mesh::Init(VertexFormat* verts, int numverts, unsigned int* indices, int numindices, GLenum usage)
{
    m_NumVerts = numverts;
    m_NumIndices = numindices;

    // Generate and fill buffer with our vertex attributes.
    if( m_VBO == 0 )
        glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(VertexFormat)*numverts, verts, usage );

    // Generate and fill buffer with our indices.
    if( m_IBO == 0 )
        glGenBuffers( 1, &m_IBO );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*numindices, indices, usage );

    CheckForGLErrors();
}

void Mesh::Init(const void* verts, int numverts, int vertexbytesize, GLenum usage)
{
    m_NumVerts = numverts;
    m_NumIndices = 0;

    // Generate and fill buffer with our vertex attributes.
    if( m_VBO == 0 )
        glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, numverts * vertexbytesize, verts, usage );

    CheckForGLErrors();
}

void Mesh::SetupAttributes(ShaderProgram* pShaderProgram)
{
    assert( m_VBO != 0 );

    // Bind our vertex and index buffers.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    if( m_IBO != 0 )
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IBO );

    GLuint programhandle = pShaderProgram->GetProgram();

    // Get the attribute locations.
    GLint aPos = glGetAttribLocation( programhandle, "a_Position" );
    GLint aColor = glGetAttribLocation( programhandle, "a_Color" );
    GLint aUV = glGetAttribLocation( programhandle, "a_UV" );
    GLint aNormal = glGetAttribLocation( programhandle, "a_Normal" );

    // Setup our vbo and attributes.
    {
        // Setup the position attribute.
        assert( aPos != -1 );
        glVertexAttribPointer( aPos, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)offsetof(VertexFormat, pos) );
        glEnableVertexAttribArray( aPos );

        // Setup the color attribute.
        if( aColor != -1 )
        {
            glVertexAttribPointer( aColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertexFormat), (void*)offsetof(VertexFormat, color) );
            glEnableVertexAttribArray( aColor );
        }

        // Setup the uv attribute.
        if( aUV != -1 )
        {
            glVertexAttribPointer( aUV, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)offsetof(VertexFormat, uv) );
            glEnableVertexAttribArray( aUV );
        }

        // Setup the uv attribute.
        if (aNormal != -1)
        {
            glVertexAttribPointer(aNormal, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)offsetof(VertexFormat, normal));
            glEnableVertexAttribArray(aNormal);
        }
    }
}

void Mesh::SetupUniforms(mat4* pMatWorld, mat4* pMatView, mat4* pMatProj, vec3 campos, Material* a_Material, int digit, unsigned int Lightcount, vec3 Lightpos[], vec4 LightColor[], mat4* Rotationmat)
{
    GLuint programhandle = a_Material->GetShader()->GetProgram();


    





    // Enable our shader program.
    glUseProgram( programhandle );

    // Get the uniform locations.
    GLint uWorldMatrix = glGetUniformLocation(programhandle, "u_WorldMatrix");
    GLint uViewMatrix = glGetUniformLocation(programhandle, "u_ViewMatrix");
    GLint uProjectionMatrix = glGetUniformLocation(programhandle, "u_ProjectionMatrix");
	GLint uCameraPosition = glGetUniformLocation( programhandle, "u_CameraPosition" );
	GLint uTexture = glGetUniformLocation( programhandle, "u_Texture" );

    GLint uRotation = glGetUniformLocation(programhandle, "u_RotationMatrix");

    GLint uTextureCube = glGetUniformLocation(programhandle, "u_TextureCube");
  //  u_LightColor
    //u_LightPosition
    GLint uTime = glGetUniformLocation( programhandle, "u_Time" );
    GLint uDigit = glGetUniformLocation(programhandle, "u_Digit");

    GLint LightPos = glGetUniformLocation(programhandle, "u_LightPosition");
    GLint LightCol = glGetUniformLocation(programhandle, "u_LightColor");
    GLint LightCount = glGetUniformLocation(programhandle, "u_LightCount");


    GLuint texturehandle = a_Material->GetTexture();
  
        GLuint CubeMapHandle = a_Material->GetCubeMapTexture();
   
    

    // Setup the texture.
    if( texturehandle != 0 && uTexture != -1 )
    {
        glActiveTexture( GL_TEXTURE0 + 0 );
        glBindTexture( GL_TEXTURE_2D, texturehandle );
        glUniform1i( uTexture, 0 );
    }
    if (CubeMapHandle != 0 && uTextureCube != -1)
    {
        glActiveTexture(GL_TEXTURE0 + 1);
        glBindTexture(GL_TEXTURE_CUBE_MAP, CubeMapHandle);
        glUniform1i(uTextureCube, 1);
    }
    if (uWorldMatrix != -1)
    {

       
                 
        glUniformMatrix4fv(uWorldMatrix, 1, GL_FALSE, &pMatWorld->m11); // Pass in a matrix parameter
    }

    if (uViewMatrix != -1)
    {
      


        glUniformMatrix4fv(uViewMatrix, 1, GL_FALSE, &pMatView->m11); // Pass in a matrix parameter
    }

    if (uProjectionMatrix != -1)
    {
        
        glUniformMatrix4fv(uProjectionMatrix, 1, GL_FALSE, &pMatProj->m11); // Pass in a matrix parameter
    }
    if (uRotation != -1)
    {

        glUniformMatrix4fv(uRotation, 1, GL_FALSE, &Rotationmat->m11); // Pass in a matrix parameter
    }


    if( uCameraPosition != -1 )
    {
        glUniform3f( uCameraPosition, campos.x, campos.y, campos.z );
    }

    if (LightPos != -1)
    {
        glUniform3fv(LightPos, 3, &Lightpos[0].x);
    }
    if (LightCol != -1)
    {
        
        
            glUniform4fv(LightCol, 4, &LightColor[0].x);
        
    }
	
    //if(LightCount)

    // Setup time.
    if( uTime != -1 )
    {
        glUniform1f( uTime, (float)GetSystemTime() );
    }

    // Setup the texture
    if (uTexture != -1)
    {
        glUniform1i(uTexture, 0);
    }

    // Setup the digits
    if (uDigit != -1)
    {
        glUniform1i(uDigit, digit);
    }

    CheckForGLErrors();
}

void Mesh::Draw(ShaderProgram* pShaderProgram)
{
    GLuint programhandle = pShaderProgram->GetProgram();

    // Draw the shape.
    if( m_NumIndices > 0 )
    {
        glDrawElements( m_PrimitiveType, m_NumIndices, GL_UNSIGNED_INT, 0 );
    }
    else
    {
        glDrawArrays( m_PrimitiveType, 0, m_NumVerts );
    }

    GLint aPos = glGetAttribLocation( programhandle, "a_Position" );
    GLint aColor = glGetAttribLocation( programhandle, "a_Color" );
    GLint aUV = glGetAttribLocation( programhandle, "a_UV" );
    GLint aNormal = glGetAttribLocation( programhandle, "a_Normal" );

    // Disable the attribute arrays used
    glDisableVertexAttribArray( aPos );

    if( aColor != -1 )
        glDisableVertexAttribArray( aColor );
    

    if( aUV != -1 )
        glDisableVertexAttribArray( aUV );
    

    if( aNormal != -1 )
        glDisableVertexAttribArray( aNormal );

    CheckForGLErrors();
}

