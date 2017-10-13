#version 120

varying vec3 v_position;
varying vec2 v_tex_coord;
varying vec3 v_normal;

uniform sampler2D diffuse;
uniform bool u_use_lighting;
uniform bool u_use_texture;
uniform vec3 u_default_color;
uniform vec3 u_light_pos;
uniform vec3 u_cam_pos;

void main() {

    vec3 unit_normal = normalize(v_normal);
    vec3 to_light = normalize(u_light_pos - v_position);
    vec3 to_cam = normalize(u_cam_pos - v_position);
    vec4 light_color = vec4(1, 1, 1, 1);
    vec4 color;
    if (u_use_texture) {
        color = texture2D(diffuse, v_tex_coord);
    }
    else {
        color = vec4(u_default_color, 1);
    }
    vec4 diffuse;
    if (u_use_lighting) {
        diffuse = light_color * color * clamp(dot(unit_normal, to_light), 0, 1);
    }
    else {
        diffuse = color;
    }
    
    gl_FragColor = diffuse;

}
