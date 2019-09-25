
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec2		a_vTexCoord0; // [building ID, terrain height]
attribute vec4		a_vTexCoord1; // building's top center
attribute vec2		a_vTexCoord2;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mMMatrix;
uniform mat4		hu_mPVMatrix;
uniform vec3		hu_vCameraPos;

uniform vec4		u_vFloatingHighDistanceFunction;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vColorCoord;
varying float		v_fBuildingID;

void main(void)
{
	vec4 vWorldPos = hu_mMMatrix*a_vPosition0;
	vec4 vCenterPos = hu_mMMatrix*a_vTexCoord1;
	vec3 vDiff = vCenterPos.xyz - hu_vCameraPos;
	float fDistToCamera = length(vDiff);
	float fMaxHeight = GetGrowingValue(u_vFloatingHighDistanceFunction, fDistToCamera);

	float fTerrainHeight = a_vTexCoord0.t;
	float fHeightNoTerrain = vWorldPos.y - fTerrainHeight;
	if (fHeightNoTerrain > fMaxHeight)
	{
		vWorldPos.y -= fHeightNoTerrain - fMaxHeight;
	}

	v_fBuildingID = a_vTexCoord0.s;
	v_vColorCoord = a_vTexCoord2;

	gl_Position = hu_mPVMatrix*vWorldPos;
}
