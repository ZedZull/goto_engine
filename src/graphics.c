static void graphics_init(int width, int height) {
    glViewport(0, 0, width, height);
    glClearColor((100.0f / 255.0f), (149.0f / 255.0f), (237.0f / 255.0f), 1.0f);
}

static void graphics_begin_frame(void) {
    glClear(GL_COLOR_BUFFER_BIT);
}

static void graphics_end_frame(void) {

}
