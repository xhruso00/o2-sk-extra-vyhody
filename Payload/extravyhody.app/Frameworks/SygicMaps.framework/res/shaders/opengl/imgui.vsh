
// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMatrix;

// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec2		a_vPosition0;
attribute vec2		a_vTexCoord0;
attribute vec4		a_vColor0;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTexCoord;
varying vec4		v_vColor;

void main(void)
{
	v_vTexCoord = a_vTexCoord0;
	v_vColor = a_vColor0;
    gl_Position = hu_mPMatrix * vec4(a_vPosition0, 0.0, 1.0);
}
