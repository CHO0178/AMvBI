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
	PORTB->PCR[18] |= 1 << PORT_PCR_MUX_SHIFT;
	// nastavte pin cervene led diody na output
	GPIOB->PDDR |= 1 << 18;
	// zapnete cervenou diodu
	GPIOB->PDOR &= ~(1 << 18);  // log. 0 0V dovoli protekat proudu skrze diodu viz datasheet
}

void cviceni2Setup()
{
	// presmerujte signal z periferie GPIO na příslušný pin cervene a zelene diody
	PORTB->PCR[18] |= 1 << PORT_PCR_MUX_SHIFT;
	PORTB->PCR[19] |= PORT_PCR_MUX(1);
	// nastavte cervenou a zelenou diodu na vystup
	GPIOB->PDDR |= (1 << 18) | (1 << 19);



}
void cviceni2Loop()
{
	// blikejte stridave cervenou, zelenou a zadnou diodou
	// zapni cervenou diodu
	GPIOB->PDOR = 1 << 19;   //nastaveni zelene na log. 1 (3,3V) zamezi proudu diodou
	// zamestnej procesor
	for(int i = 0;i < 2000000; i++){}
	// zapni zelenou diodu a vypni cervenou
	GPIOB->PDOR = 1 << 18;
	// zamestnej procesor
	for(int i = 0;i < 2000000; i++){}
	// vypni zeleou diodu
	GPIOB->PDOR = 0;
	// zamestnej procesor
	for(int i = 0;i < 2000000; i++){}
}

void cviceni3Loop()
{
	// vytvor semafor:  R -> Y(red&green) -> G -> Y
	GPIOB->PDOR |= 1 << 19;
	heavyFunction();
	GPIOB->PDOR = 0;
	heavyFunction();
	GPIOB->PDOR = 1 << 18;
	heavyFunction();
	GPIOB->PDOR = 0;
	heavyFunction();
}

