
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMMatrix;
uniform vec3		hu_vCameraPos;
uniform	vec4		u_vBlendByDistanceFunction;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTexCoord;
varying float		v_fBlendFactor;

// ------- FUNCTIONS ------- 


void main(void)
{
	vec3 vWorldPosition = vec3(hu_mMMatrix*a_vPosition0);
	v_fBlendFactor = 1.0 - GetGrowingValue(u_vBlendByDistanceFunction, 0.001*length(vWorldPosition - hu_vCameraPos));

	gl_Position = hu_mPMVMatrix * a_vPosition0;
	v_vTexCoord = a_vTexCoord0.st;
}
