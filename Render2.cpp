void InitRenderer() {
    // Set up OpenGL context, shaders, and buffers
    glEnable(GL_DEPTH_TEST);
    Shader basicShader("vertex_shader.glsl", "fragment_shader.glsl");
    basicShader.use();
    
    // Load and configure 3D models, textures
    LoadModel("boss_model.obj");
    LoadTexture("boss_texture.png");
}
