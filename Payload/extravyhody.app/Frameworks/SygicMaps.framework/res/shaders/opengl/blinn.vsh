
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec4		a_vNormal0;

#if defined(TEXTURE_A) || defined(TEXTURE_D) || defined(TEXTURE_S)
attribute vec2		a_vTexCoord0;
#endif

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mNormalMatrix;
uniform mat4		hu_mMVMatrix;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec3		v_vPosition;
varying vec3		v_vNormal;
#if defined(TEXTURE_A) || defined(TEXTURE_D) || defined(TEXTURE_S)
varying vec2		v_vTexCoord;
#endif

void main(void)
{
	gl_Position = hu_mPMVMatrix * a_vPosition0;

	v_vPosition = (hu_mMVMatrix * a_vPosition0).xyz;
	v_vNormal = normalize((hu_mNormalMatrix * a_vNormal0).xyz);

#if defined(TEXTURE_A) || defined(TEXTURE_D) || defined(TEXTURE_S)
	v_vTexCoord = a_vTexCoord0;
#endif
}
