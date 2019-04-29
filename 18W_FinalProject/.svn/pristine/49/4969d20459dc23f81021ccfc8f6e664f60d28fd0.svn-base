#include "GamePCH.h"

CameraObject::CameraObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale)
: GameObject( pScene, name, pos, rot, scale, 0, 0 )
{
    m_CameraDistance = 0;
    m_CameraHeight = 0;
    m_FocusObject = 0;
}

CameraObject::~CameraObject()
{
}

void CameraObject::Update(float deltatime)
{
    // if r is pressed show these debug options
    if (m_PressedR1 == true)
    {
        ImGui::Begin("Camera Rotation Level 1");
        ImGui::SliderFloat("X", &m_Rotation.x, 0, 360, "%.2f");
        ImGui::SliderFloat("Y", &m_Rotation.y, 0, 360, "%.2f");
        ImGui::End(); // debugging to rotate the camera on the x and y axis, this is mainly to view the cubemap
    }

    if (m_PressedR2 == true)
    {
        ImGui::Begin("Camera Rotation Level ");
        ImGui::SliderFloat("X", &m_Rotation.x, 0, 360, "%.2f");
        ImGui::SliderFloat("Y", &m_Rotation.y, 0, 360, "%.2f");
        ImGui::End(); // debugging to rotate the camera on the x and y axis, this is mainly to view the cubemap
    }

    if(GetFocusObject() != nullptr)
    {
        float cx = cos(m_Rotation.x / 180.0f * PI);
        float sx = sin(m_Rotation.x / 180.0f * PI);

        float cy = cos(m_Rotation.y / 180.0f * PI);
        float sy = sin(m_Rotation.y / 180.0f * PI);


        float dist = m_CameraDistance;

        //-D cX sY, D sX, -D cXcY


        vec3 eye(-dist  * cx* sy, dist * sx, -dist * cx * cy);

        vec3 FocusPos = GetFocusObject()->GetPosition();

        float lerpx = Lerp(eye.x, FocusPos.x, 0.60f);
        float lerpy = Lerp(eye.y, FocusPos.y, 0.80f);
        float lerpz = Lerp(eye.z, FocusPos.z, 0.40f);

        vec3 Lerpvec = vec3(lerpx, lerpy, lerpz);

        eye += Lerpvec;

        m_MatView.CreateLookAtViewLeftHanded(eye, vec3(0, 1, 0), vec3(Lerpvec.x, Lerpvec.y, Lerpvec.z));

        m_MatProj.CreatePerspectiveVFoV(45, 600.0f / 600.0f, 0.01f, 100);
    }
    else
    {
        float cx = cos(m_Rotation.x / 180.0f * PI);
        float sx = sin(m_Rotation.x / 180.0f * PI);


        float cy = cos(m_Rotation.y / 180.0f * PI);
        float sy = sin(m_Rotation.y / 180.0f * PI);


        float dist = m_CameraDistance;

        //-D cX sY, D sX, -D cXcY


        vec3 eye(-dist  * cx* sy, dist * sx, -dist * cx * cy);

        m_MatView.CreateLookAtViewLeftHanded(eye, vec3(0, 1, 0), vec3(0, 0, 0));

        m_MatProj.CreatePerspectiveVFoV(45, 600.0f / 600.0f, 0.01f, 100);
    }

    GameObject::Update( deltatime );
}

void CameraObject::SetCameraHeight(float height)
{
    m_CameraHeight = height;

}

void CameraObject::SetCameraDistance(float dist)
{
    m_CameraDistance = dist;
}

void CameraObject::SetFirstDebugMode(bool debug)
{
    m_PressedR1 = debug;
}

void CameraObject::SetSecondDebugMode(bool debug)
{
    m_PressedR2 = debug;
}
