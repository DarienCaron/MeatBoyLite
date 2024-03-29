
attribute vec3 a_Position;
attribute vec2 a_UV;
attribute vec4 a_Color;

uniform mat4 u_WorldMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectionMatrix;

uniform vec3 u_CameraPosition;
uniform vec2 u_ProjectionScale;

varying vec2 v_UV;

void main()
{
	// Store object space position.
	vec4 objectpos = vec4(a_Position, 1);

	vec4 worldpos = u_WorldMatrix * objectpos;
	

	// Calculate view space position.
	vec4 viewpos = u_ViewMatrix * worldpos;

	// Calculate clip space position.
	vec4 finalpos = u_ProjectionMatrix *  viewpos;

	// Store final position in gl_Position
    gl_Position = finalpos;

	v_UV = a_UV;
}
