
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0; // (u, index to color texture)
attribute vec3		a_vTexCoord1; // parpedicular

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mMVMatrix;
uniform mat4		hu_mPMatrix;
uniform vec4		hu_vViewport;
uniform float		hu_fGroundDistance;
uniform vec2		hu_vDimsTexture_u_tColors;

uniform vec4		u_fxWidthScaleByGroundDistance;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec2		v_vColorUV;
varying vec2		v_vColorUV2;
varying float		v_fWidth;

void main(void)
{
	v_vTex0UV = a_vTexCoord0;

	float color = (0.5 + 2.0*a_vTexCoord0.y)/hu_vDimsTexture_u_tColors.x;
	float color2 = (1.5 + 2.0*a_vTexCoord0.y)/hu_vDimsTexture_u_tColors.x;
	v_vColorUV = vec2(color, 0.5);
	v_vColorUV2 = vec2(color2, 0.5);

	vec4 vPos = a_vPosition0;
	float k = GetGrowingValue(u_fxWidthScaleByGroundDistance, hu_fGroundDistance);

	vec4 vPosEye = hu_mMVMatrix*vPos;

	vec3 vShift = a_vTexCoord1;
	vec3 vShiftEye = mat3(hu_mMVMatrix)*vShift;

	vec4 vPosEyeShifted = vPosEye + vec4(k*vShiftEye, 0.0);
	vec4 vMiddleEye = vPosEye - vec4(vShiftEye, 0.0);
	vec4 vDiff = vPosEyeShifted - vMiddleEye;
	vec4 vOpposite = vMiddleEye - vDiff;
	vec2 v0 = GetScreenCoords(vPosEyeShifted, hu_mPMatrix, hu_vViewport);
	vec2 v1 = GetScreenCoords(vOpposite, hu_mPMatrix, hu_vViewport);

	v_fWidth = length(v0 - v1); // path width in pixels

	gl_Position = hu_mPMatrix*vPosEyeShifted;
}
