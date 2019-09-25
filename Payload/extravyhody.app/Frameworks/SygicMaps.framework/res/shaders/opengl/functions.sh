#ifdef GL_FRAGMENT_PRECISION_HIGH
	#define float_hp highp float
	#define vec2_hp highp vec2
	#define vec3_hp highp vec3
	#define vec4_hp highp vec4
	#define sampler2D_hp highp sampler2D
#else
	#define float_hp float
	#define vec2_hp vec2
	#define vec3_hp vec3
	#define vec4_hp vec4
	#define sampler2D_hp sampler2D
#endif

#define lerp mix

vec4 vec4b2f(int r, int g, int b, int a)
{
    return vec4(float(r)/255.0, float(g)/255.0, float(b)/255.0, float(a)/255.0);
}

float GetGrowingValue(vec4 fnParams, float x)
{
	float y = fnParams.x + fnParams.w*(x - fnParams.z);
	return min(fnParams.y, max(fnParams.x, y));
}

float GetFunctionValue(vec4 fnParams, float x)
{
	bool growing = fnParams.x < fnParams.y;
	float mn = growing ? fnParams.x : fnParams.y, mx = growing ? fnParams.y : fnParams.x;
	float scaled = fnParams.x + fnParams.w*(x - fnParams.z);
	return clamp(scaled, mn, mx);
}

float saturate(float f)
{
	return clamp(f, 0.0, 1.0);
}

float fresnel(vec3 vViewDirection, vec3 vNormal)
{
	return saturate(dot(vViewDirection, vNormal));
}

vec2 GetScreenCoords(vec4 vEyeCoords, mat4 mProjection, vec4 vViewport)
{
	vec4_hp vClip = mProjection*vEyeCoords;
	// clip -> NDC -> screen
	vec2 vScreen = vec2(vViewport.z, vViewport.w)*((1.0 + vClip.xy/vClip.w)/2.0);
	return vScreen;
}

float GetDistanceFromEyePlane(sampler2D sDepth, vec2 vCoords, vec4 vCameraNearFar)
{
	float z = 2.0*texture2D(sDepth, vCoords).x - 1.0; // depth from [0.0, 1.0] -> [-1.0, 1.0]
	return (2.0*vCameraNearFar.x*vCameraNearFar.y)/(vCameraNearFar.w - z*vCameraNearFar.z);
}

float GetDistanceFromEye(sampler2D sDepth, vec2 vCoords, mat4 mInverseProjection)
{
    float z = 2.0*texture2D(sDepth, vCoords).x - 1.0; // depth from [0.0, 1.0] -> [-1.0, 1.0]
    vec4 vClipSpacePosition = vec4(vCoords*2.0 - 1.0, z, 1.0);
    vec4 vViewSpacePosition = mInverseProjection*vClipSpacePosition;

    // Perspective division
    vViewSpacePosition /= vViewSpacePosition.w;

	return length(vViewSpacePosition.xyz);
}

float_hp GetDistanceFromEyeHP(sampler2D_hp sDepth, vec2 vCoords, mat4 mInverseProjection)
{
    float_hp z = 2.0*texture2D(sDepth, vCoords).x - 1.0;
    vec4_hp vClipSpacePosition = vec4(vCoords*2.0 - 1.0, z, 1.0);
    vec4_hp vViewSpacePosition = mInverseProjection*vClipSpacePosition;

    // Perspective division
    vViewSpacePosition /= vViewSpacePosition.w;

	return length(vViewSpacePosition.xyz);
}

float interpolate(float param, float begin, float end)
{
	return clamp((param - begin) / (end - begin), 0.0, 1.0);
}
