#ifndef DCO_H_
#define DCO_H_

#define FREQ_15_MHZ 1500000
#define FREQ_3_MHZ 3000000
#define FREQ_6_MHZ 6000000
#define FREQ_12_MHZ 12000000
#define FREQ_24_MHZ 24000000
#define PERIOD_100 60000
#define PERIOD_200 30000
#define PERIOD_300 20000
#define PERIOD_400 15000
#define PERIOD_500 12000
#define PERIOD 200
#define T_100 95
#define T_200 200
#define T_300 315
#define T_400 440
#define T_500 560
#define S_100 52
#define S_200 104
#define S_300 160
#define S_400 215
#define S_500 275

void set_DCO(int frequency);

#endif /* DCO_H_ */