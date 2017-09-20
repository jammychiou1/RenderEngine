#version 120

varying vec3 v_position;
varying vec2 v_tex_coord;
varying vec3 v_normal;

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
    specular = light_color * pow(clamp(dot(reflect(-to_light, unit_normal), to_cam), 0, 1), 10) * 0.75;
    //if (dot(unit_normal, to_light) > 0) {
    //    specular = light_color * pow(clamp(dot(reflect(-to_light, unit_normal), to_cam), 0, 1), 10) * 0.75;
    //}
    gl_FragColor = clamp(diffuse + specular, vec4(0), vec4(1));
    //gl_FragColor = vec4(unit_normal, 1);
}
