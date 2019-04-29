
uniform samplerCube u_TextureCube;

varying vec2 v_UV;
varying vec3 v_CubemapUV;

void main()
{
	vec4 col = textureCube( u_TextureCube, v_CubemapUV );

	//if(col.w <= 0.0f)
	{
		//discard;
	}

	gl_FragColor = col;
}
