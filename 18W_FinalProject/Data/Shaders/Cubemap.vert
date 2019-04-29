
attribute vec3 a_Position;
attribute vec2 a_UV;
attribute vec4 a_Color;

uniform mat4 u_WorldMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectionMatrix;

uniform vec3 u_CameraPosition;
uniform vec2 u_ProjectionScale;

varying vec2 v_UV;
varying vec3 v_CubemapUV;

void main()
{
	// Store object space position.
	v_CubemapUV = a_Position;
	vec4 objectpos = vec4(a_Position, 1);

	
	

	// Calculate view space position.
	vec4 viewpos = u_ViewMatrix * vec4(objectpos.xyz, 0);

	// Calculate clip space position.
	vec4 finalpos = u_ProjectionMatrix *  vec4(viewpos.xyz, 1);

	// Store final position in gl_Position
    gl_Position = finalpos + 40;

	v_UV = a_UV;
	
}
