
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
#if !defined(ON_GLOBE)
attribute vec4		a_vPosition1;
attribute vec2		a_vTexCoord0; // parpendicular
#else
attribute vec3		a_vTexCoord0; // parpendicular
#endif
attribute vec2		a_vTexCoord1; // [uv.t, path length]
attribute vec4		a_vColor0; // [road type, road direction, uv.s, ?]

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mMVMatrix;
uniform mat4		hu_mPMatrix;
uniform float		hu_fDistanceScaleFactor;
uniform vec4		hu_vViewport;
uniform float		hu_fDiscreteLog2GroundDistanceInKm;
uniform lowp float	hu_fSin11; // debug

// per type
#if defined(MAX_PATH_TYPES)
uniform vec4		u_vColor[MAX_PATH_TYPES];
uniform vec4		u_vBorderColor[MAX_PATH_TYPES];
uniform vec4		u_vMaskColor[MAX_PATH_TYPES];
uniform vec2		u_vWidthScales[MAX_PATH_TYPES]; // [width scale, border width in pixels]
uniform vec3		u_vMasksScales[MAX_PATH_TYPES]; // [mask, oneway, closed]
uniform float		u_fMaxDistance[MAX_PATH_TYPES]; // in km
#else
uniform vec4		u_vColor;
uniform vec4		u_vBorderColor;
uniform vec4		u_vMaskColor;
uniform vec2		u_vWidthScales; // [width scale, border width in pixels]
uniform vec3		u_vMasksScales; // [mask, oneway, closed]
uniform float		u_fMaxDistance; // in km
#endif

#if defined(CLOSED_COLOR_OVERRIDE)
uniform vec4		u_vClosedColor;
uniform vec4		u_vClosedBorderColor;
uniform vec4		u_vClosedMaskColor;
#endif

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTexCoord2; // uv
varying vec4		v_vColor;
varying vec4		v_vBorderColor;
varying vec4		v_vMaskColor;
varying vec2		v_fDistance; // [max, current] in km
varying float		v_fPathWidth;
varying float		v_fMaskIndex;
varying float		v_fBorderWidth;

void main(void)
{
	float fRoadType = a_vColor0.x + 0.01;
	int iRoadType = int(fRoadType);

#if defined(MAX_PATH_TYPES)
	v_vColor = u_vColor[iRoadType];
	v_vBorderColor = u_vBorderColor[iRoadType];
	v_vMaskColor = u_vMaskColor[iRoadType];
	vec2 vWidthScales = u_vWidthScales[iRoadType];
	vec3 vMasksScales = u_vMasksScales[iRoadType];
	float fMaxDistance = u_fMaxDistance[iRoadType];
#else
	v_vColor = u_vColor;
	v_vBorderColor = u_vBorderColor;
	v_vMaskColor = u_vMaskColor;
	vec2 vWidthScales = u_vWidthScales;
	vec3 vMasksScales = u_vMasksScales;
	float fMaxDistance = u_fMaxDistance;
#endif

	v_fBorderWidth = vWidthScales.y;

	bool isRoadEnd = a_vTexCoord1.y < 0.0;
	v_fMaskIndex = 0.0;
	v_vTexCoord2 = vec2(a_vColor0.z, a_vTexCoord1.x);
	if (!isRoadEnd)
	{
		int iRoadDirection = int(a_vColor0.y + 0.01);
		bool bOneWay = iRoadDirection == 1 || iRoadDirection == 2;

		float scale = 1.0 / (hu_fDiscreteLog2GroundDistanceInKm*vMasksScales.x);

		if (iRoadDirection == 4/*closed*/)
		{
			scale = 1.0 / (hu_fDiscreteLog2GroundDistanceInKm * vMasksScales.z);
			v_fMaskIndex = 2.0;
		}
#if defined(CLOSED_COLOR_OVERRIDE)
		else if (iRoadDirection == 5)
		{
			v_fMaskIndex = 2.0;
			v_vColor = (u_vClosedColor.a < 0.01) ? v_vColor : u_vClosedColor;
			v_vBorderColor = (u_vClosedBorderColor.a < 0.01) ? v_vBorderColor : u_vClosedBorderColor;
			v_vMaskColor = u_vClosedMaskColor;
		}
#endif
		else if (bOneWay)
		{
			scale = 1.0 / (hu_fDiscreteLog2GroundDistanceInKm*vMasksScales.y);
			v_fMaskIndex = 1.0;
		}

		float fPathLength = a_vTexCoord1.y; // 105.0
		float fTotalLenScaled = scale * fPathLength; // 105/10 = 10.5
		float fTotalLenRounded = floor(fTotalLenScaled); // 10
		fTotalLenRounded = max(1.0, fTotalLenRounded); // 10
		float f = fTotalLenRounded / fTotalLenScaled; // 10/10.5 = 0.95

		float fScaledv = iRoadDirection == 2 ? fPathLength - a_vTexCoord1.x : a_vTexCoord1.x;
		v_vTexCoord2.y = scale * f*(fScaledv); // 0 -> 0, 50 -> 5, 100 -> 10
	}

	vec4 vPos = a_vPosition0;
#if defined(ON_GLOBE)
	vec3 vShift = a_vTexCoord0;
#else
	vec3 vShift = vec3(a_vTexCoord0.x, 0.0, a_vTexCoord0.y);
#endif

	float roadClassScale = vWidthScales.x;

	// eye space
	vec4 vPosEye = hu_mMVMatrix*vPos;
	float fDistToCameraInKm_ = hu_fDistanceScaleFactor*0.001*length(vPosEye.xyz); // dist to point
	float fDistToCameraInKm = hu_fDistanceScaleFactor*0.001*(-vPosEye.z); // dist to plane

	v_fDistance = vec2(fMaxDistance, fDistToCameraInKm_);

	vec3 vShiftEye = mat3(hu_mMVMatrix)*vShift;
	vec4 vMiddleEye = vPosEye - vec4(vShiftEye, 0.0);
	vec4 vPosEyeShifted = vMiddleEye + vec4(roadClassScale*vShiftEye, 0.0);
	vec2 v0 = GetScreenCoords(vPosEyeShifted, hu_mPMatrix, hu_vViewport);

	vec4 vOppositeEye = vMiddleEye - (vPosEyeShifted - vMiddleEye);
	vec2 v1 = GetScreenCoords(vOppositeEye, hu_mPMatrix, hu_vViewport);

#if defined(ON_GLOBE)
	v_fPathWidth = length(v0 - v1); // not precise but good enough for globe view as we see paths mostly from the top
#else
	vec4 vPosCross = a_vPosition1;

	vec4 vPosEyeCross = hu_mMVMatrix*vPosCross;
	float fDistToCameraInKm2 = (hu_fDistanceScaleFactor*0.001)*length(vPosEyeCross.xyz);

	vec3 vShiftCross = -vShift;
	vec3 vShiftEyeCross = mat3(hu_mMVMatrix)*vShiftCross;
	vec4 vMiddleEyeCross = vPosEyeCross - vec4(vShiftEyeCross, 0.0);
	vec4 vPosEyeCrossShifted = vMiddleEyeCross + vec4(roadClassScale*vShiftEyeCross, 0.0);
	vec2 v2 = GetScreenCoords(vPosEyeCrossShifted, hu_mPMatrix, hu_vViewport);

	vec2 v12 = v2 - v1;
	// ax + by + c = 0
	// c = - ax - by
	vec2 normalized = normalize(v12);
	vec2 n = vec2(normalized.y, -normalized.x);
	float c = -(n.x*v2.x) -(n.y*v2.y);

	v_fPathWidth = abs(n.x*v0.x + n.y*v0.y + c);
#endif

	gl_Position = hu_mPMatrix*vPosEyeShifted;
}
