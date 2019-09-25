
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform vec3		hu_vCameraPos;
uniform vec3		u_vNormalizedLightDir;
uniform float		u_fGlobeRadius;
uniform float		u_fAtmosphereRadius;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying float		v_fAlpha;

// ------- FUNCTIONS ------- 
void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;

	//const float f = 0.001; // to avoid limited precision issue on some platforms
    vec3 position = a_vPosition0.xyz;//*f;
    vec3 camPos = hu_vCameraPos;//*f;
    float fGlobeRadius = u_fGlobeRadius;//*f;
    float fAtmosphereRadius = u_fAtmosphereRadius;//*f;
 
	float radius = length(position);
    float radius2 = radius*radius; 
    float camHeight = length(camPos);
    vec3 camToPos = position - camPos;
    float farDist = length(camToPos);
 
	vec3 lightDir = -u_vNormalizedLightDir;
    vec3 normal = normalize(position);
 
    vec3 rayDir = camToPos/farDist;
    float camHeight2 = camHeight*camHeight;
 
    // Calculate the closest intersection of the ray with the outer atmosphere
    float B = 2.0*dot(camPos, rayDir);
    float C = camHeight2 - radius2;
    float det = max(0.0, B*B - 4.0*C);
    float nearDist = 0.5*(-B - sqrt(det));
    vec3 nearPos = camPos + (rayDir*nearDist);
    vec3 nearNormal = normalize(nearPos);

    // get dot products we need
    float lc = dot(lightDir, camPos/camHeight);
    float ln = dot(lightDir, normal);
    float lnn = dot(lightDir, nearNormal);

    // get distance to surface horizon
    float altitude = camHeight - fGlobeRadius;
    float horizonDist = sqrt((altitude*altitude) + (2.0*fGlobeRadius*altitude));
    float maxDot = horizonDist / camHeight;
 
    // get distance to atmosphere horizon - use max(0,...) because we can go into the atmosphere
    altitude = max(0.0, camHeight - fAtmosphereRadius);
    horizonDist = sqrt((altitude*altitude) + (2.0*fAtmosphereRadius*altitude));
 
	float minDot = horizonDist/camHeight;
 
    // get dot product of the vertex we're looking out
    float posDot = dot(camToPos/farDist, -camPos/camHeight) - minDot;
 
    // calculate the height from surface in range 0..1
    float height = posDot*(1.0/(maxDot - minDot));
 
    // push the horizon back based on artistic taste
	const float StretchAmt = 0.3;
    ln = max(0.0,ln + StretchAmt);
    lnn = max(0.0,lnn + StretchAmt);

    // the front color is the sum of the near and far normals
    float brightness = saturate(ln + (lnn*lc));
 
    v_fAlpha = height*brightness;
}
