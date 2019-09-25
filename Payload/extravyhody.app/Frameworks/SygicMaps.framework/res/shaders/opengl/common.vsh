
#if defined(COLOR_TO_TEXTURE_INTERPOLATION)
#define TEXTURE0
#define CONST_COLOR
#endif

#if defined(CONST_COLOR) && !defined(VERTEX_COLOR)
// when "vertex color" not present there is no need to interpolate "const color", send it to pixel shader instead
#undef CONST_COLOR
#endif

// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;

#if defined(TEXTURE0)
attribute vec2		a_vTexCoord0;
#endif

#ifdef VERTEX_COLOR
attribute vec4		a_vColor0;
#endif

// ------- UNIFORMS (SHADER CONSTS) -------
uniform vec4		u_vGeoNormalmapInfo;
uniform	mediump vec4	u_vColor;
uniform	vec4		u_vBlendByDistanceFunction;
uniform	float		v_fBlendByDistanceCoef;

uniform bool		hu_bIsGlobeView;
uniform mat4		hu_mPMVMatrix;
uniform vec2		hu_vDimsTexture_u_tGeoNormalmap;
uniform mat4		hu_mLocalToGeoMatrix;
uniform mat4		hu_mMMatrix;
uniform vec3		hu_vCameraPos;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
#if defined(GEONORMALMAP)
varying vec2		v_vHeightmapUV0, v_vHeightmapUV1, v_vHeightmapUV2, v_vHeightmapUV3, v_vHeightmapUV4, v_vHeightmapUV5, v_vHeightmapUV6, v_vHeightmapUV7, v_vHeightmapUV8;
#endif

#if defined(TEXTURE0)
varying vec2		v_vTexCoord;
#endif

#if defined(VERTEX_COLOR)
varying vec4		v_vColor;
#endif

#if defined(BLEND_BY_DISTANCE)
varying float		v_fBlendFactor;
#endif

// ------- FUNCTIONS ------- 
#if defined(GEONORMALMAP)
const float MATH_PI = 3.141592;
const float RAD2DEG = 57.295779;

vec3 P3dToGeo(vec3 p)
{
	vec2 v;
	
	v.x = MATH_PI*0.5 - atan(p.z, p.x);
	if (v.x > MATH_PI*1.0) v.x -= MATH_PI*2.0;
	
	v.y = MATH_PI*0.5 - atan(length(vec2(p.x, p.z)), p.y);

	v.x *= RAD2DEG*100000.0;
	v.y *= RAD2DEG*100000.0;

	return vec3(v.x, 0.0, -v.y);
}

void SetHeightmapUVs(vec2 uv)
{
	float fOff = 1.0/hu_vDimsTexture_u_tGeoNormalmap.x;
	v_vHeightmapUV0 = uv + vec2(-fOff,  fOff);
	v_vHeightmapUV1 = uv + vec2(  0.0,  fOff);
	v_vHeightmapUV2 = uv + vec2( fOff,  fOff);
	v_vHeightmapUV3 = uv + vec2(-fOff,  0.0);
	v_vHeightmapUV4 = uv;
	v_vHeightmapUV5 = uv + vec2( fOff,  0.0);
	v_vHeightmapUV6 = uv + vec2(-fOff, -fOff);
	v_vHeightmapUV7 = uv + vec2(  0.0, -fOff);
	v_vHeightmapUV8 = uv + vec2( fOff, -fOff);
}
#endif

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
	vec3 vWorldPosition = vec3(hu_mMMatrix*a_vPosition0);

#if defined(BLEND_BY_DISTANCE)
	v_fBlendFactor = GetFunctionValue(u_vBlendByDistanceFunction, (1.0/v_fBlendByDistanceCoef)*0.001*length(vWorldPosition - hu_vCameraPos));
#endif

#if defined(GEONORMALMAP)
	vec3 vGeoVertex = hu_bIsGlobeView ? P3dToGeo(vWorldPosition) : vec3(hu_mLocalToGeoMatrix*a_vPosition0);
	vec2 vHeightmapUV = vec2(vGeoVertex.x - u_vGeoNormalmapInfo.x, vGeoVertex.z + u_vGeoNormalmapInfo.y)*u_vGeoNormalmapInfo.z;
	SetHeightmapUVs(vHeightmapUV);
#endif

#if defined(TEXTURE0)
	v_vTexCoord = a_vTexCoord0;
#endif

#ifdef VERTEX_COLOR
	vec4 vColor = a_vColor0;
#endif

#ifdef CONST_COLOR
	vColor *= u_vColor;
#endif

#ifdef VERTEX_COLOR
	v_vColor = vColor;
#endif
}
