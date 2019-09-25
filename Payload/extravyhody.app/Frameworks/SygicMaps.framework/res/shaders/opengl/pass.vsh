
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
}
