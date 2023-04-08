#ifndef RTC_H
#define RTC_H

void rtc_init(void);

/* caller implemented */
void rtc_tick(void);
void pit_tick(void);

#endif //RTC_H
