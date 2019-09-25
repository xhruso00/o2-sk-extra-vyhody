
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;
attribute vec2		a_vTexCoord2;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMMatrix;
uniform vec3		hu_vCameraPos;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying float		v_fBuildingID;
varying vec2		v_vColorCoord;

void main(void)
{
	v_fBuildingID = a_vTexCoord0.s;
	v_vColorCoord = a_vTexCoord2;

	gl_Position = hu_mPMVMatrix*a_vPosition0;
}
