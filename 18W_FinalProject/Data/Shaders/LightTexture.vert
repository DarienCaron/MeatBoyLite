
attribute vec4 a_Position;
attribute vec2 a_UV;
attribute vec4 a_Color;
attribute vec3 a_Normal;

uniform mat4 u_WorldMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectionMatrix;

varying vec2 v_UV;
varying vec3 v_SurfacePositionInWorldSpace;
varying vec3 v_Normal;

void main()
{

    vec4 objectpos = a_Position;                   // Store object space position.
	vec4 worldpos = u_WorldMatrix * objectpos;				// Calculate view space position.	
	v_SurfacePositionInWorldSpace = worldpos.xyz;
	vec4 viewpos = u_ViewMatrix * worldpos;                 // Calculate clip space position.
	vec4 finalpos = u_ProjectionMatrix *  viewpos; 
	
	gl_Position = finalpos;								    // Store final position in gl_Position						
	
	v_UV = a_UV;
	v_Normal = normalize(a_Normal);
}
