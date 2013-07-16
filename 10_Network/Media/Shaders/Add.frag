uniform sampler2D source;
uniform sampler2D bloom;

void main()
{
    vec4 sourceFragment = texture2D(source, gl_TexCoord[0].xy);
    vec4 bloomFragment = texture2D(bloom, gl_TexCoord[0].xy);
    gl_FragColor = sourceFragment + bloomFragment;
}