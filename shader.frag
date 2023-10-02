#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

vec3 palette(float t) {
    vec3 a = vec3(0.821, 0.328, 0.242);
    vec3 b = vec3(0.514, 0.375, 0.699);
    vec3 c = vec3(0.612, 0.340, 0.296);
    vec3 d = vec3(2.820, 3.026, -0.273);

    return a + b*cos(6.28318*(c*t+d));
}

void main() {
    vec2 uv = (gl_FragCoord.st * 2.0 - u_resolution) / u_resolution.s;
    float d = length(uv);
    vec3 color = palette(d + u_time);
    
    d = sin(d * 16.0 + u_time) / 16.0;
    d = abs(d);
    // d = smoothstep(0.0, 0.1, d);
    d = 0.02 / d;
    // vec3 color = vec3(1.0, 1.0, 0.0);
    color *= d;
    gl_FragColor = vec4(color, 1.0);
}