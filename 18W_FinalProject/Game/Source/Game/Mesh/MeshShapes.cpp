#include "GamePCH.h"

Mesh* Mesh::CreateBox(vec3 size)
{
    VertexFormat verts[4];

    verts[0] = VertexFormat( -size.x/2, -size.y/2, 0,255,255,255,255, 0,0 );
    verts[1] = VertexFormat( -size.x/2,  size.y/2, 0,255,255,255,255, 0,1 );
    verts[2] = VertexFormat(  size.x/2,  size.y/2, 0,255,255,255,255, 1,1 );
    verts[3] = VertexFormat(  size.x/2, -size.y/2, 0,255,255,255,255, 1,0 );

    unsigned int indices[6] = { 0,2,1, 0,3,2 };

    Mesh* pMesh = new Mesh();
    pMesh->Init( verts, 4, indices, 6, GL_STATIC_DRAW );

    return pMesh;
}


Mesh * Mesh::CreateCube(vec3 size)
{
	VertexFormat verts[24];

	verts[0] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0,  0, 0, 0, 1);
	verts[1] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1); // front face
	verts[2] = VertexFormat( size.x / 2,  size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1);
	verts[3] = VertexFormat( size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1);

	verts[4] = VertexFormat(-size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);
	verts[5] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1); // back face
	verts[6] = VertexFormat( size.x / 2,  size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);
	verts[7] = VertexFormat( size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);

	verts[8] = VertexFormat(-size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0);
	verts[9] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0); // left face
	verts[10] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);
	verts[11] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);

	verts[12] = VertexFormat(size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0);
	verts[13] = VertexFormat(size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0); // right face
	verts[14] = VertexFormat(size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);
	verts[15] = VertexFormat(size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);

	verts[16] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);
	verts[17] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0); // top face
	verts[18] = VertexFormat(size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0);
	verts[19] = VertexFormat(size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);

	verts[20] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);
	verts[21] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0); // bottom face
	verts[22] = VertexFormat(size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0);
	verts[23] = VertexFormat(size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);

	unsigned int indices[36] = { 0,1,2, 0,2,3, // front face
								 4,5,6, 4,6,7, // back face
								 8,9,10, 8,10,11,// left face
								 15,14,13, 15,12,13,// right face
								 16,17,18, 16,18,19,// top face
								 20,21,22, 20,23,22// bottom face
	};


    Mesh* pMesh = new Mesh();
    pMesh->Init(verts, 24, indices, 36, GL_STATIC_DRAW);

    return pMesh;
}


Mesh * Mesh::CreatePlane(vec2 origin, vec2 worldsize, ivec2 numofverts)
{
	const int NumofVerts = numofverts.x * numofverts.y;

	VertexFormat* verts = new VertexFormat[NumofVerts];

	int Xincrement = (int(worldsize.x) / (numofverts.x - 1));
	int Yincrement = (int(worldsize.y) / (numofverts.y - 1));

	int CurrentVert = 0;
	for (int y = 0; y < numofverts.y; y++)
	{
		for (int x = 0; x < numofverts.x; x++)
		{
			verts[CurrentVert] = VertexFormat(float(x * Xincrement), float(y * Yincrement), 0, 255, 255, 255, 255, 0, 0);
			CurrentVert++;
		}
	}
	int NumofIndicies = 0;
	int NumY = 0;
	int NumX = 0;
	if (numofverts.x == numofverts.y)
	{
		NumofIndicies = ((numofverts.x - 1) * (numofverts.y - 1) * 6);
		NumX = numofverts.x - 1;
		NumY = numofverts.y - 1;
	}
	else if (numofverts.x < numofverts.y)
	{
		NumofIndicies = ((numofverts.x) * (numofverts.y - 1) * 6);
		NumX = numofverts.x;
		NumY = numofverts.y - 1;
	}
	else if (numofverts.x > numofverts.y)
	{
		NumofIndicies = ((numofverts.x - 1) * (numofverts.y) * 6);
		NumX = numofverts.x - 1;
		NumY = numofverts.y;
	}

	int CurrentIndices = 0;

	unsigned int* indices = new unsigned int[NumofIndicies];

	for (int y = 0; y < (NumY); y++)
	{
		for (int x = 0; x < (NumX); x++)
		{
			indices[CurrentIndices] = x + 1 + (y * numofverts.x);
			CurrentIndices++;

			indices[(CurrentIndices)] = x + (y * numofverts.x);
			CurrentIndices++;

			indices[CurrentIndices] = x + (numofverts.x) + (y * numofverts.x);
			CurrentIndices++;

			indices[CurrentIndices] = x + (numofverts.x) + (y * numofverts.x);
			CurrentIndices++;

			indices[CurrentIndices] = x + (numofverts.x) + 1 + (y * numofverts.x);
			CurrentIndices++;

			indices[CurrentIndices] = x + 1 + (y * numofverts.x);
			CurrentIndices++;

		}
	}
	indices[CurrentIndices - 1] = 0;

	Mesh* pMesh = new Mesh();
	pMesh->Init(verts, NumofVerts, indices, NumofIndicies, GL_STATIC_DRAW);
	delete[] indices;
	delete[] verts;
	return pMesh;
}


Mesh * Mesh::CreateFromObjFile(const char* objfilename)
{
    long length = 0;
    char* buffer = LoadCompleteFile(objfilename, &length);
    if (buffer == 0 || length == 0)
    {
        delete buffer;
        return 0;
    }
    char* next_token = 0;
    char* line = strtok_s(buffer, "\n", &next_token);


    std::vector<vec3>vecVerts;
    std::vector<vec2>vecUVs;
    std::vector<vec3>vecNormals;

    std::vector<unsigned int>indicesVert;
    std::vector<unsigned int>indicesUV;
    std::vector<unsigned int>indicesNormal;

    while (line)
    {
        OutputMessage("%s\n", line);

        // based on the beginning of the line 
        if (line[0] == 'v' && line[1] == ' ')
        { 
            vec3 verts;
            sscanf_s(line, "%*s %f %f %f", &verts.x, &verts.y, &verts.z);
            vecVerts.push_back(verts); 
        }

        else if (line[0] == 'v' && line[1] == 't')
        {
            vec2 uvs;
            sscanf_s(line, "%*s %f %f", &uvs.x, &uvs.y);
            vecUVs.push_back(uvs);
        }

        else if (line[0] == 'v' && line[1] == 'n')
        {
            vec3 normals;
            sscanf_s(line, "%*s %f %f %f", &normals.x, &normals.y, &normals.z);
            vecNormals.push_back(normals);
        }

        else if (line[0] == 'f' )
        {
            unsigned int indiceVerts[3];
            unsigned int uvVerts[3];
            unsigned int normalVerts[3];
            sscanf_s(line, "%*s %d/%d/%d %d/%d/%d %d/%d/%d", &indiceVerts[0], &uvVerts[0], &normalVerts[0],
                &indiceVerts[1], &uvVerts[1], &normalVerts[1], &indiceVerts[2], &uvVerts[2], &normalVerts[2] );

            indicesVert.push_back(indiceVerts[0]);
            indicesVert.push_back(indiceVerts[1]);
            indicesVert.push_back(indiceVerts[2]);

            indicesUV.push_back(uvVerts[0]);
            indicesUV.push_back(uvVerts[1]); 
            indicesUV.push_back(uvVerts[2]);

            indicesNormal.push_back(normalVerts[0]);
            indicesNormal.push_back(normalVerts[1]);
            indicesNormal.push_back(normalVerts[2]);

        }
        
        

        line = strtok_s(0, "\n", &next_token);
    }

            VertexFormat* verts = new VertexFormat[indicesVert.size()];
            unsigned int vertIndex = 0;
            unsigned int uvIndex = 0;
            unsigned int normalIndex = 0;


            for (int i = 0; i < (int)indicesVert.size(); i++)
            {
                vertIndex = indicesVert[i];
                vec3 pos = vecVerts[vertIndex-1];
                verts[i].pos = pos;
            }
            for (int i = 0; i < (int)indicesUV.size(); i++)
            {
               uvIndex = indicesUV[i];
               vec2 pos = vecUVs[uvIndex - 1];
               verts[i].uv = pos;
            }
            for (int i = 0; i < (int)indicesNormal.size(); i++)
            {
                normalIndex = indicesNormal[i];
                vec3 pos = vecNormals[normalIndex - 1];
                verts[i].normal = pos;
            }


    Mesh* pMesh = new Mesh();
    pMesh->Init(verts, indicesVert.size(), 0, 0, GL_STATIC_DRAW);

    return pMesh;

    //delete[] indices;
    delete[] verts;

    
}
Mesh * Mesh::CreateInverseCube(vec3 size)
{
    VertexFormat verts[24];

    verts[0] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 0, 1);
    verts[1] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1); // front face
    verts[2] = VertexFormat(size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1);
    verts[3] = VertexFormat(size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, -1, 0, 0, 1);

    verts[4] = VertexFormat(-size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);
    verts[5] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1); // back face
    verts[6] = VertexFormat(size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);
    verts[7] = VertexFormat(size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 0, 1);

    verts[8] = VertexFormat(-size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0);
    verts[9] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0); // left face
    verts[10] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);
    verts[11] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);

    verts[12] = VertexFormat(size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0);
    verts[13] = VertexFormat(size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 0, 1, 0); // right face
    verts[14] = VertexFormat(size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);
    verts[15] = VertexFormat(size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 0, 1, 0);

    verts[16] = VertexFormat(-size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);
    verts[17] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0); // top face
    verts[18] = VertexFormat(size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0);
    verts[19] = VertexFormat(size.x / 2, size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);

    verts[20] = VertexFormat(-size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);
    verts[21] = VertexFormat(-size.x / 2, size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0); // bottom face
    verts[22] = VertexFormat(size.x / 2, -size.y / 2, 0, 255, 255, 255, 255, 0, 0, 1, 0, 0);
    verts[23] = VertexFormat(size.x / 2, -size.y / 2, -1, 255, 255, 255, 255, 0, 0, 1, 0, 0);

    unsigned int indices[36] = { 0,1,2, 0,2,3, // front face
        4,5,6, 4,6,7, // back face
        8,9,10, 8,10,11,// left face
        15,14,13, 15,12,13,// right face
        16,17,18, 16,18,19,// top face
        20,21,22, 20,23,22// bottom face
    };


    Mesh* pMesh = new Mesh();
    pMesh->Init(verts, 24, indices, 36, GL_STATIC_DRAW);

    return pMesh;
}

