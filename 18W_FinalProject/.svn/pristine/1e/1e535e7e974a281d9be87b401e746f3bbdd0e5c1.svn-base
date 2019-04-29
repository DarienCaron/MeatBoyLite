#ifndef __SkyBox_H__
#define __SkyBox_H__


class SkyBox : public GameObject
{
public:
    SkyBox(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    SkyBox(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
    virtual ~SkyBox();

    virtual void Update(float deltatime);
    virtual void Draw(vec3 campos);


protected:
    Mesh* m_pMesh;
    Material* m_Material;
};

















#endif //__SkyBox_H__
