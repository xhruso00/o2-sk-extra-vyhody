
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;
attribute vec3		a_vTexCoord1;
attribute vec4		a_vColor0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
//uniform float		hu_fGroundMpp;
uniform float		hu_fGroundDistance;

uniform vec4		u_fxWidthScaleByGroundDistance;
 vec2		u_vTextureUVScale = vec2(1.0);
uniform float		u_fWidth;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec4		v_vColor;

void main(void)
{
	v_vTex0UV = a_vTexCoord0*u_vTextureUVScale;

	vec4 vPos = a_vPosition0;
	vec3 vShift = a_vTexCoord1;
	//float k = GetGrowingValue(u_fxWidthScaleByGroundDistance, hu_fGroundMpp);
	float k = GetGrowingValue(u_fxWidthScaleByGroundDistance, hu_fGroundDistance);
	vPos.xyz += k * u_fWidth * vShift;
	v_vColor = a_vColor0;
	
	gl_Position = hu_mPMVMatrix * vPos;
}
