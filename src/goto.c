#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Goto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);

    load_opengl_functions();

    graphics_init(SCREEN_WIDTH, SCREEN_HEIGHT);

    bool is_running = true;

    double delta_time = (1.0 / 60.0);

    double last_time = (SDL_GetTicks() / 1000.0);
    double unprocessed_time = 0.0;

    while (is_running) {
        double current_time = (SDL_GetTicks() / 1000.0);
        double frame_time = current_time - last_time;
        last_time = current_time;

        unprocessed_time += frame_time;

        while (unprocessed_time >= delta_time) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    is_running = false;
                }
            }

            // TODO(zedzull): Update here!

            unprocessed_time -= delta_time;
        }

        graphics_begin_frame();

        graphics_end_frame();
        
        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(gl_context);

    SDL_Quit();

    return 0;
}
