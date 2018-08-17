#ifndef __FAN_H
#define __FAN_H

#define ENC PCout(1)
#define IN5 PCout(2)
#define IN6 PCout(3)

void Fan_Init(void);
void miehuo(void);
void duojixuanzhuan(void);
void fengshan(u16 c);

#endif
