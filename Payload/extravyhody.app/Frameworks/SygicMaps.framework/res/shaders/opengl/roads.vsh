
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0;
attribute vec3		a_vTexCoord1;
attribute vec4		a_vColor0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMVMatrix;
uniform mat4		hu_mMVIMatrix;
uniform float		hu_vCameraDistanceToMpp;
uniform float		hu_fSin11; // debug
							   //uniform float		hu_fGroundMpp;
uniform float		hu_fGroundDistance;
vec2		u_vTextureUVScale = vec2(1);
uniform float		u_fWidth;
//uniform vec4		u_fxWidthByDistance;
//uniform vec4		u_fxWidthByAngle;
uniform vec4		u_fxWidthScaleByDistance;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec4		v_vColor;

void main(void)
{
	v_vTex0UV = a_vTexCoord0*u_vTextureUVScale;
	vec4 vPos = a_vPosition0;
	vec3 vShift = a_vTexCoord1;
	//vec3 vShift = a_vTexCoord1*u_fWidth;

	//if (hu_fSin11 > 0.0)
	//{
	// eye space
	vec4 vPosEye = hu_mMVMatrix*vPos;
	vec3 vShiftEye = normalize(vShift*mat3(hu_mMVIMatrix));

	//vec3 vCam2Pos = normalize(vPosEye.xyz);
	//float fAngle = dot(vShiftEye, vCam2Pos);
	//float fWidthByAngle = GetGrowingValue(u_fxWidthByAngle, fAngle);
	//float fDistToCamera = length(vPosEye.xyz);
	//float fWidthByDistance = GetGrowingValue(u_fxWidthByDistance, fDistToCamera);
	//vPos.xyz += (fWidthByAngle*fWidthByDistance + u_fWidth)*vShift; // original
	//float k = (fDistToCamera*hu_vCameraDistanceToMpp + u_fWidth)*0.5;
	float k = GetGrowingValue(u_fxWidthScaleByDistance, hu_fGroundDistance);
	vPos.xyz += k * u_fWidth * vShift;
	//vPos.y += fWidthByAngle*fWidthByDistance;
	v_vColor = a_vColor0;
	//}
	//else
	//{	
	//	vPos.xyz += u_fWidth*vShift;
	//}

	// I want to keep this stuff for future impovements
	//float r = 1.0;
	//float g = 0.0;
	//float b = 0.0;
	//float a = k;

	//r = 0.0;
	//g = fWidthByAngle/5.0;
	//a = 1.0;

	//// angle
	////b = fWidthByAngle/5.0;
	//// distance
	////if (k > 3.0)
	////{
	////	r = 1.0;
	////	b = 1.0;
	////	a = k - 3.0;
	////}
	////else
	////if (k > 2.0)
	////{
	////	r = 0.0;
	////	b = 1.0;
	////	a = k - 2.0;
	////}
	////else
	////if (k > 1.0)
	////{
	////	r = 0.0;
	////	g = 1.0;
	////	a = k - 1.0;
	////}
	//v_vColor = vec4(r,g,b,a);

	gl_Position = hu_mPMVMatrix*vPos;
}
