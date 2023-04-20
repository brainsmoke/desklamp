#ifndef FIRMWARE_H
#define FIRMWARE_H

void load(void);
void save(void);
void restore(void);
void factory_reset(void);

void yield(void);

void print_state(void);
void debug_print(void);

#endif //FIRMWARE_H
