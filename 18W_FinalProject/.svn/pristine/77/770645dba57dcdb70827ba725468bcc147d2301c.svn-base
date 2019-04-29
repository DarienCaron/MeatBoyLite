#ifndef __CameraObject_H__
#define __CameraObject_H__

class CameraObject : public GameObject
{
protected:
	mat4 m_MatView;
	mat4 m_MatProj;
    float m_CameraHeight;
    float m_CameraDistance;
    bool m_PressedR1 = false;
    bool m_PressedR2 = false;

    GameObject* m_FocusObject;

public:
    CameraObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale);
    virtual ~CameraObject();

    virtual void Update(float deltatime);

	mat4* GetViewMatrix() { return &m_MatView; }
	mat4* GetProjMatrix() { return &m_MatProj; }

    void SetFocusObject(GameObject* obj) { m_FocusObject = obj; }
    GameObject* GetFocusObject() { return m_FocusObject; }

    void SetCameraHeight(float height);
    void SetCameraDistance(float dist);

    float Lerp(float from, float to, float percent) { return from + percent * (to - from); }

    void SetFirstDebugMode(bool debug);
    void SetSecondDebugMode(bool debug);


};

#endif //__CameraObject_H__
