#version 410 core
out vec4 fragColor;         //The final color

in vec3 normalTransposed;   //Normal of fragment, already transposed
in vec3 fragmentPosition;
in vec2 UV;       //for textures

uniform sampler2D textureSampler;

uniform float ambientStrengt = 0.1;

uniform vec3 lightPosition;
uniform vec3 lightColor = vec3(.3, .3, 1.);  //blueish
uniform float lightStrengt = 0.9;
uniform float specularStrength = 0.9;
uniform int specularExponent = 32;

uniform vec3 objectColor = vec3(1.0, 1.0, 1.0); //white

uniform vec3 cameraPosition;

void main() {
    //ambient
    vec3 ambient = ambientStrengt * lightColor;

    //diffuse
    vec3 normalCorrected = normalize(normalTransposed);
    vec3 lightDirection = normalize(lightPosition - fragmentPosition);
    float angleFactor = max(dot(normalCorrected, lightDirection), 0.0);
    vec3 diffuse = angleFactor * objectColor * lightColor * lightStrengt;

    //specular
    vec3 viewDirection = normalize(cameraPosition - fragmentPosition);
    float spec = 0.0;
    if (angleFactor > 0.0)     //calculations only needed if diffuse is above 0.0
    {
        vec3 reflectDirection = reflect(-lightDirection, normalCorrected);
        spec = pow(max(dot(viewDirection, reflectDirection), 0.0), specularExponent);
    }
    vec3 specular = spec * lightColor * specularStrength;

    vec3 result = ambient + diffuse + specular;

    fragColor = vec4(result, 1.0) * texture(textureSampler, UV);
}

//Using calculations in world space,
//https://learnopengl.com/Lighting/Basic-Lighting
//but could just as easy be done in camera space
//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-8-basic-shading/
