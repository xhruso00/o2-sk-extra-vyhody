//------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTexCoord;

// ------- FUNCTIONS -------


void main(void)
{
	gl_Position = hu_mPMVMatrix * a_vPosition0;
	v_vTexCoord = a_vTexCoord0.st;
}