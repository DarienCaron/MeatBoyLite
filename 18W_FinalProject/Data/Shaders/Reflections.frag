
uniform samplerCube u_TextureCube;
varying vec2 v_UV;

uniform vec3 u_CameraPosition;

varying vec3 v_SurfacePositionInWorldSpace;
varying vec3 v_Normal;
varying mat4 v_RotationMat;

void main()
{	
	vec3 Eye =  v_SurfacePositionInWorldSpace - u_CameraPosition;
	vec3 Incident_Eye = normalize(Eye);

	vec3 normals = v_Normal;



	vec3 normalized = normalize(normals);


	vec3 reflected = reflect(Incident_Eye,normalized );



	 // reflected = vec3(u_CameraPosition * reflected);

	  vec4 col = textureCube( u_TextureCube, reflected );

	gl_FragColor = col;
	
}
