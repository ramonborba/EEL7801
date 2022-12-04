idf_component_register(SRCS "ShowerState.cpp" "Shower.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES Profile ShowerDevice isr_handlers)
