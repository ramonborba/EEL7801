idf_component_register(SRCS "ZeroDetector.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES gpio_cxx isr_handlers power_control config driver )
