
attribute vec3 a_Position;
attribute vec2 a_UV;


uniform int u_Digit;
uniform mat4 u_WorldMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectionMatrix;
uniform vec4 a_Color;

varying vec2 v_UV;

void main()
{
	vec4 objectSpacePos = vec4(a_Position, 1);
    vec4 worldSpacePos = u_WorldMatrix * objectSpacePos;
    vec4 viewSpacePos = u_ViewMatrix * worldSpacePos;
    vec4 finalPos = u_ProjectionMatrix * viewSpacePos  ;

    gl_Position = finalPos;

    v_UV = a_UV;

	v_UV *= vec2(0.1f, 1.0f);
	v_UV += vec2((0.1 * u_Digit), 1.0f);
}
