idf_component_register(SRCS "tasks_api.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES config app_comm heartbeat interface power_control read_sensors startup)
