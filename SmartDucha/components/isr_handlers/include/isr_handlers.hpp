/**
 * @file isr_handlers.hpp
 * 
 * @brief isr handlers header file
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 26-07-2022
 */

#ifndef ISR_HANDLERS_HPP_
#define ISR_HANDLERS_HPP_

#define DBOUNCE_TIME        (2) // Debouncing time in ms.
#define DBOUNCE_THRESHOLD   (DBOUNCE_TIME / portTICK_PERIOD_MS) // Debouncing threshold in system ticks

/**
 * @brief ISR to handle button presses with software debouncing.
 * 
 * @param pvParameters Number of the pin this handler is attached to.
 */
void ISR_zeroDetector (void* pvParameters);

#endif /* ISR_HANDLERS_HPP_ */
