idf_component_register(SRCS "power_control.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES Profile ShowerDevice Potencia  NTCSensor Triac)
