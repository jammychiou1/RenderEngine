#version 330

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_tex_coord;
layout(location = 2) in vec3 a_normal;

out vec3 v_position;
out vec2 v_tex_coord;
out vec3 v_normal;

uniform mat4 u_transform;
uniform mat4 u_camera;

void main() {
    gl_Position = u_camera * u_transform * vec4(a_position, 1.0);
    v_position = (u_transform * vec4(a_position, 1.0)).xyz;
    v_tex_coord = a_tex_coord;
    v_normal = normalize((u_transform * vec4(a_normal, 0.0)).xyz);
}
