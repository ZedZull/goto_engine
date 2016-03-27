#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Goto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    load_opengl_functions();

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glClearColor((100.0f / 255.0f), (149.0f / 255.0f), (237.0f / 255.0f), 1.0f);

    bool is_running = true;

    while (is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(gl_context);

    SDL_Quit();

    return 0;
}
