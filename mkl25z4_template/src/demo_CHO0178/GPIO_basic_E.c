#include "MKL25Z4.h"
#include "wdog.h"
#include "littleHelper.h"

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
void cviceni4Setup();
void cviceni2Loop();
void cviceni3Loop();
void cviceni4Loop();

int main(void)
{
	wdog_init(WDOG_CONF_DIS);

	while (1) {
		wdog_refresh();
	}

	return 0;
}

void cviceni1Setup()
{
	// presmerujte signal z periferie GPIO na prislusny pin cervene diody

	// nastavte pin cervene led diody na output

	// zapnete cervenou diodu

}

void cviceni2Setup()
{
	// presmerujte signal z periferie GPIO na příslušný pin cervene a zelene diody

	// nastavte cervenou a zelenou diodu na vystup
	//GPIOB->PDDR = (1<<18) | (1<<19);

}
void cviceni2Loop()
{
	// blikejte stridave cervenou, zelenou a zadnou diodou
	// zapni cervenou diodu

	// zamestnej procesor

	// zapni zelenou diodu a vypni cervenou

	// zamestnej procesor

	// vypni zelenou diodu

	// zamestnej procesor

}

void cviceni3Loop()
{
	// vytvor semafor:  R -> Y(red&green) -> G -> Y
}

void cviceni4Setup()
{
	//presmerujte signal z periferie GPIO na příslušný pin tlacitka

}

void cviceni4Loop()
{
	//vlozte hodnotu z tlacitka na diodu

}
