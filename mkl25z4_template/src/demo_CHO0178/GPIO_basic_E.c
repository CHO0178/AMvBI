#include "MKL25Z4.h"
#include "wdog.h"

/*

pinout(str. 161)

PORT (CH11)
	PCR[32]
		ISF
		IRQC
		MUX
	ISFR


GPIO (CH41)
	PDOR
	PCOR
	PTOR
	PDIR
	PDDR
*/

void cviceni1Setup();
void cviceni2Setup();
void cviceni1Loop();
void cviceni2Loop();
void cviceni3Loop();

int main(void)
{
	wdog_init(WDOG_CONF_LPOCLK_1024_CYCLES);

	cviceni1Setup();

	while (1) {
		wdog_refresh();
	}

	return 0;
}

void cviceni1Setup()
{
	// presmerujte signal z periferie GPIO na pin příslušný pin cervene diody

	// nastavte pin cervene led diody na output

	// zapnete cervenou diodu

}

void cviceni2Setup()
{
	// presmerujte signal z periferie GPIO na pin příslušný pin cervene a zelene diody

	// nastavte cervenou a zelenou diodu na vystup

}
void cviceni2Loop()
{
	// blikejte stridave cervenou, zelenou a zadnou diodou
	// zapni cervenou diodu

	// zamestnej procesor

	// zapni zelenou diodu

	// zamestnej procesor

	// vypni cervenou diodu

	// zamestnej procesor

}

void cviceni3Loop()
{
	// vytvor semafor
}
