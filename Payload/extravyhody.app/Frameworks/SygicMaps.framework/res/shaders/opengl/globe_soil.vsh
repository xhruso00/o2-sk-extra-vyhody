
// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMMatrix;

// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec3		v_vNormal;

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
	vec4 vWorld = hu_mMMatrix*a_vPosition0;
	v_vTex0UV = a_vTexCoord0;
	v_vNormal = 0.001*vWorld.xyz;
}
