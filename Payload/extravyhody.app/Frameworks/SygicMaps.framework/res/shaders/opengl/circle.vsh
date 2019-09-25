
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;

void main(void)
{
	v_vTex0UV = a_vTexCoord0;

    gl_Position = hu_mPMVMatrix * a_vPosition0;
}

