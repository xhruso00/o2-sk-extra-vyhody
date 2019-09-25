
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
//attribute vec4		a_vTexCoord0;
attribute vec2		a_vTexCoord2;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMMatrix;
uniform vec3		hu_vCameraPos;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vColorCoord;
varying float		v_fDistToCamera;

void main(void)
{
	vec4 vWorldPos = hu_mMMatrix*a_vPosition0;
	vec3 vDiff = vWorldPos.xyz - hu_vCameraPos;
	v_fDistToCamera = length(vDiff);

	v_vColorCoord = a_vTexCoord2;

	gl_Position = hu_mPMVMatrix*a_vPosition0;
}
