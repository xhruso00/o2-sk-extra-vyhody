
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec4		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform vec2		hu_vDimsTexture0;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec2		v_vUV0;
varying vec2		v_vUV1;
varying vec2		v_vUV2;
varying vec2		v_vUV3;

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
	v_vTex0UV = a_vTexCoord0.st;
	
	float stepx = 1.0/hu_vDimsTexture0.s;
	float stepy = 1.0/hu_vDimsTexture0.t;
	
	v_vUV0 = vec2(v_vTex0UV.x - stepx, v_vTex0UV.y - stepy);
	v_vUV1 = vec2(v_vTex0UV.x + stepx, v_vTex0UV.y + stepy);
	v_vUV2 = vec2(v_vTex0UV.x + stepx, v_vTex0UV.y - stepy);
	v_vUV3 = vec2(v_vTex0UV.x - stepx, v_vTex0UV.y + stepy);
}
