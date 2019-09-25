
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec4		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform vec2		hu_vDimsTexture0;
uniform float		u_fStep;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex[9];

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
	
	float blurSize = u_fStep/hu_vDimsTexture0.y;
	
	v_vTex[0] = vec2(a_vTexCoord0.x, a_vTexCoord0.y - 4.0*blurSize);
	v_vTex[1] = vec2(a_vTexCoord0.x, a_vTexCoord0.y - 3.0*blurSize);
	v_vTex[2] = vec2(a_vTexCoord0.x, a_vTexCoord0.y - 2.0*blurSize);
	v_vTex[3] = vec2(a_vTexCoord0.x, a_vTexCoord0.y - blurSize);
	v_vTex[4] = a_vTexCoord0.xy;
	v_vTex[5] = vec2(a_vTexCoord0.x, a_vTexCoord0.y + blurSize);
	v_vTex[6] = vec2(a_vTexCoord0.x, a_vTexCoord0.y + 2.0*blurSize);
	v_vTex[7] = vec2(a_vTexCoord0.x, a_vTexCoord0.y + 3.0*blurSize);
	v_vTex[8] = vec2(a_vTexCoord0.x, a_vTexCoord0.y + 4.0*blurSize);
}
