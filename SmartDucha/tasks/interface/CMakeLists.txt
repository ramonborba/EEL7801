idf_component_register(SRCS "interface.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES Shower startup gpio_cxx isr_handlers)
