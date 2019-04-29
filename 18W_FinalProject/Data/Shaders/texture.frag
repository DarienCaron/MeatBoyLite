
uniform sampler2D u_Texture;

varying vec2 v_UV;

void main()
{
	vec4 col = texture2D( u_Texture, v_UV );

	if(col.w <= 0.0f)
	{
		discard;
	}

	gl_FragColor = col;
}
