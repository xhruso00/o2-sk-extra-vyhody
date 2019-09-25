
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0; // uv
attribute vec3		a_vTexCoord1; // parpendicular
attribute vec4		a_vColor0; // (road type, road direction, ?, ?)

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mMVMatrix;
uniform mat4		hu_mPMatrix;
uniform vec4		hu_vViewport;
uniform lowp float	hu_fSin11; // debug
uniform float		hu_fGroundDistanceInKm;
uniform float		hu_fDistanceScaleFactor;
uniform vec2		hu_vDimsTexture_u_tColors;
uniform mediump int	hu_nRenderPass;
uniform vec4		u_fxWidthScaleByDistance;
uniform float		u_vWidth;
uniform vec2		u_vWidthScales; // [add. width scale, border scale]
uniform float		u_fMaxDistance; // in km
uniform vec4		u_fxWidthScaleByGroundDistance;
uniform vec4		u_fxBorderWidthScaleByDistance;
uniform vec4		u_fxColorsInterpolator; // function of (border width)/(total width)

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec4		v_vColorUVs;
varying vec2		v_vParams;
varying vec3		v_fPackedWidths; // [total width (includes border width) in pixels, border width in pixels, border width in meters]
varying vec2		v_fDistance; // [max, current] in km
varying float		v_fColorsInterpolator;

void main(void)
{
	v_vTex0UV = a_vTexCoord0;

	float color = (0.5 + 2.0*a_vColor0.x)/hu_vDimsTexture_u_tColors.x;
	float color2 = (1.5 + 2.0*a_vColor0.x)/hu_vDimsTexture_u_tColors.x;

	v_vColorUVs.xy = vec2(color, 0.5);
	v_vColorUVs.zw = vec2(color2, 0.5);

	v_vParams = a_vColor0.xy;
	vec4 vPos = a_vPosition0;
	vec3 vShift = a_vTexCoord1;
	float k = u_vWidthScales.x*GetGrowingValue(u_fxWidthScaleByGroundDistance, hu_fGroundDistanceInKm);


    // eye space
	vec4 vPosEye = hu_mMVMatrix*vPos;
	float fDistToCameraInKm = hu_fDistanceScaleFactor*0.001*length(vPosEye.xyz);
	//float fDistToEyePlaneInKm = -hu_fDistanceScaleFactor*0.001*vPosEye.z;
	/*float */k += 0.0 + GetGrowingValue(u_fxWidthScaleByDistance, fDistToCameraInKm);
	//k = 1.0;
    
	//vec3 vShiftEye = normalize(vShift*mat3(hu_mMVIMatrix));
	vec3 vShiftEye = mat3(hu_mMVMatrix)*vShift;
    
	vec4 vPosEyeShifted = vPosEye + vec4(k*vShiftEye, 0.0);
	vec2 v0 = GetScreenCoords(vPosEyeShifted, hu_mPMatrix, hu_vViewport);

	float fHalfWidth = 0.5*u_vWidth;
	float fRatio = fHalfWidth/(hu_fDistanceScaleFactor*length(vShiftEye));

	vec4 vMiddleEye = vPosEye - vec4(vShiftEye, 0.0);
	vec2 vm = GetScreenCoords(vMiddleEye, hu_mPMatrix, hu_vViewport);

	vec3 vShiftEyeN = normalize(vShiftEye);
	float fScaledLength = length(vPosEyeShifted - vMiddleEye);
	float b = min(fScaledLength, u_vWidthScales.y*GetGrowingValue(u_fxBorderWidthScaleByDistance, fDistToCameraInKm)/hu_fDistanceScaleFactor);
	//vec4 vPosEyeShiftedBorder = vMiddleEye + b*fScaledLength*vec4(vShiftEyeN, 0.0);
	vec4 vPosEyeShiftedBorder = vPosEyeShifted - b*vec4(vShiftEyeN, 0.0);
	vec2 v1 = GetScreenCoords(vPosEyeShiftedBorder, hu_mPMatrix, hu_vViewport);

	// v_fPackedWidths = [total width(includes border width) in pixels, border width in pixels, border width in meters]
	v_fPackedWidths.z = length(vPosEyeShifted - vPosEyeShiftedBorder); // border width in meters
	float fWidth = length(v0 - vm); // 1/2 of path width in pixels
	v_fPackedWidths.x = fWidth;
	float fBorderWidth = length(v0 - v1); // border width in pixels
	v_fPackedWidths.y = fBorderWidth;

	v_fDistance = vec2(u_fMaxDistance, fDistToCameraInKm);

	v_fColorsInterpolator = GetGrowingValue(u_fxColorsInterpolator, (fBorderWidth/fWidth)/fRatio); // function of (border width)/(total width)

	if (hu_nRenderPass == 1)
	{
		gl_Position = hu_mPMatrix*vPosEyeShiftedBorder;
	}
	else
	{
		gl_Position = hu_mPMatrix*vPosEyeShifted;
	}
}
