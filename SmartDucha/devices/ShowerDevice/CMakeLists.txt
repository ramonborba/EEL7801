idf_component_register(SRCS "ShowerDevice.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES Profile power_control Potencia read_sensors Triac ZeroDetector )
