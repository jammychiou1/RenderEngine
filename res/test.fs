#version 330

in vec3 v_position;
in vec2 v_tex_coord;
in vec3 v_normal;

layout(location = 0) out vec4 o_color;

uniform sampler2D diffuse;
uniform vec3 u_light_pos;
uniform vec3 u_cam_pos;

void main() {

    vec3 unit_normal = normalize(v_normal);
    vec3 to_light = normalize(u_light_pos - v_position);
    vec3 to_cam = normalize(u_cam_pos - v_position);
    vec4 light_color = vec4(1, 1, 1, 1);

    vec4 diffuse = light_color * texture2D(diffuse, v_tex_coord) * clamp(dot(unit_normal, to_light), 0, 1);
    vec4 specular = vec4(0);
    if (dot(unit_normal, to_light) > 0) {
        specular = light_color * pow(clamp(dot(reflect(-to_light, unit_normal), to_cam), 0, 1), 10) * 0.75;
    }
    o_color = clamp(diffuse + specular, vec4(0), vec4(1));
}
