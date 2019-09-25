
// ------- ATTRIBUTES (VERTEX BUFFER DATA) -------
attribute vec4		a_vPosition0;
attribute vec4		a_vColor0;
attribute vec2		a_vTexCoord0;

// ------- UNIFORMS (SHADER CONSTS) -------
uniform mat4		hu_mPMVMatrix;
uniform mat4		hu_mMMatrix;
uniform float		hu_fFrameTime;
uniform vec3		hu_vCameraPos;

// ------- INTERPOLATORS (SHADER OUTPUTS) -------
varying vec2		v_vTex0UV;
varying vec2		v_vTex1UV;
varying vec2		v_vTex2UV;
varying vec2		v_vTex3UV;
varying vec4		v_vColor;
varying vec3		v_vVertexDir;

void main(void)
{
	gl_Position = hu_mPMVMatrix*a_vPosition0;
	v_vColor = a_vColor0;

	vec4 vLocalPos = hu_mMMatrix*a_vPosition0;
	v_vVertexDir = normalize(hu_vCameraPos - vLocalPos.xyz);

	float fTime = hu_fFrameTime;
    v_vTex0UV = (a_vTexCoord0/103.0)+vec2(fTime/17.0, fTime/29.0);
    v_vTex1UV = a_vTexCoord0/107.0-vec2(fTime/-19.0, fTime/31.0);
    v_vTex2UV = a_vTexCoord0/vec2(897.0, 983.0)+vec2(fTime/101.0, fTime/97.0);
    v_vTex3UV = a_vTexCoord0/vec2(991.0, 877.0)-vec2(fTime/109.0, fTime/-113.0);
}
