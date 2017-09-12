#version 120

attribute vec3 a_position;

uniform mat4 u_trans;
uniform mat4 u_cam;

void main() {
    gl_Position = u_cam * u_trans * vec4(a_position, 1.0);
}
