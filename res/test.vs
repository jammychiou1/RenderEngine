#version 120

attribute vec3 a_position;
attribute vec2 a_tex_coord;
attribute vec3 a_normal;

varying vec3 v_position;
varying vec2 v_tex_coord;
varying vec3 v_normal;

uniform mat4 u_transform;
uniform mat4 u_camera;

void main() {
    gl_Position = u_camera * u_transform * vec4(a_position, 1.0);
    v_position = (u_transform * vec4(a_position, 1.0)).xyz;
    v_tex_coord = a_tex_coord;
    v_normal = normalize((u_transform * vec4(a_normal, 0.0)).xyz);
}
