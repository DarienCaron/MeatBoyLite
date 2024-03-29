
uniform sampler2D u_Texture;
varying vec2 v_UV;

uniform vec3 u_CameraPosition;

varying vec3 v_SurfacePositionInWorldSpace;
varying vec3 v_Normal;

//uniform unsigned int u_LightCount;

uniform vec4 u_LightColor[3];
uniform vec3 u_LightPosition[3];

vec4 FinalColor = vec4(0, 0, 0, 1);

void main()
{
	
for(int i = 0; i < 3; i++)
{
	vec3 Diffuse = vec3(0,0,0);
	vec3 Specular = vec3(0,0,0);
	vec3 Ambient = vec3(0,0,0);
	vec3 LightPos = u_LightPosition[i];
	vec4 SurfaceColor = texture2D(u_Texture,v_UV);
	vec3 CameraPos = u_CameraPosition;
	vec3 SurfacePosition = v_SurfacePositionInWorldSpace;
	vec3 Normals = v_Normal;
	vec4 LightColor = u_LightColor[i];

	float Brightness = 4.0f;


	vec4 color = vec4(0,0,0,0);


	Ambient += CalculateAmbientLighting(1.0f,SurfaceColor);
	Diffuse += CalculateDiffuse(SurfacePosition, LightPos, Normals, Brightness, LightColor, 5.0f);
	Specular += CalculateSpecular(SurfacePosition, CameraPos, LightColor, Normals, 0.5f,GetNormalizedDir2Light(SurfacePosition, LightPos) );
	

	color = ((vec4(Ambient,1) + vec4(Diffuse,1) + vec4(Specular,1)));

	 
	FinalColor += color; 
	}

	

	gl_FragColor = FinalColor;
	
}
